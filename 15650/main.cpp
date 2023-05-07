#include <iostream>

using namespace std;

int n, m;


void solve(string prefix, int start, int end, int length) {
  for(int i=start;i<=end;i++) {
    if(length > 1) {
      string newPrefix = prefix + " " + to_string(i);
      if(prefix.length() > 0) solve(newPrefix, i+1, end, length - 1);
      else solve(to_string(i), i+1, end, length - 1);
    } else {
      if(prefix.length() > 0) cout << prefix << " " << i << '\n';
      else cout << i << '\n';
    }
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  solve("", 1, n, m);
}