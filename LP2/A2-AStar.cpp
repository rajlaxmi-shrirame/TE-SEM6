#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y; // Coordinates of the node
    int g, h; // Cost values
    Node* parent; // Parent node

    Node(int x, int y, int g, int h, Node* parent) : x(x), y(y), g(g), h(h), parent(parent) {}

    // Calculate the total cost (f) of the node
    int f() const {
        return g + h;
    }
};

// Helper function to calculate the heuristic (Manhattan distance)
int calculateHeuristic(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

// A* algorithm implementation
vector<pair<int, int>> findPath(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    // Possible movement directions (up, down, left, right)
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    // Priority queue for the open set
    auto compare = [](const Node* a, const Node* b) {
        return a->f() > b->f();
    };
    priority_queue<Node*, vector<Node*>, decltype(compare)> openSet(compare);

    // Create a start node
    Node* startNode = new Node(start.first, start.second, 0, calculateHeuristic(start.first, start.second, end.first, end.second), nullptr);
    openSet.push(startNode);

    // Matrix to track visited nodes and their parents
    vector<vector<Node*>> visited(numRows, vector<Node*>(numCols, nullptr));

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        // Check if the current node is the goal
        if (current->x == end.first && current->y == end.second) {
            vector<pair<int, int>> path;
            while (current != nullptr) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            // Check if the new position is within bounds and not an obstacle
            if (newX >= 0 && newX < numRows && newY >= 0 && newY < numCols && grid[newX][newY] == 0) {
                int newG = current->g + 1; // Cost of moving to the neighbor
                int newH = calculateHeuristic(newX, newY, end.first, end.second);
                Node* neighbor = new Node(newX, newY, newG, newH, current);

                // Check if the neighbor has been visited or has a better path
                if (visited[newX][newY] == nullptr || newG < visited[newX][newY]->g) {
                    visited[newX][newY] = neighbor;
                    openSet.push(neighbor);
                }
            }
        }
    }

    return {}; // If no path found
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // pair<int, int> start = {0, 0};
    // pair<int, int> end = {4, 4};

    int startx;
    int starty;
    int endx;
    int endy;

    cout<<"Enter Start Co-ordinates:";
    cin>>startx>>starty;

    cout<<"Enter End Co-ordinates:";
    cin>>endx>>endy;

    pair<int, int> start = {startx, starty};
    pair<int, int> end = {endx, endy};

    vector<pair<int, int>> path = findPath(grid, start, end);

    if (path.empty())
        cout << "No path found." << endl;
    else {
        cout << "Path found:" << endl;
        for (const auto& point : path) 
            cout << "(" << point.first << ", " << point.second << ")" << endl;
    }

    return 0;
}
