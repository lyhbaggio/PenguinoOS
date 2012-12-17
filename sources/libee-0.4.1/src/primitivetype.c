/**
 * @file primitivetype.c
 * Implementation of the primitiveType class.
 *//*
 * Libee - An Event Expression Library inspired by CEE
 * Copyright 2010 by Rainer Gerhards and Adiscon GmbH.
 *
 * This file is part of libee.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * A copy of the LGPL v2.1 can be found in the file "COPYING" in this distribution.
 */
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>

#include "libee/libee.h"
#include "libee/internal.h"

#define ERR_ABORT {r = 1; goto done; }

#define CHECK_CTX \
	if(ctx->objID != ObjID_CTX) { \
		r = -1; \
		goto done; \
	}

ee_ctx
ee_initPrimitiveType(void)
{
	ee_ctx ctx;
	if((ctx = calloc(1, sizeof(struct ee_ctx_s))) == NULL)
		goto done;

	ctx->objID = ObjID_CTX;
	ctx->dbgCB = NULL;
done:
	return ctx;
}

int
ee_exitPrimitiveType(ee_ctx ctx)
{
	int r = 0;

	CHECK_CTX;

	ctx->objID = ObjID_None; /* prevent double free */
	free(ctx);
done:
	return r;
}

/* some helpers */
static inline int
hParseInt(unsigned char **buf, es_size_t *lenBuf)
{
	unsigned char *p = *buf;
	es_size_t len = *lenBuf;
	int i = 0;
	
	while(len > 0 && isdigit(*p)) {
		i = i * 10 + *p - '0';
		++p;
		--len;
	}

	*buf = p;
	*lenBuf = len;
	return i;
}

/* parsers for the primitive types
 *
 * All parsers receive 
 *
 * @param[in] ctx context object
 * @param[in] str the to-be-parsed string
 * @param[in/out] offs an offset into the string
 * @param[in] ed string with extra data for parser use
 * @param[out] newVal newly created value
 *
 * They will try to parse out "their" object from the string. If they
 * succeed, they:
 *
 * create a nw ee_value (newVal) and store the obtained value into it
 * update buf and lenBuf to reflect the parsing carried out
 *
 * returns 0 on success and EE_WRONGPARSER if this parser could
 *           not successfully parse (but all went well otherwise) and something
 *           else in case of an error.
 */
#define BEGINParser(ParserName) \
int ee_parse##ParserName(ee_ctx __attribute__((unused)) ctx, es_str_t *str, es_size_t *offs, \
                      __attribute__((unused)) es_str_t *ed, struct ee_value **value) \
{ \
	es_size_t r = EE_WRONGPARSER;

#define ENDParser \
	return r; \
}




/**
 * Parse a TIMESTAMP as specified in RFC5424 (subset of RFC3339).
 */
