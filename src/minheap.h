#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct minHeapNode minHeapNode;
typedef struct minHeap minHeap;

struct minHeap {
  int heapSize; // Size of the heapNodes array
  int numHeapNodes; // Number of nodes in the heap
  int (*compare)(void *valueOne, void *valueTwo);
  int (*insert)(minHeap *heap, void *node);
  void (*heapify)(minHeap *heap);
  void *(*peekMin)(minHeap *heap);
  void *(*delMin)(minHeap *heap);
  void **heapNodes; // Array of pointers to minHeapNodes
};

minHeap *newMinHeap(int size, int (*compare)(void *valueOne, void *valueTwo));

#endif // MINHEAP_H