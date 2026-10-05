## 2024-05-18 - Avoid timeval double conversions on hot path
**Learning:** Returning parsed time in struct timeval just to re-combine it adds unnecessary math cycles and can be removed, especially on IPC paths where system time is queried frequently. Further, `GetSystemTimeAsFileTime` directly retrieves the FILETIME skipping calendar generation compared to `GetSystemTime` (except on Windows CE which lacks the direct call).
**Action:** Always prefer retrieving raw time directly where precise formatting is unneeded, and look out for redundant unpacking/packing math on raw integer return values.
