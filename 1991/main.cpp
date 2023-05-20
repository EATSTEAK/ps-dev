#include <iostream>
#include <map>

using namespace std;

struct node {
  char data;
  node* left;
  node* right;
};

map<char, node*> nodes;
int n;

node* createNewNode() {
  node* newNode = new node();
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

void preoderTraversal(node* n) {
  if(n == nullptr) return;
  cout << n->data;
  preoderTraversal(n->left);
  preoderTraversal(n->right);
}

void inorderTraversal(node* n) {
  if(n == nullptr) return;
  inorderTraversal(n->left);
  cout << n->data;
  inorderTraversal(n->right);
}

void postorderTraversal(node* n) {
  if(n == nullptr) return;
  postorderTraversal(n->left);
  postorderTraversal(n->right);
  cout << n->data;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  nodes.insert({'A', createNewNode()});
  nodes['A']->data = 'A';
  for(int i=1;i<=n;i++) {
    char r, lc, rc;
    cin >> r >> lc >> rc;
    if(lc != '.') {
      nodes.insert({lc, createNewNode()});
      nodes[lc]->data = lc;
      nodes[r]->left = nodes[lc];
    }
    if(rc != '.') {
      nodes.insert({rc, createNewNode()});
      nodes[rc]->data = rc;
      nodes[r]->right = nodes[rc];
    }
  }
  preoderTraversal(nodes['A']);
  cout << '\n';
  inorderTraversal(nodes['A']);
  cout << '\n';
  postorderTraversal(nodes['A']);
  cout << '\n';
}