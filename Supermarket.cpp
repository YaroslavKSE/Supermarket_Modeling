#include "Supermarket.h"

Supermarket::Supermarket() = default;

Supermarket::Supermarket(const vector<Refrigerator>& refrigerators, const vector<Freezer>& freezers,
                                             const vector<Shelve>& shelves) {
    this -> Refrigerators = refrigerators;
    this -> Freezers = freezers;
    this -> Shelves = shelves;
}

void Supermarket::AddFridge(const Refrigerator& fridge) {
    Refrigerators.push_back(fridge);
}

void Supermarket::AddToExactFridge(Product *const product, int number) {
    Refrigerators[number].AddProduct(product);

}

void Supermarket::AddFreezer(const Freezer& freezer) {
    Freezers.push_back(freezer);
}

void Supermarket::AddToExactFreezer(Product *const product, int number) {
    Freezers[number].AddProduct(product);

}

void Supermarket::AddShelve(const Shelve& shelve) {
    Shelves.push_back(shelve);
}

void Supermarket::AddToExactShelve(Product *const product, int number) {
    Shelves[number].AddProduct(product);
}

void Supermarket::View() {
    for (int i = 0; i < Shelves.size(); ++i) {
        cout << "Shelve #" << i << "\n";
        Shelves[i].Print();
    }
    for (int i = 0; i < Refrigerators.size(); ++i) {
        cout << "Refrigerator #" << i << "\n";
        Refrigerators[i].Print();
    }
    for (int i = 0; i < Freezers.size(); ++i) {
        cout << "Freezer #" << i << "\n";
        Freezers[i].Print();
    }
}

void Supermarket::ViewByType(const string& containerType) {
    if(containerType == "Shelve"){
        for (int i = 0; i < Shelves.size(); ++i) {
            cout << "Shelve #" << i << "\n";
            Shelves[i].Print();
        }
    }
    if(containerType == "Refrigerator"){
        for (int i = 0; i < Refrigerators.size(); ++i) {
            cout << "Refrigerator #" << i << "\n";
            Refrigerators[i].Print();
        }
    }
    if(containerType == "Freezer"){
        for (int i = 0; i < Freezers.size(); ++i) {
            cout << "Freezer #" << i << "\n";
            Freezers[i].Print();
        }
    }

}

void Supermarket::NextDay() {
    for (auto & Shelve : Shelves) {
        Shelve.NextDay();
    }

    for (auto & Refrigerator : Refrigerators) {
        Refrigerator.NextDay();
    }
//    for (auto & Freezer : Freezers) {
//        Freezer.NextDay();
//    }
}

void Supermarket::Take(const string& fromWhere, int number, const string& name) {
    if(fromWhere == "Shelve"){
        Shelves[number].RemoveProduct(name);
    }
    if(fromWhere == "Refrigerator"){
        Refrigerators[number].RemoveProduct(name);
    }
    if(fromWhere == "Freezer"){
        Freezers[number].RemoveProduct(name);
    }
}

void Supermarket::SetTemperature(const string& fridgeOrFreezer, int position, int number) {
    if(fridgeOrFreezer == "Freezer"){
        Freezers[position].SetTemperature(number);
    }
    if(fridgeOrFreezer == "Refrigerator"){
        Refrigerators[position].SetTemperature(number);
    }
}

void Supermarket::AddProduct(const vector<Product*>& products) {
    int SIndex = 0;
    int RIndex = 0;
    int FIndex = 0;
    for (auto & product : products) {
        auto *check = dynamic_cast<Checker*>(product);
        if(check->placeToPut == 'S'){
            if (Shelves[SIndex].GetCapacity() < Shelves[SIndex].maxSize)
            {
                Shelves[SIndex].AddProduct(product);
                continue;
            }
            if (Shelves[SIndex].GetCapacity() == Shelves[SIndex].maxSize && SIndex < Shelves.size()){
                SIndex++;
            }
            if(Shelves[SIndex - 1].GetCapacity() == Shelves[SIndex - 1].maxSize && SIndex == Shelves.size()){
                Shelve shelve;
                shelve.AddProduct(product);
                Shelves.push_back(shelve);
            }
        }
        if(check->placeToPut == 'R'){
            if (Refrigerators[RIndex].GetCapacity() < Refrigerators[RIndex].maxSize)
            {
                Refrigerators[RIndex].AddProduct(product);
                continue;
            }
            if (Refrigerators[RIndex].GetCapacity() == Refrigerators[RIndex].maxSize && RIndex < Refrigerators.size()){
                RIndex++;
            }
            if(Refrigerators[RIndex - 1].GetCapacity() == Refrigerators[RIndex - 1].maxSize && RIndex == Refrigerators.size()){
                Refrigerator refrigerator;
                refrigerator.AddProduct(product);
                Refrigerators.push_back(refrigerator);
            }
        }
        if(check->placeToPut == 'F'){
            if (Freezers[FIndex].GetCapacity() < Freezers[FIndex].maxSize)
            {
                Freezers[FIndex].AddProduct(product);
                continue;
            }
            if (Freezers[FIndex].GetCapacity() == Freezers[FIndex].maxSize && FIndex < Freezers.size()){
                FIndex++;
            }
            if(Freezers[FIndex - 1].GetCapacity() == Freezers[FIndex - 1].maxSize && FIndex == Freezers.size()){
                Freezer freezer;
                freezer.AddProduct(product);
                Freezers.push_back(freezer);
            }
        }
    }

}


