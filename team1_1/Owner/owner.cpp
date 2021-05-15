#include "owner.h"

Owner::Owner(){
    //default constructor
    //cout << "default constructor called (owner)" << endl;

    dbName = "../../projectDB.sqlite";
    openDB();
    lastPetID = getLastPetID();
}

Owner::Owner(string n, string a, int zip, long pN, string e){
    name = n;
    address = a;
    zipCode = zip;
    phoneNumber = pN;
    email = e;
    //cout << "simple constructor called (owner)" << endl;
    //openDB();
    //lastPetID = getLastPetID();
}

Owner::Owner(string database, string n, string a, int zip, long pN, string e){
    dbName = database;
    name = n;
    address = a;
    zipCode = zip;
    phoneNumber = pN;
    email = e;
    pets = vector<Pet>();
    openDB();
    //fillPets();
    lastPetID = getLastPetID();


}
Owner::~Owner(){
    petsDB.close();
}


/*
 * Loops through the database and retreives the last pet id used
 * @return Last pet ID
*/
int Owner::getLastPetID(){
    int lPI = 0;

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        QString s = "SELECT MAX(id) FROM pets";
        query.exec(s);
        while(query.next()){
            lPI = query.value(0).toInt();
        }
    }

    return lPI;
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
void Owner::setPhoneNumber(long p){
    phoneNumber = p;
}

/*
 * Gets the phone number of the owner, for contact information
 * @return The phone number of the owner
*/
long Owner::getPhoneNumber(){
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
    int id = query.value(0).toInt();
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

    Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);

    return p;
}

/*
 * Goes through the pets database and gets all the pets of the owner
 * Stores the pets in the 'pets' vector
*/
void Owner::fillPets(){
    pets.clear();
    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        string s = "SELECT id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio FROM pets WHERE shelter = \"" + name + "\"";
        QString qs = QString::fromStdString(s);
        query.exec(qs);
        while(query.next()){
            int id = query.value(0).toInt();
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

            Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            pets.push_back(p);
        }
    }
}

/*
 * Gets the pets of the owner
 * @return All pets of the owner
*/
vector<Pet> Owner::getPets(){
    return pets;
}

/*
 * Updates the specified Pet with new information provided by the owner
 * @param p Pet to be updated
*/
void Owner::updatePet(Pet p){
    QString s = "UPDATE pets SET ";
    s += "name = \"" + QString::fromStdString(p.getName()) + "\", ";
    s += "species = \"" + QString::fromStdString(p.getSpecies()) + "\", ";
    s += "breed = \"" + QString::fromStdString(p.getBreed()) + "\", ";
    s += "age = \"" + QString::fromStdString(p.getAge()) + "\", ";
    s += "size = \"" + QString::fromStdString(p.getSize()) + "\", ";
    s += "temperament = \"" + QString::fromStdString(p.getTemperament()) + "\", ";
    s += "gender = \"" + QString::fromStdString(p.getGender()) + "\", ";
    s += "goodWith = \"" + QString::fromStdString(p.getGoodWith()) + "\", ";
    s += "shelter = \"" + QString::fromStdString(p.getShelter()) + "\", ";
    s += "bio = \"" + QString::fromStdString(p.getBio()) + "\" ";
    s += "WHERE id = ";
    s += QString::number(p.getID()) + "";
    //cout << "query is: " << s.toStdString() << endl;

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        query.exec(s);
    }

    fillPets();
}

/*
 * Uploads one pet at a time into the database
 * @param p Pet to be uploaded
*/
void Owner::uploadPet(Pet p){
    p.setID(lastPetID + 1);

    //using given pet information in the query
    QString s1 = "INSERT INTO pets(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio) VALUES(";
    s1 += QString::number(p.getID()) + ", \"";
    s1 += QString::fromStdString(p.getName()) + "\", \"";
    s1 += QString::fromStdString(p.getSpecies()) + "\", \"";
    s1 += QString::fromStdString(p.getBreed()) + "\", \"";
    s1 += QString::fromStdString(p.getAge()) + "\", \"";
    s1 += QString::fromStdString(p.getSize()) + "\", \"";
    s1 += QString::fromStdString(p.getTemperament()) + "\", \"";
    s1 += QString::fromStdString(p.getGender()) + "\", \"";
    s1 += QString::fromStdString(p.getGoodWith()) + "\", \"";
    s1 += QString::fromStdString(p.getShelter()) + "\", \"";
    s1 += QString::fromStdString(p.getBio()) + "\")";

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        query.exec(s1);
    }

    //uploading the images of the pet into the media DB
    vector<string> images = p.getImageFiles();
    for(int i = 0; i < (int)images.size(); i++){
        QString s2 = "INSERT INTO media(petID, filename, mediaType) VALUES(";
        s2 += QString::number(p.getID()) + ", \"";
        s2 += QString::fromStdString(images.at(i)) + "\", \"";
        s2 += QString::fromStdString("image") + "\")";

        if(petsDB.open()){
            QSqlQuery query = QSqlQuery(petsDB);
            query.exec(s2);
        }
    }

    pets.push_back(p);
    lastPetID += 1;
}

