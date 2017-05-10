//https://www.reddit.com/r/dailyprogrammer/comments/4m3ddb/20160601_challenge_269_intermediate_mirror/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void decrypt(string encrypted, char grid[15][15]) {
//    for (int i = 0; i < 15; i++) {
//        for (int j = 0; j < 15; j++) {
//            cout << grid[i][j];
//        }
//        cout << endl;
//    }
    stringstream ss;
    for (int index = 0; index < encrypted.length(); index++) {
        int i;
        int j;
        int di = 0;
        int dj = 0;
        int c = encrypted.at(index);
        if (c < 96) {
            //upper case
            if (c <= 13 + 64) {
                i = c - 64;
                j = 0;
                dj++;
            } else {
                i = 14;
                j = c - 64 - 13;
                di--;
            }
        } else {
            //lower case
            if (c <= 13 + 96) {
                i = 0;
                j = c - 96;
                di++;
            } else {
                i = c - 96 - 13;
                j = 14;
                dj--;
            }
        }
        do {
            i += di;
            j += dj;
            if (grid[i][j] == '/') {
                int temp = di;
                di = -dj;
                dj = -temp;
            } else if (grid[i][j] == '\\') {
                int temp = di;
                di = dj;
                dj = temp;
            }
        } while (i != 0 && i != 14 && j != 0 && j != 14);
        ss << grid[i][j];
    }
    cout << ss.str() << endl;
}

int main() {
    char grid[15][15];
    for(int i = 1; i < 14; i++) {
        grid[0][i] = i + 96;
        grid[i][14] = i + 96 + 13;
        grid[i][0] = i + 64;
        grid[14][i] = i + 64 + 13;
    }
    string encrypted;
    ifstream myfile("input.txt");
    if (myfile.is_open()) {
        string line;
        for (int i = 1; i < 14; i++) {
            getline(myfile, line);
            stringstream ss(line);
            ss >> noskipws;
            for (int j = 1; j < 14; j++) {
                ss >> grid[i][j];
            }
        }
        getline(myfile, encrypted);
        decrypt(encrypted, grid);
    }
    myfile.close();
    while (true) {
        getline(cin, encrypted);
        decrypt(encrypted, grid);
    }
}
