#ifndef LAB_2_SUPERMARKET_MODELING_FREEZER_H
#define LAB_2_SUPERMARKET_MODELING_FREEZER_H

#include "Product.h"
#include "Shelve.h"
#include <vector>

using namespace std;

class Freezer : public Shelve{
    int Capacity = 0;
public:
    Freezer(int temperature, vector<Product*> products);

    Freezer();

    int maxSize = 8;

    void AddProduct(Product* product) override;

    void Print() override;

    void NextDay() override;

    void SetTemperature(int number);

    Product* GetFirstProduct() override;

    void RemoveProduct(string name);

    int GetCapacity() override;

private:
    int temperature{};
    vector<Product*> Products;
};

#endif //LAB_2_SUPERMARKET_MODELING_FREEZER_H
