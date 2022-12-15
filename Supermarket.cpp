#include "Supermarket.h"

Supermarket::Supermarket() = default;

Supermarket::Supermarket(const vector<Refrigerator>& refrigerators, const vector<Freezer>& freezers,
                         const vector<Shelve>& shelves) {
    this -> Refrigerators = refrigerators;
    this -> Freezers = freezers;
    this -> Shelves = shelves;
}

void Supermarket::AddFridge(Refrigerator fridge) {
    Refrigerators.push_back(fridge);
}

void Supermarket::AddFreezer(Freezer freezer) {
    Freezers.push_back(freezer);
}

void Supermarket::AddShelve(Shelve shelve) {
    Shelves.push_back(shelve);
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
