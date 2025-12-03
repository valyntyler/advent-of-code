#include <bits/stdc++.h>

using namespace std;

enum Direction { left = -1, right = 1 };

pair<Direction, int> parse(string s) {
  Direction dir = s[0] == 'L' ? Direction::left : Direction::right;
  s.erase(0, 1);
  int num = stoi(s);
  return {dir, num};
}

int main() {
  cout << "Hello, world!" << '\n';

  int total = 0;
  int index = 50;

  string s;
  while (cin >> s) {
    auto p = parse(s);
    auto dir = p.first;
    auto num = p.second;

    int offset = num * dir;
    int newidx = index + offset;

    cout << s << ": " << index << " -> ";

    int count = abs(newidx) / 100;
    if (index != 0 && newidx <= 0) {
      ++count;
    }

    // index is always positive
    // num can be a value like 357
    // dir is either 1 or -1
    // so offset can be 357, -768, etc..
    // meaning (index + offset) % 100 will be the final value of index

    index = ((newidx % 100) + 100) % 100;
    total += count;
    cout << newidx << " === " << index << ", +" << count << endl;
  }

  cout << total << endl;

  return 0;
}
