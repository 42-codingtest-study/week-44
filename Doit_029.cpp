#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int N, M, tmp, s, e;
vector<int> v;

int binary(int l, vector<int> &vec, int s, int e) {
  if (s > e) return 0;
  int m = (s + e) / 2;
  if (l == vec[m])
    return 1;
  else if (l < vec[m])
    return binary(l, vec, s, m - 1);
  else
    return binary(l, vec, m + 1, e);
}

int main() {
  fast;
  cin >> N;
  while (N--) cin >> tmp, v.push_back(tmp);
  sort(v.begin(), v.end());
  cin >> M;
  while (M--) {
    cin >> tmp;
    s = 0, e = v.size() - 1;
    cout << binary(tmp, v, s, e) << "\n";
  }
}
