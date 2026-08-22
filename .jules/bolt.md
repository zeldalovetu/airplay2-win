# Bolt's Journal

## 2024-05-15 - [GetSystemTime optimization on Windows]
**Learning:** In Windows C/C++ development, prefer calling `GetSystemTimeAsFileTime` directly over the two-step `GetSystemTime` + `SystemTimeToFileTime` to avoid unnecessary calendar math overhead, especially on high-frequency hot paths like IPC messaging. Legacy Windows CE requires the older two-step method, so use `#if defined(_WIN32_WCE)` for compatibility.
**Action:** Always check for `GetSystemTime` followed by `SystemTimeToFileTime` and optimize to `GetSystemTimeAsFileTime` directly where applicable.
