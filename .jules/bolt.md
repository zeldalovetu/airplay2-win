## 2024-09-03 - Optimize xdw_get_sys_time_ms
**Learning:** In high-frequency IPC messaging on Windows, `xdw_get_sys_time_ms` was doing redundant math: calling `GetSystemTime` and `SystemTimeToFileTime` (slower than `GetSystemTimeAsFileTime`), calculating seconds and microseconds to put them in a `timeval` struct, and then immediately extracting and multiplying them back to a single 64-bit microsecond timestamp.
**Action:** Use `GetSystemTimeAsFileTime` natively on non-WinCE builds and directly return the microsecond value (`t`) without the intermediate `timeval` conversion steps.
