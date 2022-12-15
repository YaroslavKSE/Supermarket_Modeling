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

void Shelve::NextDay() {
    int i = 0;
    for (auto & Product : Products) {
        auto *check = dynamic_cast<Bread*>(Product);
        if(nullptr != dynamic_cast<Bread*>(Product)){
            if(check->GetDaysToExpire() == 1){
                check->Print();
                Products.erase(Products.begin() + i);
                continue;
            }
        }
        auto *check2 = dynamic_cast<Water*>(Product);
        if(nullptr != dynamic_cast<Water*>(Product)){
            if(check2->GetDaysToExpire() == 1){
                check2->Print();
                Products.erase(Products.begin() + i);
                continue;
            }
        }
        i++;
    }

}

void Shelve::RemoveProduct(string name) {
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
