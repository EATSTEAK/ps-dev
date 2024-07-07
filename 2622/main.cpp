#include <iostream>

using namespace std;

int n;

int solve(int n) {
  int count = 0;
  for(int i=1;i<n;i++) {
    for(int j=i;j<n;j++) {
      int k= n-i-j;
      if(j>k) break;
      if(i+j>k) count++;
    }
  }
  return count;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  printf("%d", solve(n));
}

