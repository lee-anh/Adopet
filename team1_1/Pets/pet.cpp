#include "pet.h"


Pet::Pet()
{
    id = -1;
    name = "";
    species = "";
    breed = "";
    age = "";
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
        database = "../../../../../projectDB.sqlite";
        fillMediaFiles(database);
    } else {
        database = "../../projectDB.sqlite";
        fillMediaFiles(database);

    }
}

Pet::~Pet(){
    //temperament.clear();
}

/*
 * Accessor method for pet id
 * @return pet id
*/
int Pet::getID(){
    return id;
}

/*
 * Setter method for pet id
 * @param pet id
*/
void Pet::setID(int petID){
    id = petID;
}

/*
 * Accessor method for pet name
 * @return pet name
*/
string Pet::getName(){
    return name;
}

/*
 * Setter method for pet name
 * @param pet name
*/
void Pet::setName(string n){
    name = n;
}

/*
 * Accessor method for pet species
 * @return pet species
*/
string Pet::getSpecies(){
    return species;
}

/*
 * Setter method for pet species
 * @param pet species
*/
void Pet::setSpecies(string sp){
    species = sp;
}

/*
 * Accessor method for pet breed
 * @return pet breed
*/
string Pet::getBreed(){
    return breed;
}

/*
 * Setter method for pet breed
 * @param pet breed
*/
void Pet::setBreed(string b){
    breed = b;
}

/*
 * Accessor method for pet age
 * @return pet age
*/
string Pet::getAge(){
    return age;
}

/*
 * Setter method for pet age
 * @param pet age
*/
void Pet::setAge(string a){
    age = a;
}

/*
 * Accessor method for pet size
 * @return pet size
*/
string Pet::getSize(){
    return size;
}

/*
 * Setter method for pet size
 * @param pet size
*/
void Pet::setSize(string sz){
    size = sz;
}

/*
 * Accessor method for pet temperament
 * @return pet temperament
*/
string Pet::getTemperament(){
    return temperament;
}

/*
 * Setter method for pet temperament
 * @param pet temperament
*/
void Pet::setTemperament(string t){
    temperament = t;
}

/*
 * Accessor method for pet gender
 * @return pet gender
*/
string Pet::getGender(){
    return gender;
}

/*
 * Setter method for pet gender
 * @param pet gender
*/
void Pet::setGender(string g){
    gender = g;
}

/*
 * Accessor method for pet's goodWith attribute
 * @return who the pet is good with
*/
string Pet::getGoodWith(){
    return goodWith;
}

/*
 * Setter method for pet good with
 * @param pet good with
*/
void Pet::setGoodWith(string gw){
    goodWith = gw;
}

/*
 * Accessor method for pet's current shelter (owner)
 * @return pet's current shelter
*/
string Pet::getShelter(){
    return shelter;
}

/*
 * Setter method for pet shelter
 * @param pet shelter
*/
void Pet::setShelter(string sh){
    shelter = sh;
}

/*
 * Accessor method for pet's bio
 * @return pet's bio
*/
string Pet::getBio(){
    return bio;
}

/*
 * Setter method for pet bio
 * @param pet bio
*/
void Pet::setBio(string bi){
    bio = bi;
}


/*
 * Accessor method for pet id
 * @return pet id
*/
//int Pet::getPetID(){
  //  return id;
//}

/*
 * Setter method for pet id
 * @param pet id
*/
//void Pet::setPetID(int id){
  //  this->id = id;
//}

/*
 * Loops through the database and sets the pets media files
 * @param dbName Name of the database in use
*/
void Pet::fillMediaFiles(string dbName){
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
            } else if(petID == id && mediaType == "video") {
                videoFiles.push_back(filename);
            }
        }
    }

    petsDB = QSqlDatabase();
    QSqlDatabase::removeDatabase("mediaCxn");
    //petsDB.close();
}

/*
 * Accessor method that retrieves image files
 * @return The pet's image files
*/
vector<string> Pet::getImageFiles(){
    return imageFiles;
}

/*
 * Adds an image file onto the pet's image file collection
 * @file Image file to be added
*/
void Pet::addImageFile(string file){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "shelterCxn");
    petsDB.setDatabaseName(QString::fromStdString(database));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);

        QString s = "INSERT INTO media (petID, filename, mediaType) VALUES("+
                QString::number(getID()) + ", \"" + QString::fromStdString(file) +
                "\", \"image\")";

        query.exec(s);

        petsDB = QSqlDatabase();
        QSqlDatabase::removeDatabase("shelterCxn");


    }
    imageFiles.push_back(file);
}

