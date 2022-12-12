#include "Product.h"
Product::Product(string name, int weight): Name(move(name)), Weight(weight){}

Product::Product() = default;
