#include <iostream>
#include <windows.h>

#include <iomanip>          //for I/O manipulator i.e setw() operator
#include <conio.h>          //for getch()
#include <cstdlib>          //for system("cls")
#include <string>
#include <fstream>          //for File I/O
#include <cmath>            //for floor function
#include <ctime>			//for time

#include <sstream>      //for ostringstream and string to int conversion

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//function prototypes
void drawLine(int, char);
void writeTitle();
void startPage();

//function to hold for user input
inline void hold()
{
    string temp;
    drawLine(30, '=');
    cout << "Input 0 to return" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

string toString(int a)
{
    ostringstream stream;
    stream << a;
    return (stream.str());
}

class Book
{
	protected:
	    int book_id;
		string name;
		string writer;
		string publisher;
		string category;
		int noc;        //number of copies available
		float price;
		int pages;

	public:
	    Book() {}

	    Book(int id, string _name, string _writer, string _publilsher, string _category, int _noc, float _price, int _pages)
	    {
	        book_id = id;
	        name = _name;
	        writer = _writer;
	        publisher = _publilsher;
	        category = _category;
	        noc = _noc;
	        price = _price;
	        pages = _pages;
	    }

		int getBookId()
		{
		    return book_id;
		}
		string getBookName()
		{
		    return name;
		}
		string getWriter()
		{
		    return writer;
		}
		string getPublisher()
		{
		    return publisher;
		}
		string getCategory()
		{
		    return category;
		}
		int getNoc()
		{
		    return noc;
		}
		float getPrice()
		{
		    return price;
		}
		int getPages()
		{
		    return pages;
		}

		void setBookId(int id)
		{
		    book_id = id;
		}
		void setBookName(string str)
		{
		    name = str;
		}
		void setBookWriter(string str)
		{
		    writer = str;
		}
		void setBookPublisher(string str)
		{
            publisher = publisher;
		}
		void setBookCategory(string str)
		{
		    category = str;
		}
		void setBookNoc(int n)
		{
		    noc = n;
		}
		void setBookPrice(float p)
		{
		    price = p;
		}
		void setBookPages(int p)
		{
		    pages = p;
		}

		void listBook(const string& fileName);
		void searchBook(const string&);
		void getData();

};

void Book :: listBook(const string& fileName)
{
    system("cls");
    writeTitle();

	drawLine(115, '=');
    cout << "S.No." << setw(15) << setiosflags(ios::right) << "Book Name" << setw(15) << "Author" << setw(20) <<
    "Publisher" << setw(20) << "Category" << setw(20) << "No. of Copies"
    << setw(10) << "Price" << setw(10) << "Pages" << endl;

    drawLine(115, '=');

    ifstream infile;        //opening record file to read the records
    infile.open(fileName.c_str());

    /* stringstream strstream;
    strstream = infile.rdbuf();
    string str = strstream.str();
    cout << str << endl; */

   // Book book;

        //reading all book informations
        //infile.read(reinterpret_cast <char *> (&book), sizeof(book));
       // infile >> book_id >> name >> writer >> publisher >> category >> price >> pages;

        //displaying info
        string str;
        while(infile)
        {
            getline(infile, str);       //get line and stores in str
            cout << str << endl;
        }

        infile.close();

        //book.showData();

}

void Book :: searchBook(const string& fileName)
{
    ifstream infile(fileName.c_str());

    int searchedId;
    bool isFound = false;
    while(1){
        cout << "Enter Book Id: "; cin >> searchedId;
        break;

//        if (floor(id) == id) break;
//        else cout << "Enter a valid Id: " << endl;
    }

    string stream;

	istringstream isStream;
	int id;
    cout << "\n===========================\n";
    while(infile >> id)
    {

    	getline(infile, stream);
    	if (searchedId == id)
    	{

    		isFound = true;

    		drawLine(115, '=');
		    cout << "S.No." << setw(15) << setiosflags(ios::right) << "Book Name" << setw(15) << "Author" << setw(20) <<
            "Publisher" << setw(20) << "Category" << setw(20) << "No. of Copies"
            << setw(10) << "Price" << setw(10) << "Pages" << endl;

            drawLine(115, '=');

		   	cout << id <<" \t" << stream << endl;
		}


//        if (stream.find(searchedId, 0) != string::npos) {
//            isFound = true;
////            cout << "Record Found" << endl;
////            cout << "===========================\n\n";
//            cout << "S.No." << setw(15) << setiosflags(ios::right) << "Book Name" << setw(15) << "Author" << setw(20) <<
//            "Publisher" << setw(20) << "Category" << setw(20) << "No. of Copies"
//            << setw(10) << "Price" << setw(10) << "Pages" << endl;
//
//            cout << stream << endl;
//
//        }
        if (infile.eof()) break;
    }
    if (!isFound) {
        cout << "Sorry, Record not found\n" << endl;
        cout << "\n===========================\n\n";
    }

}

void Book :: getData()
{
    cout << "Enter Book Id: "; cin >> book_id;
    cout << "Enter Book Name: "; getline(cin, name);
    cout << "Enter Author Name: "; getline(cin, writer);
    cout << "Enter Publisher: "; getline(cin, publisher);
    cout << "Enter Category:"; getline(cin, category);
    cout << "Enter No. of Copies Available: "; cin >> noc;
    cout << "Enter Price : "; cin >> price;
    cout << "Enter Total Pages: "; cin >> pages;
}

class Admin : public Book
{
	private:
        string adminName;
        string adminFileName;
        string logList;

	public:
		Admin(): adminFileName("admin.txt"), logList("log.txt")
		{ }
	    void setAdminName(string name)
	    {
	        adminName = adminName;
	    }
	    void getUserFrmFile()
	    {
	    	ifstream infile(adminFileName.c_str());

	    	getline(infile, adminName);
	    	infile.close();
//	    	remove(adminFileName.c_str());
		}
		string getAdmin()
		{
			getUserFrmFile();
			return adminName;
		}
		void writeToFile(string name)
		{
			ofstream outfile(adminFileName.c_str());

			time_t currentTime = time(0);
			char* date = ctime(&currentTime);

			outfile << name << endl;
			outfile.close();
			ofstream logfile (logList.c_str(), ios::app);
			logfile << setw(20) << setiosflags(ios::left) << name << "\t" << date;
			logfile.close();
		}
		void getLogReport()
		{
			ifstream logfile(logList.c_str());

			cout << "\n\n\t\t\t\tLog Report" << endl;
			cout << "\t\t";		drawLine(40, '=');

			cout << "\n\n\n S.No. \t Admin Name \t\t  Log Time" << endl;
			drawLine(60, '=');
			string str;
			int count = 0;
			while(getline(logfile, str))
			{
				count++;
				cout << count << "\t" << str << endl;
				if (logfile.eof()) break;
			}
			logfile.close();
		}
	    void addBook(const string& fileName);
	    void updateBook(const string& fileName);
	    void deleteBook(const string&);
	    void adminPage();
	    void adminMenu();
};

void Admin :: addBook(const string& fileName)
{
    //Book book;
   // book.getData();

   fflush(stdin);
    while(true)
    {
        ifstream infile(fileName.c_str());

        cout << "Enter Book Id: "; cin >> book_id;

        int bookId;
        bool idFound = false;

        string stream;
        infile.seekg(0, ios::beg);
        infile.clear();
        while(infile >> bookId)
        {
        	getline(infile, stream);
            if (bookId == book_id) {
                   idFound = true;
                   cout << "Sorry, Book Id Exists..." << endl;
                   drawLine(30, '=');
                   _getch();
                   break;
            }
            if (infile.eof()) break;
        }
        infile.close();

        if (!idFound) break;
    }

    ofstream outfile(fileName.c_str(),ios::app);
    if (!outfile.is_open()) outfile.open(fileName.c_str(), ios::app);

    fflush(stdin);
    cout << "Enter Book Name: "; getline(cin, name);
    cout << "Enter Author Name: "; getline(cin, writer);
    cout << "Enter Publisher: "; getline(cin, publisher);
    cout << "Enter Category:"; getline(cin, category);
    cout << "Enter No. of Copies Available: "; cin >> noc;
    cout << "Enter Price : "; cin >> price;
    cout << "Enter Total Pages: "; cin >> pages;

    //Book book(book_id, name, writer, publisher, category, noc, price, pages);

    /*
    reinterpret cast is a type casting
    used to convert one pointer of another pointer of any type,
    no matter either the class is related to each other or not.
    It does not check if the pointer type and data pointed by the pointer is same or not.
    */
    //outfile.write(reinterpret_cast <char*> (&book), sizeof(book));

    //*
    outfile << book_id << " "
    << setw(15) << name << " "
    << setw(15) << writer << " "
    << setw(20) <<  publisher << " "
    << setw(20) << category << " "
    << setw(10) << noc << " "
    << setw(15) << price << " "
    << setw(10) << pages << "\n" ;
    //*/

//    outfile << book_id
//    << "\t" << name << "\t" << writer << "\t" << publisher << "\t" << category
//    << "\t" << noc << "\t" << price << "\t" << pages << endl;

    outfile.flush();
    outfile.close();

}

void Admin :: updateBook(const string& fileName)
{
    ifstream infile(fileName.c_str());

    string copyFile = "copy.txt";
    ofstream outfile(copyFile.c_str());

    int searchedId;
    bool isFound = false;
    bool isOk = false;

    while(1){
        cout << "Enter Book Id: "; cin >> searchedId; break;
        //if (floor(id) == id) break;
        //else cout << "Enter a valid Id: " << endl;
    }

    string stream;
    int id;

    cout << "\n===========================\n";
    while(infile >> id)
    {
    	getline(infile, stream);
        if (id == searchedId) {
            isFound = 1;
            cout << "Record Found" << endl;

        	drawLine(115, '=');
		    cout << "S.No." << setw(15) << setiosflags(ios::right) << "Book Name" << setw(15) << "Author" << setw(20) <<
            "Publisher" << setw(20) << "Category" << setw(20) << "No. of Copies"
            << setw(10) << "Price" << setw(10) << "Pages" << endl;

            drawLine(115, '=');

            cout << id << setw(10) << "\t" << stream << endl;


            string str;
           // cout << "Enter 1 to Continue and 0 to return... " << endl;
            //cin >> str;
            while(1)
            {
                cout << "Enter 1 to Continue and 0 to return... " << endl;
                cin >> str;
                if (str == "1")
                {
                    isOk == true;
                    break;
                }
                if (str == "0") break;
            }
            if (str == "1")
            {
                addBook(copyFile);
            }

        }
        else
        {
            outfile << stream << endl;
        }
        if (infile.eof()) break;
    }

    infile.close();
    outfile.close();
    if (isFound && isOk)
    {
        remove(fileName.c_str());
        rename(copyFile.c_str(), fileName.c_str());

    }
    if (!isFound) {
        cout << "Sorry, Record not found\n" << endl;
        cout << "\n===========================\n\n";
    }
}

void Admin :: deleteBook(const string& fileName)
{
    ifstream infile(fileName.c_str());

    string copyFile = "copy.txt";
    ofstream outfile(copyFile.c_str());

    int searchedId;
    bool isFound = 0;

    bool isOk = 0;

    while(1){
        cout << "Enter Book Id: "; cin >> searchedId; break;
        //if (floor(id) == id) break;
        //else cout << "Enter a valid Id: " << endl;
    }

    string stream;
    int id;

    cout << "\n===========================" << endl;
    while(infile >> id)
    {
    	getline(infile, stream);
        if (id == searchedId) {
            isFound = 1;
            cout << "Record Found" << endl;

      		drawLine(115, '=');
		    cout << "S.No." << setw(15) << setiosflags(ios::right) << "Book Name" << setw(15) << "Author" << setw(20) <<
            "Publisher" << setw(20) << "Category" << setw(20) << "No. of Copies"
            << setw(10) << "Price" << setw(10) << "Pages" << endl;

            drawLine(115, '=');

            cout << id << "\t" << stream << endl;


            string str;
           // cout << "Enter 1 to Continue and 0 to return... " << endl;
            //cin >> str;
            while(1)
            {
                cout << "Enter 1 to Continue and 0 to return... " << endl;
                cin >> str;
                if (str == "1")
                {
                    isOk = 1;
                    break;
                }
                if (str == "0") break;
            }

        }
        else
        {
            outfile << id << stream << endl;
        }
        if (infile.eof()) break;
    }

    infile.close();
    outfile.close();
    if (isOk)
    {
        remove(fileName.c_str());
        rename(copyFile.c_str(), fileName.c_str());
        cout << "\n\n"; drawLine(30, '=');
        cout << "Deleted..." << endl;
    }
    if (!isFound) {
        cout << "Sorry, Record not found\n" << endl;
        cout << "\n===========================\n\n";
    }
}

 void Admin :: adminPage()
{
	Admin admin;
    writeTitle();
    cout << "\t\t\t\t\t\t\t\tLogged In As : " << admin.getAdmin() << endl;
	cout << " Admin Section:"<< endl;
	drawLine(30, '-');
	cout << "1. Add new Book" << endl;
	cout << "2. List all Book" << endl;
	cout << "3. List Ordered Book" << endl;
	cout << "4. Search Book" << endl;
	cout << "5. Update Book Record" << endl;
	cout << "6. Remove Book" << endl;
	cout << "7. Get Log Report" << endl;
	cout << "8. Exit\n\n" << endl;
	drawLine(30, '-');
	cout << "Select an Option : " ;

}

void Admin :: adminMenu()
{
    Admin a1;
    int choice;
    bool stop = 0;
    string recordFile = "record.txt";
    string orderRecord = "ordered record.txt";

    while(1)
    {
        system("cls");
        adminPage();
        while (1)
        {
            cin >> choice;
            if (choice < 0 || choice > 8)
            {
                cout << "\n\nPlease Enter valid Input" << endl;
               // system("pause");
            }
            else break;

        }//end of while
        switch (choice)
        {
        case 1:
        	{
        		char ch;
	        	bool loop = true;
	            while(loop)
	            {
	        		system("cls");
	        		writeTitle();

	                a1.addBook(recordFile);
	                cout << "\nDo You Want to Add More?(Y/N)\n";
	                cin >> ch;
	                if (ch != 'y' || ch != 'Y') loop = true;
	            }
			}

            break;
        case 2:
        	system("cls");
        	writeTitle();
            a1.listBook(recordFile);
            hold();
            break;
        case 3:
        	system("cls");
        	writeTitle();
            a1.listBook(orderRecord);
            hold();
            break;
        case 4:
        	system("cls");
        	writeTitle();
            a1.searchBook(recordFile);
            hold();
            break;
        case 5:
        	system("cls");
        	writeTitle();
            a1.updateBook(recordFile);
            hold();
            break;
        case 6:
        	system("cls");
        	writeTitle();
            a1.deleteBook(recordFile);
            hold();
            break;
       case 7:
       		system("cls");
    		a1.getLogReport();
    		hold();
    		break;

        case 8:
            cout << "\n\n========================";
            cout << "\nExiting....";
            exit(2);

        }//end of switch
    }//end of while


}

class User : public Book
{
private:
    string userName;
public:
    void userPage();
    void userMenu();
    void placeOrder();

};

void User :: placeOrder()
{
    string recordFile = "record.txt";
    string orderRecord = "ordered record.txt";

    listBook(recordFile.c_str());

    ifstream infile(recordFile.c_str());
    ofstream outfile(orderRecord.c_str());
    string id;

    while(1)
    {
        cout << "\n===========================" << endl;
        cout << "Enter Book Id to order: "; cin >> id;
        cout << "\n=====================================" << endl;
        break;
    }

    string str;
    bool isOrdered = false;

    infile.clear();
    infile.seekg(0, ios::beg);          //returning to beginning of a file

    while(infile)
    {
        getline(infile, str);
        if (str.find(id) != string::npos)
        {

            isOrdered = true;
            cout << "Book Successfully Ordered" << endl;
            cout << "=====================================\n\n";
            cout << str << endl;
            outfile << str << endl;
            _getch();
            break;
        }
       // cout << str << endl;
      //  if (infile.eof()) break;
    }
    if (!isOrdered)
    {
        cout << "Sorry, Book with Book Id = " << id << " is not available" << endl;
        cout << "=====================================\n\n";
        _getch();
    }


    infile.close();
    outfile.close();
}

void User :: userPage()
{
    writeTitle();
	cout << " User Section:\n" << endl;
	cout << "=========================" << endl;
	cout << "1. List all Book" << endl;
	cout << "2. Search Book" << endl;
	cout << "3. Purchase Book" << endl;
	cout << "4. Exit\n\n" << endl;
	cout << "========================" << endl;
	cout << "Select an Option : " ;
}

void User :: userMenu()
{
    int choice;
    bool stop = 0;
    User user;

    string recordFile = "record.txt";
    string orderRecord = "order_record.txt";

    while(1)
    {
        system("cls");
        userPage();
        while (1)
        {
            cin >> choice;
            if (choice < 0 || choice > 7)
            {
                cout << "\n\nPlease Enter valid Input" << endl;
               // system("pause");
            }
            else break;

        }//end of while

        switch (choice)
        {
        case 1:
        	system("cls");
        	writeTitle();
            user.listBook(recordFile);
            hold();
            break;
        case 2:
        	system("cls");
        	writeTitle();
            user.searchBook(recordFile);
            hold();
            break;
        case 3:
        	system("cls");
        	writeTitle();
            user.placeOrder();
            break;
        case 4:
            cout << "\n\n========================";
            cout << "\nExiting....";
            exit(2);
        }
    }
}

class Password
{
private:
    string defaultPsw;
    string psw;
    const char BACKSPACE;
public:
	Password() : defaultPsw("0000"), BACKSPACE(8)
	{ }
    void mask_password()
    {
        char ch;

        cout << "\n==================================" << endl;
        cout << "Enter Password(At least 4 digit): " ;

        for (int i = 0; i < 4; i++)
        {
            ch = _getch();
            if (ch == BACKSPACE)
            {
                cout << "\b \b";
                i-=2;
                psw.erase(psw.size()-1);
                continue;
            }
            psw.push_back(ch);
            _putch('#');
        }
       // cout << "\nYour Password is : " << psw << "\n";

    }

    bool check_password()
    {
        return ((defaultPsw == psw) ? true : false);
    }
    string getPassword()
    {
        return psw;
    }
};


    void login()
    {
        string user;
        ofstream outfile();

        fflush(stdin);
        cout << "Enter User Name: "; getline(cin, user);
        Admin admin;


        //cout << "Enter Password: " ; password.mask_password();

        int time = 0;
            									// Input username
          //  if (account == "blue" && pwd.GetPassword() == "shit") return;					// XD
         //   status = Login(account, pwd.GetPassword());										// Get user's status
                while(1)
                {
                	Password password;
                	fflush(stdin);
                    password.mask_password();
                    password.check_password();
                    if (password.check_password())
                    {
                    	admin.writeToFile(user);
                        cout << "\n==================================" << endl;
                        cout << "Login Successful...." << endl;
                        cout << "\n==================================" << endl;
                        _getch();
                        admin.adminMenu();
                    }
                    else
                        time++;										// Try how many times
                        if (time < 3) cout << "\nOops! Login fail. Please try again.. " << endl;
                        else if (time < 4) cout << "\nAre you sure you remember the password? (Last Attempt)" << endl;

                        else {
                        	cout << endl;
                        	drawLine(50,'=');
                            cout << "\nMaybe you should choose user Mode "<< endl;
							_getch();
                            startPage();
                            break;
                        }

                }


    }



void startPage()
{
    system("cls");
	int choice;

	writeTitle();

	cout << "1. Login as Administrator" << endl;
	cout << "2. Login as User: " << endl;
	cout << "3. Exit" << endl;
	while (1)
    {
        cout << "==========================" << endl;
        cout << "Select an Option: "; cin >> choice;
        if (choice >0 || choice <=2) break;
        cout << "Select Option Carefully" << endl;
    }

    switch (choice)
    {
    case 1:
        {
            login();
        }
        break;
    case 2:
        {
            User usr;
            usr.userMenu();
        }
        break;
    case 3:
        cout << "\n\n========================";
        cout << "\nExiting....";
        exit(2);

    }




}

int main(int argc, char** argv)
{
    startPage();
	return 0;
}

/*
Function Declarations:
-----------------------
*/
void drawLine(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << endl;
}
void writeTitle()
{
    cout << "\n\t\t\t\t BOOK STORE MANAGEMENT SYSTEM\n";
    cout << "\t\t";
    drawLine(70, '=');
    cout << "\n\n" ;
}
