#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encrypt(string& word) {
    int length = word.length();
    string newstring;
    for (int i = 0; i < length; i++) {
        newstring += (char)(word[i] + (i+1));
    }
    return newstring;
}
string decrypt(string& word)
{
    int length = word.length();
    string newstring;
    for (int i = 0; i < length; i++) 
    {
        newstring += (char)(word[i] - (i+1));
    }
    return newstring;
}


int main() {
    string word;
    ofstream file("q1.txt");
    cout << "Enter a string: " << endl;
    getline(cin, word);
    string encrypted= encrypt(word);
    file<<encrypted;

    file.close();

    ifstream file1("q1.txt");
    string word1;
    if(file1.is_open())
    {
        getline(file1, word1);
       file1.close();
       cout<<"Decrypted text:"<<decrypt(word1)<<endl;
    }
    else{
        cout<<"Error opening file."<<endl;
    }

    return 0;
}