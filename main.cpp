#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << "Hello, world!" << '\n';

  int index = 50;
  int count = 0;

  string s;
  while (cin >> s) {
    int dir = s[0] == 'L' ? -1 : 1;
    s.erase(0, 1);
    int num = stoi(s);

    index += num * dir;
    index = (index + 100) % 100;

    if (index == 0) {
      count += 1;
    }
  }

  cout << count << endl;

  return 0;
}
