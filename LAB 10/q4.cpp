#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SimpleLogger {
private:
string filename;
int fileNumber;
size_t currentSize;
const size_t MAX_SIZE = 1048576;

void createNewFile() {
    fileNumber++;
    filename = "log" + to_string(fileNumber) + ".txt";
    currentSize = 0;
    ofstream file(filename);
    file.close();
    cout << "Created new log file: " << filename << endl;
}
public:
SimpleLogger() : fileNumber(1), currentSize(0) {
filename = "log1.txt";
ofstream file(filename);
file.close();
cout << "Initial log file created: " << filename << endl;
}

void log(const string& message) {
    if (currentSize > MAX_SIZE) {
        cout << "File size exceeded 1MB (" << currentSize << " bytes)" << endl;
        createNewFile();
    }

    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << message << endl;
        currentSize += message.size() + 1;
        file.close();
        cout << "Logged message (" << currentSize << "/" << MAX_SIZE << " bytes)" << endl;
    }
}
};

int main() {
SimpleLogger logger;

string sampleMessage(10000, 'x');

for (int i = 1; i <= 150; i++) {
    logger.log("Message " + to_string(i) + ": " + sampleMessage);
}

cout << "Finished logging. Check the log files in your directory." << endl;
return 0;
}