#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"

int main() {
    Product bread("White", 2, "bread");
    Product bread2("Black", 3, "bread");
    ProductWithDD milk1(Product("Yahotynske", 0.7, "Milk"), 14);
    ProductWithDD eggs(Product("YasenSvit", 0.1, "eggs"), 30);

    vector<Product> productsOnShelve;
    Shelve shelve1;

    FileReader fileReader("products.txt");
    vector<string> records = fileReader.ReadText();

    shelve1.AddProduct(bread);
    shelve1.AddProduct(bread2);
    return 0;
}
