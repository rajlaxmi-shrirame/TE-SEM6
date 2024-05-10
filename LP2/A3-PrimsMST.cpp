#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;


struct Edge {
    int to;
    int weight;
};

vector<pair<int, int>> primMST(vector<vector<Edge>>& graph) {
    int n = graph.size(); 
    vector<int> minWeight(n, INT_MAX); 
    vector<int> parent(n, -1);
    vector<bool> visited(n, false); 
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    minWeight[0] = 0;
    pq.push({0, 0}); 
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        visited[u] = true;
        
        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            
            if (!visited[v] && weight < minWeight[v]) {
                minWeight[v] = weight;
                parent[v] = u;
                pq.push({minWeight[v], v});
            }
        }
    }
    
    vector<pair<int, int>> MST;
    for (int i = 1; i < n; ++i) {
        MST.push_back({parent[i], i});
    }
    
    return MST;
}

int main() {
    int n = 5; 
    vector<vector<Edge>> graph(n);
    
    // Add edges
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 1});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 2});
    graph[1].push_back({4, 4});
    graph[2].push_back({4, 5});
    graph[3].push_back({4, 3});
    
    vector<pair<int, int>> MST = primMST(graph);
    
    cout << "Edges of the minimum spanning tree:" << endl;
    for (auto edge : MST) {
        cout << edge.first << " - " << edge.second << endl;
    }
    
    return 0;
}
