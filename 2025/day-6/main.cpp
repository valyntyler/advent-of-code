#include <bits/stdc++.h>
#include <istream>

using namespace std;
using ll = long long;

void print(vector<ll> numbers) {
  for (auto number : numbers) {
    cout << number << " ";
  }
  cout << endl;
}

ll compute(vector<ll> &numbers, bool add) {
  if (numbers.size() == 0) {
    return 0;
  }

  ll total = 0;
  if (!add) {
    total = 1;
  }
  for (auto number : numbers) {
    if (add) {
      total += number;
    } else {
      total *= number;
    }
  }
  cout << (add ? "(+)" : "(*)") << " ";
  print(numbers);
  cout << "total: " << total << endl;
  numbers.clear();
  return total;
}

int main() {
  ll grand;

  vector<string> lines;

  while (!cin.eof()) {
    string line;
    getline(cin, line);
    lines.push_back(line);
  }

  ll total = 0;
  bool add = true;
  vector<ll> numbers;

  for (ll j = 0; j < lines[2].size(); ++j) {
    ll n = 0;
    for (ll i = 0; i < lines.size() - 1; ++i) {
      char c = lines[i][j];
      switch (c) {
      case '*':
        grand += compute(numbers, add);
        add = false;
        break;
      case '+':
        grand += compute(numbers, add);
        add = true;
        break;
      case ' ':
        break;
      }
      if (c >= '0' && c <= '9') {
        int d = c - '0';
        n *= 10;
        n += d;
      }
    }
    if (n != 0) {
      // cout << n << endl;
      numbers.push_back(n);
    }
  }

  grand += compute(numbers, add);
  cout << "grand total: " << grand << endl;

  return 0;
}
