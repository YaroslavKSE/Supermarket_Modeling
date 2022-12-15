#ifndef LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H
#define LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H

#include "Product.h"
#include <vector>
using namespace std;

class Refrigerator{
public:
    Refrigerator(int temperature, vector<Product*> products);

    Refrigerator();

    void AddProduct(Product* product);

    void Print();

    void NextDay();

private:
    int temperature{};
    vector<Product*> Products;

};


#endif //LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H