#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> sch;
  for(int i=0;i<n;i++) {
    int start, end;
    cin >> start >> end;
    sch.push_back({end, start});
  }
  sort(sch.begin(), sch.end());
  int t = sch[0].first;
  int res = 1;
  for(int i=1;i<n;i++) {
    if(t <= sch[i].second) {
      res++;
      t = sch[i].first;
    }
  }
  cout << res << '\n';
}