#include <bits/stdc++.h>

using namespace std;

int height;
int width;

vector<vector<char>> mat;

char get_cell(int x, int y) {
  if (x >= width || y >= height || x < 0 || y < 0) {
    return '.';
  }

  return mat[y][x];
}

bool can_access(int x, int y) {
  auto n = get_cell(x, y - 1);
  auto s = get_cell(x, y + 1);
  auto e = get_cell(x + 1, y);
  auto w = get_cell(x - 1, y);

  auto nw = get_cell(x - 1, y - 1);
  auto sw = get_cell(x - 1, y + 1);
  auto ne = get_cell(x + 1, y - 1);
  auto se = get_cell(x + 1, y + 1);

  auto dirs = {n, s, e, w, nw, sw, ne, se};
  int count = 0;
  for (auto dir : dirs) {
    count += dir == '@' ? 1 : 0;
  }

  return count < 4;
}

int main() {
  int i = 0;
  while (!cin.eof()) {
    mat.push_back({});
    string row;
    getline(cin, row);
    mat[i].resize(row.length());
    int j = 0;
    for (char c : row) {
      mat[i][j] = c;
      ++j;
    }
    ++i;
  }

  mat.pop_back();
  height = mat.size();
  width = mat[0].size();

  cout << width << " : " << height << endl;

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      cout << mat[y][x];
    }
    cout << endl;
  }

  int total = 0;
  int count;
  do {
    cout << endl;
    count = 0;
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        bool good = can_access(x, y) && get_cell(x, y) == '@';
        cout << (good ? 'x' : mat[y][x]);
        if (good) {
          mat[y][x] = '.';
        }
        count += good;
      }
      cout << endl;
    }
    cout << count << endl;
    total += count;
  } while (count != 0);

  cout << total << endl;

  return 0;
}
