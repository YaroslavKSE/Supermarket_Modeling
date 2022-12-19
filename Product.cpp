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
    this -> DueDateChecker::Name = product.GetName();
    this -> DueDateChecker::Weight = product.GetWeight();
    this -> NumberOfEggs = numberOfEggs;
    DueDateChecker::DaysToExpire = daysToExpire;
}

void Eggs::Print() {
    DueDateChecker::Print();
    cout << "Days To Expire:" << DaysToExpire << " Number of eggs:" << NumberOfEggs << "\n";

}


Milk::Milk(Product product, int daysToExpire) {
    this -> Milk::Name = product.GetName();
    this -> Milk::Weight = product.GetWeight();
    DueDateChecker::DaysToExpire = daysToExpire;
}


void Milk::Print() {
    DueDateChecker::Print();
    cout << "Days To Expire:" << DaysToExpire <<"\n" ;
}

Bread::Bread(Product product, int daysToExpire) {
    this -> DueDateChecker::Name = product.GetName();
    this -> DueDateChecker::Weight = product.GetWeight();
    DueDateChecker::DaysToExpire = daysToExpire;
}

void Bread::Print() {
    DueDateChecker::Print();
    cout << "Days To Expire:" << DaysToExpire <<"\n" ;
}

Water::Water(Product product, int daysToExpire) {
    this -> DueDateChecker::Name = product.GetName();
    this -> DueDateChecker::Weight = product.GetWeight();
    DueDateChecker::DaysToExpire = daysToExpire;
}

void Water::Print() {
    DueDateChecker::Print();
    cout << "Days to expire: " << DaysToExpire << "\n";
}


bool DueDateChecker::IsValid() {
    if (DaysToExpire == 1){
        return true;
    }
    return false;
}

void DueDateChecker::Print() {
    Product::Print();
}


