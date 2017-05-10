//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <locale>

using namespace std;

void doWord(string word, map<string, string> table) {
    int length = word.length();
    int index = 0;
    locale loc;
    ostringstream ss;
    string match;
    while (index < length) {
        word = word.substr(0, index) + toupper(word.at(index), loc) + word.substr(index+1, length-index-1);
        if (index < length - 1) {
            match = table[word.substr(index, 2)];
        }
        if (match == "") {
            match = table[word.substr(index, 1)];
            index++;
        } else {
            index+=2;
        }
        ss << match << " ";
        match = "";
    }
    cout << word << " (" << ss.str().substr(0, ss.str().length() - 1) << ")" << endl;
}

int main() {
    map<string, string> table;
    string line;
    string element;
    string symbol;
    ifstream myFile("periodicTable.txt");
    locale loc;
    if (myFile.is_open()) {
        //header line
        getline(myFile, line);
        while(getline(myFile, line)) {
            istringstream ss(line);
            ss >> element >> symbol;
            table[symbol] = tolower(element.at(0), loc) + element.substr(1, element.length() - 1);
        }
    }
    myFile.close();

    string input;
    while (input != "quit") {
        getline(cin, input);
        doWord(input, table);
    }
}
