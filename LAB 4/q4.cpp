#include <iostream>
#include <string>

using namespace std;

class Books {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
  
    Books(string a = "", string t = "", double p = 0.0, string pub = "", int s = 0)
        : author(a), title(t), price(p), publisher(pub), stock(s) {}

  
    bool isAvailable(const string& Title, const string& Author) {
        return title == Title && author == Author;
    }

    void processPurchase(int requiredCopies)  {
        if (stock >= requiredCopies) {
            double totalCost = price * requiredCopies;
            cout << "Book is available. Total cost: " << totalCost << endl;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }


    void displayDetails() {
        cout << "Title: " << title <<endl<<"Author: " << author<<endl << "Price: " << price <<endl<<"Publisher: " << publisher<<endl<< "Stock: " << stock << endl;
    }
};

int main() {

    Books inventory[3] = {
        Books("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 20.99, "Bloomsbury", 10),
        Books("George Orwell", "1984", 15.99, "Secker & Warburg", 5),
        Books("Jane Austen", "Pride and Prejudice", 12.99, "T. Egerton", 8),
    };


    string Title, Author;
    cout << "Enter the title of the book: ";
    getline(cin, Title);
    cout << "Enter the author of the book: ";
    getline(cin, Author);

    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (inventory[i].isAvailable(Title, Author)) 
        {
            found = true;
            cout << "Book found!"<<endl<<" Details:" << endl;
            inventory[i].displayDetails();

         
            int requiredCopies;
            cout << "Enter the number of copies required: ";
            cin >> requiredCopies;

            inventory[i].processPurchase(requiredCopies);
            break;
        }
    }

    if (!found) {
        cout << "The book is not available in the inventory." << endl;
    }

    return 0;
}