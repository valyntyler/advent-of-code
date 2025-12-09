#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct vector3 {
  ll x;
  ll y;
  ll z;

  ll dist(vector3 other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) +
                pow(z - other.z, 2));
  }

  void print() {
    cout << x << " ";
    cout << y << " ";
    cout << z << " ";
    cout << endl;
  }
};

vector<vector3> read_junctions() {
  vector<vector3> junctions;
  while (!cin.eof()) {
    string s;
    getline(cin, s);
    if (s == "") {
      break;
    }
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    vector3 junc;
    ss >> junc.x;
    ss >> junc.y;
    ss >> junc.z;
    junctions.push_back(junc);
  }
  return junctions;
}

map<pair<size_t, size_t>, ll> compute_distances(vector<vector3> junctions) {
  map<pair<size_t, size_t>, ll> distances;
  for (int i = 0; i < junctions.size(); ++i) {
    for (int j = i + 1; j < junctions.size(); ++j) {
      distances[{i, j}] = junctions[i].dist(junctions[j]);
    }
  }
  return distances;
}

int main() {
  vector<vector3> junctions = read_junctions();

  // for (auto elem : junctions) {
  //   elem.print();
  // }

  map<pair<size_t, size_t>, ll> distances = compute_distances(junctions);

  vector<pair<ll, pair<size_t, size_t>>> distances_swapped;
  for (auto d : distances) {
    distances_swapped.push_back({d.second, d.first});
  }

  sort(distances_swapped.begin(), distances_swapped.end());

  int k = 10;
  vector<vector<size_t>> components;
  vector<size_t> visited;

  for (auto d : distances_swapped) {
    if (k == 0) {
      break;
    }

    auto edge = d.second;
    for (auto comp : components) {
      if (count(comp.begin(), comp.end(), edge.first)) {
      }
      if (count(comp.begin(), comp.end(), edge.second)) {
      }
    }

    visited.push_back(edge.first);
    visited.push_back(edge.second);

    cout << "[" << edge.first << ", " << edge.second << "]";
    cout << ": " << d.first << endl;

    --k;
  }

  return 0;
}
