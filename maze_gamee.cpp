//Maze game............
#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][3], int row, int col, vector<vector<bool>>& visited) {
    return (newx >= 0 && newx < row) &&
           (newy >= 0 && newy < col) &&
           maze[newx][newy] == 1 &&
           !visited[newx][newy];
}

void printAllPath(int maze[][3], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited) {
    if (srcx == row - 1 && srcy == col - 1) {
        cout << output << endl;
        return;
    }

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // RIGHT
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // LEFT
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main() {
    int maze[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1},
    };
    int row = 3;
    int col = 3;

    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    if (maze[0][0] == 0) {
        cout << "No Path Exists" << endl;
    }
    else {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
  }
    return 0;
}
