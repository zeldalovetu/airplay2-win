## 2024-05-24 - Unnecessary Calendar Math in High-Frequency Time Retrieval
**Learning:** `xdw_get_sys_time_ms` unnecessarily splits raw time units into seconds and microseconds just to immediately combine them again, and uses slower `GetSystemTime` instead of `GetSystemTimeAsFileTime`. This occurs in IPC message paths.
**Action:** Optimize time retrieval by returning raw microseconds directly and using `GetSystemTimeAsFileTime` when available, bypassing struct timeval overhead.
