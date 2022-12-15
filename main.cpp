#include <locale>
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
            const string& name = record[i + 2];
            float weight = stof(record[i + 3]);
            Product *milk = new Milk(Product(name, weight), dueDate);
            fridge.AddProduct(milk);
            i = i + 3;
        }
        if (record[i] == "Eggs") {
            int dueDate = stoi(record[i + 1]);
            const string& name = record[i + 2];
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
            i = i + 1;
        }
        if (record[i] == "Pork") {
            Product *meat = new Meat(record[i], stof(record[i + 1]));
            freezer.AddProduct(meat);
            i = i + 1;
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
            i = i + 2;
        }
        if (record[i] == "\"White" && record[i+1] == "Bread\"") {
            int dueDate = stoi(record[i + 2]);
            float weight = stof(record[i + 3]);
            Product *bread = new Bread(Product("White Bread", weight), dueDate);
            shelve.AddProduct(bread);
            i = i + 3;
        }
        if (record[i] == "Domestos") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
            i = i + 1;
        }
        if (record[i] == "Gillette") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
            i = i + 1;
        }
        if (record[i] == "Dove") {
            Product *soap = new Soap(record[i], stof(record[i + 1]));
            shelve.AddProduct(soap);
            i = i + 1;
        }
        if (record[i] == "Morshynska") {
            Product *water = new Water(Product(record[i], stof(record[i + 2])), stoi(record[i + 1]));
            shelve.AddProduct(water);
            i = i + 2;
        }
        if (record[i] == "Buvette") {
            Product *water = new Water(Product(record[i], stof(record[i + 2])), stoi(record[i + 1]));
            shelve.AddProduct(water);
            i = i + 2;
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
    for (auto & i : records) {
        vector<string> record = Split(i, ' ');
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

    while (true) {
        cout << "Enter command:" << "\n";
        string command;
        getline(cin, command);
        vector<string> userInput = Split(command, ' ');
        if (userInput[0] == "View" && userInput.size() == 1) {
            supermarket.View();
            continue;
        }
        if(userInput[0] == "View" && !userInput[1].empty()){
            supermarket.ViewByType(userInput[1]);
            continue;

        }
        if(userInput[0] == "Next" && userInput[1] == "day"){
            supermarket.NextDay();
            continue;
        }

        if(userInput[0] == "Exit"){
            break;
        }
    }
    return 0;
}