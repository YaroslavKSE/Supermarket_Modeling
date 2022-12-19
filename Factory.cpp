#include "Factory.h"

Factory::Factory() = default;

void Factory::GenerateProducts() {
    FillProducts();
    FillNames();
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> dist(0, 6); // define the range
    for (int n = 0; n < 20; ++n) {
        int random = dist(gen);
        if(TypesOfProduct[random] == "Bread"){
            float weight = float(dist(gen)) / 10 * 3;
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
            float weight = float(dist(gen)) / 10 * 3;
            int days = dist(gen) * 4 + 1;
            Product* milk = new Milk(Product(MilkNames[dist(gen)], weight), days);
            Stock.push_back(milk);
            continue;
        }
        if(TypesOfProduct[random] == "Eggs"){
            float weight = float(dist(gen))/ 10;
            int days = dist(gen) * 4 + 1;
            int number = dist(gen) * 2 + 6;
            Product* eggs = new Eggs(Product(EggsNames[dist(gen)], weight), days, number);
            Stock.push_back(eggs);
            continue;
        }
//        if(TypesOfProduct[random] == "Fish"){
//            Product* fish = new Fish("das", 2);
//            Stock.push_back(fish);
//            continue;
//        }
//        if(TypesOfProduct[random] == "Meat"){
//            Product* meat = new Meat("das", 2);
//            Stock.push_back(meat);
//            continue;
//        }
//        if(TypesOfProduct[random] == "Soap"){
//            Product* soap = new Soap("das", 2);
//            Stock.push_back(soap);
//            continue;
//        }
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
}
