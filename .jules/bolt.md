
## $(date +%Y-%m-%d) - Optimize xdw_get_sys_time_ms to avoid redundant calculations
**Learning:** `xdw_get_sys_time_ms` was doing redundant calendar math via `GetSystemTime` and `SystemTimeToFileTime`, and then dividing raw microseconds to `struct timeval` seconds and microseconds just to recombine them on the hot path for IPC messaging. Direct raw filetime capture and return is significantly faster and removes year 2038 overflow risk on `long tp.tv_sec`.
**Action:** When working on Windows C/C++ projects, prioritize `GetSystemTimeAsFileTime` directly over the two-step `GetSystemTime` + `SystemTimeToFileTime` unless Windows CE fallback is required, and return raw time units directly to avoid intermediate conversions in hot loops or message IPC logic.
