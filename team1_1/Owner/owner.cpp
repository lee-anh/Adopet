#include "owner.h"

Owner::Owner(string t){
    if(t == "Shelter Owner" || t == "Foster Parent") ownerType = t;
    else ownerType = "";
}

Owner::Owner(string n, string oT, string a, int zip, int pN, string e){
    name = n;
    ownerType = oT;
    address = a;
    zipCode = zip;
    phoneNumber = pN;
    email = e;
}

/*
 * Gets the owner type of the owner
 * @return The owner type of the owner
*/
string Owner::getOwnerType(){
    return ownerType;
}

/*
 * Sets the name of the owner
 * @param n The name of the owner
*/
void Owner::setName(string n){
    name = n;
}

/*
 * Gets the name of the owner
 * @return The name of the owner
*/
string Owner::getName(){
    return name;
}

/*
 * Sets the address of the owner
 * @param a The address of the owner
*/
void Owner::setAddress(string a){
    address = a;
}

/*
 * Gets the address of the owner
 * @return The address of the owner
*/
string Owner::getAddress(){
    return address;
}

/*
 * Sets the zip code of the owner
 * @param z The zip code of the owner
*/
void Owner::setZipCode(int z){
    zipCode = z;
}

/*
 * Gets the zip code of the owner
 * @return The zip code of the owner
*/
int Owner::getZipCode(){
    return zipCode;
}

/*
 * Sets the phone number of the owner
 * @param p The phone number of the owner
*/
void Owner::setPhoneNumber(int p){
    phoneNumber = p;
}

/*
 * Gets the phone number of the owner, for contact information
 * @return The phone number of the owner
*/
int Owner::getPhoneNumber(){
    return phoneNumber;
}

/*
 * Sets the email of the owner
 * @param e The email of the owner
*/
void Owner::setEmail(string e){
    email = e;
}

/*
 * Gets the email of the owner, for contact information
 * @return The email of the owner
*/
string Owner::getEmail(){
    return email;
}

/*
 * Creates a Pet object with the information present in the passed query
 * @param query A QSqlQuery object
 * @return A new Pet object with the retrieved information
*/
Pet Owner::makePet(QSqlQuery query){
    //storing information in each line
    string name = query.value(1).toString().toStdString();
    string species = query.value(2).toString().toStdString();
    string breed = query.value(3).toString().toStdString();
    string age = query.value(4).toString().toStdString();
    string size = query.value(5).toString().toStdString();
    string temperament = query.value(6).toString().toStdString();
    string gender = query.value(7).toString().toStdString();
    string goodWith = query.value(8).toString().toStdString();
    string shelter = query.value(9).toString().toStdString();
    string bio = query.value(10).toString().toStdString();

    Pet p = Pet(name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
    return p;
}

/*
 * Goes through the pets database and gets all the pets of the owner
 * Stores the pets in the 'pets' vector
*/
void Owner::fillPets(){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "ownerCxn");
    string fullName = "../../projectDB.sqlite";
    petsDB.setDatabaseName(QString::fromStdString(fullName));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        QString s = "SELECT id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio FROM pets";
        query.exec(s);
        while(query.next()){
            string shelter = query.value(9).toString().toStdString();
            if(shelter == name) {
                Pet pet = makePet(query);
                pets.push_back(pet);
            }
        }
    }

    petsDB.removeDatabase(petsDB.connectionName());
    petsDB.close();
}

/*
 * Gets the pets of the owner
 * @return All pets of the owner
*/
vector<Pet> Owner::getPets(){
    return pets;
}

/*
 * Uploads one pet at a time into the database
 * @param p Pet to be uploaded
*/
void Owner::uploadPet(Pet p){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "ownerCxn");
    string fullName = "../../projectDB.sqlite";
    petsDB.setDatabaseName(QString::fromStdString(fullName));

    QString s = "INSERT INTO pets(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio) VALUES(\"";
    s += QString::number(1000) + "\", ";    //arbitrary id
    s += QString::fromStdString(p.getName()) + "\", ";
    s += QString::fromStdString(p.getSpecies()) + "\", ";
    s += QString::fromStdString(p.getBreed()) + "\", ";
    s += QString::fromStdString(p.getAge()) + "\", ";
    s += QString::fromStdString(p.getSize()) + "\", ";
    s += QString::fromStdString(p.getTemperament()) + "\", ";
    s += QString::fromStdString(p.getGender()) + "\", ";
    s += QString::fromStdString(p.getGoodWith()) + "\", ";
    s += QString::fromStdString(p.getShelter()) + "\", ";
    s += QString::fromStdString(p.getBio()) + ")";

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        query.exec(s);
    }

    petsDB.removeDatabase(petsDB.connectionName());
    petsDB.close();
}

/*
 * Uses the passed fields to create a pet and adds it onto the database
 * @petFields List of pet data
*/
void Owner::addPetFromLine(QStringList petData){

    for (int i = 0; i < petData.size(); ++i){
              string element = petData.at(i).toStdString();
              cout << i << ": " << element << endl;
    }
    cout << endl;
}

/*
 * Reads a txt file containing all the pets an owner wants to add into the database
 * Uploads all the pets into the database
 * @file Txt file that contains all the pets to be uploaded
*/
void Owner::uploadPets(){
    QFile file("./pets.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        cout << "Error: file not opened!\n";
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList petData = line.split(",");
        addPetFromLine(petData);
    }

    file.close();
}
