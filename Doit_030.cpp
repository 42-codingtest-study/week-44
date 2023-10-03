#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// 가장 작은 크기의 블루레이 구하기 (m 개의 블루레이에 모든 동영상 다 담아야해요)
//  이 문제를 보고 투포인터로 풀어야 된다는걸 유추하려면
//  배열이 순서가 바뀌지 않는다. 순서대로 담아야 하니까. -> 이 때 이진탐색이 가능함.
// 시작 인덱스는 최대 길이의 레슨
// 종료 인덱슨느 모든 레슨 길이의 합

int n, m;
int arr[100001];
int start_, end_, mid;

int main()
{
  cin >> n >> m;
  start_ = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    start_ = max(start_, arr[i]);
    end_ += arr[i]; // end 의 시작은 모든 강의 길이의 합.
  }
  int cnt, sum;

  while (start_ <= end_)
  {
    mid = (start_ + end_) / 2;
    cnt = 0; // cnt 에서 mid 길이의 블루레이일 때 필요한 블루레이의 숫자를 저장한다.
    sum = 0;
    for (int idx = 0; idx < n; idx++)
    {
      if (sum + arr[idx] > mid) // 인강들 담다가 mid 보다 커지면, 블루레이 하나 새로 써야함.
      {
        cnt++;
        sum = 0;
      }
      sum += arr[idx];
    }

    if (sum != 0)
      cnt++;
    if (m >= cnt) // 해서 담다보니, mid 길이 블루레이에 강의를 순서대로 담다보니 m개보다 불루레이를 더 적게 썻으면, end 를 줄여준다.
      end_ = mid - 1;
    else
      start_ = mid + 1;
  }
  cout << start_;

  return 0;
}