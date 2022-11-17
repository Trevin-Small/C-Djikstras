#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
} Node;

int compare(void *a, void *b) {
  Node *one = (Node *)a;
  Node *two = (Node *)b;
  if (one->value > two->value) {
    return 1;
  } else if (one->value == two->value) {
    return 0;
  }

  return -1;
}

void toString(minHeap *heap, void *node) {
  printf("Node Value: %d\n", ((Node *)node)->value);
}


int main() {

  const int SIZE = 10;

  Node **nodes = malloc(sizeof(Node *) * SIZE);

  minHeap *heap = newMinHeap(SIZE, compare);

  for (int i = 0; i < SIZE; i++) {
    Node *node = malloc(sizeof(Node));
    node->value = SIZE - i - 1;
    nodes[i] = node;
    heap->insert(heap, (void *)node);
  }

  for (int i = 0; i < SIZE; i++) {
    void *heapNode = (*heap).delMin(heap);
    toString(heap, heapNode);
  }

  return 0;
}