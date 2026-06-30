## 2024-06-30 - [O(N^2) memmove bottleneck in string stripping]
**Learning:** Found a surprisingly common anti-pattern where an O(N) operation like stripping whitespace from a string becomes O(N^2) because `memmove` is called in a loop for every matched character, moving the entire rest of the string each time.
**Action:** Always scan for `memmove` or manual array shifting inside loops that process strings or arrays. Replace them with O(N) two-pointer (read/write) compaction strategies.
