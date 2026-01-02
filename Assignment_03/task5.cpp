#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =====================
// Edge Structure
// =====================
struct Edge {
    char u, v;
    int weight;
    Edge(char u, char v, int w) : u(u), v(v), weight(w) {}
};

// =====================
// Union-Find / Disjoint Set
// =====================
class DisjointSet {
private:
    unordered_map<char, char> parent;

public:
    void makeSet(vector<char> nodes) {
        for (char node : nodes)
            parent[node] = node;
    }

    char find(char x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(char x, char y) {
        char px = find(x);
        char py = find(y);
        if (px != py)
            parent[py] = px;
    }

    bool sameSet(char x, char y) {
        return find(x) == find(y);
    }
};

// =====================
// Kruskal MST Class
// =====================
class KruskalMST {
private:
    vector<Edge> edges;
    vector<char> nodes;

public:
    void addNode(char node) {
        nodes.push_back(node);
    }

    void addEdge(char u, char v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    void computeMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

        cout << "--- Sorted Edges ---\n";
        for (auto &e : edges)
            cout << e.u << "-" << e.v << " : " << e.weight << endl;

        // Initialize disjoint set
        DisjointSet ds;
        ds.makeSet(nodes);

        vector<Edge> mst;
        int totalWeight = 0;

        cout << "\n--- MST Selection Steps ---\n";
        for (auto &e : edges) {
            if (!ds.sameSet(e.u, e.v)) {
                mst.push_back(e);
                totalWeight += e.weight;
                ds.unite(e.u, e.v);
                cout << "Accepted: " << e.u << "-" << e.v << " (" << e.weight << ")\n";
            } else {
                cout << "Rejected (cycle): " << e.u << "-" << e.v << " (" << e.weight << ")\n";
            }
        }

        cout << "\n--- Final MST Edges ---\n";
        for (auto &e : mst)
            cout << e.u << "-" << e.v << " : " << e.weight << endl;

        cout << "Total MST Distance: " << totalWeight << " miles\n";
    }
};

// =====================
// MAIN PROGRAM
// =====================
int main() {
    KruskalMST network;

    // Add nodes
    network.addNode('A');
    network.addNode('B');
    network.addNode('C');
    network.addNode('D');
    network.addNode('E');
    network.addNode('F');
    network.addNode('G');

    // Add edges
    network.addEdge('A','C',15);
    network.addEdge('B','C',20);
    network.addEdge('B','D',25);
    network.addEdge('C','E',30);
    network.addEdge('D','E',35);
    network.addEdge('E','F',40);
    network.addEdge('E','G',45);
    network.addEdge('F','G',50);

    network.computeMST();

    return 0;
}
