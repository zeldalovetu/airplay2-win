## 2024-10-24 - [Unnecessary Arithmetic in High-Frequency Paths]
**Learning:** Found redundant operations (division and modulo to split epoch time, immediately followed by multiplication and addition to recombine it) in an IPC messaging path.
**Action:** Return the raw unit directly, avoiding unnecessary CPU cycles in hot paths.
