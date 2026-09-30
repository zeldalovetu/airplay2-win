## 2024-05-24 - Optimize xdw_get_sys_time_ms
**Learning:** In the `airplay2-win` codebase, `xdw_get_sys_time_ms` actually returns microseconds, not milliseconds. Also, calling `GetSystemTime` followed by `SystemTimeToFileTime` incurs unnecessary calendar math overhead on non-CE Windows. Furthermore, splitting time into seconds and microseconds via division and modulo only to immediately recombine them wastes CPU cycles.
**Action:** Use `GetSystemTimeAsFileTime` directly on standard Windows and return the computed microseconds directly without intermediate `timeval` conversion.
