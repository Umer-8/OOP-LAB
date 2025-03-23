#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(const string& title, const string& pubDate, const string& id, const string& pub)
        : title(title), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(const string& title, const string& pubDate, const string& id, const string& pub,
         const string& author, const string& isbn, int pages)
        : Media(title, pubDate, id, pub), author(author), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    string duration;
    string rating;

public:
    DVD(const string& title, const string& pubDate, const string& id, const string& pub,
        const string& director, const string& duration, const string& rating)
        : Media(title, pubDate, id, pub), director(director), duration(duration), rating(rating) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << "\nRating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(const string& title, const string& pubDate, const string& id, const string& pub,
       const string& artist, int tracks, const string& genre)
        : Media(title, pubDate, id, pub), artist(artist), numberOfTracks(tracks), genre(genre) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
    string issueNumber;
    string editor;

public:
    Magazine(const string& title, const string& pubDate, const string& id, const string& pub,
             const string& issueNumber, const string& editor)
        : Media(title, pubDate, id, pub), issueNumber(issueNumber), editor(editor) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\nEditor: " << editor << endl;
    }
};

class Library {
    Media* mediaList[100];
    int size;

public:
    Library(Media* media[], int count) : size(count) {
        for (int i = 0; i < count; ++i) {
            mediaList[i] = media[i];
        }
    }

    void searchMedia(const string& title) const {
        for (int i = 0; i < size; ++i) {
            if (mediaList[i]->getTitle() == title) {
                mediaList[i]->displayInfo();
                return;
            }
        }
        cout << "Media with title \"" << title << "\" not found." << endl;
    }

    void searchMedia(const string& attribute, const string& value) const {
        for (int i = 0; i < size; ++i) {
            if (attribute == "publicationDate" && mediaList[i]->getPublicationDate() == value) {
                mediaList[i]->displayInfo();
                return;
            }
        }
        cout << "Media with " << attribute << " \"" << value << "\" not found." << endl;
    }

    void displayAll() const {
        for (int i = 0; i < size; ++i) {
            mediaList[i]->displayInfo();
            cout << "----------------------------\n";
        }
    }

    ~Library() {
        for (int i = 0; i < size; ++i) {
            delete mediaList[i];
        }
    }
};

int main() {
    Media* mediaItems[] = {
        new Book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180),
        new DVD("Inception", "2010-07-16", "D001", "Warner Bros.", "Christopher Nolan", "148 min", "PG-13"),
        new CD("Thriller", "1982-11-30", "C001", "Epic Records", "Michael Jackson", 9, "Pop"),
        new Magazine("National Geographic", "2021-01-01", "M001", "National Geographic Society", "January 2021", "Susan Goldberg")
    };

    Library library(mediaItems, 4);

    cout << "Displaying all media items in the library:\n";
    library.displayAll();

    cout << "\nSearching for media with title \"Inception\":\n";
    library.searchMedia("Inception");

    cout << "\nSearching for media with publication date \"1982-11-30\":\n";
    library.searchMedia("publicationDate", "1982-11-30");

    return 0;
}