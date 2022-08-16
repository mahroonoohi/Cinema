#include<iostream>
#include<windows.h>
#include<Vector>
#include<string>
#include<conio.h>
#include<iomanip>
#include<File>
//class
using namespace std;

class persons
{
public:
    string pasword;
    string username;
};
class Movie
{
public:
    string Movie_name;
    string movie_director;
    string actors_1;
    string actor_2;
    string actor_3;
    string Made_in;
    string Movie_genre;
    int Tim_Movie;

    int Production_Year;
    int capacity;
};
//functions
void setcolor(int);
void print_1();
void print_2();
void print_3();
void print_4();
void print_5();
void timer();
void search();
void display();
void displayofgroup();
void QFilee();
void write();
void sort();
void reduce();
//data QVector
QVector<persons> person;
QVector<Movie> movie;
QVector<Movie> group;
QVector<Movie> group1;
QVector<string> strfile;
QVector<Movie> stdfile;
QVector<Movie>::iterator it;
int main()
{
    persons a;
    print_1(); print_2();
    while (UINT64_MAX)
    {
        string comand;
        bool find = false; bool ok = false; bool finish = false;
        setcolor(14);
        cout << "::@comand::";
        getline(cin, comand);
        if (comand == "REGISTER")
        {
            getline(cin, a.username);
            getline(cin, a.pasword);
            string text1, text2;
            QFile file("c:/mahroo/persons.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::WriteOnly))
            {
                while (!file.atEnd())
                {
                    text1 = (string)file.readLine();
                    if (text1 != "\n")
                    {
                        text1.pop_back();
                        strfile.push_back(text1);
                    }
                    text2 = (string)file.readLine();
                    if (text2 != "")
                    {
                        text2.pop_back();
                        strfile.push_back(text1);
                    }
                    if (a.username == text1 && a.pasword == text2)
                    {
                        find = true;
                        break;
                    }
                }
            }
            if (find == true)
            {
                setcolor(4);
                string message = "::Wrong Comand Check for LOGIN Or You Should RIGSTER ::";
                cout << message << endl;
                setcolor(15);
                print_2();
                continue;
            }
            else
            {
                strfile.push_back(a.username);
                strfile.push_back(a.pasword);
                string str, text1, text2;
                const char* c;
                QFile file("C:/mahroo/persons.txt");
                if (file.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    for (int i = 0; i < strfile.size(); i++)
                    {
                        str = strfile[i];
                        c = str.c_str();
                        file.write(c);
                        file.write("\n");
                    }
                }
                setcolor(12);
                string message = "::Your Registration Was SuccessfuLl::";
                cout << message << endl;
                setcolor(9);
                string messagee = "::Now To Continue LOGIN::";
                cout << messagee << endl;
                setcolor(15);
                continue;
            }
        }
        else if (comand == "LOGIN")
        {
            getline(cin, a.username);
            getline(cin, a.pasword);
            string text1, text2;
            QFile file("c:/mahroo/persons.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                while (!file.atEnd())
                {
                    text1 = (string)file.readLine();
                    if (text1.at(text1.size() - 1) == '\n')
                        text1.pop_back();
                    text2 = (string)file.readLine();
                    if (text2.at(text2.size() - 1) == '\n')
                        text2.pop_back();
                    if (a.username == text1 && a.pasword == text2)
                    {
                        find = true;
                        break;
                    }
                }
            }
            if (!find)
            {
                setcolor(4);
                string message = "You Have Not RIGISTER Yet";
                cout << message << endl;
                setcolor(15);
                print_2();
                continue;
            }
        }
        if (find)
        {
            if (find == true && person.size() == 0)
            {
                person.push_back(a);
            }
            if (person.size() != 0 && find == true)
            {
                for (int i = 0; i < person.size(); i++)
                {
                    if (a.username == person[i].username && a.pasword == person[i].pasword)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    person.push_back(a);
                }
            }
            stdfile.clear();
            QFilee();
            for (int i = 0; i < stdfile.size(); i++)
            {
                movie.push_back(stdfile[i]);
            }
            sort();
            reduce();
            setcolor(13);
            timer();
            if (a.username == "Admin" && a.pasword == "Admin")
            {
                finish = true;
            }
            if (finish)
            {
                while (UINT64_MAX)
                {
                    cout << "::WELCOME DEAR ADMIN THESE ARE ITEMS YOU CAN DO::" << endl;
                    print_3();
                    string comand;
                    setcolor(12);
                    cout << "CHOOSE NUMBER FROM 1 TO 9" << endl;
                    cin >> comand;
                    cin.ignore();
                    Movie T, s;
                    if (comand == "1")
                    {
                        setcolor(10);
                        cout << "::ENTER NAME FOR MOVIE::" << endl;
                        getline(cin, T.Movie_name);
                        cout << "::ENTER MOVIE DIRECTOR::" << endl;
                        getline(cin, T.movie_director);
                        cout << "::ENTER FIRST ACTOR::" << endl;
                        getline(cin, T.actors_1);
                        cout << "::ENTER SECEND ACTOR ::" << endl;
                        getline(cin, T.actor_2);
                        cout << ":: ENTER THIRD ACTOR::" << endl;
                        getline(cin, T.actor_3);
                        cout << "::ENTER NAME FOR COUNTRY ::" << endl;
                        getline(cin, T.Made_in);
                        cout << "::ENTER GENRE FOR MOVIE ::" << endl;
                        getline(cin, T.Movie_genre);
                        cout << "::ENTER TIME FOR MOVIE::" << endl;
                        cin >> T.Tim_Movie;
                        cin.ignore();
                        cout << "::ENTER THE YEAR FOR PROUDUCING MOVIE::" << endl;
                        cin >> T.Production_Year;
                        cout << "::DEAR ADMIN CHOOSE CAPACITY FOR YOUR OWN MOVIE ::" << endl;
                        cin >> T.capacity;
                        stdfile.clear();
                        QFilee();
                        stdfile.push_back(T);
                        movie.clear();
                        for (int i = 0; i < stdfile.size(); i++)
                        {
                            if (movie.size() == 0)
                            {
                                movie.push_back(stdfile[i]);
                            }
                            for (int j = 0; j < movie.size(); j++)
                            {
                                if ((movie[j].Movie_name == stdfile[i].Movie_name) && (movie[j].movie_director == stdfile[i].movie_director) && (movie[j].Made_in == stdfile[i].Made_in) && (movie[j].Movie_genre == stdfile[i].Movie_genre) && (movie[j].Production_Year == stdfile[i].Production_Year) && (movie[j].Tim_Movie == stdfile[i].Tim_Movie) && (movie[j].actors_1 == stdfile[i].actors_1) && (movie[j].actor_2 == stdfile[i].actor_2) && (movie[j].actor_3 == stdfile[i].actor_3) && (movie[j].capacity == stdfile[i].capacity))
                                {
                                    break;
                                }
                                else
                                {
                                    movie.push_back(stdfile[i]);
                                    break;
                                }
                            }
                        }
                        sort();
                        write();
                        setcolor(1);
                        string message = "::Adding_Movie wes Succesfully Choose Another Opshens To Do::";
                        cout << message << endl;
                        timer();
                        system("cls");
                        continue;
                    }
                    else if (comand == "2")
                    {
                        cout << "::ENTER NUMBER OF MOVIE TO DELETE::" << endl;
                        int numbermovie;
                        cin >> numbermovie;
                        for (int i = 0; i < movie.size(); i++)
                        {
                            if (i == (numbermovie - 1))
                            {
                                it = movie.begin();
                                movie.erase(it + i);
                                setcolor(2);
                                cout << "::deleting movie was succedfull::" << endl;
                                sort();
                                system("cls");
                                break;
                            }
                        }
                        write();
                    }
                    else if (comand == "3")
                    {
                        int k, i;
                        setcolor(9);
                        display();
                        setcolor(14);
                        cout << "::WHICH MOVIE DO YOU WANT TO EDITE CHOOSE NUMBER::" << endl;
                        cin >> i;
                        while (UINT64_MAX)
                        {
                            string comand, suggestion, M;
                            setcolor(3);
                            print_4();
                            cout << endl;
                            setcolor(6);
                            cout << "WHICH PART DO YOU WANT TO EDIT " << endl;
                            cin >> comand;
                            cin.ignore();
                            if (comand == "1")
                            {
                                cout << "::choose new name for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].Movie_name = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "2")
                            {
                                cout << "::choose new movie director for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].movie_director = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "3")
                            {
                                cout << "::choose new acters_1 for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].actors_1 = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "4")
                            {
                                cout << "::choose new acters_2 for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].actor_2 = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "5")
                            {
                                cout << "::choose new acters_3 for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].actor_3 = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "6")
                            {
                                cout << "::choose new country for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].Made_in = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "7")
                            {
                                cout << "::choose new genre for your own movie::" << endl;
                                getline(cin, M);
                                movie[i - 1].Movie_genre = M;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "8")
                            {
                                cout << "::choose new time  for your own movie::" << endl;
                                cin >> k;
                                movie[i - 1].Tim_Movie = k;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "9")
                            {
                                cout << "::choose new year for your own movie::" << endl;
                                cin >> k;
                                movie[i - 1].Production_Year = k;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                            if (comand == "10")
                            {
                                cout << "::choose new capacity for your own movie::" << endl;
                                cin >> k;
                                movie[i - 1].capacity = k;
                                write();
                                string messege = "::DO YOU WANT TO CONTINUE EDDITING OR STOP::";
                                cout << "1-";
                                cout << "Continue" << endl;
                                cout << "2-";
                                cout << "Stop" << endl;
                                cin >> suggestion;
                                if (suggestion == "1")
                                {
                                    continue;
                                }
                                else if (suggestion == "2")
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else if (comand == "4")
                    {
                        search();
                    }
                    else if (comand == "5")
                    {
                        display();
                    }
                    else if (comand == "6")
                    {
                        string commend;
                        setcolor(11);
                        cout << " ::ON WHAT BASIS DO YOU WANT TO GROUP CHOOSE NUMBER FROME 1 TO 9 ::" << endl;
                        setcolor(14); cout << "1_"; setcolor(9);
                        cout << "movie_director" << endl; setcolor(14); cout << "2_"; setcolor(9); cout << "actors_1" << endl; setcolor(14); cout << "3_";
                        setcolor(9); cout << "actor_2" << endl; setcolor(14); cout << "4_"; setcolor(9); cout << "actor_3" << endl; setcolor(14); cout << "5_";
                        setcolor(9); cout << "Made_in" << endl; setcolor(14); cout << "6-"; setcolor(9); cout << "Movie_genre" << endl; setcolor(14); cout << "7_";
                        setcolor(9);  cout << "Tim_Movie" << endl; setcolor(14); cout << "8_"; setcolor(9); cout << "Production_Year" << endl; setcolor(15); cout << endl;
                        getline(cin, commend);
                        string saved;
                        int timegroup = 0;
                        if (commend == "1")
                        {
                            setcolor(10);
                            cout << "A STRING FOR BASE TO SEARCH IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].movie_director == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "2")
                        {
                            setcolor(10); cout << "A STRING FOR BASE TO SEARCH  IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].actors_1 == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "3")
                        {
                            setcolor(10);
                            cout << "A STRING FOR BASE TO SEARCH IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].actor_2 == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "4")
                        {
                            setcolor(10);
                            cout << "A STRING FOR BASE TO SEARCH IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].actor_3 == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "5")
                        {
                            setcolor(10); cout << "A STRING FOR BASE TO SEARCH  IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].Made_in == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "6")
                        {
                            setcolor(10);
                            cout << "A STRING FOR BASE TO SEARCH IN GROUP" << endl;
                            getline(cin, saved);
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].Movie_genre == saved)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "7")
                        {
                            setcolor(13);
                            cout << "A TIME FOR BASE TO SEARCH" << endl;
                            cin >> timegroup;
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].Tim_Movie == timegroup)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }
                        else if (commend == "8")
                        {
                            setcolor(10);
                            cout << "A YEAR FOR BASE TO SEARCH" << endl;
                            cin >> timegroup;
                            for (int i = 0; i < movie.size(); i++)
                            {
                                if (movie[i].Production_Year == timegroup)
                                {
                                    group1.push_back(movie[i]);
                                }
                            }
                        }

                    }
                    else if (comand == "7")
                    {
                        displayofgroup();
                    }
                    else if (comand == "8")
                    {

                        setcolor(11);
                        cout << "1-";
                        setcolor(14);
                        cout << "RESTART SECEND HISTORY CLEAR" << endl;
                        setcolor(11);
                        cout << "2-";
                        setcolor(14);
                        cout << "FINISH PROGRAM" << endl;
                        setcolor(2);
                        cout << "::CHOOSE NUMBER::" << endl;
                        int m;
                        cin >> m;
                        if (m == 1)
                        {
                            person.clear();
                            movie.clear();
                            setcolor(9);
                            cout << "HISTORY CLEARED PROGRAM WILL START AFTER A FEW MINUTES GOOD LUCK" << endl;
                            print_2();
                            break;
                        }
                        else if (m == 2)
                        {
                            setcolor(6);
                            cout << "PROGRAM HAS BEEN FINISHED HAVE A GOOD DAY :)) THANK YOU FOR COMMING" << endl;
                            setcolor(15);
                            return 0;
                        }
                    }
                }
            }
            else
            {
                while (UINT64_MAX)
                {
                    reduce();
                    setcolor(14);
                    cout << "::WECOME DEAR MEMBER THESE ARE Items YOU CAN DO::" << endl;
                    print_5(); cout << endl;
                    setcolor(10);
                    cout << "::CHOOSE NUMBER FROME 1 TO 5 IF YOU want::" << endl;
                    string commend;
                    cin >> commend;
                    if (commend == "1")
                    {
                        search();
                    }
                    else if (commend == "2")
                    {
                        display();
                    }
                    else if (commend == "3")
                    {
                        displayofgroup();
                    }
                    else if (commend == "4")
                    {
                        cout << endl;
                        cout << "::CHOOSE ONE MOVIE TO SEE::" << endl;
                        while (UINT64_MAX)
                        {
                            system("cls");
                            display();
                            setcolor(7);
                            int map;
                            int p;
                            cout << "::CHOOSE NUMBER::" << endl;
                            setcolor(13);
                            cout << "1-continue to choose" << endl; cout << "2-choose another opshen" << endl;
                            cin >> p;
                            if (p == 1)
                            {
                                cout << "ENTER NUMBER OF MOVIE " << endl;
                                cin >> map;
                                for (int i = 0; i < movie.size(); i++)
                                {
                                    if ((map - 1) == i)
                                    {
                                        if (movie[i].capacity == 0)
                                        {
                                            setcolor(4);
                                            cout << "THE CAPACITY OF THIS MOVIE IS FINISHED CHOOSE ANOTHER IF YOU WANT" << endl;
                                            timer();
                                            break;
                                        }
                                        else
                                        {
                                            setcolor(2);
                                            cout << ":: YOUR RESERVATION IN CINEMA WEAS SUCCESFULL:)) ::" << endl;
                                            movie[i].capacity--;
                                            write();
                                            timer();
                                        }
                                    }
                                }
                            }
                            else if (p == 2)
                            {
                                break;
                            }

                        }
                    }
                    else if (commend == "5")
                    {
                        setcolor(11); cout << "1-";
                        setcolor(7); cout << "RESTART" << endl;
                        setcolor(11); cout << "2-";
                        setcolor(7); cout << "FINISH PROGRAM" << endl;
                        setcolor(11); cout << "3-";
                        setcolor(7); cout << "SHOW YOUR PANEL" << endl; int m;
                        cin.ignore();
                        cin >> m;
                        if (m == 1)
                        {
                            print_2();
                            break;
                        }
                        else if (m == 2)
                        {
                            return 0;
                        }
                        else if (m == 3)
                        {
                            system("cls");
                            continue;
                        }

                    }
                }
            }
        }

    }
    return 0;
}
void setcolor(int colorcode) {

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colorcode % 255);
}
void print_1()
{
    setcolor(5);
    cout << ":: Welcome To The Cinema These are Commands You Can Choose but first Register ::" << endl; setcolor(10);
    cout << "________________________________________________________________________________ " << endl; setcolor(4); cout << "1-";
    setcolor(1); cout << "Adding_Movie" << endl;
    setcolor(4); cout << "2-"; setcolor(1); cout << "Remove_Movie" << endl; setcolor(4); cout << "3-"; setcolor(1); cout << "Editing_Movie" << endl; setcolor(4);
    cout << "4-"; setcolor(1); cout << "Search_Movie" << endl; setcolor(4);
    cout << "5-"; setcolor(1); cout << "Display_All_Movie" << endl; setcolor(4); cout << "6-";
    setcolor(1); cout << "Grouping_All_Movie" << endl; setcolor(4); cout << "7-";
    setcolor(1); cout << "Searchig_for_Groups" << endl; setcolor(4); cout << "8-";
    setcolor(1); cout << "Watching_all_Movie_OF_Group" << endl; cout << endl; setcolor(15);
}
void print_2()
{
    setcolor(13);
    cout << "::Choose One Item::" << endl;
    setcolor(12);
    cout << "1-";
    setcolor(2);
    cout << "REGISTER::" << endl;
    setcolor(12);
    cout << "2-";
    setcolor(2);
    cout << "LOGIN::" << endl;
    cout << endl;
    setcolor(15);
}
void print_3()
{
    setcolor(4); cout << "1-";
    setcolor(1); cout << "Adding_Movie" << endl; setcolor(4); cout << "2-"; setcolor(1);  cout << "Remove_Movie" << endl;
    setcolor(4); cout << "3-"; setcolor(1); cout << "Editing_Movie" << endl; setcolor(4); cout << "4-"; setcolor(1); cout << "Search_Movie" << endl;
    setcolor(4); cout << "5-"; setcolor(1); cout << "Display_All_Movie" << endl; setcolor(4); cout << "6-"; setcolor(1); cout << "Grouping_All_Movie & Searchig_for_Groups" << endl;
    setcolor(4);; setcolor(4); cout << "7-"; setcolor(1); cout << "Watching_all_Movie_OF_Group" << endl;
    setcolor(4); cout << "8-"; setcolor(1); cout << "LOG OUT" << endl; cout << endl; setcolor(15);
}
void print_4()
{
    setcolor(14);  cout << "1_"; setcolor(9); cout << "Movie_name"; setcolor(14); cout << "2_"; setcolor(9);
    cout << "movie_director"; setcolor(14); cout << "3_"; setcolor(9); cout << "actors_1"; setcolor(14); cout << "4_";
    setcolor(9); cout << "actor_2"; setcolor(14); cout << "5_"; setcolor(9); cout << "actor_3"; setcolor(14); cout << "6_";
    setcolor(9); cout << "Made_in"; setcolor(14); cout << "7-"; setcolor(9); cout << "Movie_genre"; setcolor(14); cout << "8_";
    setcolor(9);  cout << "Tim_Movie"; setcolor(14); cout << "9_"; setcolor(9); cout << "Production_Year"; setcolor(15);
    setcolor(14); cout << "10_"; setcolor(9); cout << "capacity";
}
void timer()
{
    int s;
    setcolor(6);
    cout << "::A_COUNTDOWN_TIMER::" << endl;
    setcolor(9);
    cout << "Enter_In_Seconds_Here" << endl;
    cin >> s;
    setcolor(3);
    cout << "::Time_Remaining" << endl;
    for (int sec = s; sec >= 0; sec--)
    {
        if (sec == 0)
            s = 59;
        Sleep(1000);
        system("cls");
        cout << sec << endl;
    }
    system("cls");
    Sleep(1000);
}
void print_5()
{
    setcolor(4); cout << "1-"; setcolor(5); cout << "searching_movie"; cout << endl; setcolor(4); cout << "2-"; setcolor(5); cout << "Display_All_Movie" << endl; setcolor(4);
    cout << "3-"; setcolor(5); cout << "Watching_all_Movie_OF_Group" << endl; setcolor(4); cout << "4-"; setcolor(5); cout << "reserve ticket"; cout << endl; setcolor(4); cout << "5-"; setcolor(5); cout << "LOGOUT";
    cout << endl;
}
void search()
{
    string message, search;
    setcolor(13);
    cout << "::ON WHAT BASIS DO YOU WANT TO SEARCH IN CHOOSE NUMBER FROM 1 TO 8::" << endl;
    print_4();
    cout << endl; cin >> message;
    char ch;
    int p = 0;
    if (message == "1")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].Movie_name.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].Movie_name << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "2")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].movie_director.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].movie_director << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "3")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].actors_1.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].actors_1 << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "4")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].actor_2.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].actor_2 << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "5")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].actor_3.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].actor_3 << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "6")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].Made_in.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].Made_in << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
    else if (message == "7")
    {
        while (UINT64_MAX)
        {
            setcolor(13);
            cout << "::ENTER CHARECTOR::" << endl;
            cout << search;
            cin.ignore();
            cin.get(ch);
            if (ch == '.')
            {
                system("cls");
                break;
            }
            search.push_back(ch);
            p++;
            for (int i = 0; i < movie.size(); i++)
            {
                if (movie[i].Movie_genre.substr(0, p) == search.substr(0, p))
                {
                    cout << movie[i].Movie_genre << endl;
                }
            }
            cout << "--------------------------------------------------------------" << endl;
            timer();
            system("cls");
        }
    }
}
void display()
{
    system("cls");
    if (movie.size() == 0)
    {
        setcolor(4);
        cout << "LIST is Empty DEAR ADMIN MUST ADD SOME MOVIE" << endl;
        timer();
        system("cls");
    }
    else
    {
        movie.clear();
        stdfile.clear();
        QFilee();
        for (int i = 0; i < stdfile.size(); i++)
        {
            movie.push_back(stdfile[i]);
        }
        sort();
        reduce();
        for (int i = 0; i < movie.size(); i++)
        {
            if (movie[i].capacity == 0)
            {
                cout << "---------------------------------------------------------------------------" << endl;
                setcolor(13);
                cout << i + 1 << endl;
                setcolor(4);
                cout << std::left << std::setw(20) << "1-Movie_name" << "    " << movie[i].Movie_name << endl;
                cout << std::left << std::setw(20) << "2-movie_director" << "    " << movie[i].movie_director << endl;
                cout << std::left << std::setw(20) << "3-actors_1" << "    " << movie[i].actors_1 << endl;
                cout << std::left << std::setw(20) << "4-actors_2" << "    " << movie[i].actor_2 << endl;
                cout << std::left << std::setw(20) << "5-actors_3" << "    " << movie[i].actor_3 << endl;
                cout << std::left << std::setw(20) << "6-Made_in" << "    " << movie[i].Made_in << endl;
                cout << std::left << std::setw(20) << "7-Movie_genre" << "    " << movie[i].Movie_genre << endl;
                cout << std::left << std::setw(20) << "8-Tim_Movie" << "    " << movie[i].Tim_Movie << endl;
                cout << std::left << std::setw(20) << "9-Production_Year" << "    " << movie[i].Production_Year << endl;
                cout << std::left << std::setw(20) << "10-capacity" << "    " << movie[i].capacity << endl;
                cout << "---------------------------------------------------------------------------" << endl;
                cout << endl;
            }
            else
            {
                setcolor(2);
                cout << "----------------------------------------------------------------------" << endl;
                setcolor(13);
                cout << i + 1 << endl;
                setcolor(2);
                cout << std::left << std::setw(20) << "1-Movie_name" << "    " << movie[i].Movie_name << endl;
                cout << std::left << std::setw(20) << "2-movie_director" << "    " << movie[i].movie_director << endl;
                cout << std::left << std::setw(20) << "3-actors_1" << "    " << movie[i].actors_1 << endl;
                cout << std::left << std::setw(20) << "4-actors_2" << "    " << movie[i].actor_2 << endl;
                cout << std::left << std::setw(20) << "5-actors_3" << "    " << movie[i].actor_3 << endl;
                cout << std::left << std::setw(20) << "6-Made_in" << "    " << movie[i].Made_in << endl;
                cout << std::left << std::setw(20) << "7-Movie_genre" << "    " << movie[i].Movie_genre << endl;
                cout << std::left << std::setw(20) << "8-Tim_Movie" << "    " << movie[i].Tim_Movie << endl;
                cout << std::left << std::setw(20) << "9-Production_Year" << "    " << movie[i].Production_Year << endl;
                cout << std::left << std::setw(20) << "10-capacity" << "    " << movie[i].capacity << endl;
                cout << "----------------------------------------------------------------------" << endl;
                cout << endl;
            }
        }
    }
}
void displayofgroup()
{
    if (group1.size() == 0)
    {
        setcolor(4);
        cout << "ADMIN MUST GROUP THERE IS NO FILM ON GROUP" << endl;
    }
    else
    {
        setcolor(11);
        cout << "::THES ARE MOVIE OF GROUPING::" << endl;
        for (int i = 0; i < group1.size(); i++)
        {
            cout << std::left << std::setw(20) << "Movie_name" << "    " << group1[i].Movie_name << endl;
            cout << std::left << std::setw(20) << "movie_director" << "    " << group1[i].movie_director << endl;
            cout << std::left << std::setw(20) << "actors_1" << "    " << group1[i].actors_1 << endl;
            cout << std::left << std::setw(20) << "actors_2" << "    " << group1[i].actor_2 << endl;
            cout << std::left << std::setw(20) << "actors_3" << "    " << group1[i].actor_3 << endl;
            cout << std::left << std::setw(20) << "Made_in" << "    " << group1[i].Made_in << endl;
            cout << std::left << std::setw(20) << "Movie_genre" << "    " << group1[i].Movie_genre << endl;
            cout << std::left << std::setw(20) << "Tim_Movie" << "    " << group1[i].Tim_Movie << endl;
            cout << std::left << std::setw(20) << "Production_Year" << "    " << group1[i].Production_Year << endl;
            cout << std::left << std::setw(20) << "capacity" << "    " << group1[i].capacity << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
        }
    }
}
void QFilee()
{
    string str, text1, text2, text3, text4, text5, text6, text7, text8, text9, text10;
    Movie T, s;
    QFile file("C:/mahroo/movie.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::WriteOnly))
    {
        while (!file.atEnd())
        {
            text1 = (string)file.readLine();
            if (text1 == "\n")
            {
                text1 = (string)file.readLine();
            } text2 = (string)file.readLine();
            if (text2 == "\n")
            {
                text2 = (string)file.readLine();
            }  text3 = (string)file.readLine();
            if (text3 == "\n")
            {
                text3 = (string)file.readLine();
            } text4 = (string)file.readLine();
            if (text4 == "\n")
            {
                text4 = (string)file.readLine();
            } text5 = (string)file.readLine();
            if (text5 == "\n")
            {
                text5 = (string)file.readLine();
            } text6 = (string)file.readLine();
            if (text6 == "\n")
            {
                text6 = (string)file.readLine();
            }  text7 = (string)file.readLine();
            if (text7 == "\n")
            {
                text7 = (string)file.readLine();
            } text8 = (string)file.readLine();
            if (text8 == "\n")
            {
                text8 = (string)file.readLine();
            } text9 = (string)file.readLine();
            if (text9 == "\n")
            {
                text9 = (string)file.readLine();
            } text10 = (string)file.readLine();
            if (text10 == "\n")
            {
                text10 = (string)file.readLine();
            }  s.Movie_name = text1; s.movie_director = text2; s.actors_1 = text3; s.actor_2 = text4; s.actor_3 = text5;  s.Made_in = text6;  s.Movie_genre = text7; s.Tim_Movie = stoi(text8);  s.Production_Year = stoi(text9);  s.capacity = stoi(text10);
            stdfile.push_back(s);
            continue;
        }
    }
}
void write()
{
    string  str;
    const char* c;
    QFile  file("C:/mahroo/movie.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        for (QVector<Movie>::const_iterator it = movie.begin();
            it != movie.end(); ++it)
        {
            str = (*it).Movie_name; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).movie_director; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).actors_1; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).actor_2; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).actor_3; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).Made_in; c = str.c_str(); file.write(c); file.write("\n");
            str = (*it).Movie_genre; c = str.c_str(); file.write(c); file.write("\n");
            str = to_string((*it).Tim_Movie); c = str.c_str(); file.write(c); file.write("\n");
            str = to_string((*it).Production_Year); c = str.c_str(); file.write(c); file.write("\n");
            str = to_string((*it).capacity); c = str.c_str(); file.write(c); file.write("\n");
        }
    }
}
void sort()
{
    for (int i = 0; i < movie.size(); i++)
    {
        if (movie[i].Movie_name.at(movie[i].Movie_name.size() - 1) == '\n')
        {
            movie[i].Movie_name.pop_back();
        } if (movie[i].movie_director.at(movie[i].movie_director.size() - 1) == '\n')
        {
            movie[i].movie_director.pop_back();
        } if (movie[i].Made_in.at(movie[i].Made_in.size() - 1) == '\n')
        {
            movie[i].Made_in.pop_back();
        } if (movie[i].Movie_genre.at(movie[i].Movie_genre.size() - 1) == '\n')
        {
            movie[i].Movie_genre.pop_back();
        }if (to_string(movie[i].Production_Year).at(to_string(movie[i].Production_Year).size() - 1) == '\n')
        {
            to_string(movie[i].Production_Year).pop_back();
        } if (to_string(movie[i].Tim_Movie).at(to_string(movie[i].Tim_Movie).size() - 1) == '\n')
        {
            to_string(movie[i].Tim_Movie).pop_back();
        } if (movie[i].actors_1.at(movie[i].actors_1.size() - 1) == '\n')
        {
            movie[i].actors_1.pop_back();
        } if (movie[i].actor_2.at(movie[i].actor_2.size() - 1) == '\n')
        {
            movie[i].actor_2.pop_back();
        }if (movie[i].actor_3.at(movie[i].actor_3.size() - 1) == '\n')
        {
            movie[i].actor_3.pop_back();
        }if (to_string(movie[i].capacity).at(to_string(movie[i].capacity).size() - 1) == '\n')
        {
            to_string(movie[i].capacity).pop_back();
        }
    }
}
void reduce()
{
    for (int i = 0; i < movie.size(); i++)
    {
        if (group.size() == 0)
        {
            group.push_back(movie[i]);
        }
        for (int j = 0; j < group.size(); j++)
        {
            if ((group[j].Movie_name == movie[i].Movie_name) && (group[j].movie_director == movie[i].movie_director) && (group[j].Made_in == movie[i].Made_in) && (group[j].Movie_genre == movie[i].Movie_genre) && (group[j].Production_Year == movie[i].Production_Year) && (group[j].Tim_Movie == movie[i].Tim_Movie) && (group[j].actors_1 == movie[i].actors_1) && (group[j].actor_2 == movie[i].actor_2) && (group[j].actor_3 == movie[i].actor_3) && (group[j].capacity == movie[i].capacity))
            {
                break;
            }
            else
            {
                group.push_back(movie[i]);
                break;
            }
        }
    }
    movie.clear();
    for (int i = 0; i < group.size(); i++)
    {
        movie.push_back(group[i]);
    } group.clear();
}
