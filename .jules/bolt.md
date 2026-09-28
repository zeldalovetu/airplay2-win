
## 2024-05-24 - Redundant Time Recombination and GetSystemTimeAsFileTime
**Learning:** In `xdw_get_sys_time_ms`, epoch time was being unnecessarily split into seconds and microseconds using division and modulo, only to be immediately recombined using multiplication and addition. Also, `GetSystemTime` followed by `SystemTimeToFileTime` was used unconditionally instead of the much faster `GetSystemTimeAsFileTime` available on modern Windows.
**Action:** Use `GetSystemTimeAsFileTime` directly for a performance boost (retaining CE fallback) and eliminate the redundant division/modulo arithmetic on the hot path (IPC messages) by returning the raw time directly.
