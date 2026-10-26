
## 2024-05-14 - Optimize xdw_get_sys_time_ms
**Learning:** `xdw_get_sys_time_ms` in `airplay2-win/VideoSource/utils/xdw_socket_ipc.c` converts `GetSystemTime` (via `SystemTimeToFileTime`) into a 64-bit integer, subtracts epoch, then converts back to `timeval` structure to calculate total microseconds. This means it computes seconds by division, and microseconds by modulo, only to multiply seconds by 1000000 again to add to microseconds, which is functionally equivalent to `(t - EPOCH) / 10`.
**Action:** Optimize `xdw_get_sys_time_ms` by using `GetSystemTimeAsFileTime` directly, and returning the epoch time divided by 10 directly, bypassing `struct timeval` altogether. Maintain legacy `GetSystemTime` code path for Windows CE by wrapping the direct call in `#if defined(_WIN32_WCE)`.
