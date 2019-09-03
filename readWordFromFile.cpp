#include "readWordFromFile.h"

using namespace std;

readWordFromFile::readWordFromFile(string fileName) {
    this->inputFile.open(fileName);
    this->inputFile.unsetf(ios_base::skipws);   //清除“跳过空白”标志
}

std::string readWordFromFile::readAWord(void) {
    char readChar;
    bool inWord = false;    //记录当前单词是否结束
    string currentWord = "";    //当前读到的单词
    while (!inputFile.eof()) {
        inputFile >> readChar;      //读一个字符
        if ((readChar >= 97 && readChar <= 122)) {
            inWord = true;
            currentWord += readChar;
        }
        else if ((readChar >= 65 && readChar <= 90)) {
            inWord = true;
            readChar += 32;     //大写字母转换小写
            currentWord += readChar;
        }
        else {
            if (inWord != false) {//单词结束
                inWord = false;
                break;
            }
        }

    }
    return currentWord;
}

bool readWordFromFile::isOver(void) {
    return inputFile.eof();
}

void readWordFromFile::closeFile(void) {
    this->inputFile.close();
}