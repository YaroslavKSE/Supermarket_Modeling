#include "Shelve.h"

#include <utility>

Shelve::Shelve(vector <Product*> products) : Products(std::move(products)) {}

Shelve::Shelve()
= default;

void Shelve::AddProduct(Product* product)
{
    Products.push_back(product);
}

void Shelve::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}
