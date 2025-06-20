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

    cout << "Enter cnice" << endl;
    cin >> T.cnic;
    T.day = "Friday";

    if (n == 1) T.movie_name = "Pathan";
    else if (n == 2) T.movie_name = "Shiddatt";
    else if (n == 3) T.movie_name = "Azadi";
    else if (n == 4) T.movie_name = "LifeTime";
    else if (n == 5) T.movie_name = "Afghani";
    else if (n == 6) T.movie_name = "Sita Ramam";
    else if (n == 7) T.movie_name = "Mission Impossible 7";
    else if (n == 8) T.movie_name = "Kudo";
    else if (n == 9) T.movie_name = "Loyality matters";
    else if (n == 10) T.movie_name = "Power is power";

    file << T.cnic << "\t" << T.movie_name << "\t" << T.day << endl;
    file.close();

    // 🎟 Show the ticket receipt here
    cout << "\n============= 🎟 Ticket Receipt =============\n";
    cout << "✔ Ticket successfully booked!\n";
    cout << "CNIC         : " << T.cnic << endl;
    cout << "Movie        : " << T.movie_name << endl;
    cout << "Day          : " << T.day << endl;
    cout << "=============================================\n";
}

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
                if (n == 1)
                {
                    R.movie_name = "Pathan";
                }
                else if (n == 2)
                {
                    R.movie_name = "Shiddat";
                }
                else if (n == 3)
                {
                    R.movie_name = "Azadi";
                }
                else if (n == 4)
                {
                    R.movie_name = "LifeTime";
                }
                else if (n == 5)
                {
                    R.movie_name = "Afghani";
                }
                else if (n == 6)
                {
                    R.movie_name = "Sita Ramam";
                }
                else if (n == 7)
                {
                    R.movie_name = "Mission Impossible 7";
                }
                else if (n == 8)
                {
                    R.movie_name = "Kudo";
                }
                else if (n == 9)
                {
                    R.movie_name = "Loyality matters";
                }
                else if (n == 10)
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

    // Save to file
    ofstream file("customers.txt", ios::app);
    file << name << "\t" << age << "\t" << cnic << endl;
    file.close();
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
// This class is responsible for handling booking of tickets.
class BookTickets : public handlingFiles
{
public:
    void bookTicket()
{
    if (returnAvailableTickets() != 0)
    {
        int n;
        movieList(); // from the movie class that is a parent class
        cout << "Enter your choice" << endl;
        cin >> n;

        User u;
        u.getUserData(); // collect user info

        bookTicket_file(n); // then book ticket
    }
}

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
	void viewCustomerData()
{
    if (!authenticate()) return;

    ifstream file("customers.txt");
    if (!file.is_open())
    {
        cout << "No customer data available.\n";
        return;
    }

    string name;
    int age;
    int cnic;
    cout << "\n--- Registered Customers ---\n";
    while (file >> name >> age >> cnic)
    {
        cout << "Name: " << name << " | Age: " << age << " | CNIC: " << cnic << endl;
    }
    file.close();
}

    // Only this function is allowed now: Show number of tickets sold
   void addMovie() {
    if (!authenticate()) return;

    string newMovie;
    cout << "Enter new movie name to add: ";
    cin.ignore();
    getline(cin, newMovie);

    ofstream out("movies.txt", ios::app);
    if (!out) {
        cout << "❌ Failed to open movies.txt\n";
        return;
    }

    out << newMovie << endl;
    out.close();

    cout << "✅ Movie '" << newMovie << "' added successfully.\n";
}

void removeMovie() {
    if (!authenticate()) return;

    string movieToRemove;
    cout << "Enter movie name to remove: ";
    cin.ignore();
    getline(cin, movieToRemove);

    ifstream in("movies.txt");
    ofstream temp("temp.txt");

    if (!in || !temp) {
        cout << "❌ File error.\n";
        return;
    }

    string movie;
    bool found = false;

    while (getline(in, movie)) {
        if (movie != movieToRemove) {
            temp << movie << endl;
        } else {
            found = true;
        }
    }

    in.close();
    temp.close();

    remove("movies.txt");
    rename("temp.txt", "movies.txt");

    if (found) {
        cout << "✅ Movie '" << movieToRemove << "' removed.\n";
    } else {
        cout << "❌ Movie not found.\n";
    }
}
void showDynamicMovieList() {
    ifstream file("movies.txt");
    string movie;
    int index = 1;

    cout << "\n📂 Admin's Movie List (from file):\n";
    while (getline(file, movie)) {
        cout << index++ << ". " << movie << endl;
    }
    file.close();
}

void manageMoviesMenu() {
    if (!authenticate()) return;

    int choice;
    cout << "\n--- Admin Movie Management ---\n";
    cout << "1. Add Movie\n";
    cout << "2. Remove Movie\n";
    cout << "3. View Movie List\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string newMovie;
        cout << "Enter new movie name: ";
        getline(cin, newMovie);

        ofstream out("movies.txt", ios::app);
        out << newMovie << endl;
        out.close();

        cout << "✅ Movie added.\n";
    } else if (choice == 2) {
        string movieToRemove;
        cout << "Enter movie name to remove: ";
        getline(cin, movieToRemove);

        ifstream in("movies.txt");
        ofstream temp("temp.txt");
        string movie;
        bool found = false;

        while (getline(in, movie)) {
            if (movie != movieToRemove) {
                temp << movie << endl;
            } else {
                found = true;
            }
        }
        in.close();
        temp.close();
        remove("movies.txt");
        rename("temp.txt", "movies.txt");

        if (found)
            cout << "✅ Movie removed.\n";
        else
            cout << "❌ Movie not found.\n";
    } else if (choice == 3) {
        showDynamicMovieList();
    } else {
        cout << "❌ Invalid choice.\n";
    }
}

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
void initializeMovieFileIfNeeded() {
    ifstream check("movies.txt");
    if (check.peek() == ifstream::traits_type::eof()) {
        check.close();
        ofstream out("movies.txt");
        out << "Pathan\nShiddat\nAzadi\nLifetime\nAfghani\n";
        out << "Sita Ramam\nMission Impossible 7\nKudo\nLoyality matters\nPower is power\n";
        out.close();
        cout << "✅ Initialized movie list in movies.txt\n";
    } else {
        check.close();
    }
}

