/**
 * @file internal.h
 * Header for internal use only (will not be installed to target systems).
 *//*
 * Copyright 2010 by Rainer Gerhards and Adiscon GmbH.
 *
 * This file is part of ctx.
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
#ifndef LIBEE_INTERNAL_H_INCLUDED

#define	LIBEE_INTERNAL_H_INCLUDED
#define CHKR(x) \
	if((r = (x)) != 0) goto done

#define CHKN(x) \
	if((x) == NULL) { \
		r = EE_NOMEM; \
		goto done; \
	}

#endif /* #ifndef EE_H_INCLUDED */
