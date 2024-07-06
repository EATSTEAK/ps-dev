#include <iostream>


using namespace std;

int n;
int result = 0;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++) {
    int num;
    cin >> num;
    if(num != i) result++;
  }
  printf("%d", result);
}