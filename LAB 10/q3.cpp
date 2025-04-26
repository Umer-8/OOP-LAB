#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class SimpleDB {
private:
    string usersFile = "users.txt";
    string productsFile = "products.txt";
    string ordersFile = "orders.txt";

    void appendToFile(string filename, string data) {
        ofstream file(filename, ios::app);
        file << data << endl;
        file.close();
    }

    vector<string> readFile(string filename) {
        vector<string> lines;
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) lines.push_back(line);
        }
        file.close();
        return lines;
    }

    void rewriteFile(string filename, vector<string> lines) {
        ofstream file(filename);
        for (string line : lines) {
            file << line << endl;
        }
        file.close();
    }

public:
    void addUser(string firstName, string lastName, string address, string email) {
        string data = firstName + "," + lastName + "," + address + "," + email;
        appendToFile(usersFile, data);
    }

    void addProduct(string name, string description, int price) {
        string data = name + "," + description + "," + to_string(price);
        appendToFile(productsFile, data);
    }

    void addOrder(string userEmail, string productName, int total) {
        string data = userEmail + "," + productName + "," + to_string(total);
        appendToFile(ordersFile, data);
    }

    vector<string> getProductsForUser(string firstName) {
        vector<string> products;
        vector<string> userLines = readFile(usersFile);
        vector<string> productLines = readFile(productsFile);
        vector<string> orderLines = readFile(ordersFile);

        for (string order : orderLines) {
            size_t pos1 = order.find(',');
            size_t pos2 = order.find(',', pos1+1);
            string userEmail = order.substr(0, pos1);
            string productName = order.substr(pos1+1, pos2-pos1-1);

            for (string user : userLines) {
                size_t uPos = user.find(',');
                string userFirst = user.substr(0, uPos);
                string email = user.substr(user.rfind(',')+1);

                if (userFirst == firstName && email == userEmail) {
                    for (string product : productLines) {
                        string pName = product.substr(0, product.find(','));
                        if (pName == productName) {
                            products.push_back(productName);
                        }
                    }
                }
            }
        }
        return products;
    }
};

int main() {
    SimpleDB db;

    db.addUser("Linus", "Torvalds", "Linux Lane", "linus@linux.com");
    db.addUser("Bill", "Gates", "Microsoft Way", "bill@microsoft.com");
    
    db.addProduct("Linux OS", "Open source OS", 0);
    db.addProduct("Windows", "Proprietary OS", 199);
    db.addProduct("MacOS", "Apple OS", 299);
    
    db.addOrder("linus@linux.com", "Linux OS", 0);
    db.addOrder("linus@linux.com", "Linux OS", 0);

    vector<string> linusProducts = db.getProductsForUser("Linus");
    
    cout << "Products ordered by Linus:\n";
    for (string product : linusProducts) {
        cout << "- " << product << endl;
    }

    return 0;
}