#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node Node;
typedef struct Edge Edge;
typedef struct Graph Graph;

struct Node {
  int value;
  struct Edge *connections;
};

struct Edge {
  int weight;
  struct Node *to;
};

struct Graph {
  int graphSize;
  struct Node *nodes;
  minHeap *minHeap;
};


Graph *newGraph(int graphSize, Node **nodes);
int compare(void *a, void *b);

#endif // GRAPH_H