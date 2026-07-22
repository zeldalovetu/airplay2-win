## 2024-05-24 - [Avoid Windows CE SystemTime Fallbacks]
**Learning:** Using `GetSystemTime` followed by `SystemTimeToFileTime` incurs unnecessary calendar math overhead. It was intended for Windows CE, but on desktop Windows, it is slower than calling `GetSystemTimeAsFileTime` directly. This overhead becomes significant when called frequently in hot paths like IPC messaging.
**Action:** Use `GetSystemTimeAsFileTime` directly for high-frequency timestamp acquisition instead of the two-step CE fallback approach.
