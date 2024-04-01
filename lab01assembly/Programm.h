#ifndef PROGRAMM_H
#define PROGRAMM_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Operation.h"

class Program {
public:

    Program();
    std::map <std::string, int> dataParser(const std::string& filePath);
    void codeParser(const std::string& filePath);
    void writeToFile(const std::string& filePath) const;
    int getResult() const;
    static int main();
private:
    void clearStr(std::string& str);
    bool isNumber(const std::string& str);
    std::string questVar;
    std::map <std::string, int> res;
    int result;
};


#endif //PROGRAMM_H
