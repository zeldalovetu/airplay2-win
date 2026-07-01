## 2024-05-24 - [O(n^2) String Whitespace Removal]
**Learning:** Found a classic performance anti-pattern in `base64_decode` where removing spaces used `memmove` inside a loop, causing an O(n^2) time complexity. This was especially problematic for base64 encoded strings which can be quite long.
**Action:** Always replace in-place shifting loops (using `memmove` or manual shifts) with an O(n) two-pointer approach when filtering characters from a string.
