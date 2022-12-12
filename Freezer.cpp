
#include "Freezer.h"

Freezer::Freezer(int temperature, vector<Product> products) : temperature(temperature), products(move(products)) {}

Freezer::Freezer() = default;
