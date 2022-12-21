
#include "Freezer.h"

Freezer::Freezer(int temperature, vector<Product*> products) : temperature(temperature), Products(move(products)) {}

void Freezer::AddProduct(Product *product) {
    if (Capacity != maxSize) {
        Products.push_back(product);
        Capacity++;
    }
    else{
        cout << "Failed to add product"; product->Print(); cout <<"\n";
    }
}

void Freezer::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}

void Freezer::NextDay() {
    // may be needed in future
}

void Freezer::RemoveProduct(string name) {
    for (int i = 0; i < Products.size(); ++i) {
        if(Products[i]->GetName() == name){
            Products.erase(Products.begin() + i);
            Capacity--;
            break;
        }
    }
}

Product *Freezer::GetFirstProduct() {
    return Products[0];
}

void Freezer::SetTemperature(int number) {
    if (number > 0){
        cout << "You can't set temperature above than 0" << "\n";
    } else{
        temperature = number;
        cout << "Successfully set temperature to: " << number << "\n";
    }
}

int Freezer::GetCapacity() {
    return Capacity;
}

Freezer::Freezer() = default;
