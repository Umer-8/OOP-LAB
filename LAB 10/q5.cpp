#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> tasks;

void saveToFile() {
    ofstream file("todo.txt");
    for (string task : tasks) {
        file << task << endl;
    }
}

void loadFromFile() {
    ifstream file("todo.txt");
    string task;
    while (getline(file, task)) {
        if (!task.empty()) {
            tasks.push_back(task);
        }
    }
}

void showTasks() {
    
    for (int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". " << tasks[i] << endl;
    }
}

int main() {
    loadFromFile();
    
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\nChoose: ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            cout << "Enter task: ";
            string task;
            getline(cin, task);
            tasks.push_back(task);
            saveToFile();
        }
        else if (choice == 2) {
            showTasks();
        }
        else if (choice == 3) {
            showTasks();
            cout << "Enter task number to remove: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks.erase(tasks.begin() + num - 1);
                saveToFile();
            }
        }
        else if (choice == 4) {
            break;
        }
    }
    
    return 0;
}