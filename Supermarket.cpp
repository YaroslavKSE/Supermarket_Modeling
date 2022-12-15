#include "Supermarket.h"

Supermarket::Supermarket() = default;

Supermarket::Supermarket(const vector<Refrigerator>& refrigerators, const vector<Freezer>& freezers,
                                             const vector<Shelve>& shelves) {
    this -> Refrigerators = refrigerators;
    this -> Freezers = freezers;
    this -> Shelves = shelves;
}

void Supermarket::AddFridge(const Refrigerator& fridge) {
    Refrigerators.push_back(fridge);
}

void Supermarket::AddToExactFridge(Product *const product, int number) {
    Refrigerators[number].AddProduct(product);

}

void Supermarket::AddFreezer(const Freezer& freezer) {
    Freezers.push_back(freezer);
}

void Supermarket::AddToExactFreezer(Product *const product, int number) {
    Freezers[number].AddProduct(product);

}

void Supermarket::AddShelve(const Shelve& shelve) {
    Shelves.push_back(shelve);
}

void Supermarket::AddToExactShelve(Product *const product, int number) {
    Shelves[number].AddProduct(product);
}

void Supermarket::View() {
    for (int i = 0; i < Shelves.size(); ++i) {
        cout << "Shelve #" << i << "\n";
        Shelves[i].Print();
    }
    for (int i = 0; i < Refrigerators.size(); ++i) {
        cout << "Refrigerator #" << i << "\n";
        Refrigerators[i].Print();
    }
    for (int i = 0; i < Freezers.size(); ++i) {
        cout << "Freezer #" << i << "\n";
        Freezers[i].Print();
    }
}

void Supermarket::ViewByType(const string& containerType) {
    if(containerType == "Shelve"){
        for (int i = 0; i < Shelves.size(); ++i) {
            cout << "Shelve #" << i << "\n";
            Shelves[i].Print();
        }
    }
    if(containerType == "Refrigerator"){
        for (int i = 0; i < Refrigerators.size(); ++i) {
            cout << "Refrigerator #" << i << "\n";
            Refrigerators[i].Print();
        }
    }
    if(containerType == "Freezer"){
        for (int i = 0; i < Freezers.size(); ++i) {
            cout << "Freezer #" << i << "\n";
            Freezers[i].Print();
        }
    }

}

void Supermarket::NextDay() {
    for (auto & Shelve : Shelves) {
        Shelve.NextDay();
    }

    for (auto & Refrigerator : Refrigerators) {
        Refrigerator.NextDay();
    }
//    for (auto & Freezer : Freezers) {
//        Freezer.NextDay();
//    }
}

void Supermarket::Take(const string& fromWhere, int number, const string& name) {
    if(fromWhere == "Shelve"){
        Shelves[number].RemoveProduct(name);
    }
    if(fromWhere == "Refrigerator"){
        Refrigerators[number].RemoveProduct(name);
    }
    if(fromWhere == "Freezer"){
        Freezers[number].RemoveProduct(name);
    }
}

void Supermarket::SetTemperature(const string& fridgeOrFreezer, int position, int number) {
    if(fridgeOrFreezer == "Freezer"){
        Freezers[position].SetTemperature(number);
    }
    if(fridgeOrFreezer == "Refrigerator"){
        Refrigerators[position].SetTemperature(number);
    }
}


