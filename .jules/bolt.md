## 2026-09-09 - Optimize System Time Retrieval in IPC Message Queue
**Learning:** In Windows C/C++ development, calculating time in milliseconds by calling `GetSystemTime` followed by `SystemTimeToFileTime` involves unnecessary calendar math overhead, especially on high-frequency paths like IPC messaging.
**Action:** Use `GetSystemTimeAsFileTime` directly, avoiding the intermediate `SYSTEMTIME` step. Fallback to `GetSystemTime` only on platforms that don't support it (e.g. Windows CE).
