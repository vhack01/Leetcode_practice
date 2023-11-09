#include <bits/stdc++.h>
using namespace std;
struct Book
{
    int id;
    string title;
    string author;
    bool available;
};
void addBook(Book books[], int &count)
{
    if (count >= 100)
    {
        cout << "The library is full. Cannot add more books." << endl;
        return;
    }
    Book newBook;
    cout << "Enter the book ID: ";
    cin >> newBook.id;
    cout << "Enter the book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter the book author: ";
    getline(cin, newBook.author);
    newBook.available = true;
    books[count++] = newBook;
    cout << "Book added successfully." << endl;
}
void searchByTitle(const Book books[], int count)
{
    string searchTitle;
    cout << "Enter the title of the book to search for: ";
    cin.ignore();
    getline(cin, searchTitle);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].title == searchTitle)
        {
            cout << "Book found!" << endl;
            cout << "Book ID: " << books[i].id << endl;
            cout << "Book Title: " << books[i].title << endl;
            cout << "Book Author: " << books[i].author << endl;
            cout << "Availability: " << (books[i].available ? "Available" : "Issued") << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
void searchByID(const Book books[], int count)
{
    int searchID;
    cout << "Enter the ID of the book to search for: ";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].id == searchID)
        {
            cout << "Book found!" << endl;
            cout << "Book ID: " << books[i].id << endl;
            cout << "Book Title: " << books[i].title << endl;
            cout << "Book Author: " << books[i].author << endl;
            cout << "Availability: " << (books[i].available ? "Available" : "Issued") << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
void issueBook(Book books[], int count)
{
    int bookID;
    cout << "Enter the ID of the book to issue: ";
    cin >> bookID;
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].id == bookID)
        {
            if (books[i].available)
            {
                books[i].available = false;
                cout << "Book issued successfully." << endl;
            }
            else
            {
                cout << "Book is already issued." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
void returnBook(Book books[], int count)
{
    int bookID;
    cout << "Enter the ID of the book to return: ";
    cin >> bookID;
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].id == bookID)
        {
            if (!books[i].available)
            {
                books[i].available = true;
                cout << "Book returned successfully." << endl;
            }
            else
            {
                cout << "Book is already available." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
void listBooks(const Book books[], int count)
{
    if (count == 0)
    {
        cout << "No books in the library." << endl;
        return;
    }
    cout << "Listing all books:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Book ID: " << books[i].id << endl;
        cout << "Book Title: " << books[i].title << endl;
        cout << "Book Author: " << books[i].author << endl;
        cout << "Availability: " << (books[i].available ? "Available" : "Issued") << endl;
        cout << endl;
    }
}
void deleteBook(Book books[], int &count)
{
    int bookID;
    cout << "Enter the ID of the book to delete: ";
    cin >> bookID;
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].id == bookID)
        {
            // Move the last book to the current position to "delete" the book
            books[i] = books[count - 1];
            count--;
            cout << "Book deleted successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
int main()
{
    Book books[100];
    int count = 0;
    int choice;
    do
    {
        cout << "Library Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add a New Book" << endl;
        cout << "2. Search for a Book by Title" << endl;
        cout << "3. Search for a Book by ID" << endl;
        cout << "4. Issue a Book" << endl;
        cout << "5. Return a Book" << endl;
        cout << "6. List All Books" << endl;
        cout << "7. Delete a Book" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addBook(books, count);
            break;
        case 2:
            searchByTitle(books, count);
            break;
        case 3:
            searchByID(books, count);
            break;
        case 4:
            issueBook(books, count);
            break;
        case 5:
            returnBook(books, count);
            break;
        case 6:
            listBooks(books, count);
            break;
        case 7:
            deleteBook(books, count);
            break;
        case 8:
            cout << "Invalid" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}