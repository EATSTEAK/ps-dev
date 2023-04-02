#include <iostream>
#include <queue>

using namespace std;

bool graph[101][101] = {0};
bool infected[101] = {0};

int main() {
  int n, k;
  int r = 0;
  cin >> n >> k;
  while(k--) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = true;
    graph[y][x] = true;
  }
  queue<int> connected;
  connected.push(1);
  infected[1] = true;
  while(!connected.empty()) {
    int t = connected.front();
    connected.pop();
    for(int i=1;i<=n;i++) {
      if(graph[t][i] && !infected[i]) {
        r++;
        infected[i] = true;
        connected.push(i);
      }
    }
  }
  cout << r << '\n';
}
