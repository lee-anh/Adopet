#include "petrandomizer.h"

PetRandomizer::PetRandomizer()
{
    //default 10 people are created
    numOfPets = 10;
    initalizeNameVecs();
    openDB();
    loadDBVecs();

    //clear old data in csvs
    writeCsv.open("../../csvs/pets.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    writeCsv.open("../../csvs/adopters.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    writeCsv.open("../../csvs/preferences.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    srand(time(0));
}

PetRandomizer::PetRandomizer(int num){
    numOfPets = num;
    initalizeNameVecs();
    openDB();
    loadDBVecs();

    //clear old data in csvs
    writeCsv.open("../../csvs/accounts.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    writeCsv.open("../../csvs/adopters.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    writeCsv.open("../../csvs/preferences.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    srand(time(0));

}
