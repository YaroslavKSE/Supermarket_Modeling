#ifndef LAB_2_SUPERMARKET_MODELING_FACTORY_H
#define LAB_2_SUPERMARKET_MODELING_FACTORY_H
#include "Product.h"
#include "vector"
#include "map"
#include <random>

using namespace std;

class Factory {
private:
    vector<Product*> Stock;
    map<int, string> TypesOfProduct;
    vector<string> MilkNames;
    vector<string> WaterNames;
    vector<string> EggsNames;
    vector<string> BreadNames;
public:
    Factory();
    void GenerateProducts();
    void FillProducts();
    void FillNames();
};


#endif //LAB_2_SUPERMARKET_MODELING_FACTORY_H
