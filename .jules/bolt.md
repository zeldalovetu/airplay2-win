## 2024-05-24 - IPC messaging time optimization
**Learning:** In the airplay2-win codebase, `xdw_get_sys_time_ms` splits raw time into seconds and microseconds only to recombine them, causing redundant division/modulo arithmetic on a hot path. Also, `GetSystemTime` and `SystemTimeToFileTime` have extra calendar math overhead compared to `GetSystemTimeAsFileTime`.
**Action:** Use `GetSystemTimeAsFileTime` directly when not on Windows CE, and return the raw microsecond time directly rather than dividing and re-multiplying.
