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
    this -> Checker::Name = product.GetName();
    this -> Checker::Weight = product.GetWeight();
    this -> NumberOfEggs = numberOfEggs;
    Checker::DaysToExpire = daysToExpire;
    placeToPut = 'R';
}

void Eggs::Print() {
    Checker::Print();
    cout << "Days To Expire:" << DaysToExpire << " Number of eggs:" << NumberOfEggs << "\n";

}


Milk::Milk(Product product, int daysToExpire) {
    this -> Milk::Name = product.GetName();
    this -> Milk::Weight = product.GetWeight();
    Checker::DaysToExpire = daysToExpire;
    placeToPut = 'R';
}


void Milk::Print() {
    Checker::Print();
    cout << "Days To Expire:" << DaysToExpire <<"\n" ;
}

Bread::Bread(Product product, int daysToExpire) {
    this -> Checker::Name = product.GetName();
    this -> Checker::Weight = product.GetWeight();
    Checker::DaysToExpire = daysToExpire;
    placeToPut = 'S';
}

void Bread::Print() {
    Checker::Print();
    cout << "Days To Expire:" << DaysToExpire <<"\n" ;
}

Water::Water(Product product, int daysToExpire) {
    this -> Checker::Name = product.GetName();
    this -> Checker::Weight = product.GetWeight();
    Checker::DaysToExpire = daysToExpire;
    placeToPut = 'S';
}

void Water::Print() {
    Checker::Print();
    cout << "Days to expire: " << DaysToExpire << "\n";
}

Fish::Fish(Product product) {
    this -> Name = product.GetName();
    this -> Weight = product.GetWeight();
    placeToPut = 'F';
}

Meat::Meat(Product product) {
    this -> Name = product.GetName();
    this -> Weight = product.GetWeight();
    placeToPut = 'F';
}

Soap::Soap(Product product) {
    this -> Name = product.GetName();
    this -> Weight = product.GetWeight();
    placeToPut = 'S';
}

bool Checker::IsValid() {
    if (DaysToExpire == 1){
        return true;
    }
    return false;
}

void Checker::Print() {
    Product::Print();
}
