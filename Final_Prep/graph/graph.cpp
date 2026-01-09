#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
  void BFS(int start, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);

    visited[start] = true; //

    while (!q.empty()) {
      int node = q.front(); q.pop();
      cout << node << " ";

      for (int num : adj[node]) {
        if (!visited[num]) {
          visited[num] = true;
          q.push(num);
        }
      }
    }
  }

  void DFS(int start, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
      int node = stack.top(); stack.pop();
      

      if (!visited[node]) {
        visited[node] = true;
        cout << node << " ";
      }

      for (int num : adj[node]) {
        if (!visited[num]) {
          stack.push(num);
        }
      }
    }
  }

  void DFSRecursive(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int num : adj[node]) {
      if (!visited[num]) {
        DFSRecursive(num, adj, visited);
      }
    }
  }

  
};

int main() {
    int V = 5;               // number of vertices
    vector<int> adj[V];     // adjacency list
  
    // Undirected graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);
  
    adj[0].push_back(2);
    adj[2].push_back(0);
  
    adj[1].push_back(3);
    adj[3].push_back(1);
  
    adj[1].push_back(4);
    adj[4].push_back(1);
  
    adj[2].push_back(4);
    adj[4].push_back(2);
  
    Graph g;
  
    cout << "BFS starting from node 0: ";
    g.BFS(0, adj, V);
    cout << endl;
  
    cout << "DFS (Iterative) starting from node 0: ";
    g.DFS(0, adj, V);
    cout << endl;
  
    cout << "DFS (Recursive) starting from node 0: ";
    vector<bool> visited(V, false);
    g.DFSRecursive(0, adj, visited);
    cout << endl;
  
    return 0;
  }
  