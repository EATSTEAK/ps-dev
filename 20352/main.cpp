#include <iostream>
#include <cmath>


using namespace std;

long long n;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  double r = sqrt(n / M_PI);
  printf("%.10f", 2 * r * M_PI);
}