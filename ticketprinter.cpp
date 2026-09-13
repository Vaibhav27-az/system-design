class booking;
class payment;

class ticketPrinter 
{
    public:
    void print(booking* booking,payment* payment) 
    {
        cout << "\n========== TICKET ==========\n";
        booking->display();
        cout << "Payment: "
             << payment->getType()
             << "\n";
        cout << "============================\n";
    }
};