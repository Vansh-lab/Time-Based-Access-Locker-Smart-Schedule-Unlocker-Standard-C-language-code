# Time-Based-Access-Locker-Smart-Schedule-Unlocker-Standard-C-language-code
🔐 A unique C language project that simulates secure file access based on real-time clock. This CLI program only allows reading or writing to a file between defined hours (e.g., 9 AM to 5 PM). Perfect for demonstrating system time control, file handling, and logical access management in C.

 Features

- ⏱️ Time window access control (e.g., 09:00 to 17:00)
- 🔐 Prevents unauthorized access outside allowed hours
- 📁 File I/O: securely write and read sensitive notes
- 📋 Menu-driven interface
- 🧠 Shows real-world logic + system time handling in C

 How It Works

1. Define `START_HOUR` and `END_HOUR` in the code.
2. Only allows reading/writing to `secure.txt` during this time window.
3. Uses `time.h` to fetch current system hour.

 Example

If system time is 10:32 AM and access window is 09:00–17:00, access is granted.

If time is 20:00, access is denied:
 Access Denied: Outside allowed hours (09:00–17:00
🔧 How to Compile & Run
bash
gcc main.c -o locker
./locker
 Output File
- `secure.txt`: stores locked notes/data only accessible during allowed time range
🧾 License

Licensed under the [MIT License](LICENSE).
