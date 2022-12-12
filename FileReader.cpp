#include "FileReader.h"
#include <vector>

vector<string> FileReader::ReadText() {
    std::ifstream myFile;
    myFile.open(fileName);
    std::string record;
    vector<string> productRecords;
    if (myFile.is_open()) {
        while (getline(myFile, record)) { // equivalent to myFile.good()
            productRecords.push_back(record);
        }
    } else {
        std::cout << "Couldn't open file\n";
    }
    return productRecords;
}


FileReader::FileReader(string fileName) : fileName(std::move(fileName)) {}