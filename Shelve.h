#ifndef LAB_2_SUPERMARKET_MODELING_SHELVE_H
#define LAB_2_SUPERMARKET_MODELING_SHELVE_H


#include <vector>
#include "Product.h"
class Shelve
{
    vector<Product*> Products;
public:
    Shelve();
    explicit Shelve(vector<Product*> products);
    void AddProduct(Product* product);
    void Print();
};


#endif //LAB_2_SUPERMARKET_MODELING_SHELVE_H
