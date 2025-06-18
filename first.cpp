#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct ticket
{
    int cnic;
    string movie_name;
    string day;
};

struct movieReview
{
    int cnic;
    string movie_name;
    string Review;
    int rating;
};
// This is the main class which shows the total available tickets and show movielist
class movie
{
protected:
    const int total_tickets = 100;
    static int available_tickets;

public:
    void showAvailableTickets()
    {
        cout << total_tickets;
    }
    static int returnAvailableTickets()
    {
        return available_tickets;
    }
    void movieList()
    {
        cout << "1.Pathan" << endl;
        cout << "2.Shiddat" << endl;
        cout << "3.Azadi" << endl;
        cout << "4.Lifetime" << endl;
        cout << "5.Afghani" << endl;
        cout << "6.Sita Ramam" << endl;
        cout << "7.Mission Impossible 7" << endl;
        cout << "8.Kudo" << endl;
        cout << "9.Loyality matters" << endl;
        cout << "10.Power is power" << endl;
    }
};
// This class is totally responsible for file handling
class handlingFiles : public movie

{
public:
    void bookTicket_file(int n)
    {
        ofstream file;
        file.open("tickets.txt", ios::app);
        ticket T;
        cout << "Enter your cnic" << endl;
        cin >> T.cnic;
        T.day = "Friday";
        if (n = 1)
        {
            T.movie_name = "Pathan";
        }
        else if (n = 2)
        {
            T.movie_name = "Shiddatt";
        }
        else if (n = 3)
        {
            T.movie_name = "Azadi";
        }
        else if (n = 4)
        {
            T.movie_name = "LifeTime";
        }
        else if (n = 5)
        {
            T.movie_name = "Afghani";
        }
        else if (n = 6)
        {
            T.movie_name = "Sita Ramam";
        }
        else if (n = 7)
        {
            T.movie_name = "Mission Impossible 7";
        }
        else if (n = 8)
        {
            T.movie_name = "Kudo";
        }
        else if (n = 9)
        {
            T.movie_name = "Loyality matters";
        }
        else if (n = 10)
        {
            T.movie_name = "Power is power";
        }
        file << T.cnic << "\t" << T.movie_name << "\t" << T.day << endl;
        file.close();
        cout << "Ticket Booked" << endl;
    };

    void reviewFilm(int CNIC)
    {

        ifstream ifs;
        ofstream ofs;
        ticket T;
        movieReview R;
        ifs.open("tickets.txt");
        ofs.open("reviews.txt");

        ifs >> T.cnic;
        ifs >> T.movie_name;
        ifs >> T.day;
        if (!ifs.eof())
        {
            if (CNIC == T.cnic)
            {
                cout << "CNIC FOUND" << endl;
                int n;
                cout << "Enter your review" << endl;
                cout << "Select the movie" << endl;
                movieList();
                cin >> n;
                if (n = 1)
                {
                    R.movie_name = "Pathan";
                }
                if (n = 2)
                {
                    R.movie_name = "Shiddat";
                }
                if (n = 3)
                {
                    R.movie_name = "Azadi";
                }
                if (n = 4)
                {
                    R.movie_name = "LifeTime";
                }
                if (n = 5)
                {
                    R.movie_name = "Afghani";
                }
                else if (n = 6)
                {
                    R.movie_name = "Sita Ramam";
                }
                else if (n = 7)
                {
                    R.movie_name = "Mission Impossible 7";
                }
                else if (n = 8)
                {
                    R.movie_name = "Kudo";
                }
                else if (n = 9)
                {
                    R.movie_name = "Loyality matters";
                }
                else if (n = 10)
                {
                    R.movie_name = "Power is power";
                }
                R.cnic = CNIC;
                cout << "Enter your review in a liner" << endl;
                cin >> R.Review;
                cout<<"Also enter the rating for the Film 1-5"<<endl;
                cin>>R.rating;

                ofs << R.cnic << "\t" << R.movie_name << "\t" << R.Review << endl;
                cout << "Review submitted " << endl;
                cout << "Thanks for your feedback" << endl;
            }
            else
            {
                cout << "You haven't buy a ticket" << endl;
                cout << "Only person who buy ticket can review" << endl;
            }
        }
    };
};
// This class is responsible for handling booking of tickets.
class BookTickets : public handlingFiles
{
public:
    void bookTicket()
    {
        if (returnAvailableTickets != 0)
        {
            int n;

            movieList(); // from the movie class that is a parent class
            cout << "Enter your choice" << endl;
            cin >> n;
            bookTicket_file(n);
        }
    };
};
 int movie::available_tickets = 100;
// This class handles filmreviews
class FilmReviews : public handlingFiles
{
public:
    void movieReview()
    {
        int Cnic;
        cout << "Enter your cnic" << endl;
        cin >> Cnic;
        reviewFilm(Cnic);
    }
    void ShowFilmReviws(){
        cout<<"Film reviews"<<endl;
        ifstream ifs;

        ifs.open("review.txt");

    }
};
class SearchTicket : public handlingFiles
{
public:
    void findTicketByCNIC()
    {
        int searchCnic;
        cout << "Enter CNIC to search ticket: ";
        cin >> searchCnic;

        ifstream file("tickets.txt");
        ticket T;
        bool found = false;

        while (file >> T.cnic >> T.movie_name >> T.day)
        {
            if (T.cnic == searchCnic)
            {
                found = true;
                cout << "Ticket Found:" << endl;
                cout << "CNIC: " << T.cnic << endl;
                cout << "Movie: " << T.movie_name << endl;
                cout << "Day: " << T.day << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "No ticket found with this CNIC." << endl;
        }

        file.close();
    }
};
class CancelTicket : public handlingFiles
{
public:
    void cancelTicketByCNIC()
    {
        int searchCnic;
        cout << "Enter CNIC to cancel ticket: ";
        cin >> searchCnic;

        ifstream inFile("tickets.txt");
        ofstream tempFile("temp.txt");
        ticket T;
        bool found = false;

        while (inFile >> T.cnic >> T.movie_name >> T.day)
        {
            if (T.cnic == searchCnic)
            {
                found = true;
                cout << "Ticket cancelled for CNIC: " << T.cnic << endl;
                continue; // skip writing this record to temp file
            }
            tempFile << T.cnic << "\t" << T.movie_name << "\t" << T.day << endl;
        }

        inFile.close();
        tempFile.close();

        remove("tickets.txt");
        rename("temp.txt", "tickets.txt");

        if (!found)
        {
            cout << "No ticket found for given CNIC." << endl;
        }
    }
};
class ShowAllTickets : public handlingFiles
{
public:
    void displayAllTickets()
    {
        ifstream file("tickets.txt");
        ticket T;

        cout << "\nAll Booked Tickets:\n";
        cout << "----------------------\n";
        while (file >> T.cnic >> T.movie_name >> T.day)
        {
            cout << "CNIC: " << T.cnic
                 << " | Movie: " << T.movie_name
                 << " | Day: " << T.day << endl;
        }
        file.close();
    }
};
// ... your other classes like ShowAllTickets ...

class User {
private:
    string name;
    int age;
    int cnic;

public:
    void getUserData() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your CNIC: ";
        cin >> cnic;
    }

    void showUserData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
    }

    int getCNIC() {
        return cnic;
    }
};



int main()
{

    SearchTicket st;
    st.findTicketByCNIC();

}
