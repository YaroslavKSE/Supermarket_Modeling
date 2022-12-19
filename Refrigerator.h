#ifndef LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H
#define LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H

#include "Product.h"
#include "Shelve.h"
#include <vector>

using namespace std;

class Refrigerator : public Shelve{
public:
    Refrigerator(int temperature, vector<Product*> products);

    Refrigerator();

    void AddProduct(Product* product) override;

    Product* GetFirstProduct() override;

    void Print() override;

    void NextDay() override;

    void RemoveProduct(const string& name) override;

    void SetTemperature(int number);

private:
    int temperature;
    vector<Product*> Products;

};


#endif //LAB_2_SUPERMARKET_MODELING_REFRIGERATOR_H