#include "Product.h"
Product::Product(string name, float weight): Name(move(name)), Weight(weight){}

Product::~Product() {
}

string Product::GetName() {
    return Name;
}

float Product::GetWeight() {
    return Weight;
}

Product::Product() = default;


Eggs::Eggs(Product product, int daysToExpire, int numberOfEggs){
    this -> Eggs::Name = product.GetName();
    this -> Eggs::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
    this -> NumberOfEggs = numberOfEggs;

}

Milk::Milk(Product product, int daysToExpire) {
    this -> Milk::Name = product.GetName();
    this -> Milk::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}

Bread::Bread(Product product, int daysToExpire) {
    this -> Bread::Name = product.GetName();
    this -> Bread::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}

Water::Water(Product product, int daysToExpire) {
    this -> Water::Name = product.GetName();
    this -> Water::Weight = product.GetWeight();
    this -> DaysToExpire = daysToExpire;
}
