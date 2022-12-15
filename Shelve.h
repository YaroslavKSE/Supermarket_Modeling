#ifndef LAB_2_SUPERMARKET_MODELING_SHELVE_H
#define LAB_2_SUPERMARKET_MODELING_SHELVE_H


#include <vector>
#include "Product.h"
class Shelve
{
protected:
    vector<Product*> Products;
public:
    Shelve();
    explicit Shelve(vector<Product*> products);

    void AddProduct(Product* product);

    void Print();

    void NextDay();
};


#endif //LAB_2_SUPERMARKET_MODELING_SHELVE_H
