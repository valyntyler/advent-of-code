#include <bits/stdc++.h>
#include <istream>

using namespace std;
using ll = long long;

vector<vector<char>> grid;
vector<pair<int, int>> visited;

int start;
int splits = 0;

void print() {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void read() {
  int i = 0;
  while (!cin.eof()) {
    string row;
    getline(cin, row);
    if (row == "") {
      continue;
    }
    int j = 0;
    grid.push_back({});
    for (char c : row) {
      grid[i].push_back(c);
      if (c == 'S') {
        start = j;
      }
      j++;
    }
    i++;
  }
}

void process(int x, int y) {
  for (int j : {x - 1, x + 1}) {
    for (int i = y + 1; i < grid.size(); i++) {
      if (grid[i][j] == '^') {
        pair<int, int> coords = {j, i};
        int visits = count(visited.begin(), visited.end(), coords);
        if (visits == 0) {
          // cout << "[" << j << "," << i << "]" << endl;
          ++splits;
          process(j, i);
          visited.push_back(coords);
        }
        break;
      }
    }
  }
}

int main() {
  read();
  print();
  process(start, 0);
  for (auto val : visited) {
    int x = val.first;
    int y = val.second;
    grid[y][x] = 'x';
  }
  print();
  cout << "splits: " << splits + 1 << endl;
  return 0;
}
