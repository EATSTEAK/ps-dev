#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;


int t;

void solveCase() {
  int k;
  priority_queue<int, vector<int>> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  map<int, int> values;
  int size = 0;
  cin >> k;
  while(k--) {
    char opcode;
    int n;
    cin >> opcode >> n;
    if(opcode == 'D') {
      if(size < 1) continue;
      if(n > 0) {
        while(!max_heap.empty() && values[max_heap.top()] == 0) max_heap.pop();
        values[max_heap.top()] -= 1;
        max_heap.pop();
        size--;
      } else {
        while(!min_heap.empty() && values[min_heap.top()] == 0) min_heap.pop();
        values[min_heap.top()] -= 1;
        min_heap.pop();
        size--;
      }
    }
    if(opcode == 'I') {
      max_heap.push(n);
      min_heap.push(n);
      values[n] += 1;
      size++;
    }
  }
  while(!max_heap.empty() && values[max_heap.top()] == 0) max_heap.pop();
  while(!min_heap.empty() && values[min_heap.top()] == 0) min_heap.pop();
  if(size < 1) cout << "EMPTY\n";
  else cout << max_heap.top() << ' ' << min_heap.top() << '\n';
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> t;
  while(t--) {
    solveCase();
  }
}