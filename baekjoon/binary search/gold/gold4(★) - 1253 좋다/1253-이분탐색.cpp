// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/cf7ce676aad54a2786941423afd99612
#include <bits/stdc++.h>
using namespace std;

int cnt, n;
vector<int> a;

// i: 좋은지 판단할 대상, j: 합을 구성하는 첫 번째 수
void solve(int i) {
  for(int j = 0; j < n; j++) {
    if(j == i) continue; // 나 자신이 구성에 속하면 안됨
    int x = a[i] - a[j]; // x가 합을 구성하는 다른 수, 얘가 배열에 있고 인덱스가 i, j아니면 성공
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    while(idx < n && a[idx] == x) { // x와 같은 수만 탐색
      if(idx != i && idx != j) { cnt++; return; }
      idx++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  // a[i] 기준으로 삼고 좋은 수인지 판별
  for(int i = 0; i < n; i++) solve(i);
  cout << cnt;
}