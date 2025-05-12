#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> cx = {1, 1, 2, 2, -1, -1, -2, -2};
vector<int> cy = {2, -2, 1, -1, 2, -2, 1, -1};

int N;

bool limits(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

bool isempty(const vector<int>& board, int x, int y) {
    return limits(x, y) && board[y * N + x] < 0;
}

int getDegree(const vector<int>& board, int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (isempty(board, x + cx[i], y + cy[i])) {
            count++;
        }
    }
    return count;
}

bool nextMove(vector<int>& board, int& x, int& y) {
    int minDeg = 9;
    int minIdx = -1;
    int nx, ny;

    for (int i = 0; i < 8; ++i) {
        nx = x + cx[i];
        ny = y + cy[i];
        if (isempty(board, nx, ny)) {
            int deg = getDegree(board, nx, ny);
            if (deg < minDeg) {
                minDeg = deg;
                minIdx = i;
            }
        }
    }

    if (minIdx == -1) return false;

    nx = x + cx[minIdx];
    ny = y + cy[minIdx];
    board[ny * N + nx] = board[y * N + x] + 1;
    x = nx;
    y = ny;
    return true;
}

void printBoard(const vector<int>& board) {
    const int cellWidth = 4;

    auto printLine = [](int N, int width, char left, char middle, char right, char fill) {
        cout << left;
        for (int i = 0; i < N - 1; ++i) {
            cout << string(width, fill) << middle;
        }
        cout << string(width, fill) << right << "\n";
    };

    printLine(N, cellWidth, '+', '+', '+', '-');

    for (int i = 0; i < N; ++i) {
        cout << "|";
        for (int j = 0; j < N; ++j) {
            cout << setw(cellWidth) << board[i * N + j] << "|";
        }
        cout << "\n";
        printLine(N, cellWidth, '+', '+', '+', '-');
    }
}

bool isNeighbour(int x, int y, int sx, int sy) {
    for (int i = 0; i < 8; ++i) {
        if ((x + cx[i] == sx) && (y + cy[i] == sy)) {
            return true;
        }
    }
    return false;
}

bool findClosedTourFrom(int sx, int sy) {
    vector<int> board(N * N, -1);
    int x = sx, y = sy;
    board[y * N + x] = 1;

    for (int i = 0; i < N * N - 1; ++i) {
        if (!nextMove(board, x, y)) {
            return false;
        }
    }

    if (!isNeighbour(x, y, sx, sy)) {
        return false;
    }

    cout << "Closed knight's tour found starting at (" << sx << ", " << sy << "):\n";
    printBoard(board);
    return true;
}

int main() {
    cout<<"Enter board size n (n x n): ";
    cin>>N;

    if (N < 1) {
        cout << "Invalid board size.\n";
        return 1;
    }

    for (int sx = 0; sx < N; ++sx) {
        for (int sy = 0; sy < N; ++sy) 
            if (findClosedTourFrom(sx, sy)) {
                return 0;
            }
    }

    cout << "No closed knight's tour found for this board size."<<endl;
    return 0;
}