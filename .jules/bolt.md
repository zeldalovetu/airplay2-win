## 2024-05-24 - [O(n²) String Manipulation with memmove]
**Learning:** Found an instance in `base64_decode` where removing whitespace from a string was done using `memmove` inside a loop, resulting in $O(n^2)$ complexity. This caused significant performance degradation for long strings.
**Action:** When searching for performance optimizations, look for `memmove` inside loops, especially for simple string character filtering which can often be solved with an $O(n)$ two-pointer approach.
