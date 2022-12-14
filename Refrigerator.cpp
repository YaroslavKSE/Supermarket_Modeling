#include "Refrigerator.h"


Refrigerator::Refrigerator(int temperature, vector<Product*> products) : temperature(temperature),
                                                                         Products(move(products)) {}

void Refrigerator::AddProduct(Product *product) {
    Products.push_back(product);
}

Refrigerator::Refrigerator() = default;