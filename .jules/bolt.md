## 2024-10-27 - Optimize xdw_get_sys_time_ms
**Learning:** In performance-critical paths (e.g., IPC messaging), redundant arithmetic operations like splitting raw epoch time into seconds and microseconds just to immediately recombine them wastes CPU cycles. Also, `GetSystemTimeAsFileTime` is much faster than `GetSystemTime` followed by `SystemTimeToFileTime` due to calendar math overhead.
**Action:** Use `GetSystemTimeAsFileTime` directly where supported (fallback to two-step for Windows CE), and return the raw time unit directly without splitting and recombining.
