## 2024-05-18 - Optimize raw epoch time calculation
**Learning:** In high-frequency paths like IPC messaging, splitting raw epoch time into seconds and microseconds via division and modulo just to immediately recombine them burns unnecessary CPU cycles.
**Action:** Return the raw time unit directly without redundant splitting and recombining arithmetic operations. Prefer GetSystemTimeAsFileTime over GetSystemTime + SystemTimeToFileTime to avoid calendar math overhead.
