#ifndef DUMMY_WINDOWS_H
#define DUMMY_WINDOWS_H

#include <stdint.h>

typedef struct _FILETIME {
    uint32_t dwLowDateTime;
    uint32_t dwHighDateTime;
} FILETIME;

typedef struct _SYSTEMTIME {
    uint16_t wYear;
    uint16_t wMonth;
    uint16_t wDayOfWeek;
    uint16_t wDay;
    uint16_t wHour;
    uint16_t wMinute;
    uint16_t wSecond;
    uint16_t wMilliseconds;
} SYSTEMTIME;

void GetSystemTime(SYSTEMTIME *st);
void SystemTimeToFileTime(const SYSTEMTIME *st, FILETIME *ft);
void GetSystemTimeAsFileTime(FILETIME *ft);

#endif // DUMMY_WINDOWS_H
