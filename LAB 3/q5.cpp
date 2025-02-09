#include <iostream>
#include<string>
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

int main(int argc, char* argv[]) {
    const int SIZE = 5;
    if (argc != SIZE * 4 + 1) {
        return 1;
    }

    Book books[SIZE];

    int index = 1;
    for (int i = 0; i < SIZE; i++) {
        books[i].setTitle(argv[index++]);
        books[i].setISBN(argv[index++]);
        books[i].setAuthor(argv[index++]);
        books[i].setPublisher(argv[index++]);
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
