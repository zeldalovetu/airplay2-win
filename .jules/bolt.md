## 2024-05-24 - [Optimize gettimeofday for Windows]
**Learning:** The Windows `gettimeofday` compatibility implementation was making an expensive `GetTimeZoneInformation` system call and zeroing memory unconditionally, even when the `tz` parameter was `NULL`. `GetTimeZoneInformation` is known to be slow as it can interact with the registry.
**Action:** When wrapping slow OS-specific APIs in standard compatibility layers, ensure expensive lookups are lazily executed or guarded by checks for whether the caller actually requested that information.
