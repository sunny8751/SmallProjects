#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool checkSpelling(string& raw_word, unordered_set<string>& dict, unordered_set<string>& mispelled) {
    string word;
    //remove punctuation
    remove_copy_if(raw_word.begin(), raw_word.end(), back_inserter(word), ptr_fun<int, int>(&ispunct));
    raw_word = word;
    //to lower case
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (dict.find(word) == dict.end() && mispelled.find(raw_word) == mispelled.end()) {
        //remove last 's'
        if (word.length() >= 2 && word.substr(0, word.length() - 2) == "es") {
            word = word.substr(0, word.length() - 2);
        } else if (word.at(word.length() - 1) == 's') {
            word = word.substr(0, word.length() - 1);
        } else if (word.length() >= 2 && word.substr(word.length() - 2, 2) == "ed") {
            word = word.substr(0, word.length() - 2);
            if (dict.find(word + "e") != dict.end()) {
                return true;
            }
        } else if (word.length() >= 3 && word.substr(word.length() - 3, 3) == "ing") {
            word = word.substr(0, word.length() - 3);
            if (dict.find(word + "e") != dict.end()) {
                return true;
            }
        }
        if (dict.find(word) == dict.end()) {
            cout << raw_word << " is spelled incorrectly." << endl;
            mispelled.insert(raw_word);
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    ifstream myfile("dictionary.txt");
    if (!myfile.is_open()) {
        cout << "dictionary.txt could not be opened" << endl;
        return -1;
    }
    unordered_set<string> dict;
    unordered_set<string> mispelled;
    string key;
    while (!myfile.eof()) {
        getline(myfile, key);
        dict.insert(key);
    }
    myfile.close();

    string line;
    string raw_word;

    //read files in parameters
    for (int i = 1; i < argc; i++) {
        ifstream testfile(argv[i]);
        if (testfile.is_open()) {
            cout << "Reading " << argv[i] << ":\n";
            while (!testfile.eof()) {
                getline(testfile, line);
                stringstream ss(line);
                while (!ss.eof()) {
                    ss >> raw_word;
                    checkSpelling(raw_word, dict, mispelled);
                }
            }
            cout << endl << endl << endl;
        }
        testfile.close();
    }

    while (line != "q") {
        getline(cin, line);
        stringstream ss(line);
        while (!ss.eof()) {
            ss >> raw_word;
            checkSpelling(raw_word, dict, mispelled);
        }
    }
}
