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

    float GetWeight() const;

    virtual void Print();
    virtual ~Product();
};

class Milk : public Product {
private:
    int DaysToExpire;
public:
    Milk(Product product, int daysToExpire);
    int GetDaysToExpire() const;
};

class Bread : public Product {
private:
    int DaysToExpire;
public:
    Bread(Product product, int daysToExpire);
    void Print() override;
    int GetDaysToExpire() const;
};

class Water : public Product {
private:
    int DaysToExpire;
public:
    Water(Product product, int daysToExpire);
    void Print() override;
    int GetDaysToExpire();
};

class Eggs : public Product {
    int DaysToExpire;
    int NumberOfEggs;
public:
    Eggs(Product product, int daysToExpire, int NumberOfEggs);
    void Print() override;
    int GetDaysToExpire();
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