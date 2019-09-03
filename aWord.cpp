#include "aWord.h"

using namespace std;

aWord::aWord(string word) {
    this->word = word;
    this->count = 0;
}

aWord::aWord(string word, int64_t count) {
    this->word = word;
    this->count = count;
}