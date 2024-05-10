#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for distances

class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) : vertices(V), adjList(V) {}

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        adjList[source].push_back({destination, weight});
        adjList[destination].push_back({source, weight}); // For undirected graph
    }

    // Dijkstra's algorithm for Single Source Shortest Path
    vector<int> dijkstra(int source) {
        vector<int> distances(vertices, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

        distances[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distances[u] != INF && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push({distances[v], v});
                }
            }
        }

        return distances;
    }
};

int main() {
    int V = 6; // Number of vertices in the graph
    Graph graph(V);

    // Adding edges and weights to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 2);

    // int source = 0; // Source node for shortest path calculation
    int src;
    cout<<"Enter  the source vertex: ";
    cin>>src;
    int source = src;

    vector<int> shortestDistances = graph.dijkstra(source);

    cout << "Shortest distances from source vertex " << source << " to all other vertices:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        if (shortestDistances[i] == INF) {
            cout << "INF";
        } else {
            cout << shortestDistances[i];
        }
        cout << endl;
    }

    return 0;
}
