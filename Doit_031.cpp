// 1300 배열에서 k번째 수 찾기

#include <iostream>
#include <vector>
using namespace std;

// 중앙 값보다 작은 수의 개수를 세면서 범위를 절반씩 줄이는 방법
// 작은 수의 개수가 k-1보다 작으면 범위를 늘리고, 크면 범위를 줄인다.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long n, k;
  cin >> n >> k;
  long start = 1, end = k;
  long ans = 0;

  while (start <= end) {
    long mid = (start + end) / 2;
    long count = 0;
    // 중앙 값보다 작은 수 계산
    // 나눈 값이 n보다 크면 한 행의 크기가 n이므로 n
    for (int i = 1; i <= n; i++) count += min(mid / i, n);
    if (count < k)
      start = mid + 1;
    else {
      ans = mid;  // 현재 단계의 중앙 값 저장
      end = mid - 1;
    }
  }
  cout << ans << "\n";
}