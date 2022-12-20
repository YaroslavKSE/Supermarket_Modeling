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

class DueDateChecker: public Product{
protected:
    int DaysToExpire;
public:
    virtual bool IsValid();
    void Print() override;
};

class Milk : public DueDateChecker{
private:
public:
    Milk(Product product, int daysToExpire);
    void Print() override;

};

class Bread : public DueDateChecker{

public:
    Bread(Product product, int daysToExpire);
    void Print() override;
};

class Water : public DueDateChecker{
public:
    Water(Product product, int daysToExpire);
    void Print() override;
};

class Eggs : public DueDateChecker{
    int NumberOfEggs;
public:
    Eggs(Product product, int daysToExpire, int NumberOfEggs);
    void Print() override;
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