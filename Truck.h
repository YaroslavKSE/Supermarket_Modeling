#ifndef LAB_2_SUPERMARKET_MODELING_TRUCK_H
#define LAB_2_SUPERMARKET_MODELING_TRUCK_H


#include "Product.h"
#include "vector"

class Truck {
private:
    float maxCapacity{};
    vector<Product*> productsToDeliver;
public:
    Truck();
    void FillTruck(vector<Product*> products);
    void SetMaxCapacity(float number);
    vector<Product*> UnLoad();
};


#endif //LAB_2_SUPERMARKET_MODELING_TRUCK_H
