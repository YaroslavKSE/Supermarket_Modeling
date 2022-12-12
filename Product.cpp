#include "Product.h"
Product::Product(string name, int weight): Name(move(name)), Weight(weight){}

Product::Product() = default;

//Milk::Milk(int daysToExpire): Product(), DaysToExpire(daysToExpire) {}

Eggs::Eggs(int daysToExpire, int numberOfEggs): DaysToExpire(daysToExpire), NumberOfEggs(numberOfEggs){}

Milk::Milk(const Product& product, int daysToExpire) {
    this -> Milk::Name = Product::Name;
    this -> Milk::Weight = Product::Weight;
    this -> DaysToExpire = daysToExpire;
}
