#ifndef LAB_2_SUPERMARKET_MODELING_SUPERMARKET_H
#define LAB_2_SUPERMARKET_MODELING_SUPERMARKET_H
#include "vector"
#include "string"
#include "Refrigerator.h"
#include "Freezer.h"
#include "Shelve.h"


class Supermarket {
private:
    vector<Refrigerator> Refrigerators;
    vector<Freezer> Freezers;
    vector<Shelve> Shelves;
public:
    Supermarket();

    Supermarket(const vector<Refrigerator>& refrigerators, const vector<Freezer>& freezers, const vector<Shelve>& shelves);
    void AddFridge(const Refrigerator& fridge);
    void AddFreezer(const Freezer& freezer);
    void AddShelve(const Shelve& shelve);
    void AddToExactShelve(Product *const product, int number);
    void AddToExactFridge(Product *const product, int number);
    void AddToExactFreezer(Product *const product, int number);
    void View();
    void ViewByType(const string& containerType);
    void NextDay();
    void Take(const string& product, const string& name);
};


#endif //LAB_2_SUPERMARKET_MODELING_SUPERMARKET_H