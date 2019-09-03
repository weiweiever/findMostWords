#include "wordListClass.h"

using namespace std;

wordListClass::wordListClass(void) {
    this->wordList.clear();
}

void wordListClass::appendNewWord(string word) {
    this->wordList.push_back(aWord(word,1));
}

aWord* wordListClass::findWord(string word) {
    for (int i = 0; i < this->wordList.size(); i++) {
        if (this->wordList[i].word == word) {
            return &wordList[i];
        }
    }
    return NULL;
}

void wordListClass::addAWord(string word) {
    const auto res = this->findWord(word);
    if ( res == NULL) {
        this->appendNewWord(word);
    }
    else {
        res->count++;
    }
}

vector<aWord> wordListClass::findMostWords(int num) {   //输入要找几个最多的单词
    vector<aWord> mostWords(num,aWord("",0));
    int64_t minimum = 0;    //记录当前进入最多排名的最小count
    for (int i = 0; i < this->wordList.size(); i++) {
        if (this->wordList[i].count > minimum) {
            for (int j = 0; j < mostWords.size(); j++) {
                if (mostWords[j].count == minimum) {    //找到最小值
                    mostWords[j] = wordList[i];         //替换
                    minimum = mostWords[0].count;
                    for (int k = 0; k < mostWords.size(); k++) {    //找到当前最新的最小值
                        if (mostWords[k].count < minimum)
                            minimum = mostWords[k].count;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < mostWords.size(); i++) {    //对找到的单词冒泡排序
        for (int j = i; j < mostWords.size(); j++) {
            if (mostWords[i].count < mostWords[j].count) {
                aWord swapWord = mostWords[i];
                mostWords[i] = mostWords[j];
                mostWords[j] = swapWord;
            }
        }
    }
    return mostWords;
}