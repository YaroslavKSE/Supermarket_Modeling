#ifndef LAB_2_SUPERMARKET_MODELING_SHELVE_H
#define LAB_2_SUPERMARKET_MODELING_SHELVE_H


#include <vector>
#include "Product.h"
class Shelve
{
protected:
    vector<Product*> Products;
    int Capacity = 0;
public:
    Shelve();
    explicit Shelve(vector<Product*> products);

    int maxSize = 5;

    virtual int GetCapacity();
    virtual void AddProduct(Product* product);

    virtual Product* GetFirstProduct();

    virtual void Print();

    virtual void NextDay();

    virtual void RemoveProduct(const string& name);
};


#endif //LAB_2_SUPERMARKET_MODELING_SHELVE_H
