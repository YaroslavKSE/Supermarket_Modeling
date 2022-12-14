#include <locale>
#include <codecvt>
#include <sstream>
#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"
#include "Refrigerator.h"
#include "Freezer.h"
#include "Supermarket.h"

Refrigerator FillFridge(const vector<string> &record) {
    Refrigerator fridge;
    for (int i = 0; i < record.size(); ++i) {
        if (record[i] == "Milk") {
            int dueDate = stoi(record[i + 1]);
            string name = record[i + 2];
            float weight = stof(record[i + 3]);
            Product *milk = new Milk(Product(name, weight), dueDate);
            fridge.AddProduct(milk);
            i = i + 3;
        }
        if (record[i] == "Eggs") {
            int dueDate = stoi(record[i + 1]);
            string name = record[i + 2];
            float weight = stof(record[i + 3]);
            int number = stoi(record[i + 3]);
            Product *milk = new Eggs(Product(name, weight), dueDate, number);
            fridge.AddProduct(milk);
            i = i + 3;
        }
    }
    return fridge;
}

Freezer FillFreezer(const vector<string> &record) {
    Freezer freezer;
    for (int i = 0; i < record.size(); ++i) {
        if (record[i] == "Salmon") {
            Product *salmon = new Fish(record[i], stof(record[i + 1]));
            freezer.AddProduct(salmon);
        }
        if (record[i] == "Pork") {
            Product *meat = new Meat(record[i], stof(record[i + 1]));
            freezer.AddProduct(meat);
        }
    }
    return freezer;
}

Shelve FillShelve(const vector<string> &record) {
    Shelve shelve;
    for (int i = 0; i < record.size(); ++i) {
        if (record[i] == "Croissant") {
            int dueDate = stoi(record[i + 1]);
            float weight = stof(record[i + 2]);
            Product *bread = new Bread(Product(record[i], weight), dueDate);
            shelve.AddProduct(bread);
        }
        if (record[i] == "White Bread") {
            int dueDate = stoi(record[i + 1]);
            float weight = stof(record[i + 2]);
            Product *bread = new Bread(Product(record[i], weight), dueDate);
            shelve.AddProduct(bread);
        }
        if (record[i] == "Domestos") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
        }
        if (record[i] == "Gillette") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
        }
        if (record[i] == "Dove") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
        }
        if (record[i] == "Morshynska") {
            Product *water = new Water(Product(record[i], stof(record[i + 2])), stoi(record[i + 1]));
            shelve.AddProduct(water);
        }
        if (record[i] == "Buvette") {
            Product *water = new Water(Product(record[i], stof(record[i + 2])), stoi(record[i + 1]));
            shelve.AddProduct(water);
        }
    }
    return shelve;
}

vector<string> Split(const string &line, char delim) {
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (getline(iss, token, delim)) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}


int main() {

    FileReader fileReader("Products.txt");
    vector<string> records = fileReader.ReadText();
    Supermarket supermarket;
    for (int i = 0; i < records.size(); ++i) {
        vector<string> record = Split(records[i], ' ');
        if(record[0] == "Shelve"){
            supermarket.AddShelve(FillShelve(record));
        }
        if(record[0] == "Refrigerator"){
            supermarket.AddFridge(FillFridge(record));
        }
        if(record[0] == "Freezer"){
            supermarket.AddFreezer(FillFreezer(record));
        }
    }

    return 0;
}
