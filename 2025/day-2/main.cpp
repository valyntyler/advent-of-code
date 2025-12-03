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

bool invalid(ll n, int l) {
  ll x = n;
  int count = digits(n);
  if (count % l != 0) {
    return false;
  }

  count /= l;
  ll p = 1;
  while (count) {
    --count;
    p *= 10;
  }

  ll last = n % p;
  for (ll i = 0; i < l; ++i) {
    bool same = last == n % p;
    if (!same) {
      return false;
    }
    last = n % p;
    n /= p;
  }

  cout << x << endl;
  return true;
}

ll invalid_all(ll i) {
  ll sum;
  int size = digits(i);
  for (ll j = 2; j <= size; ++j) {
    if (invalid(i, j)) {
      return true;
    }
  }
  return false;
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
      if (invalid_all(i)) {
        sum += i;
      }
    }
  }
  cout << sum << endl;

  // cout << invalid_all(7979777777);
  // cout << invalid(7979777777, 6);

  return 0;
}
