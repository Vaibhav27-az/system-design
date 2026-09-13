class customer 
{
    private:
    string name;
    string phone;

    public:
    customer(string name, string phone) 
    {
        this->name = name;
        this->phone = phone;
    }

    string getName() 
    {
        return name;
    }

    string getPhone() 
    {
        return phone;
    }
};