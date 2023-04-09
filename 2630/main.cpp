#include <iostream>


using namespace std;

bool paper[129][129];
int n;
int t;
int white, blue = 0;

void checkAndCut(int x, int y, int n) {
  bool first = paper[x][y];
  bool shouldCut = false;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(paper[x + i][y + j] != first) shouldCut = true;
      if(shouldCut) break;
    }
    if(shouldCut) break;
  }
  if(shouldCut) {
    int nn = n / 2;
    checkAndCut(x, y, nn);
    checkAndCut(x + nn, y, nn);
    checkAndCut(x, y + nn, nn);
    checkAndCut(x + nn, y + nn, nn);
  } else {
    if(first) {
      blue++;
    } else {
      white++;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> t;
      paper[i][j] = t;
    }
  }
  checkAndCut(0, 0, n);
  cout << white << '\n' << blue << '\n';
}