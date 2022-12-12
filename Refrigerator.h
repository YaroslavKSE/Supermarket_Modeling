#ifndef LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H
#define LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H

#include "Product.h"
#include <vector>

using namespace std;

class Refrigerator {
public:
    Refrigerator(int temperature, vector<Product> products);

    Refrigerator();

private:
    int temperature{};
    vector<Product> products;
};


#endif //LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H
