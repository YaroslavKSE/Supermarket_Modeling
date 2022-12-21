#include "Shelve.h"

Shelve::Shelve(vector <Product*> products) : Products(std::move(products)) {}

Shelve::Shelve()
= default;

void Shelve::AddProduct(Product* product)
{

    if (Capacity != maxSize) {
        Products.push_back(product);
        Capacity++;
    }
    else{
        cout << "Failed to add product"; product->Print(); cout <<"\n";
    }
}

void Shelve::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}

void Shelve::NextDay() {
    int i = 0;
    for (auto & Product : Products) {
        auto *check = dynamic_cast<Checker*>(Product);
        if(nullptr != dynamic_cast<Checker*>(Product) && check->IsValid()){
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
            Capacity--;
            break;
        }
    }
}

Product *Shelve::GetFirstProduct() {
    return Products[0];
}

int Shelve::GetCapacity() {
    return Capacity;
}
