class customer;
class show;
class payment;
class showSeat;
class booking;

class bookingService 
{
    private:
    priceCalculator calculator;

    public:
    booking* book(customer* customerObj, show* showObj, vector<showSeat*>& seatsObj, payment* paymentObj) 
    {
        for(int i=0;i<seatsObj.size();i++) 
        {
            if(!seatsObj[i]->isAvailable()) 
            {
                cout<<"Seat already booked.\n";
                return NULL;
            }
        }

        double total = calculator.calculate(seatsObj);

        for(int i = 0; i < seatsObj.size(); i++)
        {
            seatsObj[i]->bookSeat();
        }
        booking* newBooking = new booking(customerObj, showObj, seatsObj, total);
        bool isPaid = paymentObj->pay(total);
        if(isPaid) 
        {
            newBooking->confirm();
            return newBooking;
        }

        newBooking->cancel();
        delete newBooking;

        cout << "Payment failed.\n";
        cout << "Booking not confirmed.\n";
        cout << "Seats are available again.\n";

        return NULL;
    }
};