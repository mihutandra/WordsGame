
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


template<typename T> class Graph{
private:
    std::unordered_map<T, std::vector<T>> adjList;

public:
    Graph();
    void addEdge(const T& src, const T& dest);
    void printGraph();

    std::vector<T> shortestPath(const T& start, const T& target);
};







