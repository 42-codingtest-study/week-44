// 1920 원하는 정수 찾기

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());
  cin >> m;

  for (int i = 0; i < m; i++) {
    bool check = false;
    int target;
    cin >> target;
    int start = 0;
    int end = n - 1;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (v[mid] == target) {
        check = true;
        break;
      } else if (v[mid] < target)
        start = mid + 1;
      else
        end = mid - 1;
    }
    if (check)
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
    // cout << binary_search(v.begin(), v.end(), num) << '\n';
  }
}