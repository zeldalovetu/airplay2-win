## 2024-05-13 - Initializing bolt.md
## 2024-05-13 - Avoid redundant calendar math on high-frequency IPC paths
**Learning:** `xdw_get_sys_time_ms` was doing redundant calendar math via `GetSystemTime` and `SystemTimeToFileTime` on a hot path, and converting epoch to sec/usec only to immediately merge them back.
**Action:** Use `GetSystemTimeAsFileTime` directly, bypassing calendar struct math. Add `_WIN32_WCE` conditional fallback since CE doesn't define it. Eliminate unnecessary `sec`/`usec` separation.
