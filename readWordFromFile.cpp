#include "readWordFromFile.h"

using namespace std;

readWordFromFile::readWordFromFile(string fileName) {
    this->inputFile.open(fileName);
    this->inputFile.unsetf(ios_base::skipws);   //����������հס���־
}

std::string readWordFromFile::readAWord(void) {
    char readChar;
    bool inWord = false;    //��¼��ǰ�����Ƿ����
    string currentWord = "";    //��ǰ�����ĵ���
    while (!inputFile.eof()) {
        inputFile >> readChar;      //��һ���ַ�
        if ((readChar >= 97 && readChar <= 122)) {
            inWord = true;
            currentWord += readChar;
        }
        else if ((readChar >= 65 && readChar <= 90)) {
            inWord = true;
            readChar += 32;     //��д��ĸת��Сд
            currentWord += readChar;
        }
        else {
            if (inWord != false) {//���ʽ���
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