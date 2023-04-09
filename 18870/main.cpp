#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

int n;
int input[1000001];
int sorted[1000001];

map<int, int> coords;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    input[i] = x;
    sorted[i] = x; 
  }
  sort(sorted, sorted + n);
  for(int i=0;i<n;i++) {
    int val = sorted[i];
    int idx = coords.size();
    coords.insert({val, idx});
  }
  for(int i=0;i<n;i++) {
    cout << coords[input[i]] << ' ';
  }
}