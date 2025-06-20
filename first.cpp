#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct ticket
{
    string cnic;
    string movie_name;
    string day;
};

struct movieReview
{
    string cnic;
    string movie_name;
    string Review;
    int rating;
};
struct SimpleMovieStats {
    string movie_name;
    int total_rating_sum;
    int review_count;
    double average_rating; // To store the calculated average

    // Constructor to easily initialize when creating a new stat entry
    SimpleMovieStats(string name = "", int rating = 0) :
        movie_name(name), total_rating_sum(rating), review_count(1), average_rating(0.0) {}
};
class motiveTheater
{
public:
    virtual void purposeofthisTheater() = 0;
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
       
        
            
            
            cout<<"Enter cnice"<<endl;
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
    void reviewFilm(string CNIC)

    {

        ifstream ifs;
        ofstream ofs;
        ticket T;
        movieReview R;
        ifs.open("tickets.txt");
        ofs.open("reviews.txt", ios::app);

        while (!ifs.eof())
        {

            ifs >> T.cnic;
            ifs >> T.movie_name;
            ifs >> T.day;
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
                else if (n = 2)
                {
                    R.movie_name = "Shiddat";
                }
                else if (n = 3)
                {
                    R.movie_name = "Azadi";
                }
                else if (n = 4)
                {
                    R.movie_name = "LifeTime";
                }
                else if (n = 5)
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
                cout << "Also enter the rating for the Film 1-5" << endl;
                cin >> R.rating;

                ofs << R.cnic << "\t" << R.movie_name << "\t" << R.Review << "\t" << R.rating << endl;
                cout << "Review submitted " << endl;
                cout << "Thanks for your feedback" << endl;
                ifs.close();
                return;
            }
        }

        cout << "You haven't buy a ticket" << endl;
        cout << "Only person who buy ticket can review" << endl;
    };
    void showAllmoviesReviews()
    {
        movieReview r;
        ifstream ifs;
        ifs.open("reviews.txt");
        while (!ifs.eof())
        {
            ifs >> r.cnic;
            ifs >> r.movie_name;
            ifs >> r.Review;
            ifs >> r.rating;
            cout << "CNIC: " << r.cnic
                 << " | Day: " << r.Review
                 << " | Movie: " << r.movie_name
                 << " | Day: " << r.rating << endl;
        }
        ifs.close();
        return;
    }
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
    void addmovieReview()
    {
        string Cnic;
        cout << "Enter your cnic" << endl;
        cin >> Cnic;
        reviewFilm(Cnic);
    }
    void ShowFilmReviws()
    {
        cout << "Film reviews" << endl;
        showAllmoviesReviews();
    }
    void topmovies()
    {
            ifstream ifs("reviews.txt");
        if (!ifs.is_open()) {
            cout << "No reviews available to determine top movies." << endl;
            return;
        }

        vector<SimpleMovieStats> movieStatsList; // To store aggregated data for each unique movie
        movieReview r;

        // 1. Read all reviews and aggregate data
        while (ifs >> r.cnic >> r.movie_name >> r.Review >> r.rating) {
            bool foundMovie = false;
            // Check if this movie already exists in our list
            for (size_t i = 0; i < movieStatsList.size(); ++i) {
                if (movieStatsList[i].movie_name == r.movie_name) {
                    movieStatsList[i].total_rating_sum += r.rating;
                    movieStatsList[i].review_count++;
                    foundMovie = true;
                    break;
                }
            }
            // If movie not found, add it as a new entry
            if (!foundMovie) {
                SimpleMovieStats newStats(r.movie_name, r.rating); // Use constructor
                movieStatsList.push_back(newStats);
            }
        }
        ifs.close(); // Close the reviews file

        if (movieStatsList.empty()) {
            cout << "No movies found with ratings." << endl;
            return;
        }

        // 2. Calculate average rating for each movie
        for (size_t i = 0; i < movieStatsList.size(); ++i) {
            if (movieStatsList[i].review_count > 0) {
                movieStatsList[i].average_rating = static_cast<double>(movieStatsList[i].total_rating_sum) / movieStatsList[i].review_count;
            } else {
                movieStatsList[i].average_rating = 0.0; // Should not happen if count > 0
            }
        }

        // 3. Manually sort the movies by average rating in descending order (using Bubble Sort)
        for (size_t i = 0; i < movieStatsList.size() - 1; ++i) {
            for (size_t j = 0; j < movieStatsList.size() - 1 - i; ++j) {
                if (movieStatsList[j].average_rating < movieStatsList[j+1].average_rating) {
                    // Swap elements if the current one is smaller than the next
                    SimpleMovieStats temp = movieStatsList[j];
                    movieStatsList[j] = movieStatsList[j+1];
                    movieStatsList[j+1] = temp;
                }
            }
    }

        cout << "\n--- Movies by Average Rating  ---\n";
        for (size_t i = 0; i < movieStatsList.size(); ++i) {
            cout << i + 1 << ". " << movieStatsList[i].movie_name
            << " (Average Rating: " << movieStatsList[i].average_rating << "/5.0)" << endl;
        }
    

}};

