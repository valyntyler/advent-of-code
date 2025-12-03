#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(vector<int> v) {
  if (v.size() == 1) {
    cout << v[0] << endl;
    return;
  }
  cout << v[0] << " ";
  vector<int> w(v.begin() + 1, v.end());
  print(w);
}

ll concat(vector<int> v) {
  if (v.size() == 1) {
    return v[0];
  }
  vector<int> w(v.begin() + 1, v.end());
  ll p = pow(10, w.size());
  ll head = v[0];
  ll tail = concat(w);
  return head * p + tail;
}

vector<int> parse_bank(string s) {
  vector<int> v;
  for (auto c : s) {
    v.push_back(c - '0');
  }
  return v;
}

pair<int, size_t> max_in_range(vector<int> v, size_t left, size_t right) {
  int best = 0;
  size_t best_index;
  for (int i = left; i < right; ++i) {
    if (v[i] > best) {
      best = v[i];
      best_index = i;
    }
  }
  return {best, best_index};
}

ll max_joltage(vector<int> bank, int k) {
  vector<int> v;
  size_t left = 0;
  for (int i = k - 1; i >= 0; --i) {
    auto [be, bi] = max_in_range(bank, left, bank.size() - i);
    v.push_back(be);
    left = bi + 1;
  }

  return concat(v);
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
    ll maxv = max_joltage(v, 12);
    cout << s << ": " << maxv << endl;
    sum += maxv;
  }
  cout << sum << endl;

  return 0;
}
