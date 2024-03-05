#include "GraphUtils.h"

#include <fstream>
#include <iostream>

void populateWildcardMap(const std::string& filename, std::unordered_map<std::string, std::vector<std::string>>& wildcardMap) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string word;
    while (getline(file, word)) {
        for (size_t i = 0; i < word.size(); ++i) {
            string pattern = word;
            pattern[i] = '*'; // Replace the character at index i with a wildcard

            // Add the word to the corresponding pattern in the map
            wildcardMap[pattern].push_back(word);
        }
    }

    file.close();
}

void buildGraph(Graph<std::string>& graph, const std::unordered_map<std::string, std::vector<std::string>>& wildcardMap) {
    for (const auto& pair : wildcardMap) {
        const vector<string>& words = pair.second;
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                // Check if words[i] and words[j] differ by only one letter
                int diffCount = 0;
                for (size_t k = 0; k < words[i].size(); ++k) {
                    if (words[i][k] != words[j][k]) {
                        ++diffCount;
                        if (diffCount > 1) {
                            break;
                        }
                    }
                }

                // If the difference count is exactly one, add an edge between the words
                if (diffCount == 1) {
                    graph.addEdge(words[i], words[j]);
                }
            }
        }
    }
}
