#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    string title, author, dueDate;
    bool isCheckedOut;

public:
    LibraryItem(string t, string a) : title(t), author(a), dueDate(""), isCheckedOut(false)
    {}
    virtual ~LibraryItem()
    {}
    
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getDueDate()
    {
        return dueDate;
    }
    bool getIsCheckedOut()
    {
        return isCheckedOut;
    }
    void setTitle(string newTitle)
    {
        title = newTitle;
    }
    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }
    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }
    void setIsCheckedOut(bool status)
    {
        isCheckedOut = status;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;
    virtual string getItemType() = 0;
};

class Book : public LibraryItem
{
private:
    string isbn;
    int pageCount;

public:
    Book(string title, string author, string isbn, int pages) : LibraryItem(title, author), isbn(isbn), pageCount(pages)
    {
        if (pages <= 0 || (isbn.length() != 10 && isbn.length() != 13)) 
            throw "Invalid book data";
    }

    void checkOut() override
    {
        if (getIsCheckedOut()) throw "Book already checked out";
        setIsCheckedOut(true);
        setDueDate("2024-01-15");
        cout << "Book '" << getTitle() << "' checked out!" << endl;
    }

    void returnItem() override
    {
        if (!getIsCheckedOut()) throw "Book not checked out";
        setIsCheckedOut(false);
        setDueDate("");
        cout << "Book '" << getTitle() << "' returned!" << endl;
    }

    void displayDetails() override
    {
        cout << "\nBOOK: " << getTitle() << " by " << getAuthor() 
             << "\nISBN: " << isbn << " | Pages: " << pageCount
             << "\nStatus: " << (getIsCheckedOut() ? "Checked Out" : "Available");
        if (getIsCheckedOut()) cout << " | Due: " << getDueDate();
        cout << "\n" << endl;
    }

    string getItemType() override
    {
        return "Book";
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    string genre;

public:
    DVD(string title, string director, int duration, string genre) : LibraryItem(title, director), duration(duration), genre(genre)
    {
        if (duration <= 0) throw "Invalid duration";
    }

    void checkOut() override
    {
        if (getIsCheckedOut()) throw "DVD already checked out";
        setIsCheckedOut(true);
        setDueDate("2024-01-10");
        cout << "DVD '" << getTitle() << "' checked out!" << endl;
    }

    void returnItem() override
    {
        if (!getIsCheckedOut()) throw "DVD not checked out";
        setIsCheckedOut(false);
        setDueDate("");
        cout << "DVD '" << getTitle() << "' returned!" << endl;
    }

    void displayDetails() override
    {
        cout << "\nDVD: " << getTitle() << " by " << getAuthor()
             << "\nDuration: " << duration << " min | Genre: " << genre
             << "\nStatus: " << (getIsCheckedOut() ? "Checked Out" : "Available");
        if (getIsCheckedOut()) cout << " | Due: " << getDueDate();
        cout << "\n" << endl;
    }

    string getItemType() override
    {
        return "DVD";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;
    string publicationDate;

public:
    Magazine(string title, string publisher, int issue, string pubDate) : LibraryItem(title, publisher), issueNumber(issue), publicationDate(pubDate)
    {
        if (issue <= 0) throw "Invalid issue number";
    }

    void checkOut() override
    {
        if (getIsCheckedOut()) throw "Magazine already checked out";
        setIsCheckedOut(true);
        setDueDate("2024-01-07");
        cout << "Magazine '" << getTitle() << "' checked out!" << endl;
    }

    void returnItem() override
    {
        if (!getIsCheckedOut()) throw "Magazine not checked out";
        setIsCheckedOut(false);
        setDueDate("");
        cout << "Magazine '" << getTitle() << "' returned!" << endl;
    }

    void displayDetails() override
    {
        cout << "\nMAGAZINE: " << getTitle() << " by " << getAuthor()
             << "\nIssue: " << issueNumber << " | Date: " << publicationDate
             << "\nStatus: " << (getIsCheckedOut() ? "Checked Out" : "Available");
        if (getIsCheckedOut()) cout << " | Due: " << getDueDate();
        cout << "\n" << endl;
    }

    string getItemType() override
    {
        return "Magazine";
    }
};

class LibraryManagementSystem
{
private:
    static const int MAX_ITEMS = 50;
    LibraryItem* items[MAX_ITEMS];
    int count;

public:
    LibraryManagementSystem() : count(0)
    {
        for (int i = 0; i < MAX_ITEMS; i++) items[i] = nullptr;
    }

    ~LibraryManagementSystem()
    {
        for (int i = 0; i < count; i++) delete items[i];
    }

    void addItem(LibraryItem* item)
    {
        if (count >= MAX_ITEMS) throw "Library full";
        items[count++] = item;
        cout << "Item added successfully!" << endl;
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "No items in library." << endl; return;
        }
        cout << "\n=== LIBRARY CATALOG ===" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Item " << (i + 1) << ":";
            items[i]->displayDetails();
        }
    }

