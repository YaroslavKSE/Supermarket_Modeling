#ifndef LAB_2_SUPERMARKET_MODELING_PRODUCT_H
#define LAB_2_SUPERMARKET_MODELING_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
private:
    string Name;
    int Weight{};

public:
    Product();

    Product(string name, int weight);

};

#endif //LAB_2_SUPERMARKET_MODELING_PRODUCT_H