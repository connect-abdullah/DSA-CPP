#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Graph {
private:
    unordered_map<char, vector<pair<char,int>>> adj; // adjacency list with weights

public:
    void addEdge(char u, char v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    void BFS(char start) {
        cout << "--- BFS Traversal ---\n";
        queue<char> q;
        unordered_map<char,bool> visited;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            char node = q.front(); q.pop();
            cout << "Visited: " << node << " | Queue: ";
            for (queue<char> tmp=q; !tmp.empty(); tmp.pop())
                cout << tmp.front() << " ";
            cout << endl;

            for (auto &nbr : adj[node]) {
                if (!visited[nbr.first]) {
                    visited[nbr.first] = true;
                    q.push(nbr.first);
                }
            }
        }
    }

    void DFSUtil(char node, unordered_map<char,bool> &visited, stack<char> &stk) {
        visited[node] = true;
        cout << "Visiting: " << node << " | Stack: ";
        stack<char> tmp = stk;
        tmp.push(node);
        vector<char> tempVec;
        while(!tmp.empty()) { tempVec.push_back(tmp.top()); tmp.pop(); }
        for(auto it=tempVec.rbegin(); it!=tempVec.rend(); it++) cout << *it << " ";
        cout << endl;

        for (auto &nbr : adj[node]) {
            if (!visited[nbr.first]) {
                stk.push(node);
                DFSUtil(nbr.first, visited, stk);
                stk.pop();
            }
        }
    }

    void DFS(char start) {
        cout << "\n--- DFS Traversal ---\n";
        unordered_map<char,bool> visited;
        stack<char> stk;
        DFSUtil(start, visited, stk);
    }
};

int main() {
    Graph g;
    // Add edges
    g.addEdge('A','B',2);
    g.addEdge('A','C',5);
    g.addEdge('B','C',1);
    g.addEdge('B','D',4);
    g.addEdge('C','E',3);
    g.addEdge('D','E',2);
    g.addEdge('D','F',6);
    g.addEdge('E','F',1);

    g.BFS('A');
    g.DFS('A');

    return 0;
}
