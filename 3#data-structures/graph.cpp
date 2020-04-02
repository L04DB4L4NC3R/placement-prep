#include <iostream>
#include <list>
using namespace std;

class Graph {
  // number of vertices
  int v;

  // adjacency list 
  // array of arrays 
  // 0 -> 1 -> 2
  // 1 -> 0 -> 2
  // 2 -> 0 -> 1
  list<int> *adj;

  public:
  Graph(int v);
  void addEdge(int v, int w);
  // breadth first search from a source
  void BFS(int source);
  // depth first search from a source
  void DFS(int source);
};

Graph::Graph(int v) {
  this->v = v;
  adj = new list<int>[v];
}

// add w to v's list
void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

// data structure used is QUEUE
// in BFS each vertex is pushed to a queue
// when you dequeue the vertex, you add its neighbours
// in the queue
void Graph::BFS(int source) {
}

// data structure used is STACK
// in DFS, each vertex is pushed to a stack and printed
// till we visit an already visited node again
// when we do, we need to pop it and push another 
// unvisited node in the stack
void Graph::DFS(int source) {
}

void graphs() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);
  g.DFS(2);
}
