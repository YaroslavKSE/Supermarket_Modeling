#include "Product.h"
Product::Product(string name, float weight, string type) : Name(move(name)), Weight(weight), type(type) {}

string Product::GetName() const {
    return Name;
}

float Product::GetWeight() const {
    return Weight;
}

string Product::GetType() const {
    return type;
}

Product::Product() = default;


ProductWithDD::ProductWithDD(const Product& product, int daysToExpire) {
    this -> ProductWithDD::Name = product.GetName();
    this -> ProductWithDD::Weight = product.GetWeight();
    this -> ProductWithDD::type = product.GetType();
    this -> DaysToExpire = daysToExpire;

}
