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

int N, k, s, e, m, tmp, answer;

int main() {
  fast;
  cin >> N >> k;
  s = 1, e = k;
  while (s <= e) {
    m = (s + e) / 2;
    tmp = 0;
    for (int i = 1; i <= N; i++) tmp += min(m / i, N);
    if (tmp >= k)
      answer = m, e = m - 1;
    else
      s = m + 1;
  }
  cout << s;
}
