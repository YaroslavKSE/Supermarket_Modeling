#ifndef LAB_2_SUPERMARKET_MODELING_PRODUCT_H
#define LAB_2_SUPERMARKET_MODELING_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
protected:
    string Name;
    float Weight{};

public:
    Product();

    Product(string name, float weight);

    string GetName();

    float GetWeight();
    virtual ~Product();
};

// to fix inheriting constructor
class Milk : public Product {
private:
    int DaysToExpire{};
public:
    Milk(Product product, int daysToExpire);
};


// to fix inheriting constructor
class Eggs : public Product {
    int DaysToExpire;
    int NumberOfEggs;
public:
    Eggs(Product product, int daysToExpire, int NumberOfEggs);
};

class Fish : public Product{
public:
    using Product::Product;
};

class Meat : public Product{
public:
    using Product::Product;
};

class Soap : public Product{
public:
    using Product::Product;
};

#endif //LAB_2_SUPERMARKET_MODELING_PRODUCT_H