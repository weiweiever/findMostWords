#include <iostream>
#include "wordListClass.h"
#include "readWordFromFile.h"
#include "aWord.h"
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    wordListClass words;
    readWordFromFile theFile("novel.txt");

    while (!theFile.isOver()) {
        words.addAWord(theFile.readAWord());
    }
    auto mostwords = words.findMostWords(20);
    cout  << setw(9) << "单词|" << setw(9) << "次数|" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < mostwords.size(); i++) {
        cout << setw(8) << mostwords[i].word << "|" << setw(8) << mostwords[i].count << "|"  << endl;
    }
}
