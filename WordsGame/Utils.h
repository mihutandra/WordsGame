

#ifndef WORDSGAME_UTILS_H
#define WORDSGAME_UTILS_H
#include <iostream>
#include <string>
#include <ctime>

// Function to generate a random index within a range
int getRandomIndex(int min, int max);

// Function to randomly select a word from a vector of words
std::string selectRandomWord(const std::vector<std::string>& words);

// Function to check if two words differ by only one character
bool isValidTransformation(const std::string& word1, const std::string& word2);

// Function to provide hints for valid transformations from current word to target word
void provideHint(const std::string& currentWord, const std::string& targetWord, const std::vector<std::string>& dictionary);


#endif //WORDSGAME_UTILS_H
