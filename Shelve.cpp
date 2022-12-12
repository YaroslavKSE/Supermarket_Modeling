#include "Shelve.h"

Shelve::Shelve(vector <Product> products) : Products(products) {}

Shelve::Shelve()
= default;

void Shelve::AddProduct(Product product)
{
    Products.push_back(product);
}