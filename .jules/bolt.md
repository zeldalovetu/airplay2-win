## 2024-05-18 - IPC timestamping arithmetic
**Learning:** Found a hot path in IPC messaging calculating time in microseconds, converting it to a struct timeval (sec + usec) via expensive division/modulo, and immediately recombining it by multiplying the seconds back. Also, fetching system time via calendar-based `GetSystemTime` instead of `GetSystemTimeAsFileTime` adds unnecessary overhead.
**Action:** Always return the pre-calculated raw unit directly if the intermediate split isn't needed, and prefer `GetSystemTimeAsFileTime` directly with `#ifndef _WIN32_WCE` for compatibility.
