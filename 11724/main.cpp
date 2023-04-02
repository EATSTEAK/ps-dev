#include <iostream>
#include <queue>

using namespace std;

bool graph[1001][1001] = {0};
bool searched[1001] = {0};

int main() {
  int n, m;
  int r = 0;
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = true;
    graph[v][u] = true;
  }
  for(int i=1;i<=n;i++) {
    if(!searched[i]) {
      queue<int> connected;
      connected.push(i);
      searched[i] = true;
      while(!connected.empty()) {
        int t = connected.front();
        connected.pop();
        for(int i=1;i<=n;i++) {
          if(graph[t][i] && !searched[i]) {
            searched[i] = true;
            connected.push(i);
          }
        }
      }
      r++;
    }
  }
  cout << r << '\n';
}
