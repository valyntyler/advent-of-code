#include <bits/stdc++.h>
#include <istream>

using namespace std;
using ll = long long;

vector<vector<char>> grid;
vector<pair<int, int>> visited;
map<pair<int, int>, ll> cached_timelines;

int start;

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

ll process(int x, int y) {
  pair<int, int> coords = {x, y};
  auto visits = count(visited.begin(), visited.end(), coords);
  if (visits) {
    cout << "[" << x << ",";
    cout << " " << y << "]";
    cout << ": " << cached_timelines[coords] << endl;
    return cached_timelines[coords];
  }

  ll timelines = 0;
  for (int j : {x - 1, x + 1}) {
    int i;
    for (i = y + 1; i < grid.size(); i++) {
      if (grid[i][j] == '^') {
        timelines += process(j, i);
        break;
      }
    }
    if (i == grid.size()) {
      ++timelines;
    }
  }

  // cout << "[" << x << ",";
  // cout << " " << y << "]";
  // cout << ": " << timelines << endl;

  visited.push_back(coords);
  cached_timelines[coords] = timelines;

  return timelines;
}

int main() {
  read();
  print();
  ll timelines = process(start, 0);
  cout << "timelines: " << timelines << endl;

  // for (auto item : cached_timelines) {
  //   cout << "[" << item.first.first << ",";
  //   cout << " " << item.first.second << "]";
  //   cout << ": " << item.second << endl;
  // }

  return 0;
}
