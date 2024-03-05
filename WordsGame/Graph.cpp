#include <iostream>
#include "Graph.h"

using namespace std;
#include <queue>
#include <unordered_set>

template<typename T>
Graph<T>::Graph() {}


template<typename T>
void Graph<T>::addEdge(const T& src, const T& dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);  // For undirected graph
}

template<typename T>
void Graph<T>::printGraph() {
    for (const auto& pair : adjList) {
        std::cout << pair.first << " -> ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
template<typename T>
vector<T> Graph<T>::shortestPath(const T& start, const T& target) {
    std::queue<T> q; //the queue for the traversal
    std::unordered_set<T> visited; //visited nodes
    std::unordered_map<T, T> parent;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        T current = q.front();
        q.pop();

        if (current == target) {
            // Reconstruct the shortest path
            std::vector<T> path;
            T node = target;
            while (node != start) {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const T& neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // No path found
    return {};
}
