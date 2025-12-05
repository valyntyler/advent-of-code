#include <bits/stdc++.h>
#include <iterator>

using namespace std;
using ll = long long;

struct range {
  ll begin;
  ll end;

  void print() { cout << this->begin << " - " << this->end << endl; }
  bool contains(ll point) { return point >= this->begin && point <= this->end; }

  bool intersects(range r) {
    return this->contains(r.begin) || this->contains(r.end);
  }

  range range_union(range r) {
    return range{min(this->begin, r.begin), max(this->end, r.end)};
  }

  void absorb(vector<range> &ranges) {
    for (int i = 0; i < ranges.size(); i++) {
      range r = ranges[i];
      if (this->intersects(r)) {
        *this = this->range_union(r);
        ranges.erase(ranges.begin() + i);
        this->absorb(ranges);
        break;
      }
    }
  }

  ll size() { return this->end - this->begin + 1; }
};

int main() {
  vector<range> ranges;

  string s;
  getline(cin, s);

  while (s != "") {
    size_t p = s.find('-');
    ll a = stoll(s.substr(0, p));
    ll b = stoll(s.substr(p + 1, s.size()));

    ranges.push_back({a, b});
    getline(cin, s);
  }

  vector<range> merged;
  while (!ranges.empty()) {
    range current = ranges.back();
    ranges.pop_back();
    current.absorb(ranges);
    merged.push_back(current);
  }

  ll total = 0;
  for (range r : merged) {
    r.print();
    total += r.size();
  }

  cout << total << endl;

  return 0;
}
