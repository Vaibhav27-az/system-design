class cinema 
{
    private:
    string name;
    vector<movie> movies;
    vector<screen> screens;
    vector<show> shows;

    public:
    cinema(string name) 
    {
        this->name = name;
    }

    void addMovie(movie movieObj) 
    {
        movies.push_back(movieObj);
    }

    void addScreen(screen screenObj) 
    {
        screens.push_back(screenObj);
    }

    void addShow(show showObj) 
    {
        shows.push_back(showObj);
    }

    vector<movie>& getMovies() 
    {
        return movies;
    }

    vector<show>& getShows()
    {
        return shows;
    }

    vector<screen>& getScreens() 
    {
        return screens;
    }

    void showMovies() 
    {
        cout << "\nMovies Playing\n";
        for(int i=0;i<movies.size();i++) 
        {
            cout << i + 1 << ". " << movies[i].getTitle() << "\n";
            cout << "   Language: " << movies[i].getLanguage() << "\n";
            cout << "   Duration: " << movies[i].getDuration() << " minutes\n";

            bool hasShow = false;
            cout << "   Show IDs: ";
            for (int j = 0; j < shows.size(); j++)
            {
                if (shows[j].getMovie() == &movies[i])
                {
                    if (hasShow) cout << ", ";
                    cout << shows[j].getShowId();
                    hasShow = true;
                }
            }

            if (!hasShow)
            {
                cout << "No show available";
            }
            cout << "\n\n";
        }
    }

    void showShows(movie* moviePtr) 
    {
        cout << "\nAvailable Shows\n";
        bool found = false;
        for (int i = 0; i < shows.size(); i++) 
        {
            if (shows[i].getMovie() == moviePtr)
            {
                found = true;
                shows[i].displayShow();
            }
        }
        if (!found)
        {
            cout << "No shows available for this movie.\n";
        }
    }

    show* findShow(int id) 
    {
        for(int i=0;i<shows.size();i++) 
        {
            if (shows[i].getShowId() == id)
                return &shows[i];
        }
        return NULL;
    }
};