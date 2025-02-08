#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string isbn;
    string author;
    string publisher;

public:
    void setTitle(string t) {
        title = t;
    }
    void setISBN(string i) {
        isbn = i;
    }
    void setAuthor(string a) {
        author = a;
    }
    void setPublisher(string p) {
        publisher = p;
    }

    string getTitle() {
        return title;
    }
    string getISBN() {
        return isbn;
    }
    string getAuthor() {
        return author;
    }
    string getPublisher() {
        return publisher;
    }
};

int main() {
    const int SIZE = 5;
    Book books[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        string title, isbn, author, publisher;
        cout << "Enter details for Book " << i + 1 << ":\n";
        cout << "Title: ";
        cin >> title;
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Author: ";
        cin >> author;
        cout << "Publisher: ";
        cin >> publisher;

        books[i].setTitle(title);
        books[i].setISBN(isbn);
        books[i].setAuthor(author);
        books[i].setPublisher(publisher);
    }
    
    for (int i = 0; i < SIZE; i++) {
        cout << "\nBook " << i + 1 << " Details:\n";
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "ISBN: " << books[i].getISBN() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Publisher: " << books[i].getPublisher() << endl;
    }
    
    return 0;
}
