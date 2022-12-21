#include "Refrigerator.h"


Refrigerator::Refrigerator(int temperature, vector<Product*> products) : temperature(temperature),
                                                                         Products(move(products)) {}

void Refrigerator::AddProduct(Product *product) {
    if (Capacity != maxSize) {
        Products.push_back(product);
        Capacity++;
    }
    else{
        cout << "Failed to add product"; product->Print(); cout <<"\n";
    }
}

void Refrigerator::Print() {
    for (auto & Product : Products) {
        Product->Print();
    }
}

void Refrigerator::NextDay() {
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

void Refrigerator::RemoveProduct(const string& name) {
    for (int i = 0; i < Products.size(); ++i) {
        if(Products[i]->GetName() == name){
            Products.erase(Products.begin() + i);
            Capacity--;
            break;
        }
    }
}

Product *Refrigerator::GetFirstProduct() {
    return Products[0];
}

void Refrigerator::SetTemperature(int number) {
    if (number > 10 || number < -5){
        cout << "You can't set temperature above than 10 or less than -5" << "\n";
    } else{
        temperature = number;
        cout << "Successfully set temperature to: " << number << "\n";
    }
}

int Refrigerator::GetCapacity() {
    return Capacity;
}


Refrigerator::Refrigerator() = default;