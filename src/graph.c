#include "graph.h"
#include <stdlib.h>

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

Graph *newGraph(int graphSize, Node **nodes) {
  Graph *graph = malloc(sizeof(Graph));
  graph->graphSize = graphSize;
  graph->nodes = malloc(sizeof(Node) * graphSize);

  for (int i = 0; i < graphSize; i++) {
    graph->nodes[i] = (*nodes)[i];
  }

  return graph;
}