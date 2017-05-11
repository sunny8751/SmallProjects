#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
typedef vector< vector<bool> > type;

void initGrid(int size, type& grid, double& percentage) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 100000 < 1000*percentage) {
                grid[i][j] = true;
            }
        }
    }
}

int getValue(int size, type& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        return 0;
    }
    if (grid[i][j]) {
        return 1;
    }
    return 0;
}

int countNeighbors(int size, type& grid, int i, int j) {
    int neighbors;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            neighbors += getValue(size, grid, i+di, j+dj);
        }
    }
    return neighbors;
}

int main(int argc, const char* argv[]) {
    int size;
    stringstream(argv[1]) >> size;
    double percentage; // how much to populate grid
    stringstream(argv[2]) >> percentage;
    type lastGrid(size, vector<bool>(size, false));
    initGrid(size, lastGrid, percentage);
    type newGrid = lastGrid;
    bool keepPlaying = true;
    while (keepPlaying) {
        stringstream ss;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = countNeighbors(size, lastGrid, i, j);
                if (lastGrid[i][j] && neighbors < 2) {
                    newGrid[i][j] = false;
                } else if (!lastGrid[i][j] && neighbors == 3) {
                    newGrid[i][j] = true;
                } else if (lastGrid[i][j] && neighbors > 3) {
                    newGrid[i][j] = false;
                }
                if (newGrid[i][j]) {
                    ss << "0";
                } else {
                    ss << " ";
                }
            }
            ss << endl;
        }
        lastGrid = newGrid;
        ss << "______________________________" << endl;
        cout << ss.str();
        this_thread::sleep_for(chrono::nanoseconds(100000000));
    }
}
