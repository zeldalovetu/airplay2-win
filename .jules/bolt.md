## 2024-05-19 - [Windows IPC Fast Path]
**Learning:** Legacy codebase structures like `xdw_get_sys_time_ms` often contain heavy two-step calendar math (`GetSystemTime` -> `SystemTimeToFileTime`) originally meant purely as a fallback for platforms like Windows CE that lacked `GetSystemTimeAsFileTime`. In high-frequency pathways like IPC queues, this calendar generation forces significant unnecessary overhead.
**Action:** When retrieving raw time ticks in Windows C/C++, directly call `GetSystemTimeAsFileTime`. Gate legacy fallbacks behind exact macros (e.g., `#if defined(_WIN32_WCE)`).
