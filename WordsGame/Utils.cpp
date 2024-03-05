
#include "Utils.h"

int getRandomIndex(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr)); // Seed random number generator
        initialized = true;
    }
    return min + rand() % (max - min + 1);
}


std::string selectRandomWord(const std::vector<std::string>& words) {
    int index = getRandomIndex(0, words.size() - 1);
    return words[index];
}


bool isValidTransformation(const std::string& word1, const std::string& word2) {
    int diffCount = 0;
    for (size_t i = 0; i < word1.length(); ++i) {
        if (word1[i] != word2[i]) {
            ++diffCount;
            if (diffCount > 1) {
                return false;
            }
        }
    }
    return diffCount == 1;
}


void provideHint(const std::string& currentWord, const std::string& targetWord, const std::vector<std::string>& dictionary) {
    std::cout << "Hints:\n";
    for (const std::string& word : dictionary) {
        if (isValidTransformation(currentWord, word) && isValidTransformation(word, targetWord)) {
            std::cout << word << "\n";
        }
    }
}
