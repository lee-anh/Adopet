#include "petrandomizer.h"

PetRandomizer::PetRandomizer()
{
    //default 10 people are created
    numOfPets = 10;
    initializeNameVecs();
    openDB();

    //clear old data in csvs
    writeCsv.open("../../csvs/pets.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    srand(time(0));
}

PetRandomizer::PetRandomizer(int num){
    numOfPets = num;
    initializeNameVecs();
    openDB();

    writeCsv.open("../../csvs/pets.csv", ofstream::out | ofstream::trunc);
    writeCsv.close();

    srand(time(0));

}

void PetRandomizer::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    string fullName = "../../projectDB.sqlite";
    db.setDatabaseName(QString::fromStdString(fullName));
    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully\n";
    }
}

void PetRandomizer::initializeNameVecs(){
    names = {
       "Oliver", "Liam", "Ethan", "Aiden", "Gabriel", "Caleb", "Theo", "Owen",
        "Elijah", "Henry", "Jackson", "Grayson", "Levi", "Ben", "Miles", "Alex",
        "Sebastian", "Leo", "Landon", "Emmett", "Everett", "Milo", "Jasper",
        "Lucas", "Noah", "Harrison", "Charlotte", "Ava", "Amelia", "Olivia",
        "Aurora", "Violet", "Luna", "Hazel", "Chloe", "Aria", "Scarlett",
        "Abigail", "Freya", "Adeline", "Sophia", "Nora", "Adelaide", "Emma",
        "Mila", "Lily", "Grace", "Maeve", "Ivy", "Ella", "Audrey",
        "Genevieve", "Iris", "Isabelle", "Lucy"
    };
    age = {"young", "adult","senior"};
    gender = {"male", "female"};
    size = {"small", "medium", "large"};
    if(db.open()){
        QSqlQuery query = QSqlQuery();

        //species
        QString qs = "SELECT speciesType FROM species";
        query.exec(qs);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            species.push_back(s);
        }



        //breed
        QString qs2 = "SELECT breedType, speciesType FROM breed";
        query.exec(qs2);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            string t = query.value(1).toString().toStdString();
            breed.push_back(make_pair(s,t));
        }

        //temperament
        QString qs3 = "SELECT temperamentType FROM temperament";
        query.exec(qs3);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            temperament.push_back(s);
        }


        //goodWith
        QString qs4 = "SELECT goodWithType FROM goodWith";
        query.exec(qs4);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            goodWith.push_back(s);
        }


        //shelter
        QString qs5 = "SELECT shelterType FROM shelter";
        query.exec(qs5);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            shelter.push_back(s);
        }
    }
}

void PetRandomizer::writeToCSV(){
    //Do we not skip the first line?
    for(int i=0; i<numOfPets;i++){
        writeCsv.open("../../csvs/pets.csv", ios_base::app);

        int rand1 = rand() % (int) names.size();
        string petName = names.at(rand1);
        cout << petName << endl;
        int rand2 = rand() % (int) age.size();
        string petAge = age.at(rand2);
        cout << petAge << endl;
        int rand3 = rand() % (int) gender.size();
        string petGen = names.at(rand3);
        cout << petGen << endl;
        int rand4 = rand() % (int) size.size();
        string petSize = size.at(rand4);
        cout << petSize << endl;
        int rand5 = rand() % (int) goodWith.size();
        string petGoodWith = goodWith.at(rand5);
        cout << petGoodWith << endl;
        int rand6 = rand() % (int) shelter.size();
        string petShelter = shelter.at(rand6);
        cout << petShelter << endl;
        int rand7 = rand() % (int) temperament.size();
        string petTemp = temperament.at(rand7);
        cout << petTemp << endl;
        //Do we need to fit breed with species for now?
        int rand8 = rand() % (int) breed.size();
        string petBreed = breed.at(rand8).first;
        cout << petBreed << endl;
        string petSpecies = breed.at(rand8).second;
        cout << petSpecies << endl;

        writeCsv << i << ",";
        writeCsv << petName << "," << petSpecies << "," << petBreed << "," << petSize << "," << petTemp
                 << "," << petGen << "," << petGoodWith << "," << petShelter << "," << "Lorem ipsum";
        writeCsv << "\n";
        writeCsv.close();
    }
}
