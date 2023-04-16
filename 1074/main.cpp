#include <iostream>
#include <cmath>


using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, r, c;
  int ret = 0;
  cin >> n >> r >> c;
  for(int i=n;i>1;i--) {
    int powered = round(pow(2, i));
    int sector = (r >= powered / 2 ? 2 : 0) + (c >= powered / 2 ? 1 : 0);
    // cout << "s, r, c :" << sector << ", " << r << ", " << c << ", p ^ 2 / 4 * sector = " << (powered * powered / 4) * sector << '\n';
    ret += (powered * powered / 4) * sector;
    if(r >= powered / 2) r = r - (powered / 2);
    if(c >= powered / 2) c = c - (powered / 2);
  }
  ret += r * 2 + c;
  cout << ret << '\n';
}