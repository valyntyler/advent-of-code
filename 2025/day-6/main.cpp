#include <bits/stdc++.h>
#include <sstream>

using namespace std;
using ll = long long;

enum operation { Add, Mul };

vector<vector<ll>> problems;

ll solve_problem(int j, operation op) {
  ll total = 0;
  switch (op) {
  case Add:
    total = 0;
    break;
  case Mul:
    total = 1;
    break;
  }
  for (int i = 0; i < problems.size() - 1; ++i) {
    ll n = problems[i][j];
    switch (op) {
    case Add:
      total += n;
      break;
    case Mul:
      total *= n;
      break;
    }
  }
  return total;
}

int main() {
  ll total;
  ll grand;

  int i = 0;
  while (!cin.eof()) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    int j = 0;

    if (line == "") {
      continue;
    }

    problems.push_back({});
    while (!ss.eof()) {
      string token;
      ss >> token;
      switch (token[0]) {
      case '*':
        problems[i].push_back(solve_problem(j, Mul));
        break;
      case '+':
        problems[i].push_back(solve_problem(j, Add));
        break;
      default:
        problems[i].push_back(stoi(token));
        break;
      }
      ++j;
    }
    ++i;
  }

  for (auto row : problems) {
    for (auto token : row) {
      cout << token << " ";
    }
    cout << endl;
  }

  for (int k = 0; k < problems[0].size(); ++k) {
    grand += problems[problems.size() - 1][k];
  }

  cout << grand << endl;

  return 0;
}
