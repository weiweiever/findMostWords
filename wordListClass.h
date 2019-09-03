#pragma once
#include <vector>
#include <string>
#include "aWord.h"


class wordListClass{
private:
    std::vector<aWord> wordList;
public:
    wordListClass(void);
    void appendNewWord(std::string word);
    aWord* findWord(std::string word);
    void addAWord(std::string word);
    std::vector<aWord> findMostWords(int num);
};

