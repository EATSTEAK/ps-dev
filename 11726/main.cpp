#include <iostream>


using namespace std;

int cases[1002];
int n;

int main() {
  cin >> n;
  cases[1] = 1;
  cases[2] = 2;
  for(int i=3;i<=1000;i++) {
    cases[i] = (cases[i-1] + cases[i-2]) % 10007;
  }
  cout << cases[n] << '\n';
}