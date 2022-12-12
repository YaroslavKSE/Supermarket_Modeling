#ifndef LAB_2_SUPERMARKET_MODELING_FREEZER_H
#define LAB_2_SUPERMARKET_MODELING_FREEZER_H

#include "Product.h"
#include <vector>

class Freezer{
public:
    Freezer(int temperature, vector <Product> products);
    Freezer();

private:
    int temperature{};
    vector<Product> products;
};

#endif //LAB_2_SUPERMARKET_MODELING_FREEZER_H
