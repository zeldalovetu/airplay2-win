## 2023-10-09 - Optimize xdw_get_sys_time_ms
**Learning:** In performance-critical paths (e.g., IPC messaging), computing system time using GetSystemTime + SystemTimeToFileTime adds unnecessary calendar math overhead. Additionally, splitting raw epoch time into seconds and microseconds (via division and modulo) only to immediately recombine them adds redundant CPU cycles. GetSystemTimeAsFileTime avoids the calendar math, and returning raw time avoids redundant arithmetic.
**Action:** Use GetSystemTimeAsFileTime directly on Windows (fallback on WinCE) and avoid redundant time unit conversions.
