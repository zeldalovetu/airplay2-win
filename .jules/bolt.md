## 2024-05-24 - Initial Run\n**Learning:** Started tracking performance learnings.\n**Action:** Keep updating this file with critical learnings.

## 2024-05-24 - Avoid calendar math in high frequency time calls
**Learning:** In Windows C/C++, `xdw_get_sys_time_ms` was splitting epoch time into `tv_sec` and `tv_usec` just to immediately recombine them into microseconds (`tv_sec * 1000000 + tv_usec`). This was causing redundant division and modulo operations. Also, it used a two-step `GetSystemTime` + `SystemTimeToFileTime` which is unnecessary on non-CE platforms and incurs calendar math overhead. The function actually returns microseconds, despite its `_ms` suffix.
**Action:** Replace two-step calendar time fetches with `GetSystemTimeAsFileTime` directly (with a Windows CE fallback), and avoid splitting/recombining the timestamp, directly returning the microsecond result.
