# Output — Movie Ticket Booking System

This folder contains sample outputs, run transcripts, exported diagrams/screenshots, and other artifacts that demonstrate how the Movie Booking C++ project behaves.

Overview
- Movie Ticket Booking System: a C++ console application demonstrating a simple movie booking workflow and object-oriented design. Customers can browse shows, choose seats, pay, and view bookings; administrators can add movies, screens, and shows.

Key features
- Admin management menu (add movie, screen, show)
- Customer login with 10-digit phone validation
- Domain models: Movie, Screen, Show, Seat, ShowSeat, Booking, Customer, Payment, Ticket
- Seat availability tracked per show
- Three seat categories with base prices: Silver (1–10), Gold (11–20), Platinum (21–30)
- Dynamic pricing adjustments for seat category, long movies, and evening shows
- Payment methods: UPI, Card, Cash
- Printed ticket output and per-customer booking history

Requirements
- Windows (recommended) but code compiles on other platforms with g++
- g++ compiler available on PATH
- Command prompt / PowerShell (or a POSIX shell on other platforms)

Build & run
The repository includes a simple Windows build script `build.bat` that compiles all `.cpp` files into `MovieBooking.exe` and runs the demo.

Manual compile (Windows / MinGW):

```bat
g++ *.cpp -o MovieBooking.exe
MovieBooking.exe
```

Manual compile (Linux/macOS):

```bash
g++ -std=c++17 -O2 -Wall -o MovieBooking *.cpp
./MovieBooking
```

Using the application
The program ships with demo data (example shows):

- Show 101 — Inception — Screen 1 — 18:30
- Show 102 — Avengers: Endgame — Screen 2 — 21:00

Admin demo credentials:
- Username: admin
- Password: admin123

Customer flow (summary):
1. Start the program and choose Customer Login.
2. Enter a name and a 10-digit phone number.
3. View available shows and seat layouts.
4. Book an available seat and choose a payment method.
5. On successful payment the seat becomes booked and a ticket is printed.
6. View booking history for the current customer.

Pricing rules (summary)
- Base prices: Silver Rs.100, Gold Rs.200, Platinum Rs.300
- Additional adjustments (cumulative): Gold +Rs.50, Platinum +Rs.100, movie >120 min +Rs.20, shows 18:00–22:00 +Rs.30

Project files (observed in this repository)
- main.cpp — menus, demo data, and program orchestration
- booking*.cpp, bookingservice.cpp, cinema.cpp, movie.cpp, screen.cpp, seat.cpp, show*.cpp — domain logic
- pricecalculator.cpp — pricing rules
- payment*.cpp — payment implementations
- ticketprinter.cpp — output/ticket rendering
- build.bat — Windows build/run helper

What belongs in Output/
- Text transcripts of sample runs (Output/sample_run_YYYYMMDD.txt)
- Output/screenshots/ — screenshots or image exports of program output or diagrams
- Output/logs/ — logs from runs or tests
- Output/diagrams_export/ — exported PNG/SVG diagrams

Best practices for artifacts
- Include a one-line note with each file explaining how it was produced (command, platform, inputs used).
- Name files clearly with date and short description.
- Avoid committing large binaries; use Git LFS or releases instead. If a binary is included (e.g., MovieBooking.exe), add a small README or checksum next to it describing platform and compiler.

Example: capture a sample run (Linux/macOS)

```bash
g++ -std=c++17 -O2 -Wall -o MovieBooking *.cpp
./MovieBooking > Output/sample_run_$(date +%Y%m%d)_customer_upi.txt
```

Windows (cmd / PowerShell)

```bat
g++ -std=c++17 -O2 -Wall -o MovieBooking.exe *.cpp
MovieBooking.exe > Output\sample_run_20260914_customer_upi.txt
```

Notes specific to this repo
- The app is currently in-memory and demo-oriented (data resets when the process exits).
- Authentication is demo-only (hard-coded admin account).
- Source files are organized as `.cpp` modules; splitting into headers (`.h`) and implementation files is recommended for larger projects.

Next steps I can take
- Replace the existing Output/.gitkeep with this README (done on request).
- Add a placeholder sample_run file or a screenshots/ subfolder with README placeholders.
- Create checksums or a small build log if you'd like the binary documented.

If you want me to add any example run files or create subfolders now, tell me which one and I'll create them.