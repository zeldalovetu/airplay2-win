## 2026-09-18 - IPC Time Overhead
**Learning:** High-frequency IPC messages were wasting CPU cycles splitting raw epoch time into seconds and microseconds just to immediately recombine them, and modern Windows should use GetSystemTimeAsFileTime instead of slower calendar structs.
**Action:** Return raw time units directly and use optimal API per platform.
