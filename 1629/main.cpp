#include <iostream>

using namespace std;

long long a, b, c;


long long f(long long d) {
  if(d == 1) return a % c;
  long long k = f(d / 2) % c;
  if(d % 2 == 0) return k * k % c;
  else return k * k % c * a % c;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> a >> b >> c;
  cout << f(b) << '\n';
}
