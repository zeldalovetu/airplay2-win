
## 2024-05-18 - Optimize GetSystemTimeAsFileTime overhead
**Learning:** `GetSystemTime` followed by `SystemTimeToFileTime` introduces unnecessary calendar math (breaking time into year, month, etc., and recombining it). For high-frequency calls like `xdw_get_sys_time_ms` in IPC messaging, `GetSystemTimeAsFileTime` directly retrieves raw system time with zero calendar math overhead.
**Action:** Replace two-step calendar time API usage with direct `GetSystemTimeAsFileTime` where possible, keeping the old behavior as a fallback for platforms (like Windows CE) that lack the direct API.
