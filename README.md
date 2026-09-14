# Movie Ticket Booking System

A compact C++ console program that models a movie-ticket booking flow and demonstrates basic object-oriented design principles. Patrons can browse scheduled shows, reserve seats, complete payments, and review their bookings. An administrator role can add movies, screens, and schedule shows.

## Features
- Admin panel for managing cinema data
- Customer sign-in validated with a 10-digit phone number
- Domain entities: movies, screens, shows, seats, bookings, payments, and ticket output
- Seat availability tracked per show instance
- Three seating categories with base fares:
  - Silver (seats 1–10): Rs. 100
  - Gold (seats 11–20): Rs. 200
  - Platinum (seats 21–30): Rs. 300
- Additional pricing for premium seats, long-duration movies, and evening shows
- Payment options: UPI, card, and cash
- Printed ticket output and per-customer booking history

## Requirements
- Windows is the primary tested environment
- A C++ compiler with `g++` available on `PATH`
- Command prompt, PowerShell, or a POSIX shell

## Build and Run
From the project root you can compile and run the program.

Manual (Windows / MinGW):

```bat
g++ *.cpp -o MovieBooking.exe
MovieBooking.exe
```

Manual (Linux/macOS):

```bash
g++ -std=c++17 -O2 -Wall -o MovieBooking *.cpp
./MovieBooking
```

Note: a compiled binary MovieBooking.exe exists in the repo; if you keep binaries, add platform and checksum metadata.

## Using the Application
The demo initializes two sample shows:

| Show ID | Movie | Screen | Time |
| --- | --- | --- | --- |
| 101 | Inception | 1 | 06:30 PM |
| 102 | Avengers | 2 | 09:00 PM |

### Admin
Demo credentials:
```
Username: admin
Password: admin123
```

Admin capabilities:
- Add movies
- Create screens
- Schedule shows
- List shows
- Log out

### Customer
Customers provide a name and a 10-digit phone number. Customer options include:
- View shows and seating
- Reserve seats and select a payment method
- View personal booking history
- Log out

## Pricing
Ticket cost starts from the seat base and applies cumulative adjustments:

| Rule | Additional amount |
| --- | ---: |
| Gold seat | Rs. 50 |
| Platinum seat | Rs. 100 |
| Movie duration > 120 minutes | Rs. 20 |
| Show time between 18:00 and 22:00 | Rs. 30 |

Example: an evening Platinum seat for a long movie includes all applicable surcharges.

## Project Structure
- main.cpp — program flow, menus, demo data
- movie.cpp — movie metadata
- screen.cpp — screen and seat creation
- seat.cpp — seat definitions and pricing
- show.cpp — show scheduling and per-show seat state
- showseat.cpp — show-specific seat wrapper
- customer.cpp — customer data handling
- booking.cpp — booking records and helpers
- bookingservice.cpp — booking orchestration
- pricecalculator.cpp — pricing logic
- paymenttypes.cpp, payment.cpp — payment abstraction and implementations
- ticketprinter.cpp — ticket output
- cinema.cpp — collections for movies, screens, and shows
- MovieBooking.exe — compiled executable (binary)

## Design Principles
The code demonstrates:
- Single Responsibility
- Open/Closed
- Liskov Substitution
- Interface Segregation
- Dependency Inversion

## A. Requirement Analysis

### Functional Requirements (FR)
- Admin can register cinemas, add screens/seats, and schedule shows.
- Each show creates its own show-specific seat entries.
- Customers can browse shows, check availability, reserve seats, and create bookings.
- Pricing uses seat type, movie duration, and show time.
- Payments via UPI, card, or cash.
- Successful payment marks seats booked and produces tickets.
- Customers can view booking history.

### Non-Functional Requirements (NFR)
- Production must include concurrency controls to avoid double-booking.
- Extensible payment/pricing design without modifying booking flow.
- Data consistency between seat state and bookings.
- Efficient availability lookups.
- Auditability for payments/bookings.

## B. Noun–Verb Analysis Table
(See source files for implemented methods; classes and method names are present in the listed files.)

## C. Relationship Table
(Object relationships mirror domain concepts: cinemas aggregate screens/movies, shows compose show-seats, bookings associate shows and seats, payments implement a common interface, etc.)

## D-E. Diagrams
Sequence and class diagrams live in the Diagram/ folder.

## F. Modular Working Code and Demo Run
The implementation is split across focused C++ source files. `main.cpp` wires menus and demo data while domain files implement booking and pricing behavior.

Build and run example:

```bash
g++ -std=c++17 -O2 -Wall -o MovieBooking *.cpp
./MovieBooking
```

## Current Scope
- In-memory storage (state resets when program exits).
- Demo authentication (hard-coded admin credentials).
- Single-process console prototype — no concurrency or persistence features.
- Source organized as `.cpp` modules; consider refactoring into `.h`/`.cpp` pairs for production.
