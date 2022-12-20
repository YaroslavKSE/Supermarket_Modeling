#ifndef LAB_2_SUPERMARKET_MODELING_PRODUCT_H
#define LAB_2_SUPERMARKET_MODELING_PRODUCT_H

#include <iostream>

using namespace std;

class Product {
protected:
    string Name;
    float Weight;
public:
    Product();

    Product(string name, float weight);

    string GetName();

    float GetWeight() const;
    virtual void Print();
    virtual ~Product();
};

class Checker: public Product{
protected:
    int DaysToExpire;
public:
    using Product::Product;
    virtual bool IsValid();
    void Print() override;
    char placeToPut;

};

class Milk : public Checker{
public:
    Milk(Product product, int daysToExpire);
    void Print() override;

};

class Bread : public Checker{
public:
    Bread(Product product, int daysToExpire);
    void Print() override;
};

class Water : public Checker{
public:
    Water(Product product, int daysToExpire);
    void Print() override;
};

class Eggs : public Checker{
    int NumberOfEggs;
public:
    Eggs(Product product, int daysToExpire, int NumberOfEggs);
    void Print() override;
};

class Fish : public Checker {
public:
    explicit Fish(Product product);
};

class Meat : public Checker{
public:
    explicit Meat(Product product);
};

class Soap : public Checker{
public:
    explicit Soap(Product product);
};



#endif //LAB_2_SUPERMARKET_MODELING_PRODUCT_H