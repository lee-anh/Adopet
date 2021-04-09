#include "peoplerandomizer.h"

PeopleRandomizer::PeopleRandomizer()
{
    //default 10 people are created
    numOfPeople = 10;
    initalizeNameVecs();
    openDB();
    loadDBVecs();

    //clear old data in csvs
    csv1.open("../../csvs/accounts.csv", ofstream::out | ofstream::trunc);
    csv1.close();

    csv2.open("../../csvs/adopters.csv", ofstream::out | ofstream::trunc);
    csv2.close();

    csv3.open("../../csvs/preferences.csv", ofstream::out | ofstream::trunc);
    csv3.close();

    srand(time(0));

}

PeopleRandomizer::PeopleRandomizer(int num){
    numOfPeople = num;
    initalizeNameVecs();
    openDB();
    loadDBVecs();

    //clear old data in csvs
    csv1.open("../../csvs/accounts.csv", ofstream::out | ofstream::trunc);
    csv1.close();

    csv2.open("../../csvs/adopters.csv", ofstream::out | ofstream::trunc);
    csv2.close();

    csv3.open("../../csvs/preferences.csv", ofstream::out | ofstream::trunc);
    csv3.close();

    srand(time(0));

}

PeopleRandomizer::~PeopleRandomizer(){

}

void PeopleRandomizer::writeToCSV(){



    int counter = 1;
    while(counter <= numOfPeople){
        //user info FOR ADOPTERS ONLY RIGHT NOW
        string username = "user" + to_string(counter);
        string password = "password" + to_string(counter);
        string accountType = "adopter";

        //write to accounts.csv
        csv1.open("../../csvs/accounts.csv", ios_base::app);
        //cout << username << "," << password << "," << accountType << "\n";
        csv1 << username << "," << password << "," << accountType << "\n";
        csv1.close();


        int rand1 = rand() % (int) firstNames.size();
        string fName = firstNames.at(rand1);
        int rand2 = rand() % lastNames.size();
        string lName = lastNames.at(rand2);
        string email = fName + lName + "@gmail.com";
        int zip = rand() % 224 + 15201; //valid zip in PA

        //write to adopters.csv
        csv2.open("../../csvs/adopters.csv", ios_base::app);
        csv2 << username << "," << fName << "," << lName << "," <<
                email << "," << zip << "\n";
        csv2.close();



        //preferences

        //species
        vector<string> userSpecies = vector<string>();
        int speciesRand = (rand() % species.size()) + 1;

        for(int i = 0;  i < speciesRand; i++){
            int speciesRand1 = rand() % species.size();

            string toAdd = species.at(speciesRand1);
            userSpecies.push_back(toAdd);
        }

        //get rid of duplicates
        sort(userSpecies.begin(), userSpecies.end());
        userSpecies.erase(unique(userSpecies.begin(), userSpecies.end()), userSpecies.end());


        //BREED IS A LITTLE MORE COMPLICATED
        //make sure the breed has a species type that fits a user species preference
        vector<string> userBreed = vector<string>();
        int breedRand = (rand() % breed.size()) + 1;



        for(int i = 0;  i < breedRand; i++){
            int rand1 = rand() % breed.size();

            string toAdd = breed.at(rand1).first;
            userBreed.push_back(toAdd);
        }

        /*
        for(int i = 0;  i < breedRand; i++){
            int rand2 = rand() % breed.size();

            bool stop = false;
            string toAdd;
            while(stop == false){
                string spec = breed.at(rand2).second;
                for(int j = 0; j < (int) userSpecies.size(); j++){
                    if(spec == userSpecies.at(j)){
                        toAdd = breed.at(rand2).first;

                    }
                }
                rand2 = rand() % breed.size();

            }

            userBreed.push_back(toAdd);
        }
        */

        //get rid of duplicates
        sort(userBreed.begin(), userBreed.end());
        userBreed.erase(unique(userBreed.begin(), userBreed.end()), userBreed.end());





        //age
        vector<string> userAge = vector<string>();
        int ageRand = (rand() % age.size()) + 1;

        for(int i = 0;  i < ageRand; i++){
            int rand2 = rand() % age.size();

            string toAdd = age.at(rand2);
            userAge.push_back(toAdd);
        }

        //get rid of duplicates
        sort(userAge.begin(), userAge.end());
        userAge.erase(unique(userAge.begin(), userAge.end()), userAge.end());



        //size
        vector<string> userSize = vector<string>();
        int szRand = (rand() % size.size()) + 1;

        for(int i = 0;  i < szRand; i++){
            int rand2 = rand() % size.size();

            string toAdd = size.at(rand2);
            userSize.push_back(toAdd);
        }
        //get rid of duplicates
        sort(userSize.begin(), userSize.end());
        userSize.erase(unique(userSize.begin(), userSize.end()), userSize.end());


        //temperament
        vector<string> userTemp = vector<string>();
        int teRand = (rand() % temperament.size()) + 1;

        for(int i = 0;  i < teRand; i++){
            int rand2 = rand() % temperament.size();

            string toAdd = temperament.at(rand2);
            userTemp.push_back(toAdd);
        }
        //get rid of duplicates
        sort(userTemp.begin(), userTemp.end());
        userTemp.erase(unique(userTemp.begin(), userTemp.end()), userTemp.end());


        //gender
        vector<string> userGender = vector<string>();
        int geRand = (rand() % gender.size()) + 1;

        for(int i = 0;  i < geRand; i++){
            int rand2 = rand() % gender.size();

            string toAdd = gender.at(rand2);
            userGender.push_back(toAdd);
        }
        //get rid of duplicates
        sort(userGender.begin(), userGender.end());
        userGender.erase(unique(userGender.begin(), userGender.end()), userGender.end());

        //goodWith
        vector<string> userGW = vector<string>();
        int gwRand = (rand() % goodWith.size()) + 1;

        for(int i = 0;  i < gwRand; i++){
            int rand2 = rand() % goodWith.size();

            string toAdd = goodWith.at(rand2);
            userGW.push_back(toAdd);
        }
        //get rid of duplicates
        sort(userGW.begin(), userGW.end());
        userGW.erase(unique(userGW.begin(), userGW.end()), userGW.end());

        //shelter
        vector<string> userShelter = vector<string>();
        int seRand = (rand() % shelter.size()) + 1;

        for(int i = 0;  i < seRand; i++){
            int rand2 = rand() % shelter.size();

            string toAdd = shelter.at(rand2);
            userShelter.push_back(toAdd);
        }
        //get rid of duplicates
        sort(userShelter.begin(), userShelter.end());
        userShelter.erase(unique(userShelter.begin(), userShelter.end()), userShelter.end());


        //write to CSV
        csv3.open("../../csvs/preferences.csv", ios_base::app);


        for(int i = 0; i < (int) userSpecies.size(); i++){
            csv3 << username << "," <<userSpecies.at(i) << ",species\n";
        }

        for(int i = 0; i < (int) userBreed.size(); i++){
            csv3 << username << "," << userBreed.at(i) << ",breed\n";
        }

        for(int i = 0; i < (int) userAge.size(); i++){
            csv3 << username << "," <<userAge.at(i) << ",age\n";
        }

        for(int i = 0; i < (int) userSize.size(); i++){
            csv3 << username << "," << userSize.at(i) << ",size\n";
        }

        for(int i = 0; i < (int) userTemp.size(); i++){
            csv3 << username << "," << userTemp.at(i) << ",temperament\n";
        }

        for(int i = 0; i < (int) userGender.size(); i++){
            csv3 << username << ","<< userGender.at(i) << ",gender\n";
        }

        for(int i = 0; i < (int) userGW.size(); i++){
            csv3 << username << "," << userGW.at(i) << ",goodWith\n";
        }

        for(int i = 0; i < (int) userShelter.size(); i++){
            csv3 << username << "," << userShelter.at(i) << ",shelter\n";
        }
        csv3.close();



        counter++;
    }

}




