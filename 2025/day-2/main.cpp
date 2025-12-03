#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;

  while (!cin.eof()) {
    int range_begin;
    int range_end;

    getline(cin, s, '-');
    range_begin = stoi(s);
    getline(cin, s, ',');
    range_end = stoi(s);

    cout << range_begin << " - " << range_end << endl;
  }

  return 0;
}
