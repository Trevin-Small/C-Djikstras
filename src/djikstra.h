#ifndef DJIKSTRA_H
#define DJIKSTRA_H


typedef struct djikstra {
  int *distance;
  int *prev;
  Graph *graph;
  minHeap *minHeap;
  int **(*calculatePaths)(djikstra *djs, Node *startNode);
} djikstra;



#endif