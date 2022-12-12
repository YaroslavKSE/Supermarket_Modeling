#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"

int main() {
    Product bread("White", 2);
    Product bread2("Black", 3);
    Shelve shelve1;
    Fish fish("Schuka", 5);
    Meat meat("Pork", 3);
    Soap soap("Dove", 1);
//    Milk milk2(bread, 5); // not working
    FileReader fileReader("products.txt");
    vector<string> records = fileReader.ReadText();
    shelve1.AddProduct(bread);
    shelve1.AddProduct(bread2);
    return 0;
}
