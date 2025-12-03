#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> parse_bank(string s) {
  vector<int> v;
  for (auto c : s) {
    v.push_back(c - '0');
  }
  return v;
}

int max_joltage(vector<int> bank) {
  int bba = 0;
  int bbb = 0;
  int bbai;

  for (int i = 0; i < bank.size() - 1; ++i) {
    int batt = bank[i];
    if (batt > bba) {
      bba = batt;
      bbai = i;
    }
  }

  for (int i = bbai + 1; i < bank.size(); ++i) {
    int batt = bank[i];
    if (batt > bbb) {
      bbb = batt;
    }
  }

  // cout << bba << " " << bbb << endl;
  return bba * 10 + bbb;
}

int main() {
  ll sum = 0;
  while (!cin.eof()) {
    string s;
    cin >> s;
    if (s.empty()) {
      break;
    }
    vector<int> v = parse_bank(s);
    ll maxv = max_joltage(v);
    cout << s << ": " << maxv << endl;
    sum += maxv;
  }
  cout << sum << endl;

  return 0;
}
