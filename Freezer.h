#ifndef LAB_2_SUPERMARKET_MODELING_FREEZER_H
#define LAB_2_SUPERMARKET_MODELING_FREEZER_H

#include "Product.h"
#include <vector>

using namespace std;

class Freezer {
public:
    Freezer(int temperature, vector<Product*> products);

    Freezer();

    void AddProduct(Product* product);

    void Print();

    void NextDay();

private:
    int temperature{};
    vector<Product*> Products;
};

#endif //LAB_2_SUPERMARKET_MODELING_FREEZER_H
