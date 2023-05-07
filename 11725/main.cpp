#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct vertex {
  set<int> connection;
};

int n;
vertex v[100001];
int parent[100001] = {0};

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    v[a].connection.insert(b);
    v[b].connection.insert(a);
  }
  queue<int> q;
  q.push(1);
  parent[1] = -1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int to : v[cur].connection) {
      if(parent[to] == 0) {
        parent[to] = cur;
        q.push(to);
      }
    }
  }
  for(int i=2;i<=n;i++) {
    cout << parent[i] << '\n';
  }
}