#include "Refrigerator.h"


Refrigerator::Refrigerator(int temperature, vector<Product*> products) : temperature(temperature),
                                                                         Products(move(products)) {}

void Refrigerator::AddProduct(Product *product) {
    Products.push_back(product);
}

void Refrigerator::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}

Refrigerator::Refrigerator() = default;