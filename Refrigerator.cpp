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

void Refrigerator::NextDay() {
    int i = 0;
    for (auto & Product : Products) {
        auto *check = dynamic_cast<Milk*>(Product);
        if(nullptr != dynamic_cast<Milk*>(Product)){
            if(check->GetDaysToExpire() == 1){
                check->Print();
                Products.erase(Products.begin() + i);
                continue;
            }
        }
        auto *check2 = dynamic_cast<Eggs*>(Product);
        if(nullptr != dynamic_cast<Eggs*>(Product)){
            if(check2->GetDaysToExpire() == 1){
                check2->Print();
                Products.erase(Products.begin() + i);
                continue;
            }
        }
        i++;
    }
}

void Refrigerator::RemoveProduct(string name) {
    for (int i = 0; i < Products.size(); ++i) {
        if(Products[i]->GetName() == name){
            Products.erase(Products.begin() + i);
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


Refrigerator::Refrigerator() = default;