#include <iostream>
#include <cmath>


using namespace std;

long sum_tree[502][502];
int tree[502][502];
int n;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=i;j++) {
      int k;
      cin >> k;
      tree[i][j] = k;
      if(i == 1) {
        sum_tree[i][j] = k;
      } else {
        if(j == 1) sum_tree[i][j] = sum_tree[i-1][j] + tree[i][j];
        else if(j == i) sum_tree[i][j] = sum_tree[i-1][j-1] + tree[i][j];
        else sum_tree[i][j] = max(sum_tree[i-1][j-1], sum_tree[i-1][j]) + tree[i][j];
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    if(sum_tree[n][i] > ans) ans = sum_tree[n][i];
  }
  cout << ans << '\n';
}