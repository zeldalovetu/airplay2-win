## 2024-09-11 - [Optimize timestamp calculations in Windows IPC messaging]
**Learning:** Found redundant math operations where raw 100ns epochs from Windows SystemTime were split into seconds and microseconds by division/modulo just to be immediately recombined back into microseconds for messaging timestamps.
**Action:** When parsing FILETIME to microseconds, directly divide the 100ns units by 10 and return, bypassing the intermediate timeval structure construction. This eliminates unnecessary CPU division/modulo instructions on high-frequency paths like IPC messaging.
