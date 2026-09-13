class seat;

class showSeat 
{
    private:
    seat* seatData;
    bool booked;

    public:
    showSeat(seat* seatObj) 
    {
        this->seatData = seatObj;
        booked = false;
    }

    bool isAvailable() 
    {
        return !booked;
    }

    void bookSeat()
    {
        booked = true;
    }

    void cancelSeat() 
    {
        booked = false;
    }

    seat* getSeat() 
    {
        return seatData;
    }
};