    void searchByTitle(string title)
    {
        bool found = false;
        cout << "\n=== SEARCH RESULTS ===" << endl;
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getTitle().find(title) != string::npos)
            {
                items[i]->displayDetails();
                found = true;
            }
        }
        if (!found) cout << "No items found with title: " << title << endl;
    }

    void checkOutItem(string title)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getTitle() == title)
            {
                items[i]->checkOut();
                return;
            }
        }
        throw "Item not found";
    }

    void returnItem(string title)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getTitle() == title)
            {
                items[i]->returnItem();
                return;
            }
        }
        throw "Item not found";
    }

    void demonstratePolymorphism()
    {
        cout << "\nPOLYMORPHISM DEMONSTRATION" << endl << endl;
        cout << "Calling virtual methods on different object types:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Processing " << items[i]->getItemType() << ": " << items[i]->getTitle()
                 << " | Status: " << (items[i]->getIsCheckedOut() ? "Checked Out" : "Available") << endl;
        }
    }
};

void displayMenu()
{
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add DVD" << endl; 
    cout << "3. Add Magazine" << endl;
    cout << "4. Display All Items" << endl;
    cout << "5. Search by Title" << endl;
    cout << "6. Check Out Item" << endl;
    cout << "7. Return Item" << endl;
    cout << "8. Polymorphism Demo" << endl;
    cout << "9. Exit" << endl << endl;
    cout << "Enter choice (1-9): ";
}

void clearInput()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

int main()
{
    LibraryManagementSystem lms;
    int choice;
    string title, author, isbn, genre, publisher, pubDate;
    int pages, duration, issue;

    try
    {
        lms.addItem(new Book("The Great Khali", "Khali Pehalwan", "1234567890", 180));
        lms.addItem(new DVD("The Sultan", "Sultan Pehalwan", 136, "Drama"));
        lms.addItem(new Magazine("19 Seconds", "Anshul Jubli", 45, "December 2023"));
    }
    catch (const char* e)
    {
        cout << "Error loading sample data: " << e << endl;
    }

    while (true)
    {
        try
        {
            displayMenu();
            cin >> choice;

            if (cin.fail())
            {
                clearInput();
                throw "Invalid input - please enter a number";
            }

            switch (choice)
            {
                case 1:
                    cout << "Enter book title: "; clearInput(); getline(cin, title);
                    cout << "Enter author: "; getline(cin, author);
                    cout << "Enter ISBN (10 or 13 digits): "; getline(cin, isbn);
                    cout << "Enter page count: "; cin >> pages;
                    lms.addItem(new Book(title, author, isbn, pages));
                    break;

                case 2:
                    cout << "Enter DVD title: "; clearInput(); getline(cin, title);
                    cout << "Enter director: "; getline(cin, author);
                    cout << "Enter duration (minutes): "; cin >> duration;
                    cout << "Enter genre: "; clearInput(); getline(cin, genre);
                    lms.addItem(new DVD(title, author, duration, genre));
                    break;

                case 3:
                    cout << "Enter magazine title: "; clearInput(); getline(cin, title);
                    cout << "Enter publisher: "; getline(cin, publisher);
                    cout << "Enter issue number: "; cin >> issue;
                    cout << "Enter publication date: "; clearInput(); getline(cin, pubDate);
                    lms.addItem(new Magazine(title, publisher, issue, pubDate));
                    break;

                case 4:
                    lms.displayAll();
                    break;

                case 5:
                    cout << "Enter title to search: "; clearInput(); getline(cin, title);
                    lms.searchByTitle(title);
                    break;

                case 6:
                    cout << "Enter exact title to check out: "; clearInput(); getline(cin, title);
                    lms.checkOutItem(title);
                    break;

                case 7:
                    lms.returnItem(title);
                    break;

                case 8:
                    lms.demonstratePolymorphism();
                    break;

                case 9:
                    cout << "Session has ended." << endl;
                    return 0;

                default:
                    throw "Invalid choice - please select 1-9";
            }

        }
        catch (const char* e)
        {
            cout << "Error: " << e << endl;
        }

        cout << "\nPress Enter to continue...";
        clearInput();
        cin.get();
    }

    return 0;
}