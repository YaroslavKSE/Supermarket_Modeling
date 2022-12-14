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
