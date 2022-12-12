#include "Product.h"
#include "Shelve.h"


int main()
{
    Product bread("White", 2);
    Product bread2("Black", 3);
    Shelve shelve1;
    shelve1.AddProduct(bread); shelve1.AddProduct(bread2);
    return 0;
}
