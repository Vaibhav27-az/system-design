// Inheritance:
// These classes inherit from payment.
//
// Runtime Polymorphism:
// payment* can point to any of these classes.

class upiPayment : public payment 
{
    public:
    bool pay(double amount) 
    {
        int choice;
        cout << "\nUPI Payment";
        cout << "\nAmount: Rs." << amount;
        cout << "\n1. Success";
        cout << "\n0. Failure";
        cout << "\nEnter choice: ";

        cin >> choice;
        return choice == 1;
    }

    string getType() 
    {
        return "UPI";
    }
};


class cardPayment : public payment 
{
    public:
    bool pay(double amount) 
    {
        int choice;
        cout << "\nCard Payment";
        cout << "\nAmount: Rs." << amount;
        cout << "\n1. Success";
        cout << "\n0. Failure";
        cout << "\nEnter choice: ";

        cin >> choice;
        return choice == 1;
    }

    string getType() 
    {
        return "Card";
    }
};


class cashPayment : public payment 
{
    public:
    bool pay(double amount) 
    {

        cout << "\nCash Payment";
        cout << "\nAmount: Rs." << amount;
        cout << "\nCash received.\n";
        return true;
    }

    string getType() 
    {
        return "Cash";
    }
};