class SearchTicket : public handlingFiles
{
public:
    void findTicketByCNIC()
    {
        string searchCnic;
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
        string searchCnic;
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

class User
{
private:
    string name;
    int age;
    int cnic;

public:
    void getUserData()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your CNIC: ";
        cin >> cnic;
    }

    void showUserData()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Age: " << age << endl;
    }

    int getCNIC()
    {
        return cnic;
    }
};
class Admin : public movie, public motiveTheater
{
private:
    string adminPassword = "admin123"; // Admin login password

    // Authenticate the admin
    bool authenticate()
    {
        string input;
        cout << "Enter admin password: ";
        cin >> input;
        if (input == adminPassword)
            return true;
        cout << "Wrong password. Access denied.\n";
        return false;
    }

public:
    // Only this function is allowed now: Show number of tickets sold
    void showReports()
    {
        if (!authenticate())
            return;

        ifstream file("tickets.txt"); // Only using the file that exists
        if (!file.is_open())
        {
            cout << "Error opening tickets.txt or file doesn't exist.\n";
            return;
        }

        int cnic;
        string movie, day;
        int total = 0;

        cout << "\n--- Ticket Sales Report ---\n";

        // Read each record and count
        while (file >> cnic >> movie >> day)
        {
            total++;
        }

        cout << "Total Tickets Sold: " << total << endl;
        file.close();
    }
    void purposeofthisTheater()
    {

        cout << "  ---------------PURPOSE OF THE THEATER--------------" << endl;
        cout << "  More than just movies, we're a heart of the community." << endl;
        cout << "  Bringing diverse stories, family fun, and cultural nights" << endl;
        cout << "  right to your neighborhood. We believe in cinema's power" << endl;
        cout << "  to connect, inspire, and entertain. Enjoy state-of-the-art" << endl;
        cout << "  sound, comfortable seating, and a welcoming atmosphere." << endl;
        cout << "  Every ticket supports local initiatives and vibrant arts." << endl;
        cout << "  Join us for unforgettable cinematic experiences and be" << endl;
        cout << "  part of something special. Your community, your cinema!" << endl;
    }
};
int main()
{

     motiveTheater *p;

    int whilE_loopp_choose_choice = 1;
    FilmReviews fm; // filmReviews
    BookTickets bt; // booktickets
    ShowAllTickets st;
    Admin admin;
    CancelTicket cct;
    SearchTicket tt;
    while (whilE_loopp_choose_choice == 1)
    {

        system("clear");
        cout << "--MOVIE THEATER MANAGEMENT SYSTEM--" << endl;
        cout << "Enter your choice 1-8" << endl;
        cout << "0.Show purpose" << endl;
        cout << "1.Admin panel" << endl;
        cout << "2.See movie list" << endl;
        cout << "3.All movies Reviews" << endl;
        cout << "4.Top movies of the week" << endl;
        cout << "5.All tickets list" << endl;
        cout << "6.Book a ticket" << endl;
        cout << "7.Delete Booked ticket" << endl;
        cout << "8.Search Booked ticket" << endl;
        cout << "9.Add a review" << endl;

        int choice;
        cin >> choice;
        if (choice == 0)
        {
            system("clear");
            p = &admin;
            p->purposeofthisTheater();
        }
        else if (choice == 1)
        {
            // admin panel
            system("clear");
            admin.showReports();
        }
        else if (choice == 2)
        {
            // show movie list
            system("clear");
            fm.movieList();
        }
        else if (choice == 3)
        {
            // show all movies reviews
            system("clear");
            fm.ShowFilmReviws();
        }
        else if (choice == 4)
        {
            system("clear");
            // Top movies of the week
            fm.topmovies();
        }
        else if (choice == 5)
        {
            system("clear");
            // all tickets list
            st.displayAllTickets();
        }
        else if (choice == 6)
        {
            system("clear");
            // book a ticket
            bt.bookTicket();
        }
        else if (choice == 7)
        {
            // delte booked tickets
            system("clear");
            cct.cancelTicketByCNIC();
        }
        else if (choice == 8)
        {
            // search book ticket

            system("clear");
            tt.findTicketByCNIC();
        }
        else if (choice == 9)
        {
            // add a reveiw
            system("clear");
            fm.addmovieReview();
        }

        else
        {
            //
            // system("cls");
            system("clear");

            cout << "In-Valid" << endl;
            cout << "Enter between 1-9" << endl;
        };
        cout << "Enter 0 to stop and 1 to choose again" << endl;
        cin >> whilE_loopp_choose_choice;
    }

    return 0;
}
