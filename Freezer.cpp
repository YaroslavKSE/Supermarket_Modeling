
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

void Freezer::NextDay() {
    // may be needed in future
}

void Freezer::RemoveProduct(string product, string name) {
    for (int i = 0; i < Products.size(); ++i) {
        if(Products[i]->GetName() == name){
            Products.erase(Products.begin() + i);
        }
    }
}

Product *Freezer::GetFirstProduct() {
    return Products[0];
}

Freezer::Freezer() = default;
