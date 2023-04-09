#include <iostream>


using namespace std;

struct min_heap {
  int data[100001];
  int size;
};

void initHeap(min_heap* heap) {
  heap->size = 0;
}

void swap(int& first, int& second) {
  int tmp = first;
  first = second;
  second = tmp;
}

void insert(min_heap* heap, int val) {
  int cur = ++heap->size;
  heap->data[cur] = val;
  while(cur > 1) {
    if(heap->data[cur] < heap->data[cur / 2]) {
      swap(heap->data[cur], heap->data[cur / 2]);
      cur = cur / 2;
    } else {
      break;
    }
  }
}

int delete_parent(min_heap* heap) {
  if(heap->size < 1) return 0;
  int ret = heap->data[1];
  heap->data[1] = heap->data[heap->size--];
  int parent = 1;
  int child;
  while(true) {
    child = parent * 2;
    if(child + 1 <= heap->size && heap->data[child] > heap->data[child+1])
      child++;
    if(child > heap->size || heap->data[child] > heap->data[parent])
      break;
    swap(heap->data[parent], heap->data[child]);
    parent = child;
  }
  return ret;
}


int n;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  min_heap heap;
  initHeap(&heap);
  while(n--) {
    int x;
    cin >> x;
    if(x == 0) {
      cout << delete_parent(&heap) << '\n';
    } else {
      insert(&heap, x);
    }
  }
}