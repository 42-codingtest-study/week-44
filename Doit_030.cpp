// 2343

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  int start = 0;
  int end = 0;

  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (start < vec[i]) start = vec[i];
    end += vec[i];
  }
  while (start <= end) {
    int mid = (start + end) / 2;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (sum + vec[i] > mid) {
        count++;
        sum = 0;
      }
      sum += vec[i];
    }

    if (sum != 0) count++;
    if (count > m)
      start = mid + 1;
    else
      end = mid - 1;
  }
  cout << start << "\n";
}