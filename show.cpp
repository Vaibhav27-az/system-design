class movie;
class screen;
class showSeat;

class show 
{
    private:
    int showId;
    movie* moviePtr;
    screen* screenPtr;
    string time;
    vector<showSeat> showSeats;

    public:
    show(int showId, movie* movieObj, screen* screenObj, string time) 
    {
        this->showId = showId;
        this->moviePtr = movieObj;
        this->screenPtr = screenObj;
        this->time = time;

        for(int i = 0; i < 30; i++) 
        {
            showSeats.push_back(showSeat(&screenPtr->getSeats()[i]));
        }
    }

    int getShowId() 
    {
        return showId;
    }

    movie* getMovie() 
    {
        return moviePtr;
    }

    screen* getScreen() 
    {
        return screenPtr;
    }

    string getTime() 
    {
        return time;
    }

    showSeat* getShowSeat(int number) 
    {
        if(number < 1 || number > 30) 
        {
            return NULL;
        }   
        return &showSeats[number - 1];
    }

    void displayShow() 
    {
        cout << "\nShow Details\n";
        cout << "Show ID: " << showId << "\n";
        cout << "Movie: " << moviePtr->getTitle() << "\n";
        cout << "Language: " << moviePtr->getLanguage() << "\n";
        cout << "Screen: " << screenPtr->getScreenNumber() << "\n";
        cout << "Time: " << time << "\n";
    }

    void displaySeats() 
    {
        cout << "\n========================================\n";
        cout << "               SEAT LAYOUT             \n";
        cout << "========================================\n\n";

        cout << "Silver: Seats 1-10  |  Gold: Seats 11-20  |  Platinum: Seats 21-30\n\n";

        for (int row = 0; row < 6; row++) 
        {
            for (int col = 0; col < 5; col++) 
            {
                int index = row * 5 + col;
                int seatNumber = showSeats[index].getSeat()->getNumber();
                string seatLabel = showSeats[index].isAvailable() ? "[" + to_string(seatNumber) + "]" : "[X]";

                cout << left << setw(6) << seatLabel;
            }
            cout << "\n";
        }

        cout << "\nLegend:\n";
        cout << "[N] = Available seat\n";
        cout << "[X] = Booked seat\n\n";
        cout << "Price Zones:\n";
        cout << "Silver     : Seats 1-10  | Rs.150\n";
        cout << "Gold       : Seats 11-20 | Rs.250\n";
        cout << "Platinum   : Seats 21-30 | Rs.400\n";
        cout << "========================================\n";
    }
};