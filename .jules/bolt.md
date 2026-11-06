## 2024-05-14 - Performance Opportunities
**Learning:** Found an unnecessary calendar math overhead and redundant arithmetic calculation in `xdw_get_sys_time_ms` when retrieving system time for IPC messaging. This function divides and modulates time only to immediately combine it. Also, `GetSystemTimeAsFileTime` is much faster than `GetSystemTime` followed by `SystemTimeToFileTime`.
**Action:** Simplify time calculation and use `GetSystemTimeAsFileTime` (falling back to `GetSystemTime` for Windows CE) to avoid unnecessary operations.
