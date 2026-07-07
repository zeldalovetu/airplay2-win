## 2024-07-07 - O(N^2) String Manipulation Anti-pattern
**Learning:** Found a severe string manipulation anti-pattern in `base64_decode` where `memmove` was called inside a `for` loop to remove characters (spaces). This results in `O(N^2)` time complexity because each character removal shifts all subsequent characters. On large base64 strings, this can be extremely slow.
**Action:** Always replace in-place string modification that uses loops and `memmove`/`strcpy` with a two-pointer `O(N)` approach, reading with `i` and writing with `j++`.
