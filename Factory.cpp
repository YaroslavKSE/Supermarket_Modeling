#include "Factory.h"

Factory::Factory() = default;

void Factory::GenerateProducts(int amount) {
    FillProducts();
    FillNames();
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> dist(0, 6); // define the range
    for (int n = 0; n < amount; ++n) {
        int random = dist(gen);
        if(TypesOfProduct[random] == "Bread"){
            float weight = float(dist(gen)) / 10 * 3 + 0.2;
            Product* bread = new Bread(Product(BreadNames[dist(gen)], weight), dist(gen));
            Stock.push_back(bread);
            continue;
        }
        if(TypesOfProduct[random] == "Water"){
            float weight = dist(gen) * dist(gen);
            Product* water = new Water(Product(WaterNames[dist(gen)], weight), 365);
            Stock.push_back(water);
            continue;
        }
        if(TypesOfProduct[random] == "Milk"){
            float weight = float(dist(gen)) / 10 * 3 + 0.3;
            int days = dist(gen) * 4 + 1;
            Product* milk = new Milk(Product(MilkNames[dist(gen)], weight), days);
            Stock.push_back(milk);
            continue;
        }
        if(TypesOfProduct[random] == "Eggs"){
            float weight = float(dist(gen))/ 10 + 0.05;
            int days = dist(gen) * 4 + 1;
            int number = dist(gen) * 2 + 6;
            Product* eggs = new Eggs(Product(EggsNames[dist(gen)], weight), days, number);
            Stock.push_back(eggs);
            continue;
        }
        if(TypesOfProduct[random] == "Fish"){
            float weight = float(dist(gen))/ 10 * 3 + 0.2;
            Product* fish = new Fish(Product(FishNames[dist(gen)], weight));
            Stock.push_back(fish);
            continue;
        }
        if(TypesOfProduct[random] == "Meat"){
            float weight = float(dist(gen))/ 10 * 4 + 0.2;
            Product* meat = new Meat(Product(MeatNames[dist(gen)], weight));
            Stock.push_back(meat);
            continue;
        }
        if(TypesOfProduct[random] == "Soap"){
            float weight = float(dist(gen))/ 10 * 3 + 0.1;
            Product* soap = new Soap(Product(SoapNames[dist(gen)], weight));
            Stock.push_back(soap);
            continue;
        }
    }

}

void Factory::FillProducts() {
    TypesOfProduct = {
            {0, "Bread"}, {1, "Water"}, {2, "Milk"}, {3, "Eggs"},
            {4, "Fish"}, {5, "Meat"}, {6, "Soap"}
    };
}

void Factory::FillNames() {
    // FillMilk
    MilkNames.emplace_back("Galychyna");  MilkNames.emplace_back("Ferma");
    MilkNames.emplace_back("Selyanske");  MilkNames.emplace_back("Prostokvashyno");
    MilkNames.emplace_back("Molokiya");   MilkNames.emplace_back("Voloshkove Pole");
    MilkNames.emplace_back("Yahotynske");
    // FillWater
    WaterNames.emplace_back("Morshynska"); WaterNames.emplace_back("Buvette");
    WaterNames.emplace_back("Karpatskya Dzerelna"); WaterNames.emplace_back("REO");
    WaterNames.emplace_back("Myrhorodska"); WaterNames.emplace_back("Borzhomi");
    WaterNames.emplace_back("Borzhomi");
    // FillEggs
    EggsNames.emplace_back("Yasensvit"); EggsNames.emplace_back("Kvochka");
    EggsNames.emplace_back("Ecodar"); EggsNames.emplace_back("Petyhov");
    EggsNames.emplace_back("Dytyachi"); EggsNames.emplace_back("Kvochkyno");
    EggsNames.emplace_back("Moodily");
    // FillBread
    BreadNames.emplace_back("White Bread"); BreadNames.emplace_back("Black Bread");
    BreadNames.emplace_back("Borodynskiy"); BreadNames.emplace_back("Finskiy");
    BreadNames.emplace_back("Lvivskiy"); BreadNames.emplace_back("Rosilini");
    BreadNames.emplace_back("Domashiy");
    // FillFish
    FishNames.emplace_back("Salmon"); FishNames.emplace_back("Tuna");
    FishNames.emplace_back("Tuna"); FishNames.emplace_back("Schuka");
    FishNames.emplace_back("Hek"); FishNames.emplace_back("Forel");
    FishNames.emplace_back("Dorado");
    // FillMeat
    MeatNames.emplace_back("Pork"); MeatNames.emplace_back("Veal");
    MeatNames.emplace_back("Mutton"); MeatNames.emplace_back("Chicken");
    MeatNames.emplace_back("Beef"); MeatNames.emplace_back("Venison");
    MeatNames.emplace_back("Rabbit");
    // FillSoap
    SoapNames.emplace_back("Dove"); SoapNames.emplace_back("Domestos");
    SoapNames.emplace_back("Mr.Proper"); SoapNames.emplace_back("Mr.Muscle");
    SoapNames.emplace_back("Palmolive"); SoapNames.emplace_back("Nivea");
    SoapNames.emplace_back("HeadAndShoulders");
}

vector<Product *> Factory::GetStock() {
    return Stock;
}
