#ifndef LAB_2_SUPERMARKET_MODELING_PRODUCT_H
#define LAB_2_SUPERMARKET_MODELING_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
protected:
    string Name;
    int Weight{};

public:
    Product();

    Product(string name, int weight);

};

// to fix inheriting constructor
class Milk : Product {
private:
    int DaysToExpire{};
public:
    Milk(const Product& product, int daysToExpire);
};


// to fix inheriting constructor
class Eggs : Product {
    int DaysToExpire;
    int NumberOfEggs;
public:
    Eggs(int daysToExpire, int NumberOfEggs);
};

class Fish : Product{
public:
    using Product::Product;
};

class Meat : Product{
public:
    using Product::Product;
};

class Soap : Product{
public:
    using Product::Product;
};

#endif //LAB_2_SUPERMARKET_MODELING_PRODUCT_H