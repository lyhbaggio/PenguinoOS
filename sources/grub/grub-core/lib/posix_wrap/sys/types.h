/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2009, 2010  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_POSIX_SYS_TYPES_H
#define GRUB_POSIX_SYS_TYPES_H	1

#define GRUB_POSIX 1
#include <grub/misc.h>

typedef grub_size_t size_t;
typedef grub_ssize_t ssize_t;
#include <stdbool.h>

#define UINTMAX_C(c)	c ## ULL
#define UINT32_C(c)	c ## UL
#define UINT64_C(c)	c ## ULL

typedef grub_uint8_t uint8_t;
typedef grub_uint16_t uint16_t;
typedef grub_uint32_t uint32_t;
typedef grub_uint64_t uint64_t;

typedef grub_int8_t int8_t;
typedef grub_int16_t int16_t;
typedef grub_int32_t int32_t;
typedef grub_int64_t int64_t;

#define PRIu32 PRIuGRUB_UINT32_T
#define PRIX32 PRIxGRUB_UINT32_T

#define PRIu8 PRIuGRUB_UINT8_T
#define PRIX8 PRIxGRUB_UINT8_T
#define PRIu16 PRIuGRUB_UINT16_T
#define PRIX16 PRIxGRUB_UINT16_T

#define UINT32_MAX GRUB_UINT32_MAX
#define SIZE_MAX GRUB_SIZE_MAX

#ifdef GRUB_CPU_WORDS_BIGENDIAN
#define WORDS_BIGENDIAN
#else
#undef WORDS_BIGENDIAN
#endif

#endif