void PeopleRandomizer::openDB(){
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

void PeopleRandomizer::loadDBVecs(){
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
            string t = query.value(0).toString().toStdString();
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

void PeopleRandomizer::initalizeNameVecs(){
    firstNames = {
       "Oliver", "Liam", "Ethan", "Aiden", "Gabriel", "Caleb", "Theo", "Owen",
        "Elijah", "Henry", "Jackson", "Grayson", "Levi", "Ben", "Miles", "Alex",
        "Sebastian", "Leo", "Landon", "Emmett", "Everett", "Milo", "Jasper",
        "Lucas", "Noah", "Harrison", "Charlotte", "Ava", "Amelia", "Olivia",
        "Aurora", "Violet", "Luna", "Hazel", "Chloe", "Aria", "Scarlett",
        "Abigail", "Freya", "Adeline", "Sophia", "Nora", "Adelaide", "Emma",
        "Mila", "Lily", "Grace", "Maeve", "Ivy", "Ella", "Audrey",
        "Genevieve", "Iris", "Isabelle", "Lucy"
    };
    lastNames = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Miller",
                "Davis", "Garcia", "Rodriguez", "Wilson", "Martinez", "Anderson",
                 "Taylor", "Thomas", "Hernandez", "Moore", "Martin", "Jackson",
                 "White", "Lopez", "Lee", "Gonzalez", "Harris", "Clark", "Lewis",
                 "Robinson", "Walker", "Perez", "Hall", "Tang", "Zhang", "An",
                 "Guo", "Ge", "Ming", "Zhu"
                };

    age = {"young", "adult","senior"};
    gender = {"male", "female"};
    size = {"small", "medium", "large"};
}


void PeopleRandomizer::speciesTest(){
    vector<string> userSpecies = vector<string>();
    //how many to add
    int speciesRand = (rand() % species.size()) + 1;

    for(int i = 0;  i < speciesRand; i++){
        int speciesRand1 = rand() % species.size();

        string toAdd = species.at(speciesRand1);
        userSpecies.push_back(toAdd);
    }

    //get rid of duplicates
    sort(userSpecies.begin(), userSpecies.end());
    userSpecies.erase(unique(userSpecies.begin(), userSpecies.end()), userSpecies.end());

    for(int i = 0; i < (int) userSpecies.size(); i++){
        cout << userSpecies.at(i) << endl;
    }

}
