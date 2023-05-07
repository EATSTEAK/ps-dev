#include <iostream>

using namespace std;

int n;
int price[1001][3];
int DP[1001][3];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++) {
    int r, g, b;
    cin >> r >> g >> b;
    price[i][0] = r;
    price[i][1] = g;
    price[i][2] = b;
  }
  DP[0][0] = price[0][0];
  DP[0][1] = price[0][1];
  DP[0][2] = price[0][2];
  for(int i=1;i<n;i++) {
    DP[i][0] = (DP[i-1][1] < DP[i-1][2] ? DP[i-1][1] : DP[i-1][2]) + price[i][0];
    DP[i][1] = (DP[i-1][0] < DP[i-1][2] ? DP[i-1][0] : DP[i-1][2]) + price[i][1];
    DP[i][2] = (DP[i-1][0] < DP[i-1][1] ? DP[i-1][0] : DP[i-1][1]) + price[i][2];
  }
  int ans = DP[n-1][0];
  for(int i=1;i<3;i++) {
    if(ans > DP[n-1][i]) ans = DP[n-1][i];
  }
  cout << ans << '\n';
}