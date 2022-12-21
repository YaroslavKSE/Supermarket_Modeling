#include <locale>
#include <sstream>
#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"
#include "Refrigerator.h"
#include "Freezer.h"
#include "Supermarket.h"
#include "Factory.h"
#include "Truck.h"

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
            Product *salmon = new Fish(Product(record[i], stof(record[i + 1])));
            freezer.AddProduct(salmon);
            i = i + 1;
        }
        if (record[i] == "Pork") {
            Product *meat = new Meat(Product(record[i], stof(record[i + 1])));
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
            Product *soap = new Soap(Product(record[i], stof(record[i + 1])));
            shelve.AddProduct(soap);
            i = i + 1;
        }
        if (record[i] == "Gillette") {
            Product *soap = new Soap(Product(record[i], stof(record[i + 1])));
            shelve.AddProduct(soap);
            i = i + 1;
        }
        if (record[i] == "Dove") {
            Product *soap = new Soap(Product(record[i], stof(record[i + 1])));
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
    Factory factory;
    factory.GenerateProducts(200);
    Truck truck;
    truck.SetMaxCapacity(500);
    truck.FillTruck(factory.GetStock());
    FileReader fileReader("Products.txt");
    vector<string> records = fileReader.ReadText();
    vector<Product*> deliverProducts = truck.UnLoad();
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

    supermarket.AddProduct(deliverProducts);

    while (true) {
        cout << "Enter command:" << "\n";
        string command;
        getline(cin, command);
        vector<string> userInput = Split(command, ' ');
        if (userInput[0] == "View" && userInput.size() == 1) {
            supermarket.View();
            continue;
        }
        if (userInput[0] == "View" && userInput[1] == "Factory") {
            factory.Print();
            continue;
        }
        if (userInput[0] == "View" && userInput[1] == "Truck") {
            truck.Print();
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

        // Take from Shelve 1 Domestos 1
        if(userInput[0] == "Take"){
            supermarket.Take(userInput[2], stoi(userInput[3]), userInput[4]);
        }
        // Add Shelve 1 "Soap Dove 0.45"
        if(userInput[0] == "Add"){
            if(userInput[1] == "Shelve"){
                supermarket.AddToExactShelve(FillShelve(userInput).GetFirstProduct(), stoi(userInput[2]));
            }
            if(userInput[1] == "Refrigerator"){
                supermarket.AddToExactFridge(FillFridge(userInput).GetFirstProduct(), stoi(userInput[2]));

            }
            if(userInput[1] == "Freezer"){
                supermarket.AddToExactFreezer(FillFreezer(userInput).GetFirstProduct(), stoi(userInput[2]));
            }
        }
        // Set temperature Freezer 0 -10
        if(userInput[0] == "Set"){
            supermarket.SetTemperature(userInput[2], stoi(userInput[3]), stoi(userInput[4]));
        }

        // Move from Shelve 1 Domestos 1 to Shelve 2
        if(userInput[0] == "Move"){
            if(userInput[2] == "Shelve" && userInput[userInput.size() - 2] == "Shelve"){
                supermarket.AddToExactShelve(FillShelve(userInput).GetFirstProduct(), stoi(userInput[userInput.size() - 1]));
                supermarket.Take(userInput[2], stoi(userInput[3]), userInput[4]);
                continue;
            } else{
                cout <<"You can't move this product from shelve" << "\n";
            }
            if(userInput[2] == "Refrigerator" && userInput[userInput.size() - 2] == "Refrigerator"){
                supermarket.AddToExactFridge(FillFridge(userInput).GetFirstProduct(), stoi(userInput[userInput.size() - 1]));
                supermarket.Take(userInput[2], stoi(userInput[3]), userInput[4]);
                continue;
            } else {
                cout <<"You can't move this product from fridge" << "\n";
            }
            if(userInput[2] == "Freezer" && userInput[userInput.size() - 2] == "Freezer"){
                supermarket.AddToExactFreezer(FillFreezer(userInput).GetFirstProduct(), stoi(userInput[userInput.size() - 1]));
                supermarket.Take(userInput[2], stoi(userInput[3]), userInput[4]);
                continue;
            } else {
                cout <<"You can't move this product from fridge" << "\n";
            }
        }
        if(userInput[0] == "Exit"){
            break;
        }

    }
    return 0;
}