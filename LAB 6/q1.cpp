#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Books {
protected:
    string genre;

public:
    Books(string g) : genre(g) {}

    void display() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;

public:
    Novel( string t, string a)
        : Books("Novel"), title(t), author(a) {}

    void display() {
        Books::display();
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;

public:
    Mystery( string t,  string a)
        : Books("Mystery"), title(t), author(a) {}

    void display() {
        Books::display();
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    vector<Novel> novels;
    vector<Mystery> mysteries;

    int numBooks;
    cout << "How many books do you want to add? ";
    cin >> numBooks;

    for (int i = 0; i < numBooks; i++) {
        string genre, title, author;

        cout << "Enter details for book " << i + 1 << ":" << endl;

        cout << "Genre (Novel/Mystery): ";
        cin >> genre;

        cout << "Title: ";
        cin >> title;

        cout << "Author: ";
        cin >> author;

        if (genre == "Novel") {
            novels.push_back(Novel(title, author));
        } else if (genre == "Mystery") {
            mysteries.push_back(Mystery(title, author));
        } else {
            cout << "Invalid genre! Skipping this book." << endl;
        }
    }

    cout << "Novels in the library:" << endl;
    for (size_t i = 0; i < novels.size(); i++) {
        novels[i].display();
    }

    cout << "Mysteries in the library:" << endl;
    for (size_t i = 0; i < mysteries.size(); i++) {
        mysteries[i].display();
    }

    return 0;
}