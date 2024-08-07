/*
Define a class Library with data memberes ISBN, bookTitle, author, and
numberOfCopies. Implement methods to add new books, issue books, return books,
update book details, and delete books. The library's catalob should be maintained in a
file. Specifically, implement the following operations:

1.  Add New Book: Insert a new book's details into the catalog file. Ensure that each book
    has unique ISBN and that duplicate entries are not allowed.
2.  Issue Book: Mark a book as issued by decreasing the number of available copies in the
    catalog file. Ensure that a book cannot be issued if the number of available copies is
    zero.
3.  Return Book: Mark a book as returned by increasing the number of available copies in
    the catalog file.
4.  Update Book Details: Edi the details of a bookk, such as ISBN, bookTitle, author,
    or numberOfCopies, in the catalog file. Ensure that cahnging ISBN does not result in
    duplicates.
5.  Delete Book: Allow the user to delete a book's record from the catalog file only if the
    following conditions are met:
        -   The number of available copies is zero.
        -   The book has not been issued to any user, meaning allcopies have been returned and
            there are no outstanding issues for the book.

Ensure that the number of copies is appropriately updated for each operation and that file
operations maintain data integrity. Provide methods to read from and write to the file for
maintaining the catalog data.
*/

#include<iostream>
#include<cstring>

using namespace std;

class Library{
    double ISBN;
    int numberOfCopies;
    char bookTitle[50], author[30];

    public:
        Library(double isbn, int no, char *title, char *a) : ISBN(isbn), numberOfCopies(no){
            strcpy(bookTitle, title);
            strcpy(author, a);
        }

        void getData(){
            cout << "Enter book ISBN: ";
            cin >> ISBN;
            cout << "Enter book title: ";
            cin.ignore();
            cin.getline(bookTitle, 50);
            cout << "Enter author name: ";
            cin.ignore();
            cin.getline(author, 30);
            cout << "Enter number of copies: ";
            cin >> numberOfCopies;
        }
};

int main(){

}