BEGINParser(RFC5424Date)
	unsigned char *pszTS;
	/* variables to temporarily hold time information while we parse */
	int year;
	int month;
	int day;
	int hour; /* 24 hour clock */
	int minute;
	int second;
	int secfrac;	/* fractional seconds (must be 32 bit!) */
	int secfracPrecision;
	char OffsetMode;	/* UTC offset + or - */
	char OffsetHour;	/* UTC offset in hours */
	int OffsetMinute;	/* UTC offset in minutes */
	es_size_t len;
	es_size_t orglen;
	/* end variables to temporarily hold time information while we parse */

	assert(*offs < es_strlen(str));

	pszTS = es_getBufAddr(str) + *offs;
	len = orglen = es_strlen(str) - *offs;

	year = hParseInt(&pszTS, &len);

	/* We take the liberty to accept slightly malformed timestamps e.g. in 
	 * the format of 2003-9-1T1:0:0.  */
	if(len == 0 || *pszTS++ != '-') goto fail;
	--len;
	month = hParseInt(&pszTS, &len);
	if(month < 1 || month > 12) goto fail;

	if(len == 0 || *pszTS++ != '-')
		goto fail;
	--len;
	day = hParseInt(&pszTS, &len);
	if(day < 1 || day > 31) goto fail;

	if(len == 0 || *pszTS++ != 'T') goto fail;
	--len;

	hour = hParseInt(&pszTS, &len);
	if(hour < 0 || hour > 23) goto fail;

	if(len == 0 || *pszTS++ != ':')
		goto fail;
	--len;
	minute = hParseInt(&pszTS, &len);
	if(minute < 0 || minute > 59) goto fail;

	if(len == 0 || *pszTS++ != ':') goto fail;
	--len;
	second = hParseInt(&pszTS, &len);
	if(second < 0 || second > 60) goto fail;

	/* Now let's see if we have secfrac */
	if(len > 0 && *pszTS == '.') {
		--len;
		unsigned char *pszStart = ++pszTS;
		secfrac = hParseInt(&pszTS, &len);
		secfracPrecision = (int) (pszTS - pszStart);
	} else {
		secfracPrecision = 0;
		secfrac = 0;
	}

	/* check the timezone */
	if(len == 0) goto fail;

	if(*pszTS == 'Z') {
		--len;
		pszTS++; /* eat Z */
		OffsetMode = 'Z';
		OffsetHour = 0;
		OffsetMinute = 0;
	} else if((*pszTS == '+') || (*pszTS == '-')) {
		OffsetMode = *pszTS;
		--len;
		pszTS++;

		OffsetHour = hParseInt(&pszTS, &len);
		if(OffsetHour < 0 || OffsetHour > 23)
			goto fail;

		if(len == 0 || *pszTS++ != ':')
			goto fail;
		OffsetMinute = hParseInt(&pszTS, &len);
		if(OffsetMinute < 0 || OffsetMinute > 59)
			goto fail;
	} else {
		/* there MUST be TZ information */
		goto fail;
	}

	if(len > 0) {
		if(*pszTS != ' ') /* if it is not a space, it can not be a "good" time */
			goto fail;
		++pszTS; /* just skip past it */
		--len;
	}

	/* we had success, so update parse pointer and caller-provided timestamp */
	es_size_t usedLen =  orglen - len;
	es_str_t *valstr = es_newStrFromSubStr(str, *offs, usedLen);
	*value = ee_newValue(ctx);
	ee_setStrValue(*value, valstr);
	*offs += usedLen;
	r = 0; /* parsing was successful */
#	if 0 /* currently, we need to persist only the string format */
	/* we had success, so update parse pointer and caller-provided timestamp */
	*ppszTS = pszTS;
	pTime->timeType = 2;
	pTime->year = year;
	pTime->month = month;
	pTime->day = day;
	pTime->hour = hour;
	pTime->minute = minute;
	pTime->second = second;
	pTime->secfrac = secfrac;
	pTime->secfracPrecision = secfracPrecision;
	pTime->OffsetMode = OffsetMode;
	pTime->OffsetHour = OffsetHour;
	pTime->OffsetMinute = OffsetMinute;
#	endif

fail:
ENDParser


/**
 * Parse a RFC3164 Date.
 */
