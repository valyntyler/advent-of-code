#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int digits(ll n) {
  int count = 0;
  while (n) {
    n /= 10;
    ++count;
  }
  return count;
}

bool invalid(ll n) {
  int count = digits(n);
  if (count % 2 == 1) {
    return false;
  }

  count /= 2;
  int p = 1;
  while (count) {
    --count;
    p *= 10;
  }

  return n / p == n % p;
}

int main() {
  string s;
  ll sum = 0;

  while (!cin.eof()) {
    ll range_begin;
    ll range_end;

    getline(cin, s, '-');
    range_begin = stoll(s);
    getline(cin, s, ',');
    range_end = stoll(s);

    cout << range_begin << " - " << range_end << endl;
    for (ll i = range_begin; i <= range_end; ++i) {
      if (invalid(i)) {
        sum += i;
      }
    }
  }
  cout << sum << endl;

  return 0;
}
