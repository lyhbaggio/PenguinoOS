/**
 * @mainpage
 * libestr - some essentials for string handling (and a bit more)
 *
 * Copyright 2010 by Rainer Gerhards and Adiscon GmbH.
 *
 *
 *//*
 *
 * libestr - some essentials for string handling (and a bit more)
 * Copyright 2010 by Rainer Gerhards and Adiscon GmbH.
 *
 * This file is part of libestr.
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
#ifndef LIBESTR_H_INCLUDED
#define	LIBESTR_H_INCLUDED


/**
 * Data type for string sizes.
 */
typedef unsigned int es_size_t;

/**
 * The string object.
 * @note
 * We do not use es_size_t, because that tends to be 64 bits on 64 bit platforms.
 * In almost all cases I can think of, 4GB is a sufficient upper limit on string
 * size. So we use unsigned ints, which means we save a lot of space and efficieny,
 * what is especially important if there is a large number of strings inside a
 * process.
 * For the same reason, we do \b not provide a way to create and automatically
 * free a traditional C string. That would requre another pointer (8 bytes of
 * overhead on a 64 bit machine!).
 */
typedef struct
{	
	/* word-aligned items */
	es_size_t lenStr;		/**< actual length of string,
					    MUST be first element of struct because
					    of inline functions! */
	es_size_t lenBuf;		/**< length of buffer (including free space) */
	/* non word-aligned items */
	/* --currently none-- */
	/* NOTE: the actual string data is placed AFTER the last data
	 * element. It is accessed by pointer arithmetic. This saves us
	 * storing another pointer (8 byte on 64bit machines!)
	 */
} es_str_t;


/**
 * Return library version as a classical NUL-terminated C-String.
 */
char *es_version(void);

/**
 * Get the base address for the string's buffer.
 * Proper use for library users is to gain read-only access to the buffer,
 * so that it may be used inside an i/o request or similar things. Note that
 * it is an \b invalid assumption that the buffer address keeps constant between
 * library calls. This is only guaranteed for read-only methods. For example,
 * the methods used to grow the string may be forced to reallocate the buffer
 * on a new address with sufficiently free space.
 *
 * @param[in] s string object
 * @returns address of buffer <b>Note: this is NOT a zero-terminated C string!</b>
 */
static inline unsigned char *
es_getBufAddr(es_str_t *s)
{
	return ((unsigned char*) s) + sizeof(es_str_t);
}

/**
 * Return length of provided string object.
 */
static inline es_size_t es_strlen(es_str_t *str)
{
	return(str->lenStr);
}

/**
 * Create a new string object.
 * @param[in] lenhint expected max length of string. Do \b not use too large value.
 * @returns pointer to new object or NULL on error
 */
es_str_t* es_newStr(es_size_t lenhint);

/**
 * delete a string object.
 * @param[in] str string to be deleted.
 */
void es_deleteStr(es_str_t *str);


/**
 * Create a new string object based on a "traditional" C string.
 * @param[in] cstr traditional, '\0'-terminated C string
 * @param[in] len length of str. Use strlen() if you don't know it, but often it
 *  		the length is known and we use this as a time-safer (if present).
 * @returns pointer to new object or NULL on error
 */
es_str_t* es_newStrFromCStr(char *cstr, es_size_t len);


/**
 * Create a new string object from a substring of an existing string.
 * This involves copying the substring.
 *
 * @param[in] str original string
 * @param[in] start beginning position of substring (0-based)
 * @param[in] len length of substring to extract
 * @returns pointer to new object or NULL on error
 *
 * If start > strlen, a valid (!) empty string will be returned. If
 * start+len > strlen, the rest of the string starting at start will be
 * returned.
 */
es_str_t* es_newStrFromSubStr(es_str_t *str, es_size_t start, es_size_t len);


/**
 * Create a new string object from a buffer.
 * This involves copying the buffer.
 *
 * @param[in] buf buffer begin
 * @param[in] len length of buffer
 * @returns pointer to new object or NULL on error
 */
es_str_t* es_newStrFromBuf(char *buf, es_size_t len);


/**
 * Empty a string.
 * An existing string is set to empty state, but no allocation
 * or allocation information is reset. This function is useful if
 * the same string object is used several times within a loop
 * and it shall be re-set to "" on each iteration. As the allocation
 * is preserved, the string in most cases needs to grow only very
 * few times. This is considered the fastest method to repeatedly
 * work with temporary strings.
 *
 * @param[in] str the string to empty
 */
static inline void
es_emptyStr(es_str_t *str)
{
	str->lenStr = 0;
}



/**
 * Duplicate a str.
 * Currently, the string is actually duplicated. May be changed to
 * copy-on-write in later releases.
 *
 * @param[in] str original string
 * @returns pointer to new object or NULL on error
 */
static inline es_str_t*
es_strdup(es_str_t *str)
{
	return es_newStrFromSubStr(str, 0, es_strlen(str));
}


