#include "Shelve.h"

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

void Shelve::NextDay() {
    int i = 0;
    for (auto & Product : Products) {
        auto *check = dynamic_cast<DueDateChecker*>(Product);
        if(nullptr != dynamic_cast<DueDateChecker*>(Product) && check->IsValid()){
            check->Print();
            Products.erase(Products.begin() + i);
            continue;
            }
        i++;
    }
}


void Shelve::RemoveProduct(const string& name) {
    for (int i = 0; i < Products.size(); ++i) {
        if(Products[i]->GetName() == name){
            Products.erase(Products.begin() + i);
            break;
        }
    }
}

Product *Shelve::GetFirstProduct() {
    return Products[0];
}
