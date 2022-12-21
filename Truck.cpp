#include "Truck.h"

Truck::Truck() = default;

void Truck::FillTruck(vector<Product *> products) {
    float totalWeightLoaded = 0;
    for (auto & product : products) {
        totalWeightLoaded += product->GetWeight();
        if(product->GetWeight() <= totalWeightLoaded && totalWeightLoaded <= maxCapacity){
            productsToDeliver.push_back(product);
        }
        else{
            cout << "Can't take from Factory:";
            product->Print(); cout << "\n";
        }
    }
}

void Truck::SetMaxCapacity(float number) {
    maxCapacity = number;
}

vector<Product*> Truck::UnLoad() {
    return productsToDeliver;
}

void Truck::Print() {
    cout << "Products that are loaded in truck:" << "\n";
    for (auto & i : productsToDeliver) {
        i->Print();
    }
}
