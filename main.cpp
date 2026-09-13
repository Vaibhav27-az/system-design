#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

#include "movie.cpp"
#include "seat.cpp"
#include "screen.cpp"
#include "showseat.cpp"
#include "show.cpp"
#include "customer.cpp"
#include "paymenttypes.cpp"
#include "payment.cpp"
#include "pricecalculator.cpp"
#include "booking.cpp"
#include "bookingservice.cpp"
#include "ticketprinter.cpp"
#include "cinema.cpp"

void showMenu() 
{
    cout << "\n===== MOVIE TICKET BOOKING =====\n";
    cout << "1. View Movies\n";
    cout << "2. View Shows\n";
    cout << "3. View Seats\n";
    cout << "4. Book Ticket\n";
    cout << "5. View Bookings\n";
    cout << "6. Cancel Booking\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
}

void showAdminMenu()
{
    cout << "\n===== ADMIN PANEL =====\n";
    cout << "1. View Movies\n";
    cout << "2. View Shows\n";
    cout << "3. Add Movie\n";
    cout << "4. Add Show\n";
    cout << "5. Back to Login\n";
    cout << "Enter choice: ";
}

movie* chooseMovie(cinema& cinemaRef) 
{
    cinemaRef.showMovies();

    int choice;
    cout << "Choose movie: ";
    cin >> choice;

    if(choice < 1 || choice > cinemaRef.getMovies().size()) 
    {
        cout << "Invalid movie choice.\n";
        return NULL;
    }

    return &cinemaRef.getMovies()[choice - 1];
}

show* chooseShow(cinema& cinemaRef, movie* movieRef) 
{
    cinemaRef.showShows(movieRef);
    int id;
    cout << "Enter Show ID: ";
    cin >> id;
    show* selectedShow = cinemaRef.findShow(id);
    if(selectedShow == NULL || selectedShow->getMovie() != movieRef) 
    {
        cout << "Invalid show.\n";
        return NULL;
    }
    return selectedShow;
}

vector<showSeat*> chooseSeats(show* showRef) 
{
    showRef->displaySeats();
    int count;
    cout << "How many seats: ";
    cin >> count;
    vector<showSeat*> seats;
    if (count < 1 || count > 30) 
    {
        cout << "Invalid number of seats.\n";
        return seats;
    }
    for(int i = 0; i < count; i++) 
    {
        int number;
        cout << "Enter seat number: ";
        cin >> number;
        showSeat* selectedSeat = showRef->getShowSeat(number);
        if(selectedSeat == NULL || !selectedSeat->isAvailable()) 
        {
            cout << "Seat unavailable.\n";
            seats.clear();
            return seats;
        }
        bool duplicate = false;
        for(int j = 0; j < seats.size(); j++) 
        {
            if(seats[j] == selectedSeat) 
            {
                duplicate = true;
                break;
            }
        }

        if(duplicate) 
        {
            cout << "Seat selected twice.\n";
            seats.clear();
            return seats;
        }

        seats.push_back(selectedSeat);
    }

    return seats;
}

payment* choosePayment() 
{
    int choice;
    cout << "\n1. UPI\n";
    cout << "2. Card\n";
    cout << "3. Cash\n";
    cout << "Choose payment: ";
    cin >> choice;
    if (choice == 1) 
    {
        return new upiPayment();
    }
    if (choice == 2) 
    {
        return new cardPayment();
    }
    if (choice == 3) 
    {
        return new cashPayment();
    }

    cout << "Invalid payment choice.\n";
    return NULL;
}

void addMovieToCinema(cinema& cinemaRef)
{
    string title, language;
    int duration;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter movie title: ";
    getline(cin, title);
    cout << "Enter movie language: ";
    getline(cin, language);
    cout << "Enter movie duration (minutes): ";
    cin >> duration;

    cinemaRef.addMovie(movie(title, language, duration));
    cout << "Movie added successfully.\n";
}

void addShowToCinema(cinema& cinemaRef)
{
    if (cinemaRef.getMovies().empty())
    {
        cout << "No movies available to create a show.\n";
        return;
    }

    if (cinemaRef.getScreens().empty())
    {
        cout << "No screens available to create a show.\n";
        return;
    }

    movie* selectedMovie = chooseMovie(cinemaRef);
    if (selectedMovie == NULL)
    {
        return;
    }

    cout << "\nAvailable Screens\n";
    for (int i = 0; i < cinemaRef.getScreens().size(); i++)
    {
        cout << i + 1 << ". Screen " << cinemaRef.getScreens()[i].getScreenNumber() << "\n";
    }

    int screenChoice;
    cout << "Choose screen: ";
    cin >> screenChoice;
    if (screenChoice < 1 || screenChoice > cinemaRef.getScreens().size())
    {
        cout << "Invalid screen choice.\n";
        return;
    }

    string time;
    cout << "Enter show time (example: 07:30 PM): ";
    cin >> time;

    int newShowId = 100;
    for (int i = 0; i < cinemaRef.getShows().size(); i++)
    {
        if (cinemaRef.getShows()[i].getShowId() >= newShowId)
        {
            newShowId = cinemaRef.getShows()[i].getShowId() + 1;
        }
    }

    cinemaRef.addShow(show(newShowId, selectedMovie, &cinemaRef.getScreens()[screenChoice - 1], time));
    cout << "Show added successfully with ID " << newShowId << ".\n";
}

