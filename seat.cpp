class seat;

const int SILVER_PRICE = 150;
const int GOLD_PRICE = 250;
const int PLATINUM_PRICE = 400;

class seat 
{
    private:
    int number;
    string type;

    public:
    seat(int number, string type) 
    {
        this->number = number;
        this->type = type;
    }

    int getNumber() 
    {
        return number;
    }

    string getType() 
    {
        return type;
    }

    int getPrice() 
    {
        if(type=="SILVER") 
        {
            return SILVER_PRICE;
        }   
        if(type == "GOLD") 
        {
            return GOLD_PRICE;
        }   
        return PLATINUM_PRICE;
    }
};