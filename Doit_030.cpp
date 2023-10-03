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

int N, M, tmp, sum = 0, s = 0, e = 0;
vector<int> v;  // 각 레슨의 길이를 저장할 벡터

int main() {
  fast;
  cin >> N >> M;  // 레슨의 수와 블루레이의 수 입력
  // 블루레이의 최소 길이는 레슨 중 가장 긴 것
  // 블루레이의 최대 길이는 모든 레슨의 합
  while (N--) cin >> tmp, s = max(s, tmp), e += tmp, v.push_back(tmp);
  // 이분 탐색 시작
  while (s <= e) {
    int mid = (s + e) / 2, cnt = 0, sum = 0;
    for (int i = 0; i < v.size(); i++) {
      // 현재 레슨을 추가했을 때 블루레이 길이를 초과하면 새로운 블루레이 사용
      if (sum + v[i] > mid) cnt++, sum = 0;
      sum += v[i];  // 레슨 길이 누적
    }
    if (sum != 0) cnt++;  // 마지막에 남아있는 레슨들을 위한 블루레이 필요
    // 블루레이의 개수에 따른 이분 탐색 조건 판단
    if (M >= cnt)
      e = mid - 1;
    else if (M < cnt)
      s = mid + 1;
  }
  cout << s;  // 최소 블루레이 길이 출력
}
