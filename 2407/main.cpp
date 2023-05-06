#include <iostream>


using namespace std;

string mem[101][101] = {};

string add_num(string first, string second) {
  string num = "";
  int sum = 0;
  int size = max(first.size(),second.size());
  for(int i=0;i<size || sum;i++){
    if(first.size()>i) sum += first[i]-'0';
    if(second.size()>i) sum += second[i]-'0';
    num += sum%10 +'0';
    sum /= 10;
  }
  return num;
}

string c(int n, int m) {
  if(n == m || m == 0) return "1";
  if(mem[n][m].length() > 0) return mem[n][m];
  mem[n][m] = add_num(c(n - 1, m - 1), c(n - 1, m));
  return mem[n][m];
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  c(n, m);
  for(int i=mem[n][m].size()-1;i>=0;i--)
    cout << mem[n][m][i];
}