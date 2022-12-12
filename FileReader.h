#ifndef LAB_2_SUPERMARKET_MODELING_FILEREADER_H
#define LAB_2_SUPERMARKET_MODELING_FILEREADER_H


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class FileReader {
private:
    string fileName;
public:
    explicit FileReader(string fileName);

    vector<string> ReadText();
};


#endif //LAB_2_SUPERMARKET_MODELING_FILEREADER_H
