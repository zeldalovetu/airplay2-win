
## 2024-05-13 - [Optimize IPC timestamp logic]
**Learning:** Found that `xdw_get_sys_time_ms` was doing redundant math: 1) dividing and taking modulo to populate `tv_sec` and `tv_usec`, and 2) then immediately multiplying and adding them back to return an `int64_t`. It also used the slower `GetSystemTime` instead of `GetSystemTimeAsFileTime` directly.
**Action:** Always check the return type and ensure we aren't splitting unified timestamps into structs just to re-combine them again, and use the most direct Windows API for retrieving epoch time when calendar parts aren't needed.
