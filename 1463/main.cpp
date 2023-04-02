#include <iostream>

using namespace std;

int results[1000001];

int main() {
  long n;
  int t = 0;
  cin >> n;
  results[2] = 1;
  results[3] = 1;
  for(int i=4;i<=n;i++) {
    results[i] = results[i-1] + 1;
    if(i % 2 == 0) results[i] = (results[i/2] + 1 > results[i] ? results[i] : results[i/2] + 1);
    if(i % 3 == 0) results[i] = (results[i/3] + 1 > results[i] ? results[i] : results[i/3] + 1);
  }
  cout << results[n] << '\n';
}
