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
  cin >> N >> k;  // 행렬의 크기와 K 입력
  s = 1, e = k;   // 이분 탐색 범위 초기화
  // 이분 탐색 시작
  while (s <= e) {
    m = (s + e) / 2, tmp = 0;
    // 1부터 N까지 각 행에서 m보다 작거나 같은 수의 개수를 계산
    for (int i = 1; i <= N; i++) tmp += min(m / i, N);

    // 계산된 tmp가 k 이상이면 답 후보 갱신 및 탐색 범위 변경
    if (tmp >= k)
      answer = m, e = m - 1;
    else
      s = m + 1;
  }

  cout << s;  // K번째 수 출력
}
