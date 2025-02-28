#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string name;
    string isbn;

public:
    Book(string name, string isbn) : name(name), isbn(isbn) {}

    string getIsbn() const {
        return isbn;
    }

    string getName() const {
        return name;
    }
};

class Catalog {
private:
    vector<string> isbns;

public:
    Catalog() {
        cout << "Catalog created." << endl;
    }

    ~Catalog() {
        cout << "Catalog destroyed." << endl;
    }

    void addBook(const string& isbn) {
        isbns.push_back(isbn);
    }

    bool findBook(const string& isbn) const {
        for (int i = 0; i < isbns.size(); ++i) {
            if (isbns[i] == isbn) {
                return true;
            }
        }
        return false;
    }
};

class Library {
private:
    string name;
    Catalog catalog;
    vector<Book*> books;

public:
    Library(string name) : name(name) {
        cout << "Library " << name << " created." << endl;
    }

    ~Library() {
        for (int i = 0; i < books.size(); ++i) {
            delete books[i];
        }
        cout << "Library " << name << " destroyed." << endl;
    }

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addBook(book->getIsbn());
    }

    void removeBook(const string& isbn) {
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->getIsbn() == isbn) {
                delete books[i];
                books.erase(books.begin() + i);
                cout << "Book with ISBN " << isbn << " removed." << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }

    void findBookInCatalog(const string& isbn) const {
        if (catalog.findBook(isbn)) {
            cout << "Book with ISBN " << isbn << " found in the catalog." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in the catalog." << endl;
        }
    }
};

int main() {
    Library library("Central Library");

    Book* book1 = new Book("The Character", "10011-1111");
    Book* book2 = new Book("Lion King", "37372-82819");
    Book* book3 = new Book("Titanic", "72271-9439290");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.findBookInCatalog("37372-82819");
    library.findBookInCatalog("99999-99999");

    library.removeBook("72271-9439290");

    library.findBookInCatalog("72271-9439290");

    return 0;
}