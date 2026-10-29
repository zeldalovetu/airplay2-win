## 2024-10-29 - Optimize xdw_get_sys_time_ms
**Learning:** In performance-critical paths (e.g., IPC messaging), `xdw_get_sys_time_ms` was redundantly splitting raw epoch time into seconds and microseconds (via division and modulo) only to immediately recombine them, wasting CPU cycles. Additionally, calling `GetSystemTime` + `SystemTimeToFileTime` is slower than calling `GetSystemTimeAsFileTime` directly.
**Action:** Always prefer returning the raw calculated time unit directly and use the more direct system API when possible, preserving Windows CE fallback via `#if defined(_WIN32_WCE)`.