/*
 * Removes the specified Pet from the owner and all DBs (pets, media)
 * @param p Pet to be removed
*/
void Owner::removePet(Pet p){
    //removing from pets
    QString s1 = "DELETE FROM pets WHERE id = ";
    s1 += QString::number(p.getID()) + "";
    //cout << "query is: " << s1.toStdString() << endl;

    //removing from media
    QString s2 = "DELETE FROM media WHERE petID = ";
    s2 += QString::number(p.getID()) + "";
    //cout << "query is: " << s2.toStdString() << endl;

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        query.exec(s1);
        query.exec(s2);
    }

    lastPetID = getLastPetID();
    fillPets();
}


/*
 * Creates a Pet object with the information present in the passed query
 * @param query A QSqlQuery object
 * @return A new Pet object with the retrieved information
*/

Pet Owner::makePet(QStringList petData){
    //checking if the passed qstringlist contains the correct amount of fields

    if(petData.size() != 11) {
        cout << "File content is not formatted correctly! A certain pet field is missing" << endl;
        return Pet();
    }
    else {
        //storing information in each line
        string name = petData.at(0).toStdString();
        string species = petData.at(1).toStdString();
        string breed = petData.at(2).toStdString();
        string age = petData.at(3).toStdString();
        string size = petData.at(4).toStdString();
        string temperament = petData.at(5).toStdString();
        string gender = petData.at(6).toStdString();
        string goodWith = petData.at(7).toStdString();
        string shelter = petData.at(8).toStdString();
        string bio = petData.at(9).toStdString();
        string mediaFiles = petData.at(10).toStdString();


        Pet p = Pet( name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
        vector<string> media = vector<string>();
        string word = "";
        for(int i = 0; i < (int)  mediaFiles.size(); i++){
            if(mediaFiles.at(i) == ' '){
                if(word.size() > 1){
                    media.push_back(word);
                }
                word = ""; //clear the word
            } else {
                word = word + mediaFiles[i];
            }

        }
        if(mediaFiles.size() > 1){
            media.push_back(word);
        }

        //add photos and vidoes
        for(int i = 0; i < (int) media.size(); i++){
            cout << media.at(i) << endl;
            int ext = media.at(i).size();
            if(media.at(i).size() > 4){
                if(media.at(i).at(ext-4) == 'j'&& media.at(i).at(ext-3) == 'p'&& media.at(i).at(ext-2) == 'e'&& media.at(i).at(ext-1) == 'g'){
                    p.addImageFile(media.at(i));
                } else if (media.at(i).at(ext-3) == 'm' && media.at(i).at(ext-2) == 'p' && media.at(i).at(ext-1) =='4'){
                    p.addVideoFile(media.at(i));
                }
            }


        }

        p.setID(lastPetID + 1);
        lastPetID += 1;

        return p;
    }
}


/*
 * Reads a txt file containing all the pets an owner wants to add into the database
 * Uploads all the pets into the database
 * @file Txt file that contains all the pets to be uploaded
*/
bool Owner::uploadPets(string filename){
    QFile file(QString::fromStdString(filename));
    if(!file.open(QIODevice::ReadOnly)) {
        cout << "Error: file not opened!\n";
    }

    QTextStream in(&file);
    int counter = 0;
    while(!in.atEnd()) {

        QString line = in.readLine();
        QStringList petData = line.split(",");

        Pet p = makePet(petData);
        if(p.getName() != "") {
            if(counter != 0){ //skip the first line
                uploadPet(p);
            }
        } else {
            return false;
        }
        counter++;
    }
    return true;

    file.close();
}


void Owner::openDB(){
    petsDB = QSqlDatabase::addDatabase("QSQLITE", "ownerCxn");
    string fullName = dbName;
    petsDB.setDatabaseName(QString::fromStdString(fullName));
    if(!petsDB.open()){
        std::cerr << "Database does not open -- "
                  << petsDB.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from Owner class)\n";
    }
}
