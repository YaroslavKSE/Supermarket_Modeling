#include "Refrigerator.h"


Refrigerator::Refrigerator(int temperature, vector<Product> products) : temperature(temperature),
                                                                        products(move(products)) {}

Refrigerator::Refrigerator() = default;