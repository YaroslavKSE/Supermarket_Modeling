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
    vector<string> FishNames;
    vector<string> MeatNames;
    vector<string> SoapNames;
public:
    Factory();
    void GenerateProducts(int amount);
    void FillProducts();
    void FillNames();
    vector<Product*> GetStock();
};


#endif //LAB_2_SUPERMARKET_MODELING_FACTORY_H
