#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "GraphUtils.h"
#include "Utils.h"

using namespace std;

// Function prototypes
void automaticMode(){
    // Step 1: Prompt User for Input
    string startingWord, targetWord;
    cout << "Enter the starting word: ";
    cin >> startingWord;
    cout << "Enter the target word: ";
    cin >> targetWord;

    // Step 2: Load Dictionary
    unordered_map<string, vector<string>> wildcardMap;
    populateWildcardMap("words_alpha.txt", wildcardMap); // Assuming words_alpha.txt contains the dictionary

    // Step 3: Build Graph
    Graph<string> graph;
    buildGraph(graph, wildcardMap);

    // Step 4: Find Shortest Path
    vector<string> transformations = graph.shortestPath(startingWord, targetWord);

    // Step 5: Display Transformations
    if (transformations.empty()) {
        cout << "No transformations found from " << startingWord << " to " << targetWord << endl;
    } else {
        cout << "Transformations from " << startingWord << " to " << targetWord << ":" << endl;
        for (const string& word : transformations) {
            cout << word << endl;
        }
    }
};
void playingMode(){
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    // Read words from dictionary file
    std::vector<std::string> dictionary;
    std::ifstream file("dictionary.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening dictionary file.\n";
        return;
    }

    std::string word;
    while (file >> word) {
        dictionary.push_back(word);
    }
    file.close();
    // Randomly select starting and target words
    std::string startWord = selectRandomWord(dictionary);
    std::string targetWord = selectRandomWord(dictionary);

    std::cout << "Welcome, " << playerName << "!\n";
    std::cout << "Starting word: " << startWord << "\n";
    std::cout << "Target word: " << targetWord << "\n";

    // Game loop
    std::string transformation;
    while (startWord != targetWord) {
        std::cout << "Enter your transformation: ";
        std::cin >> transformation;

        // Validate transformation
        if (!isValidTransformation(startWord, transformation)) {
            std::cout << "Invalid transformation! Please try again.\n";
            continue;
        }

        // Update starting word
        startWord = transformation;
        // Provide hint if requested
        char choice;
        std::cout << "Do you want a hint? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            provideHint(startWord, targetWord, dictionary);
        }
    }

    std::cout << "Congratulations, you reached the target word!\n";
    return;
}

void recordGameData(const string& username, const string& startingWord, const string& targetWord,
                    const string& dateTime, int hintsUsed, const vector<string>& wordsUsed,
                    int numMoves, int optimalMoves);// Implementation to record game data and save it to a file


int main() {
    int choice;
    do {
        // Display menu
        cout << "Word Game Menu" << endl;
        cout << "1. Automatic Mode" << endl;
        cout << "2. Playing Mode" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                automaticMode();
                break;
            case 2:
                playingMode();
                break;
            case 0:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
