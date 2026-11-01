## 2024-11-01 - Optimize xdw_get_sys_time_ms Windows time functions
**Learning:** Found an IPC path doing redundant division and multiplication (recombining seconds and microseconds back into total microseconds), and unnecessary calendar math via GetSystemTime instead of GetSystemTimeAsFileTime.
**Action:** Always prefer GetSystemTimeAsFileTime directly in Windows environments unless on Windows CE, and eliminate redundant arithmetic in hot paths.
