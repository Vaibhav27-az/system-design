class movie 
{
    private:
    string title;
    string language;
    int duration;

    public:
    // Compile-time Polymorphism: overloaded constructors
    movie() 
    {
        title="";
        language="";
        duration=0;
    }

    movie(string title, string language, int duration) 
    {
        // this keyword
        this->title=title;
        this->language=language;
        this->duration=duration;
    }

    string getTitle() 
    {
        return title;
    }

    string getLanguage() 
    {
        return language;
    }

    int getDuration() 
    {
        return duration;
    }

    void display() 
    {
        cout << "\nMovie Details\n";
        cout << "Name: " << title << "\n";
        cout << "Language: " << language << "\n";
        cout << "Duration: " << duration << " minutes\n";
    }
};