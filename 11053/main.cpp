#include <iostream>

using namespace std;

int n;
int A[1001];
int DP[1001];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++) {
    int k;
    cin >> k;
    A[i] = k;
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    DP[i] = 1;
    for(int j=i-1;j>=0;j--) {
      if(A[i] > A[j]) {
        DP[i] = DP[i] > DP[j] + 1 ? DP[i] : DP[j] + 1;
      }
    }
    ans = DP[i] > ans ? DP[i] : ans;
  }
  cout << ans << '\n';
}