int main() {
    motiveTheater* theater;
    Admin admin;
    initializeMovieFileIfNeeded();

    int main_choice;
    bool running = true;

    while (running) {
        system("cls");
        cout << "=== MOVIE THEATER MANAGEMENT SYSTEM ===" << endl;
        cout << "1. User Menu" << endl;
        cout << "2. Admin Menu" << endl;
        cout << "3. About Our Theater" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> main_choice;

        switch (main_choice) {
            case 1: {  // User Menu
                FilmReviews fm;
                BookTickets bt;
                ShowAllTickets st;
                CancelTicket cct;
                SearchTicket tt;
                
                int user_choice;
                bool in_user_menu = true;
                
                while (in_user_menu) {
                    system("cls");
                    cout << "=== USER MENU ===" << endl;
                    cout << "1. View Movie List" << endl;
                    cout << "2. Book Ticket" << endl;
                    cout << "3. Add Review" << endl;
                    cout << "4. View All Reviews" << endl;
                    cout << "5. View Top Movies" << endl;
                    cout << "6. Search Ticket" << endl;
                    cout << "7. Cancel Ticket" << endl;
                    cout << "8. View All Tickets" << endl;
                    cout << "9. About Our Theater" << endl;
                    cout << "0. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> user_choice;

                    switch (user_choice) {
                        case 1:
                            admin.showDynamicMovieList();
                            break;
                        case 2:
                            bt.bookTicket();
                            break;
                        case 3:
                            fm.addmovieReview();
                            break;
                        case 4:
                            fm.ShowFilmReviws();
                            break;
                        case 5:
                            fm.topmovies();
                            break;
                        case 6:
                            tt.findTicketByCNIC();
                            break;
                        case 7:
                            cct.cancelTicketByCNIC();
                            break;
                        case 8:
                            st.displayAllTickets();
                            break;
                        case 9:
                            theater = &admin;
                            theater->purposeofthisTheater();
                            break;
                        case 0:
                            in_user_menu = false;
                            continue;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                break;
            }
            case 2: {  // Admin Menu
                int admin_choice;
                bool in_admin_menu = true;
                
                while (in_admin_menu) {
                    system("cls");
                    cout << "=== ADMIN MENU ===" << endl;
                    cout << "1. Show Reports" << endl;
                    cout << "2. Manage Movies" << endl;
                    cout << "3. View Customer Data" << endl;
                    cout << "4. About Our Theater" << endl;
                    cout << "0. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> admin_choice;

                    switch (admin_choice) {
                        case 1:
                            admin.showReports();
                            break;
                        case 2:
                            admin.manageMoviesMenu();
                            break;
                        
                        case 3:
                            admin.viewCustomerData();
                            break;
                        case 4:
                            theater = &admin;
                            theater->purposeofthisTheater();
                            break;
                        case 0:
                            in_admin_menu = false;
                            continue;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                break;
            }
            case 3: {  // About Theater
                theater = &admin;
                theater->purposeofthisTheater();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 0:
                running = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
        }
    }

    return 0;
}
