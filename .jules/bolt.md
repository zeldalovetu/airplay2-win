## 2024-05-19 - IPC Timing Bottleneck

**Learning:** `xdw_get_sys_time_ms` in `airplay2-win/VideoSource/utils/xdw_socket_ipc.c` performs unnecessary calculation steps. It calls `GetSystemTime` and `SystemTimeToFileTime` which causes an overhead over using `GetSystemTimeAsFileTime` directly. In addition, it takes the final microsecond value, splits it into seconds and microseconds with division and modulo, and then recombines them again. Since this function is called on every IPC message, it wastes CPU cycles on the hot path.

**Action:** Replace the dual-function call with `GetSystemTimeAsFileTime` directly (with a `_WIN32_WCE` fallback), and avoid the redundant modulo math by directly returning the `t` variable (which is already the epoch time in microseconds).
