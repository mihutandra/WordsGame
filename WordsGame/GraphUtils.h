
#include <unordered_map>
#include <vector>
#include <string>
#include "Graph.h"


void populateWildcardMap(const std::string& filename, std::unordered_map<std::string, std::vector<std::string>>& wildcardMap);
void buildGraph(Graph<std::string>& graph, const std::unordered_map<std::string, std::vector<std::string>>& wildcardMap);


