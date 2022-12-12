#ifndef LAB_2_SUPERMARKET_MODELING_PRODUCT_H
#define LAB_2_SUPERMARKET_MODELING_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
protected:
    string type;
    string Name;
    float Weight{};

public:
    Product();

    Product(string name, float weight, string type);

    string GetName() const;

    float GetWeight() const;

    string GetType() const;
};

class ProductWithDD : Product{
private:
    int DaysToExpire;

public:
    ProductWithDD(const Product& product, int daysToExpire);
};


#endif //LAB_2_SUPERMARKET_MODELING_PRODUCT_H