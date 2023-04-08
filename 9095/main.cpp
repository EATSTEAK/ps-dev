#include <iostream>
#include <algorithm>

using namespace std;

int cases[12];
int t;

int main() {
  cin >> t;
  cases[1] = 1;
  cases[2] = 2;
  cases[3] = 4;
  for(int i=4;i<=12;i++) {
    cases[i] = cases[i-1] + cases[i-2] + cases[i-3];
  }
  while(t--) {
    int n;
    cin >> n;
    cout << cases[n] << '\n';
  }
}