void bookTicket(cinema& cinemaRef, customer& customerRef, vector<booking*>& bookings) 
{
    movie* selectedMovie = chooseMovie(cinemaRef);
    if (selectedMovie == NULL) 
    {
        return;
    }   

    show* selectedShow = chooseShow(cinemaRef, selectedMovie);
    if (selectedShow == NULL)
    {
        return;
    }   

    vector<showSeat*> selectedSeats = chooseSeats(selectedShow);
    if (selectedSeats.empty()) 
    {
        return;
    }   

    payment* selectedPayment = choosePayment();
    if (selectedPayment == NULL) 
    {
        return;
    }   

    bookingService service;
    booking* newBooking = service.book(&customerRef, selectedShow, selectedSeats, selectedPayment);

    if(newBooking != NULL) 
    {
        bookings.push_back(newBooking);
        ticketPrinter printer;
        printer.print(newBooking, selectedPayment);
    }
    delete selectedPayment;
}

void viewShows(cinema& cinemaRef) 
{
    movie* selectedMovie = chooseMovie(cinemaRef);
    if (selectedMovie != NULL)
    {
        cinemaRef.showShows(selectedMovie);
    }
}

void viewSeats(cinema& cinemaRef) 
{
    movie* selectedMovie = chooseMovie(cinemaRef);
    if (selectedMovie == NULL) 
    {
        return;
    }   

    show* selectedShow = chooseShow(cinemaRef, selectedMovie);
    if (selectedShow != NULL)
    {
        selectedShow->displaySeats();
    }   
}

void viewBookings(vector<booking*>& bookings) 
{
    if (bookings.empty()) 
    {
        cout << "No bookings.\n";
        return;
    }

    for (int i = 0; i < bookings.size(); i++)
    {
        bookings[i]->display();
    }   
}

void cancelBooking(vector<booking*>& bookings) {
    int id;
    cout << "Enter Booking ID: ";
    cin >> id;

    for(int i = 0; i < bookings.size(); i++)   
    {
        if (bookings[i]->getBookingId() == id && bookings[i]->isConfirmed()) {
            bookings[i]->cancel();
            cout << "Booking cancelled.\n";
            cout << "Seats are available again.\n";
            return;
        }
    }

    cout << "Booking not found.\n";
}

bool loginCustomer(customer& customerRef)
{
    string username, password;
    string name, phone;

    cout << "\n===== CUSTOMER LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username != "customer" || password != "customer123")
    {
        cout << "Invalid customer credentials.\n";
        return false;
    }

    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter phone: ";
    cin >> phone;

    customerRef = customer(name, phone);
    return true;
}

bool loginAdmin()
{
    string username, password;

    cout << "\n===== ADMIN LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123")
    {
        return true;
    }

    cout << "Invalid admin credentials.\n";
    return false;
}

int main() {
    cinema cinemaObj("My Cinema");

    cinemaObj.addMovie(movie("Inception", "English", 148));
    cinemaObj.addMovie(movie("Avengers", "English", 181));
    cinemaObj.addScreen(screen(1));
    cinemaObj.addScreen(screen(2));

    show show1(101, &cinemaObj.getMovies()[0], &cinemaObj.getScreens()[0], "06:30 PM");
    show show2(102, &cinemaObj.getMovies()[1], &cinemaObj.getScreens()[1], "09:00 PM");

    cinemaObj.addShow(show1);
    cinemaObj.addShow(show2);

    vector<booking*> bookings;
    customer customerObj("", "");
    int choice;
    bool loggedIn = false;

    do {
        cout << "\n===== LOGIN =====\n";
        cout << "1. Customer Login\n";
        cout << "2. Admin Login\n";
        cout << "3. Exit\n";
        cout << "Select login: ";
        cin >> choice;

        if (choice == 1)
        {
            if (loginCustomer(customerObj))
            {
                loggedIn = true;
                int customerChoice;
                do {
                    showMenu();
                    cin >> customerChoice;

                    if (customerChoice == 1)
                    {
                        cinemaObj.showMovies();
                    }
                    else if (customerChoice == 2)
                    {
                        viewShows(cinemaObj);
                    }
                    else if (customerChoice == 3)
                    {
                        viewSeats(cinemaObj);
                    }
                    else if (customerChoice == 4)
                    {
                        bookTicket(cinemaObj, customerObj, bookings);
                    }
                    else if (customerChoice == 5)
                    {
                        viewBookings(bookings);
                    }
                    else if (customerChoice == 6)
                    {
                        cancelBooking(bookings);
                    }
                    else if (customerChoice == 7)
                    {
                        cout << "Customer logged out.\n";
                    }
                    else
                    {
                        cout << "Invalid choice.\n";
                    }
                } while (customerChoice != 7);
                loggedIn = false;
            }
        }
        else if (choice == 2)
        {
            if (loginAdmin())
            {
                int adminChoice;
                do {
                    showAdminMenu();
                    cin >> adminChoice;

                    if (adminChoice == 1)
                    {
                        cinemaObj.showMovies();
                    }
                    else if (adminChoice == 2)
                    {
                        if (cinemaObj.getMovies().empty())
                        {
                            cout << "No shows available.\n";
                        }
                        else
                        {
                            movie* selectedMovie = chooseMovie(cinemaObj);
                            if (selectedMovie != NULL)
                            {
                                cinemaObj.showShows(selectedMovie);
                            }
                        }
                    }
                    else if (adminChoice == 3)
                    {
                        addMovieToCinema(cinemaObj);
                    }
                    else if (adminChoice == 4)
                    {
                        addShowToCinema(cinemaObj);
                    }
                    else if (adminChoice == 5)
                    {
                        cout << "Admin logged out.\n";
                    }
                    else
                    {
                        cout << "Invalid admin choice.\n";
                    }
                } while (adminChoice != 5);
            }
        }
        else if (choice == 3)
        {
            cout << "Thank you!\n";
        }
        else
        {
            cout << "Invalid login option.\n";
        }
    } while (choice != 3);

    for (int i = 0; i < bookings.size(); i++)
    {
        delete bookings[i];
    }
    return 0;
}