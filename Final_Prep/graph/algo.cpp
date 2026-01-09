#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Algorithms {

  void dijikstra(int V, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    // Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
      int node = pq.top().second;
      int d = pq.top().first;
      pq.pop();

      if (!visited[node]) {
        visited[node] = true;
      }

      for (auto it : adj[node]) {
        int neighbour = it.first;
        int weight = it.second;

        if (!visited[neighbour] && d + weight < dist[neighbour]) {
          dist[neighbour] = d + weight;
          pq.push({dist[neighbour], neighbour});
        }
      }
    }

    cout << "Shorted distance from source: " << src << ":\n";
    for (int i; i < V; i++) {
      cout << src << " -> " << i << " = " << dist[i] << endl;
    }
  }

  void prim(int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
      int node = pq.top().second;
      pq.pop();

      if (!visited[node]) {
        visited[node] = true;
      }

      for (auto it : adj[node]) {
        int neighbour = it.second;
        int weight = it.first;

        if (!visited[neighbour] && weight < dist[neighbour]) {
          dist[neighbour] = weight;
          parent[neighbour] = node;
          pq.push({dist[neighbour], neighbour});
        }
      }
    }

    // Print MST
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++) {
      cout << parent[i] << " - " << i << "    " << dist[i] << endl;
    }
  }

  // ---------- Kruskal ----------
  int findParent(int node, vector<int> &parent) {
    if (parent[node] == node) {
      return node;
    };
    return parent[node] = findParent(parent[node], parent);
  };

  void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v) {
      if (rank[u] < rank[v]) {
        parent[u] = v;
      } else if (rank[v] < rank[u]) {
        parent[v] = u;
      } else {
        parent[v] = u;
        rank[u]++;
      }
    }
  }

  struct Edge {
    int u, v, wt;
  };

  bool cmp(Edge a, Edge b) { return a.wt < b.wt; }

  void Kruskal(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmp);
    
    vector<int> parent(V);
    vector<int> rank(V, 0);
    int mstWeight = 0;

    for (int i = 0; i < V; i++)
      parent[i] = i;

    cout << "Edges in MST:\n";

    for (auto e : edges) {
      int u = e.u;
      int v = e.v;

      if (findParent(u, parent) != findParent(v, parent)) {
        cout << u << " - " << v << "  (" << e.wt << ")\n";
        mstWeight += e.wt;
        unionSet(u, v, parent, rank);
      }
    }
  }
};