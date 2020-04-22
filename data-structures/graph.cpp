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
  void DFSUtil(int v, bool visited[]);

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
  bool *visited = new bool[v];
  for(int i = 0; i < v; ++i) {
    visited[i] = false;
  }

  list<int> queue;
  visited[source] = true;
  queue.push_back(source);
  list<int>::iterator itr;

  while(!queue.empty()) {
    // pop from queue, print, then push all
    // adjacent things in
    source = queue.front();
    cout << source << " ";
    queue.pop_front();

    for(itr = adj[source].begin(); itr != adj[source].end(); ++itr) {
      if (!visited[*itr]) {
        visited[*itr] = true;
        queue.push_back(*itr);
      }
    }
  }
}

// data structure used is STACK
// in DFS, each vertex is pushed to a stack and printed
// till we visit an already visited node again
// when we do, we need to pop it and push another 
// unvisited node in the stack
void Graph::DFS(int source) {
  bool *visited = new bool[v];
  for(int i = 0; i < v; ++i) {
    visited[i] = false;
  }
  for(int i = 0; i < v; ++i) {
    if(visited[i] == false) 
      DFSUtil(i, visited);
  }
}


// the recursive utility function for DFS
void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";
  list<int>::iterator itr;

  for(itr = adj[v].begin(); itr != adj[v].end(); ++itr) {
    if (!visited[*itr]) {
      DFSUtil(*itr, visited);
    }
  }
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
  printf("\n");
  g.DFS(2);
}
