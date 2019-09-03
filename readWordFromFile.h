#pragma once
#include <fstream>

class readWordFromFile{
private:
    std::fstream inputFile;
public:
    readWordFromFile(std::string fileName);
    std::string readAWord(void);
    bool isOver(void);
    void closeFile(void);
};

