## 2024-07-09 - [O(n^2) memmove in base64 string manipulation]
**Learning:** Found a common anti-pattern where a loop calls `memmove` to skip over unwanted characters (spaces) in a string. This effectively leads to O(n^2) runtime since the remainder of the string is moved for every space character found. This is particularly problematic for base64 decoding since base64 strings frequently have line breaks and padding.
**Action:** Always replace loop-based `memmove` character stripping with a two-pointer O(n) approach.
