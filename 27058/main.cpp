#include <iostream>
#include <string.h>

using namespace std;

char codes[27];
char message[81];

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> codes;
  cin.ignore();
  cin.getline(message, 80);
  for(int i=0;i<strlen(message);i++) {
    if(message[i] >= 'a' && message[i] <= 'a' + 26) {
      message[i] = codes[message[i] - 'a'];
    } else if(message[i] >= 'A' && message[i] <= 'A' + 26) {
      message[i] = codes[message[i] - 'A'] - 32;
    }
  }
  printf("%s\n", message);
}