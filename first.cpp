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
};

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
    int returnAvailableTickets()
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
    }
};
class handlingFiles : public movie
{
public:
    void bookTicket_file(int n)
    {
        ofstream file;
        file.open("C:\\Users\\Shekhani Laptops\\Documents\\tickets.txt", ios::app);
        ticket T;
        cout << "Enter your cnic" << endl;
        cin >> T.cnic;
        T.day = "Friday";
        if (n = 1)
        {
            T.movie_name = "Pathan";
        }
        if (n = 2)
        {
            T.movie_name = "Shiddat";
        }
        if (n = 3)
        {
            T.movie_name = "Azadi";
        }
        if (n = 4)
        {
            T.movie_name = "LifeTime";
        }
        if (n = 5)
        {
            T.movie_name = "Afghani";
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
        ifs.open("C:\\Users\\Shekhani Laptops\\Documents\\tickets.txt");
        ofs.open("C:\\Users\\Shekhani Laptops\\Documents\\reviews.txt");

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
                R.cnic = CNIC;
                cout << "Enter your review in a liner" << endl;
                cin >> R.Review;

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
class BookTickets : public handlingFiles
{
public:
    void bookTicket()
    {
        if (100 != 0)
        {
            int n;
            movieList(); // from the movie class that is a parent class
            cout << "Enter your choice" << endl;
            cin >> n;
            bookTicket_file(n);
        }
    };
};
static int availabe_tickets = 100;
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
};
int main()
{
    FilmReviews b;
    b.movieReview();
}