class screen 
{
    private:
    int screenNumber;
    vector<seat> seats;

    public:
    screen(int screenNumber) 
    {
        this->screenNumber = screenNumber;
        for(int i = 1; i <= 10; i++)
        {
            seats.push_back(seat(i, "SILVER"));
        }

        for(int i = 11; i <= 20; i++)
        {
            seats.push_back(seat(i, "GOLD"));
        }

        for(int i = 21; i <= 30; i++)
        {
            seats.push_back(seat(i, "PLATINUM"));
        }
    }

    int getScreenNumber() 
    {
        return screenNumber;
    }

    vector<seat>& getSeats() 
    {
        return seats;
    }
};