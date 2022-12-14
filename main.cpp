#include "Product.h"
#include "Shelve.h"
#include "FileReader.h"

int main() {

    Product* eggs = new Eggs(Product("Yasensvit", 0.1), 30, 20);
    Product* eggs2 = new Eggs(Product("Yasensvit", 0.1), 20, 10);
    Product* fish = new Fish("Schuka", 2);
    Product* meat = new Meat("Pork", 3);
    Product* soap = new Soap("Dove", 0.7);
    Product* milk = new Milk(Product("Yahotunske", 1), 14);
    vector<Product*> shelve;
    shelve.push_back(eggs);
    shelve.push_back(fish);
    shelve.push_back(meat);
    shelve.push_back(milk);
    shelve.push_back(eggs2);
    Eggs* eggs1 = dynamic_cast<Eggs*>(shelve[0]); // to check if the element in array is eggs
    Eggs* eggs3 = dynamic_cast<Eggs*>(shelve[4]);
    vector<Product> productsOnShelve;
    Shelve shelve1;
    shelve1.AddProduct(fish);
    shelve1.AddProduct(eggs);
    FileReader fileReader("products.txt");
    vector<string> records = fileReader.ReadText();


    return 0;
}
