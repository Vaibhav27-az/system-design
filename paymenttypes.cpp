class payment;

// Abstraction:
// payment gives a common interface for all payment methods.

class payment 
{
    public:
    virtual bool pay(double amount) = 0;
    virtual string getType() = 0;
    virtual ~payment() 
    {
    }
};