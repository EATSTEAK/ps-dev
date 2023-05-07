#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int numbers[9];
int out[9];

bool isIn[10001] = {0};

void solve(int length) {
  if(length == m) {
    for(int i=0;i<m;i++) {
      cout << out[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=0;i<n;i++) {
    if(isIn[i] == false) {
      out[length] = numbers[i];
      isIn[i] = true;
      solve(length + 1);
      isIn[i] = false;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    int k;
    cin >> k;
    numbers[i] = k;
  }
  sort(numbers, numbers + n);
  solve(0);
}