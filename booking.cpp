class customer;
class show;
class showSeat;

class booking 
{
    private:
    static int nextBookingId;
    int bookingId;
    customer* customerPtr;
    show* showPtr;
    vector<showSeat*> seats;
    double amount;
    bool confirmed;

    public:
    booking(customer* customerObj, show* showObj, vector<showSeat*>& seatsObj, double amount) 
    {
        this->customerPtr=customerObj;
        this->showPtr=showObj;
        this->seats=seatsObj;
        this->amount=amount;
        this->confirmed=false;
        this->bookingId=nextBookingId++;
    }

    int getBookingId() 
    {
        return bookingId;
    }

    bool isConfirmed() 
    {
        return confirmed;
    }

    void confirm() 
    {
        confirmed = true;
    }

    void cancel() 
    {
        for(int i=0;i<seats.size();i++)
        {
            seats[i]->cancelSeat();
        }
        confirmed=false;
    }

    void display() 
    {
        cout<<"\n==============================\n";
        cout<<"Booking ID: "<<bookingId<<"\n";
        cout<<"Customer: "<<customerPtr->getName()<<"\n";
        cout<<"Movie: "<<showPtr->getMovie()->getTitle()<<"\n";
        cout<<"Screen: "<<showPtr->getScreen()->getScreenNumber()<<"\n";
        cout<<"Time: "<<showPtr->getTime()<<"\n";
        cout<<"Seats: ";

        for(int i=0;i<seats.size();i++)
        {
            cout<<seats[i]->getSeat()->getNumber()<<" ";
        }

        cout<<"\nTotal: Rs."<<amount<<"\n";

        if(confirmed)
        {
            cout << "Status: CONFIRMED\n";
        }
        else
        {
            cout << "Status: CANCELLED\n";
        }
        cout << "==============================\n";
    }
};

int booking::nextBookingId = 1001;