#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
public:
    const string name; 
    vector<MenuItem> menu; 
    vector<string> orders; 
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}

    string addOrder(const string& itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled!";
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0.0;
        for (const auto& itemName : orders) {
            for (const auto& item : menu) {
                if (item.name == itemName) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menu.empty()) {
            return "";
        }
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        MenuItem("Espresso", "drink", 3.50),
        MenuItem("Latte", "drink", 4.00),
        MenuItem("Croissant", "food", 2.50),
        MenuItem("Sandwich", "food", 5.00)
    };

    CoffeeShop shop("Java Junction", menu);

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Croissant") << endl;
    cout << shop.addOrder("Cappuccino") << endl; // Unavailable item

    cout << "Orders: ";
    for (const auto& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food: ";
    for (const auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}