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
    void AddFridge(Refrigerator fridge);
    void AddFreezer(Freezer freezer);
    void AddShelve(Shelve shelve);
    void View();
    void ViewByType(const string& containerType);
};


#endif //LAB_2_SUPERMARKET_MODELING_SUPERMARKET_H
