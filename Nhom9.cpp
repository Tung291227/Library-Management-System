#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Person(tính trừu tượng)
class Person
{
protected:
    int id;
    string name;

public:
    virtual void input()
    {
        cout << "ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);
    }

    virtual void displayInfo() = 0;
};

//Reader(tính kế thừa)
class Reader : public Person
{
public:
    void input() override
    {
        Person::input();
    }

    void displayInfo() override
    {
        cout << "\n===== READER =====\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

//LIBRARIAN(tính kế thừa)
class Librarian : public Person
{
private:
    string position;

public:
    void input() override
    {
        Person::input();

        cout << "Position: ";
        getline(cin, position);
    }

    void displayInfo() override
    {
        cout << "\n===== LIBRARIAN =====\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
    }
};

//LIBRARY ITEM(tính trừu tượng)
class LibraryItem
{
protected:
    int itemID;
    string title;

public:
    virtual void input()
    {
        cout << "Item ID: ";
        cin >> itemID;
        cin.ignore();

        cout << "Title: ";
        getline(cin, title);
    }

    virtual void displayInfo() = 0;
};

//BOOK(tính kế thừa)
class Book : public LibraryItem
{
private:
    string author;
    string category;  //tính đóng gói
    bool available;

public:
    Book()
    {
        available = true;
    }

    void input() override
    {
        LibraryItem::input();

        cout << "Author: ";
        getline(cin, author);

        cout << "Category: ";
        getline(cin, category);
    }

    void displayInfo() override
    {
        cout << "\n===== BOOK =====\n";
        cout << "ID: " << itemID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Category: " << category << endl;
        cout << "Status: "
             << (available ? "Available" : "Borrowed")
             << endl;
    }

    void borrowBook()
    {
        available = false;
    }

    void returnBook()
    {
        available = true;
    }
};

//MAGAZINE(tính kế thừa)
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    void input() override
    {
        LibraryItem::input();

        cout << "Issue Number: ";
        cin >> issueNumber;
        cin.ignore();
    }

    void displayInfo() override
    {
        cout << "\n===== MAGAZINE =====\n";
        cout << "ID: " << itemID << endl;
        cout << "Title: " << title << endl;
        cout << "Issue Number: " << issueNumber << endl;
    }
};

//MAIN
int main()
{
    
    Reader reader;
    Librarian librarian;

    Book book;
    Magazine magazine;

    cout << "READER INPUT:" << endl;
    reader.input();

    cout << "LIBRARIAN INPUT:" << endl;
    librarian.input();

    cout << "BOOK INPUT:" << endl;
    book.input();

    cout << "MAGAZINE INPUT:" << endl;
    magazine.input();
    cout << "\n INFORMATION" << endl;
    vector<LibraryItem*> items; //tính đa hình
    items.push_back(&book);
    items.push_back(&magazine);
    for (LibraryItem* item : items)
{
    item->displayInfo();
}

    reader.displayInfo();
    librarian.displayInfo();

    return 0;
}
