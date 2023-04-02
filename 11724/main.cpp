#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];
long pSum[1001];
int n;

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    int t;
    cin >> t;
    p[i] = t;
  }
  sort(p, p + n);
  pSum[0] = p[0];
  long r = p[0];
  for(int i=1;i<n;i++) {
    pSum[i] = pSum[i-1] + p[i];
    r += pSum[i];
  }
  cout << r << '\n';
}
