## 2026-09-25 - Optimization of `xdw_get_sys_time_ms`
**Learning:** In performance-critical paths (e.g., IPC messaging), redundant arithmetic operations like splitting raw epoch time into seconds and microseconds (via division and modulo) only to immediately recombine them can cause unnecessary overhead.
**Action:** When calculating microseconds from epoch time, return the raw time unit directly to eliminate unnecessary CPU cycles, instead of separating and recombining.
