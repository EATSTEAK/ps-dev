#include <iostream>
#include <queue>


using namespace std;

int points[100001] = {0};

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  queue<int> q;
  q.push(n);
  while(!q.empty()) {
    int c = q.front();
    q.pop();
    if(c == k || (points[k] > 0 && points[c] + 1 < points[k])) continue;
    if(c-1 >= 0 && (points[c-1] < 1 || points[c-1] > points[c] + 1)) {
      points[c-1] = points[c] + 1;
      q.push(c-1);
    }
    if(c+1 < 100001 && (points[c+1] < 1 || points[c+1] > points[c] + 1)) {
      points[c+1] = points[c] + 1;
      q.push(c+1);
    }
    if(c*2 < 100001 && (points[c*2] < 1 || points[c*2] > points[c] + 1)) {
      points[c*2] = points[c] + 1;
      q.push(c*2);
    }
  }
  cout << points[k] << '\n';
}