/**
 * Compare a string against a buffer.
 * Semantics are the same as strcmp(). This function is required in
 * order to permit simple comparisons against C strings, what
 * otherwise would require conversions. As a side-effect, it can also
 * compare against substrings and other buffers of any type.
 *
 * @param[in] s string to compare
 * @param[in] b buffer to compare against
 * @param[in] len lenght of buffer
 * @returns 0 if equal, negative if s<cs, positive if s>cs
*/
int es_strbufcmp(es_str_t *s, unsigned char *b, es_size_t len);


/**
 * Compare two string objects.
 * Semantics are the same as strcmp().
 *
 * @param[in] s1 frist string
 * @param[in] s2 second string
 * @returns 0 if equal, negative if s1<s2, positive if s1>s2
*/
static inline int
es_strcmp(es_str_t *s1, es_str_t *s2)
{
	return es_strbufcmp(s1, es_getBufAddr(s2), s2->lenStr);
}


/**
 * A macro to compare a string against a constant C string
 */
#define es_strconstcmp(str, constcstr) \
	es_strbufcmp(str, (unsigned char*) constcstr, sizeof(constcstr) - 1)

/**
 * Extend string buffer.
 * This is called if the size is insufficient. Note that the string
 * pointer will be changed. This is an \b internal function that should
 * \b not be called from any lib user app.
 *
 * @param[in/out] ps pointer to (pointo to) string to be extened
 * @param[in] minNeeded minimum number of additional bytes needed
 * @returns 0 on success, something else otherwise
 */
int es_extendBuf(es_str_t **ps, es_size_t minNeeded);

/**
 * Append a character to the current string object.
 * Note that the pointer to the string object may change. This
 * is because we may need to aquire more memory.
 * @param[in/out] ps string to be extened (updatedable pointer required!)
 * @returns 0 on success, something else otherwise
 */
int es_addChar(es_str_t **ps, unsigned char c);


/**
 * Append a memory buffer to a string.
 * This is the method that almost all other append methods actually use.
 *
 * @param[in/out] ps1 updateable pointer to to-be-appended-to string
 * @param[in] buf buffer to append
 * @param[in] lenBuf length of buffer
 *
 * @returns 0 on success, something else otherwise
 */
int es_addBuf(es_str_t **ps1, char *buf, es_size_t lenBuf);

/**
 * A macro to add a traditional C constant to a string.
 */
#define es_addBufConstcstr(str, constcstr) \
	es_addBuf(str, constcstr, sizeof(constcstr) - 1)

/**
 * Append a second string to the first one.
 *
 * @param[in/out] ps1 updateable pointer to to-be-appended-to string
 * @param[in] s2 string to append
 *
 * @returns 0 on success, something else otherwise
 */
static inline int
es_addStr(es_str_t **ps1, es_str_t *s2)
{
	return es_addBuf(ps1, (char*) es_getBufAddr(s2), s2->lenStr);
}

/**
 * Obtain a traditional C-String from a string object.
 * The string object is not modified. Note that the C string is not
 * necessarily exactly the same string: C Strings can not contain NUL
 * characters, and as such they need to be either encoded or dropped.
 * This is done by this function. The user can specify with which character
 * sequence (a traditional C String) it shall be replaced.
 * @note
 * This function has to do a lot of work, and should not be called unless
 * absolutely necessary. If possible, use the native representation of
 * the string object. For example, you can use the buffer address and 
 * string length in most i/o calls, if you use the native versions and avoid
 * the C string i/o calls.
 *
 * @param[in] s string object
 * @param[in] nulEsc escape sequence for NULs. If NULL, NUL characters will be dropped.
 *
 * @returns NULL in case of error, otherwise a suitably-encoded standard C string.
 * 	This string is allocated from the dynamic memory pool and must be freed
 * 	by the caller.
 */
char *es_str2cstr(es_str_t *s, char *nulEsc);

/**
 * Unescape a string.
 * The escape seqences defined below will be unescaped and replaced
 * by a single character. The string is modified in place (note that
 * space is always sufficient, because the resulting string will be
 * smaller or of equal size). This function can not run into trouble,
 * so it does not return a return status.
 *
 * The following escape sequences, inspired by the C language, are supported:
 * (Note: double backslashes are for Doxygen, of course this is to
 * be used with single backslashes):
 * - \\0 NUL
 * - \\a BEL
 * - \\b Backspace
 * - \\f FF
 * - \\n LF
 * - \\r CR
 * - \\t HT
 * - \\' singlu quotation mark
 * - \\" double quotation mark
 * - \\? question mark
 * - \\\\ backslash character
 * - \\ooo ASCII Character in octal notation (o being octal digit)
 * - \\xhh ASCC character in hexadecimal notation
 * - \\xhhhh Unicode characer in headecimal notation
 * All other escape sequences are undefined. Currently, this is
 * interpreted as the escape character itself, but this is not
 * guaranteed. Most importantly, a special meaning may be assigned
 * to any of the currently-unassigned characters in the future.
 *
 * @param[in/out] s string object to unescape.
 */
void es_unescapeStr(es_str_t *s);

#endif /* #ifndef LIBESTR_H_INCLUDED */
