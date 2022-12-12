#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"

int main() {
    Product bread("White", 2);
    Product bread2("Black", 3);
    Product bread3;
    Shelve shelve1;
    FileReader fileReader("products.txt");
    vector<string> records = fileReader.ReadText();
    shelve1.AddProduct(bread);
    shelve1.AddProduct(bread2);
    return 0;
}
