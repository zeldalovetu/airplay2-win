## 2024-05-15 - [Avoid redundant calendar math in IPC hotpaths]
**Learning:** In performance-critical paths (e.g., IPC messaging), `xdw_get_sys_time_ms` split raw epoch time into seconds and microseconds only to immediately recombine them into microseconds, wasting CPU cycles. Additionally, standard Windows allows `GetSystemTimeAsFileTime` directly, bypassing the two-step `GetSystemTime` and `SystemTimeToFileTime` overhead.
**Action:** Return the raw time unit directly to eliminate unnecessary CPU cycles, and prefer `GetSystemTimeAsFileTime` when not on Windows CE.
