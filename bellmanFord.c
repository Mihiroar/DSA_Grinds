#include <stdio.h>
#include <stdlib.h>

#define INF 99999
struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
  return graph;
}

void printDistances(int dist[], int n) {
  printf("Vertex Distance from Source\n");
  for (int i = 0; i < n; ++i) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

void BellmanFord(struct Graph* graph, int src) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  for (int i = 0; i < V; i++) {
    dist[i] = INF;
  }
  dist[src] = 0;

  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INF && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;
    if (dist[u] != INF && dist[u] + weight < dist[v]) {
      printf("Graph contains negative weight cycle");
      return;
    }
  }

  printDistances(dist, V);
  return;
}

// Driver code
int main() {
  int V, E;
  printf("Enter the number of vertices: ");
  scanf("%d", &V);
  printf("Enter the number of edges: ");
  scanf("%d", &E);
  struct Graph* graph = createGraph(V, E);

  //Adding edges to the graph
  for (int i = 0; i < E; i++) {
    int src, dest, weight;
    printf("Enter source, destination and weight of edge %d: ", i + 1);
    scanf("%d %d %d", &src, &dest, &weight);
    graph->edge[i].src = src;
    graph->edge[i].dest = dest;
    graph->edge[i].weight = weight;
  }
  int src;
  printf("Enter the source vertex: ");
  scanf("%d", &src);

  BellmanFord(graph, src);
  return 0;
}
