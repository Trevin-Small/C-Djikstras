#include "minheap.h"
#include <stdlib.h>
#include <stdio.h>

void swap(minHeap *heap, int idxOne, int idxTwo) {
  void *data = heap->heapNodes[idxOne];
  heap->heapNodes[idxOne] = heap->heapNodes[idxTwo];
  heap->heapNodes[idxTwo] = data;
}

void swimUp(minHeap *heap, int idx) {
  int parentIdx;

  if (idx == 0) {
    return;
  } else {
    parentIdx = (idx - 1) / 2;
  }

  if (heap->compare(heap->heapNodes[parentIdx], heap->heapNodes[idx]) == 1) {
    swap(heap, idx, parentIdx);
    swimUp(heap, parentIdx);
  }
}

void sinkDown(minHeap *heap, int idx) {
  int smallestIdx = idx;
  int leftIdx = (2 * idx) + 1;
  int rightIdx = 2 * (idx + 1);

  if (leftIdx < heap->numHeapNodes && heap->compare(heap->heapNodes[smallestIdx], heap->heapNodes[leftIdx]) == 1) {
    smallestIdx = leftIdx;
  }

  if (rightIdx < heap->numHeapNodes && heap->compare(heap->heapNodes[smallestIdx], heap->heapNodes[rightIdx]) == 1) {
    smallestIdx = rightIdx;
  }

  if (smallestIdx != idx) {
    swap(heap, idx, smallestIdx);
    sinkDown(heap, smallestIdx);
  }

}

// Heap sort the entire array of nodes
void heapSort(minHeap *heap) {
  int lastInternalIdx = (heap->numHeapNodes / 2) - 1;

  for (int i = lastInternalIdx; i >= 0; i--) {
    sinkDown(heap, i);
  }
}

int insertNode(minHeap *heap, void *data) {

  if (heap->numHeapNodes == heap->heapSize) {
    return -1;
  }

  heap->heapNodes[heap->numHeapNodes] = data;
  heap->numHeapNodes++;

  swimUp(heap, heap->numHeapNodes - 1);

  return 0;
}

void *peekMinNode(minHeap *heap) {
  return heap->heapNodes[0];
}

void *delMinNode(minHeap *heap) {
  // Get the node to be removed from the heap
  void *node = heap->heapNodes[0];

  // Move the last leaf node into the "hole" at the root from the removed node
  heap->heapNodes[0] = heap->heapNodes[heap->numHeapNodes - 1];

  // Set the last leaf node to null since it was moved to the root
  heap->heapNodes[heap->numHeapNodes - 1] = NULL;

  heap->numHeapNodes--;

  if (heap->numHeapNodes > 1) {
    sinkDown(heap, 0);
  }

  return node;
}

minHeap *newMinHeap(int size, int (*compare)(void *valueOne, void *valueTwo)) {
  minHeap *heap = malloc(sizeof(minHeap));
  heap->heapSize = size;
  heap->numHeapNodes = 0;
  heap->compare = compare;
  heap->heapify = heapSort;
  heap->insert = insertNode;
  heap->peekMin = peekMinNode;
  heap->delMin = delMinNode;
  heap->heapNodes = malloc(sizeof(void *) * size);

  return heap;
}