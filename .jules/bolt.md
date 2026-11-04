## 2024-05-14 - Time Optimization
**Learning:** In performance-critical paths (e.g., IPC messaging), avoid redundant arithmetic operations like splitting raw epoch time into seconds and microseconds (via division and modulo) only to immediately recombine them; return the raw time unit directly to eliminate unnecessary CPU cycles.
**Action:** Apply this optimization to `xdw_get_sys_time_ms` in `xdw_socket_ipc.c` and document the impact on IPC overhead.
