## 2024-05-24 - Avoid redundant time splitting and calendar math in high-frequency IPC
**Learning:** `xdw_get_sys_time_ms` computes current time in microseconds for every IPC message. It used `GetSystemTime` followed by `SystemTimeToFileTime` which adds calendar math overhead, and then split the microseconds into seconds and microseconds using division and modulo, only to immediately recombine them.
**Action:** Use `GetSystemTimeAsFileTime` directly (with a Windows CE fallback) and return the microseconds directly to avoid redundant math in hot paths.
