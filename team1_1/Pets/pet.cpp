#include "pet.h"


Pet::Pet()
{
    id = -1;
    name = "";
    species = "";
    breed = "";
    age = -1;
    size ="";
    temperament = "";
    gender = "";
    goodWith = "";
    shelter = "";
    bio = "";
}

Pet::Pet(string petName, string petSpecies, string petBreed, string petAge,
         string petSize, string petTemperament, string petGender,
         string petGoodWith, string petShelter, string petBio){
    name = petName;
    species = petSpecies;
    breed = petBreed;
    age = petAge;
    size = petSize;
    temperament = petTemperament;
    gender = petGender;
    goodWith = petGoodWith;
    shelter = petShelter;
    bio = petBio;
}

Pet::Pet(int petId, string petName, string petSpecies, string petBreed,
         string petAge, string petSize, string petTemperament, string petGender,
         string petGoodWith, string petShelter, string petBio){
    id = petId;
    name = petName;
    species = petSpecies;
    breed = petBreed;
    age = petAge;
    size = petSize;
    temperament = petTemperament;
    gender = petGender;
    goodWith = petGoodWith;
    shelter = petShelter;
    bio = petBio;

    QString os = QSysInfo::productVersion();
    if(os == "10.16"){
        fillImageFiles("../../../../../projectDB.sqlite");
    } else {
        fillImageFiles("../../projectDB.sqlite");

    }
}

Pet::~Pet(){
    //temperament.clear();

}

//getters and setters
int Pet::getID(){
    return id;
}

void Pet::setID(int petID){
    id = petID;
}

string Pet::getName(){
    return name;
}

void Pet::setName(string n){
    name = n;
}

string Pet::getSpecies(){
    return species;
}

void Pet::setSpecies(string sp){
    species = sp;
}

string Pet::getBreed(){
    return breed;
}

void Pet::setBreed(string b){
    breed = b;
}

string Pet::getAge(){
    return age;
}

void Pet::setAge(string a){
    age = a;
}

string Pet::getSize(){
    return size;
}

void Pet::setSize(string sz){
    size = sz;
}

string Pet::getTemperament(){
    return temperament;
}

void Pet::setTemperament(string t){
    temperament = t;
}


string Pet::getGender(){
    return gender;
}

void Pet::setGender(string g){
    gender = g;
}


string Pet::getGoodWith(){
    return goodWith;
}
void Pet::setGoodWith(string gw){
    goodWith = gw;
}

string Pet::getShelter(){
    return shelter;
}

void Pet::setShelter(string sh){
    shelter = sh;
}

string Pet::getBio(){
    return bio;
}

void Pet::setBio(string bi){
    bio = bi;
}


int Pet::getPetID(){
    return id;
}

void Pet::setPetID(int id){
    this->id = id;
}

/*
 * Loops through the database and sets the pets image file name
*/
void Pet::fillImageFiles(string dbName){

    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "mediaCxn");
    string fullName = dbName;
    petsDB.setDatabaseName(QString::fromStdString(fullName));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        QString s = "SELECT petID, filename, mediaType FROM media";
        query.exec(s);
        while(query.next()){
            int petID = query.value(0).toInt();
            string filename = query.value(1).toString().toStdString();
            string mediaType = query.value(2).toString().toStdString();

            if(petID == id && mediaType == "image") {
                imageFiles.push_back(filename);
            }
        }
    }

    petsDB = QSqlDatabase();
    QSqlDatabase::removeDatabase("mediaCxn");
    //petsDB.close();

}

/*
 * Accessor method that retrieves image file name
 * @return The pet's image file name
*/
vector<string> Pet::getImageFiles(){
    return imageFiles;
}

/* //trying out zipcode stuff
int Pet::getDistance(int zipcode1, int zipcode2){
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    //QUrl* url = new QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/18042/18055/mile");
    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/18042/18055/mile")));
    QString answer = reply->readAll();
    qDebug() << answer;
    //string link= "https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/" + to_string(zipcode1) + "/" + to_string(zipcode2) + "/mile";
    //request.setUrl(QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/18042/18055/mile"));
    //QNetworkReply* reply = manager->get(request);
}
*/

void Pet::addImageFile(string file){
    imageFiles.push_back(file);
}
