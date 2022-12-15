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

vector<Product *> Refrigerator::NextDay() {
    vector<Product*> nextDayProducts;
    for (auto & Product : Products) {
        auto *check = dynamic_cast<Milk*>(Product);
        if(nullptr != dynamic_cast<Milk*>(Product)){
            if(check->GetDaysToExpire() == 1){
                check->Print();
                nextDayProducts.push_back(check);
            }
        }
        auto *checkEggs = dynamic_cast<Eggs*>(Product);
        if(nullptr != dynamic_cast<Eggs*>(Product)){
            if(checkEggs->GetDaysToExpire() == 1){
                checkEggs->Print();
                nextDayProducts.push_back(checkEggs);
            }
        }
    }
    return nextDayProducts;
}


Refrigerator::Refrigerator() = default;