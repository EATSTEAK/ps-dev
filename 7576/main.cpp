#include <iostream>
#include <queue>

using namespace std;

int tomatoes[1001][1001];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, k;
  queue<pair<int, int>> searchPoints;
  cin >> m >> n;
  for(int y=0;y<n;y++) {
    for(int x=0;x<m;x++) {
      cin >> k;
      tomatoes[x][y] = k;
      if(k > 0) searchPoints.push({x, y});
    }
  }
  while(!searchPoints.empty()) {
    pair<int, int> startPoint = searchPoints.front();
    int x = startPoint.first;
    int y = startPoint.second;
    searchPoints.pop();
    if(x+1 < m && tomatoes[x+1][y] != -1 && (tomatoes[x+1][y] == 0 || tomatoes[x+1][y] > tomatoes[x][y] + 1)) {
      tomatoes[x+1][y] = tomatoes[x][y] + 1;
      searchPoints.push({x+1, y});
    } 
    if(x-1 >= 0 && tomatoes[x-1][y] != -1 && (tomatoes[x-1][y] == 0 || tomatoes[x-1][y] > tomatoes[x][y] + 1)) {
      tomatoes[x-1][y] = tomatoes[x][y] + 1;
      searchPoints.push({x-1, y});
    }
    if(y+1 < n && tomatoes[x][y+1] != -1 && (tomatoes[x][y+1] == 0 || tomatoes[x][y+1] > tomatoes[x][y] + 1)) {
      tomatoes[x][y+1] = tomatoes[x][y] + 1;
      searchPoints.push({x, y+1});
    }
    if(y-1 >= 0 && tomatoes[x][y-1] != -1 && (tomatoes[x][y-1] == 0 || tomatoes[x][y-1] > tomatoes[x][y] + 1)) {
      tomatoes[x][y-1] = tomatoes[x][y] + 1;
      searchPoints.push({x, y-1});
    }
  }
  int ret = -1;
  for(int y=0;y<n;y++) {
    for(int x=0;x<m;x++) {
      if(tomatoes[x][y] > ret) ret = tomatoes[x][y];
      if(tomatoes[x][y] == 0) {
        cout << -1 << '\n';
        exit(0);
      }
    }
  }
  cout << ret -1 << '\n';
}