BEGINParser(RFC3164Date)
	unsigned char *p;
	es_size_t len, orglen;
	/* variables to temporarily hold time information while we parse */
	int month;
	int day;
	//int year = 0; /* 0 means no year provided */
	int hour; /* 24 hour clock */
	int minute;
	int second;

	assert(*offs < es_strlen(str));

	p = es_getBufAddr(str) + *offs;
	orglen = len = es_strlen(str) - *offs;
	/* If we look at the month (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec),
	 * we may see the following character sequences occur:
	 *
	 * J(an/u(n/l)), Feb, Ma(r/y), A(pr/ug), Sep, Oct, Nov, Dec
	 *
	 * We will use this for parsing, as it probably is the
	 * fastest way to parse it.
	 */
	if(len < 3)
		goto fail;

	switch(*p++)
	{
	case 'j':
	case 'J':
		if(*p == 'a' || *p == 'A') {
			++p;
			if(*p == 'n' || *p == 'N') {
				++p;
				month = 1;
			} else
				goto fail;
		} else if(*p == 'u' || *p == 'U') {
			++p;
			if(*p == 'n' || *p == 'N') {
				++p;
				month = 6;
			} else if(*p == 'l' || *p == 'L') {
				++p;
				month = 7;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'f':
	case 'F':
		if(*p == 'e' || *p == 'E') {
			++p;
			if(*p == 'b' || *p == 'B') {
				++p;
				month = 2;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'm':
	case 'M':
		if(*p == 'a' || *p == 'A') {
			++p;
			if(*p == 'r' || *p == 'R') {
				++p;
				month = 3;
			} else if(*p == 'y' || *p == 'Y') {
				++p;
				month = 5;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'a':
	case 'A':
		if(*p == 'p' || *p == 'P') {
			++p;
			if(*p == 'r' || *p == 'R') {
				++p;
				month = 4;
			} else
				goto fail;
		} else if(*p == 'u' || *p == 'U') {
			++p;
			if(*p == 'g' || *p == 'G') {
				++p;
				month = 8;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 's':
	case 'S':
		if(*p == 'e' || *p == 'E') {
			++p;
			if(*p == 'p' || *p == 'P') {
				++p;
				month = 9;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'o':
	case 'O':
		if(*p == 'c' || *p == 'C') {
			++p;
			if(*p == 't' || *p == 'T') {
				++p;
				month = 10;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'n':
	case 'N':
		if(*p == 'o' || *p == 'O') {
			++p;
			if(*p == 'v' || *p == 'V') {
				++p;
				month = 11;
			} else
				goto fail;
		} else
			goto fail;
		break;
	case 'd':
	case 'D':
		if(*p == 'e' || *p == 'E') {
			++p;
			if(*p == 'c' || *p == 'C') {
				++p;
				month = 12;
			} else
				goto fail;
		} else
			goto fail;
		break;
	default:
		goto fail;
	}

	len -= 3;

	/* done month */

	if(len == 0 || *p++ != ' ')
		goto fail;
	--len;

	/* we accept a slightly malformed timestamp with one-digit days. */
	if(*p == ' ') {
		--len;
		++p;
	}

	day = hParseInt(&p, &len);
	if(day < 1 || day > 31)
		goto fail;

	if(len == 0 || *p++ != ' ')
		goto fail;
	--len;

	/* time part */
	hour = hParseInt(&p, &len);
	if(hour > 1970 && hour < 2100) {
		/* if so, we assume this actually is a year. This is a format found
		 * e.g. in Cisco devices.
		 *
		year = hour;
		*/

		/* re-query the hour, this time it must be valid */
		if(len == 0 || *p++ != ' ')
			goto fail;
		--len;
		hour = hParseInt(&p, &len);
	}

	if(hour < 0 || hour > 23)
		goto fail;

	if(len == 0 || *p++ != ':')
		goto fail;
	--len;
	minute = hParseInt(&p, &len);
	if(minute < 0 || minute > 59)
		goto fail;

	if(len == 0 || *p++ != ':')
		goto fail;
	--len;
	second = hParseInt(&p, &len);
	if(second < 0 || second > 60)
		goto fail;

	/* we provide support for an extra ":" after the date. While this is an
	 * invalid format, it occurs frequently enough (e.g. with Cisco devices)
	 * to permit it as a valid case. -- rgerhards, 2008-09-12
	 */
	if(len > 0 && *p == ':') {
		++p; /* just skip past it */
		--len;
	}

	/* we had success, so update parse pointer and caller-provided timestamp */
	es_size_t usedLen =  orglen - len;
	es_str_t *valstr = es_newStrFromSubStr(str, *offs, usedLen);
	*value = ee_newValue(ctx);
	ee_setStrValue(*value, valstr);
	*offs += usedLen;
	r = 0; /* parsing was successful */
#if 0 /* TODO: see how we represent the actual timestamp */
	pTime->month = month;
	if(year > 0)
		pTime->year = year; /* persist year if detected */
	pTime->day = day;
	pTime->hour = hour;
	pTime->minute = minute;
	pTime->second = second;
#endif
fail:
ENDParser


/**
 * Parse a Number.
 * Note that a number is an abstracted concept. We always represent it
 * as 64 bits (but may later change our mind if performance dictates so).
 */
BEGINParser(Number)
	unsigned char *p;
	es_size_t len, orglen;
	long long n;


//printf("parseNumber got '%s'\n", es_str2cstr(str, NULL)+ *offs);
	p = es_getBufAddr(str) + *offs;
	orglen = len = es_strlen(str) - *offs;

	n = hParseInt(&p, &len);
	if(p == es_getBufAddr(str))
		goto fail;

	if((*value = ee_newValue(ctx)) == NULL) {
		r = EE_NOMEM;
		goto fail;
	}

	/* success, persist */
	es_size_t usedLen =  orglen - len;
	es_str_t *valstr = es_newStrFromSubStr(str, *offs, usedLen);
	ee_setStrValue(*value, valstr);
	*offs += usedLen;
	r = 0;
fail:
ENDParser


/**
 * Parse a word.
 * A word is a SP-delimited entity. The parser always works, except if
 * the offset is position on a space upon entry.
 */
BEGINParser(Word)
	unsigned char *c;
	es_size_t i;
	es_size_t len;	/**< length of substring we finally extract */
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	c = es_getBufAddr(str);
	i = *offs;

	/* search end of word */
	while(i < es_strlen(str) && c[i] != ' ') 
		i++;

	if(i == *offs) {
		r = EE_WRONGPARSER;
		goto done;
	}

	/* success, persist */
	len =  i - *offs;
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, len));
	ee_setStrValue(*value, valstr);
	*offs = i;
	r = 0;

done:	return r;
ENDParser


/**
 * Parse everything up to a specific character.
 * The character must be the only char inside extra data passed to the parser.
 * It is a program error if strlen(ed) != 1. It is considered a format error if
 * a) the to-be-parsed buffer is already positioned on the terminator character
 * b) there is no terminator until the end of the buffer
 * In those cases, the parsers declares itself as not being successful, in all
 * other cases a string is extracted.
 */
BEGINParser(CharTo)
	unsigned char *c;
	unsigned char cTerm;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	assert(es_strlen(ed) == 1);
	cTerm = *(es_getBufAddr(ed));
	c = es_getBufAddr(str);
	i = *offs;

	/* search end of word */
	while(i < es_strlen(str) && c[i] != cTerm) 
		i++;

	if(i == *offs || i == es_strlen(str) || c[i] != cTerm) {
		r = EE_WRONGPARSER;
		goto done;
	}

	/* success, persist */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, i - *offs));
	ee_setStrValue(*value, valstr);
	*offs = i;
	r = 0;

done:	return r;
ENDParser


/**
 * Parse a quoted string. In this initial implementation, escaping of the quote
 * char is not supported. A quoted string is one start starts with a double quote,
 * has some text (not containing double quotes) and ends with the first double
 * quote character seen. The extracted string does NOT include the quote characters.
 * rgerhards, 2011-01-14
 */
BEGINParser(QuotedString)
	unsigned char *c;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	c = es_getBufAddr(str);
	i = *offs;

	if(c[i] != '"')
		goto done;
	++i;

	/* search end of string */
	while(i < es_strlen(str) && c[i] != '"') 
		i++;

	if(i == es_strlen(str) || c[i] != '"') {
		r = EE_WRONGPARSER;
		goto done;
	}

	/* success, persist */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs + 1, i - *offs - 1));
	ee_setStrValue(*value, valstr);
	*offs = i + 1; /* "eat" terminal double quote */

	r = 0;

done:	return r;
ENDParser


/**
 * Parse an ISO date, that is YYYY-MM-DD (exactly this format).
 * Note: we do manual loop unrolling -- this is fast AND efficient.
 * rgerhards, 2011-01-14
 */
BEGINParser(ISODate)
	unsigned char *c;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	c = es_getBufAddr(str);
	i = *offs;

	if(*offs+10 > es_strlen(str))
		goto done;	/* if it is not 10 chars, it can't be an ISO date */

	/* year */
	if(!isdigit(c[i])) goto done;
	if(!isdigit(c[i+1])) goto done;
	if(!isdigit(c[i+2])) goto done;
	if(!isdigit(c[i+3])) goto done;
	if(c[i+4] != '-') goto done;
	/* month */
	if(c[i+5] == '0') {
		if(c[i+6] < '1' || c[i+6] > '9') goto done;
	} else if(c[i+5] == '1') {
		if(c[i+6] < '0' || c[i+6] > '2') goto done;
	} else {
		goto done;
	}
	if(c[i+7] != '-') goto done;
	/* day */
	if(c[i+8] == '0') {
		if(c[i+9] < '1' || c[i+9] > '9') goto done;
	} else if(c[i+8] == '1' || c[i+8] == '2') {
		if(!isdigit(c[i+9])) goto done;
	} else if(c[i+8] == '3') {
		if(c[i+9] != '0' && c[i+9] != '1') goto done;
	} else {
		goto done;
	}

	/* success, persist */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, 10));
	ee_setStrValue(*value, valstr);
	*offs += 10;
	r = 0;

done:	return r;
ENDParser

/**
 * Parse a timestamp in 24hr format (exactly HH:MM:SS).
 * Note: we do manual loop unrolling -- this is fast AND efficient.
 * rgerhards, 2011-01-14
 */
BEGINParser(Time24hr)
	unsigned char *c;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	c = es_getBufAddr(str);
	i = *offs;

	if(*offs+8 > es_strlen(str))
		goto done;	/* if it is not 8 chars, it can't be us */

	/* hour */
	if(c[i] == '0' || c[i] == '1') {
		if(!isdigit(c[i+1])) goto done;
	} else if(c[i] == '2') {
		if(c[i+1] < '0' || c[i+1] > '3') goto done;
	} else {
		goto done;
	}
	/* TODO: the code below is a duplicate of 24hr parser - create common function */
	if(c[i+2] != ':') goto done;
	if(c[i+3] < '0' || c[i+3] > '5') goto done;
	if(!isdigit(c[i+4])) goto done;
	if(c[i+5] != ':') goto done;
	if(c[i+6] < '0' || c[i+6] > '5') goto done;
	if(!isdigit(c[i+7])) goto done;

	/* success, persist */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, 8));
	ee_setStrValue(*value, valstr);
	*offs += 8;
	r = 0;

done:	return r;
ENDParser

/**
 * Parse a timestamp in 12hr format (exactly HH:MM:SS).
 * Note: we do manual loop unrolling -- this is fast AND efficient.
 * TODO: the code below is a duplicate of 24hr parser - create common function?
 * rgerhards, 2011-01-14
 */
BEGINParser(Time12hr)
	unsigned char *c;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	c = es_getBufAddr(str);
	i = *offs;

	if(*offs+8 > es_strlen(str))
		goto done;	/* if it is not 8 chars, it can't be us */

	/* hour */
	if(c[i] == '0') {
		if(!isdigit(c[i+1])) goto done;
	} else if(c[i] == '1') {
		if(c[i+1] < '0' || c[i+1] > '2') goto done;
	} else {
		goto done;
	}
	if(c[i+2] != ':') goto done;
	if(c[i+3] < '0' || c[i+3] > '5') goto done;
	if(!isdigit(c[i+4])) goto done;
	if(c[i+5] != ':') goto done;
	if(c[i+6] < '0' || c[i+6] > '5') goto done;
	if(!isdigit(c[i+7])) goto done;

	/* success, persist */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, 8));
	ee_setStrValue(*value, valstr);
	*offs += 8;
	r = 0;

