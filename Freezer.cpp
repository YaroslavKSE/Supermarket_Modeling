
#include "Freezer.h"

Freezer::Freezer(int temperature, vector<Product*> products) : temperature(temperature), Products(move(products)) {}

void Freezer::AddProduct(Product *product) {
    Products.push_back(product);
}

void Freezer::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}

Freezer::Freezer() = default;
