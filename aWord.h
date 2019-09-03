#pragma once
#include <string>

class aWord {
public:
    std::string word;
    int64_t count;

    aWord(std::string word);
    aWord(std::string word, int64_t count);
};