done:	return r;
ENDParser




/* helper to IPv4 address parser, checks the next set of numbers.
 * Syntax 1 to 3 digits, value together not larger than 255.
 * @param[in] str parse buffer
 * @param[in/out] offs offset into buffer, updated if successful
 * @return 0 if OK, 1 otherwise
 */
static int
chkIPv4AddrByte(es_str_t *str, es_size_t *offs)
{
	int val = 0;
	int r = 1;	/* default: fail -- simplifies things */
	unsigned char *c = es_getBufAddr(str);
	es_size_t i = *offs;

	if(i == es_strlen(str) || !isdigit(c[i])) goto done;
	val = c[i++] - '0';
	if(i < es_strlen(str) && isdigit(c[i])) {
		val = val * 10 + c[i++] - '0';
		if(i < es_strlen(str) && isdigit(c[i]))
			val = val * 10 + c[i++] - '0';
	}
	if(val > 255)	/* cannot be a valid IP address byte! */
		goto done;

	*offs = i;
	r = 0;

done:	return r;
}
/**
 * Parser for IPv4 addresses.
 */
BEGINParser(IPv4)
	unsigned char *c;
	es_size_t i;
	es_str_t *valstr;

	assert(str != NULL);
	assert(offs != NULL);
	i = *offs;
	if(es_strlen(str) - i + 1 < 7) {
		/* IPv4 addr requires at least 7 characters */
		r = EE_WRONGPARSER;
		goto done;
	}
	c = es_getBufAddr(str);

	r = EE_WRONGPARSER; /* let's assume things go wrong, leads to simpler code */
	/* byte 1*/
	if(chkIPv4AddrByte(str, &i) != 0) goto done;
	if(i == es_strlen(str) || c[i++] != '.') goto done;
	/* byte 2*/
	if(chkIPv4AddrByte(str, &i) != 0) goto done;
	if(i == es_strlen(str) || c[i++] != '.') goto done;
	/* byte 3*/
	if(chkIPv4AddrByte(str, &i) != 0) goto done;
	if(i == es_strlen(str) || c[i++] != '.') goto done;
	/* byte 4 - we do NOT need any char behind it! */
	if(chkIPv4AddrByte(str, &i) != 0) goto done;

	/* if we reach this point, we found a valid IP address */
	CHKN(*value = ee_newValue(ctx));
	CHKN(valstr = es_newStrFromSubStr(str, *offs, i - *offs));
	ee_setStrValue(*value, valstr);
	*offs = i;
	r = 0;

done:	return r;
ENDParser
