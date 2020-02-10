/*
 * Copyright (C) u-blox Melbourn Ltd
 * u-blox Melbourn Ltd, Melbourn, UK
 *
 * All rights reserved.
 *
 * This source file is the sole property of u-blox Melbourn Ltd.
 * Reproduction or utilisation of this source in whole or part is
 * forbidden without the written consent of u-blox Melbourn Ltd.
 */

#ifndef _CELLLAR_PORT_CLIB_H_
#define _CELLLAR_PORT_CLIB_H_

/** Porting layer for C library functions.  These functions
 * are thread-safe.
 */

#include "stdint.h"
#include "stddef.h"
#include "stdbool.h"
#include "limits.h"

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/** struct tm.
 */
 typedef struct {
     int32_t tm_sec;   //<! seconds after the minute, normally 0-59,
                       //< can range up to 61 if a leap second is added.
     int32_t tm_min;   //<! minutes after the hour, 0-59.
     int32_t tm_hour;  //<! hours since midnight, 0-23.
     int32_t tm_mday;  //<! day of the month, 1-31.
     int32_t tm_mon;   //<! months since January, 0-11.
     int32_t tm_year;  //<! years since 1900.
     int32_t tm_wday;  //<! days since Sunday, 0-6.
     int32_t tm_yday;  //<! days since January 1, 0-365.
     int32_t tm_isdst; //<! Daylight Saving Time flag, > 0 if in effect,
                       //< 0 if not in effect, < 0 if no information.
 } CellularPort_tm;

/* ----------------------------------------------------------------
 * FUNCTIONS: MEMORY
 * -------------------------------------------------------------- */

/** free().
 *
 * @param pMem pointer to the memory to be freed.  May be NULL.
 */
void cellularPort_free(void *pMem);

/** malloc().
 *
 * @param size the number of bytes to allocate.
 * @return     a pointer to the memory allocated or NULL on failure.
 */
void *pCellularPort_malloc(size_t sizeBytes);

/** memcpy().
 *
 * @param pDst      the destination address.
 * @param pSrc      the source address.
 * @param sizeBytes the number of bytes to copy.
 * @return          pDst.
 */
void *pCellularPort_memcpy(void *pDst, const void *pSrc,
                           size_t sizeBytes);

/** memmove().
 *
 * @param pDst      the destination memory address.
 * @param pSrc      the source memory address.
 * @param sizeBytes the number of bytes to move.
 * @return          pDst.
 */
void *pCellularPort_memmove(void *pDst, const void *pSrc,
                            size_t sizeBytes);

/** memset().
 *
 * @param pDst      a pointer to the memory to be set.
 * @param value     the value to set, treated as a byte.
 * @param sizeBytes the number of bytes to set to value.
 * @return          pDst.
 */
void *pCellularPort_memset(void *pDst, int32_t value,
                           size_t sizeBytes);

/** memcmp().
 *
 * @param p1        a pointer to the first memory address to compare.
 * @param p1        a pointer to the second memory address to
 *                  compare.
 * @param sizeBytes the number of bytes to compare.
 * @return          0 if the contents of p1 and p2 for sizeBytes
 *                  are the same.
 */
int32_t cellularPort_memcmp(const void *p1, const void *p2,
                            size_t sizeBytes);

/* ----------------------------------------------------------------
 * FUNCTIONS: STRING
 * -------------------------------------------------------------- */

/** strlen().
 *
 * @param pStr the string to find the length of.
 * @return     the number of bytes in the string.
 */
size_t cellularPort_strlen(const char *pStr);

/** strcpy().
 *
 * @param pDst         the destination string buffer.
 * @param pSrc         the source string.
 * @return             pDst.
 */
char *pCellularPort_strcpy(char *pDst, const char *pSrc);

/** strncpy().
 *
 * @param pDst         the destination string buffer.
 * @param pSrc         the source string.
 * @param sizeBytes    the number of characters to copy,
 *                     not including terminator.
 * @return             pDst.
 */
char *pCellularPort_strncpy(char *pDst, const char *pSrc,
                            size_t sizeBytes);

/** sscanf().
 *
 * @param pStr    the string to scan.
 * @param pFormat the format string.
 * @param ...     a variable list of pointers to arguments
 *                to be filled based on the contents of the
 *                string and the format string.
 * @return        the number of arguments in the variable
 *                argument list successfully populated.
 */
int32_t cellularPort_sscanf(const char *pStr, const char *pFormat,
                            ...);

/** isprint().
 *
 * @param c the character to check, treated as a char.
 * @return  non-zero if c is printable, else 0.
 */
int32_t cellularPort_isprint(int32_t c);

/** iscntrl().
 *
 * @param c the character to check, treated as a char.
 * @return  non-zero if c is a control character, else 0.
 */
int32_t cellularPort_iscntrl(int32_t c);

/* ----------------------------------------------------------------
 * FUNCTIONS: CONVERSION
 * -------------------------------------------------------------- */

/** atoi().
 *
 * @param pStr the string to convert to an integer.
 * @return     the integer.
 */
int32_t cellularPort_atoi(const char *pStr);

/** strtol().
 *
 * @param pStr  the string to convert to an int32_t.
 * @param ppEnd pointer to a char * that will be populated
 *              with the first character after the converted
 *              string.  May be NULL.
 * @param base  the number base to use for the conversion.
 * @return      the int32_t.
 */
int32_t cellularPort_strtol(const char *pStr, char **ppEnd,
                            int32_t base);

/** strtof().
 *
 * @param pStr  the string to convert to a float.
 * @param ppEnd pointer to a char * that will be populated
 *              with the first character after the converted
 *              string.  May be NULL.
 * @return      the float.
 */
float cellularPort_strtof(const char *pStr, char **ppEnd);

/* ----------------------------------------------------------------
 * FUNCTIONS: TIME
 * -------------------------------------------------------------- */

/** mktime().
 *
 * @param *pTime  point to a cellularPortTm structure.
 * @return        the time in seconds since 1970 according
 *                to the parameter passed in.
 */
int32_t cellularPort_mktime(CellularPort_tm *pTime);

/* ----------------------------------------------------------------
 * FUNCTIONS: MATHS
 * -------------------------------------------------------------- */

/** log10().
 *
 * @param log the number for which the log, base 10, is to be found.
 * @return    log10(x).
 */
double cellularPort_log10(double x);

/** pow().
 *
 * @param base the number to which exponent will be the power.
 * @return     base to the power exponent.
 */
double cellularPort_pow(double base, double exponent);

/* ----------------------------------------------------------------
 * FUNCTIONS: SYSTEM
 * -------------------------------------------------------------- */

/** assert().
 *
 * @param condition a condition which should evaluate to true, else
 *                  the system assert function will be called.
 */
void cellularPort_assert(bool condition);

/** errno get.
 *
 * @return errno.
 */
int32_t cellularPort_errno_get();

/** errno set.
 *
 * @param _errno.
 */
void cellularPort_errno_set(int32_t _errno);

#endif // _CELLLAR_PORT_CLIB_H_

// End of file
