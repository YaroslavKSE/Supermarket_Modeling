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

    virtual void AddProduct(Product* product);

    virtual Product* GetFirstProduct();

    virtual void Print();

    virtual void NextDay();

    virtual void RemoveProduct(const string& name);
};


#endif //LAB_2_SUPERMARKET_MODELING_SHELVE_H
