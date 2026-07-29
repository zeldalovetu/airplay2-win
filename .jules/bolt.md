## 2024-07-29 - [Preserving Platform Fallbacks During Optimizations]
**Learning:** [When optimizing legacy Windows C/C++ code, completely replacing a two-step API call (like `GetSystemTime` + `SystemTimeToFileTime` with `GetSystemTimeAsFileTime`) may break compilation for older, supported targets (like Windows CE) where the newer API is unavailable, as explicitly documented in the original source code.]
**Action:** [Use conditional compilation (`#if defined(_WIN32_WCE)`) to preserve the fallback behavior for legacy platforms while still applying the optimization to modern builds.]
