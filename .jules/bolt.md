## 2024-08-01 - Avoid GetSystemTime overhead on Non-Windows CE devices
**Learning:** Found legacy 2-step time resolution logic (`GetSystemTime` followed by `SystemTimeToFileTime`) in high-frequency IPC polling function `xdw_get_sys_time_ms`. This calendar math overhead is completely unnecessary on standard Windows systems where `GetSystemTimeAsFileTime` is natively available.
**Action:** Always verify if fallback workarounds meant for deprecated platforms (like Windows CE) are being unnecessarily applied to all execution paths. Use platform macros (`#if defined(_WIN32_WCE)`) to isolate them.
