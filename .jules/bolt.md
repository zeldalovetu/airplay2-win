
## 2024-05-18 - [Memory Corruption Disguised as Performance Issue]
**Learning:** In C projects that manage dynamic arrays manually (e.g. `http_response_add_data`), failing to track actual length against capacity and failing to save the new capacity (`data_size`) post-reallocation can lead to catastrophic O(N^2) reallocation overhead *and* buffer overflows on subsequent calls. A performance investigation revealed a critical memory safety bug.
**Action:** When investigating O(N^2) copying behavior in C/C++, double-check the capacity tracking logic, ensuring that reallocation condition compares against the *used length* rather than total capacity, and verify the capacity variable itself is updated.
