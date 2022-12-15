#include "Product.h"
Product::Product(string name, float weight): Name(move(name)), Weight(weight){}

Product::~Product() = default;

string Product::GetName() {
    return Name;
}

float Product::GetWeight() const {
    return Weight;
}

void Product::Print() {
    cout << "Product:" << Name << " Weight:" <<to_string(Weight) << "\n";
}

Product::Product() = default;


Eggs::Eggs(Product product, int daysToExpire, int numberOfEggs){
    this -> Eggs::Name = product.GetName();
    this -> Eggs::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
    this -> NumberOfEggs = numberOfEggs;

}

void Eggs::Print() {
    Product::Print();
    cout << "Days To Expire:" << DaysToExpire << " Number of eggs:" << NumberOfEggs << "\n";

}

int Eggs::GetDaysToExpire() {
    return DaysToExpire;
}

Milk::Milk(Product product, int daysToExpire) {
    this -> Milk::Name = product.GetName();
    this -> Milk::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}

int Milk::GetDaysToExpire() const {
    return DaysToExpire;
}

Bread::Bread(Product product, int daysToExpire) {
    this -> Bread::Name = product.GetName();
    this -> Bread::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}

void Bread::Print() {
    Product::Print();
    cout << "Days To Expire:" << DaysToExpire <<"\n" ;
}

int Bread::GetDaysToExpire() const {
    return DaysToExpire;
}

Water::Water(Product product, int daysToExpire) {
    this -> Water::Name = product.GetName();
    this -> Water::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}

void Water::Print() {
    Product::Print();
    cout << "Days to expire: " << DaysToExpire << "\n";
}
