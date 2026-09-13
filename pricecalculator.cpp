class priceCalculator 
{
    public:
    double calculate(vector<showSeat*>& seats) 
    {
        double total = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            total += seats[i]->getSeat()->getPrice();
        }
        return total;
    }
};