void Pet::preventDupMedia(){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "shelterCxn");
    petsDB.setDatabaseName(QString::fromStdString(database));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        QString r = "DELETE FROM media WHERE petID = " + QString::number(getID()); //prevent duplicates
        query.exec(r);

        petsDB = QSqlDatabase();
        QSqlDatabase::removeDatabase("shelterCxn");


    }
}
/*
 * Accessor method that retrieves video files
 * @return The pet's image files
*/
vector<string> Pet::getVideoFiles(){
    return videoFiles;
}

/*
 * Adds an image file onto the pet's image file collection
 * @file Image file to be added
*/
void Pet::addVideoFile(string file){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "shelterCxn");
    petsDB.setDatabaseName(QString::fromStdString(database));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);

        QString s = "INSERT INTO media (petID, filename, mediaType) VALUES("+
                QString::number(getID()) + ", \"" + QString::fromStdString(file) +
                "\", \"video\")";

        query.exec(s);

        petsDB = QSqlDatabase();
        QSqlDatabase::removeDatabase("shelterCxn");
       }

    videoFiles.push_back(file);
}


/*
 * Gets the owner information of the given pet
 * @param dbName Name of the database file
 * @return owner object
*/

Owner Pet::getOwner(string dbName){
    QSqlDatabase petsDB = QSqlDatabase::addDatabase("QSQLITE", "shelterCxn");
    string fullName = dbName;
    petsDB.setDatabaseName(QString::fromStdString(fullName));

    if(petsDB.open()){
        QSqlQuery query = QSqlQuery(petsDB);
        QString s = "SELECT username, name, phoneNumber, emailAddress, ownerAddress, zip FROM owner WHERE name=\"" +
                QString::fromStdString(shelter) + "\"";
        query.exec(s);
        while(query.next()){
            //string username = query.value(0).toString().toStdString();
            string name = query.value(1).toString().toStdString();
            long phoneNumber = query.value(2).toLongLong();
            cout << phoneNumber <<endl;
            string emailAddress = query.value(3).toString().toStdString();
            string ownerAddress = query.value(4).toString().toStdString();
            int zip = query.value(5).toInt();

            Owner o = Owner(name, ownerAddress, zip, phoneNumber, emailAddress);

            petsDB = QSqlDatabase();
            QSqlDatabase::removeDatabase("shelterCxn");
            return o;
        }
    }
    return Owner();
}

/*
void Pet::afterRequest(QNetworkReply* reply){
    QString res = reply->readAll();
    qDebug() << res;
}
*/

//trying out zipcode stuff
int Pet::getDistance(int zipcode1, int zipcode2){
    cout << "Zipcode 1 is: " << zipcode1 << endl;
    cout << "Zipcode 2 is: " << zipcode2 << endl;

    /*

    QNetworkAccessManager* manager = new QNetworkAccessManager();
    //QUrl url = QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/distance.csv/18042/18055/mile");
    //connect(manager, &QNetworkAccessManager::finished, this, &Pet::replyFinished);
    connect(manager, &QNetworkAccessManager::finished, this, [&](QNetworkReply *reply){
        QByteArray data = reply->readAll();
        QString str = QString::fromLatin1(data);
    }

    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl("https://www.zipcodeapi.com/rest/2SGf0OrfGHFzxZlcQDqpLCs0DatJiQXqCSI9RqPMy7J0Ms0HopAxuDBG5R12oHXr/distance.json/01721/02446/mile")));

    //QNetworkReply* reply = manager->get(request);
    QString res = reply->readAll();
    qDebug() << res;
    //string link= "https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/" + to_string(zipcode1) + "/" + to_string(zipcode2) + "/mile";
    //request.setUrl(QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/18042/18055/mile"));
    //QNetworkReply* reply = manager->get(request);
      */


    /*
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    //QUrl url = QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/distance.csv/18042/18055/mile");
    //connect(manager, &QNetworkAccessManager::finished, &Pet::afterRequest);
    QString urlLink = "https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/distance.csv/18042/18055/mile";
    QUrl url = QUrl(urlLink);
    QNetworkRequest request(url);
    QNetworkReply* reply = manager->get(request);
    QString res = reply->readAll();
    qDebug() << res;
    //string link= "https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/" + to_string(zipcode1) + "/" + to_string(zipcode2) + "/mile";
    //request.setUrl(QUrl("https://www.zipcodeapi.com/rest/FV614NtEuZYNXon9VgYDlqO54JdD9XVESVJ9AAxpwOXRdJ5rPcvS5fud8YNwu6Dd/multi-distance.csv/18042/18055/mile"));
    //QNetworkReply* reply = manager->get(request);

    */
    return 0;
}




