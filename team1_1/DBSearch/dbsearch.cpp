#include "dbsearch.h"

/*!
 * \brief DBSearch default constructor. Not recommended for use
 */
DBSearch::DBSearch()
{

    cout << "default constructor called (DBSearch)";


}

/*!
 * \brief DBSearch main constructor, recommended
 * \param dbFilepath database filepath
 */
DBSearch::DBSearch(string dbFilepath){
    filepath = dbFilepath;
    //Databse stuff
    openDB();

    //load keyword vectors
    fillStaticVecs();
    fillVecsFromDB();

}


/*!
 * \brief DBSearch experimental constructor, not recommended
 * \param d

DBSearch::DBSearch(QSqlDatabase d){
    dbSearchdb = d;
    fillStaticVecs();
    fillVecsFromDB();
}
*/

/*!
 * \brief DBSearch destructor, closes database
 */
DBSearch::~DBSearch()
{

    dbSearchdb.close();
}


/*!
 * \brief search - search a user provided string for keywords
 * \param s user provided string
 * \return
 */
void DBSearch::search(string s){

    //clear vectors in the constraints vector, not constraint vector itself
    for(int i = 0; i < (int) constraints.size(); i++){
        constraints[i].clear();
    }

    //lowercase the input
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    vector<string> words = vector<string>();
    string word = ""; //temp word string
    for(auto x: s){
        if(x == ' '){
            words.push_back(word);
            word = "";
        } else {
            word = word + x;
        }
        cout << word << endl;
    }
    //adding the word as a search option
    words.push_back(word);

    //checking if the words are keywords (matching pet tags)
    for(int i = 0; i < (int) words.size(); i++){
        s = words[i];
        string attributeToSearch = "";

        //species
        for(int i = 0; i < (int) mainSpecies.size(); i++){

            if(s == mainSpecies.at(i)){
                attributeToSearch = "species";
                break;
            }

        }

        //breed
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainBreeds.size(); i++){
                if(s == mainBreeds.at(i)){
                    attributeToSearch = "breed";
                    break;
                }
            }
        }

        //age
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainAges.size(); i++){
                if(s == mainAges.at(i)){
                    attributeToSearch = "age";
                    break;
                }
            }
        }

        //size
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainSizes.size(); i++){
                if(s == mainSizes.at(i)){
                    attributeToSearch = "size";
                    break;
                }
            }
        }

        //temperament
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainTemperaments.size(); i++){
                if(s == mainTemperaments.at(i)){
                    attributeToSearch = "temperament";
                    break;
                }
            }
        }

        //gender
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainGenders.size(); i++){
                if(s == mainGenders.at(i)){
                    attributeToSearch = "gender";
                    break;
                }
            }
        }

        //goodWith
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainGoodWith.size(); i++){
                if(s == mainGoodWith.at(i)){
                    attributeToSearch = "goodWith";
                    break;
                }
            }
        }


        //shelter
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) mainShelters.size(); i++){
                if(s == mainShelters.at(i)){
                    attributeToSearch = "shelter";
                    break;
                }
            }
        }

        //name
        if(attributeToSearch == ""){
            for(int i = 0; i < (int) names.size(); i++){
                if(s == names.at(i)){
                    attributeToSearch = "name";
                    break;
                }
            }
        }

        //cout << "adding this attribute to constraints: " << s << endl;
        //add to attributes to search for
        addToAttributes(s, attributeToSearch);
   }

}


/*!
 * \brief addToAttributes adds an attribute to the constraints vector
 * \param attribute attribute to dd
 * \param category attribute's category
 * \return true if successfully added to constraints vector, false if not
 */
bool DBSearch::addToAttributes(string attribute, string category){
    int index = getIndex(category);

    if(index < 0){
        return false;
    }
    //else

    //cout << "pushing this attribute to constraints: " << attribute << endl;
    constraints[index].push_back(attribute);
    return true;
}

/*!
 * \brief removeFromAttributes removes an attribute from the constraints vector
 * \param attribute attribute to remove
 * \param category attribute's cattegory
 * \return true if successfully removed from constraints vector, false if not
 */
bool DBSearch::removeFromAttributes(string attribute, string category){
    int index = getIndex(category);
    bool toReturn = false;
    if (index < 0){
        return toReturn;
    }
    //else
    for(int i = 0; i < (int) constraints[index].size(); i++){
        if(attribute == constraints[index][i]){
            constraints[index].erase(constraints[index].begin() + i);
            toReturn = true;
            break;
        }
    }

    return toReturn;

}



/*!
 * \brief runNewQuery, driver method for running a query to the database
 * \return how many matches in the database for a given query
 */
int DBSearch::runNewQuery(bool dist){
    distance = dist;
    if(distance == true){
        zips = parseFile();
    }
    //clear the current vector of matchingPets
    matchingPets.clear();

    //generate query from current constraints vector
    string qry = createQuery();

    //run query, which alters the matchingPets vector
    return queryDB(qry);


}

/*!
 * \brief createQuery, helper method to runNewQuery()
 * creates a string representation of the query
 * \return the query in string format
 */
string DBSearch::createQuery(){
    string query = "SELECT id, name, species, breed, age, "
        "size, temperament, gender, goodWith, shelter, bio FROM pets ";
    int first = 0;

    //setting up the query specifications based on user's search
    for(int i = 0; i < (int) constraints.size(); i++){
        vector<string> temp = constraints[i];
        if(first == 0 && temp.size() > 0){
            query = query + "WHERE (";
            first++;
        } else if (first > 0 && temp.size() > 0){
            query = query + "AND (";
        } //else do nothing

        for(int j = 0; j < (int) temp.size(); j++){
            query = query  + attributes[i] + " = \"" + temp[j] + "\"";
            if(j < ((int) temp.size() - 1)){
                query = query + " OR ";
            } else {
                query = query + ") ";
            }
        }
    }
    //cout << getConstraints() << endl;
    //cout << query << endl;

    return query;
}

/*!
 * \brief getter method to retrieve the contents of constraints
 * \return string that contains all the key words searched for
 */
string DBSearch::getConstraints(){
    string s = "";
    for(int i = 0; i < (int) constraints.size(); i++){
        vector<string> temp = constraints[i];
        for(int j = 0; j < (int) temp.size(); j++){
            s += temp[j] + ", ";
        }
    }
    return s.substr(0, s.size() - 1);
}



/*!
 * \brief queryDB, helper method to runNewQuery()
 * executes a query
 * \param qry string version of query to execute
 * \return how many matches in the database there were
 */
int DBSearch::queryDB(string qry){
    int count = 0;
    if(dbSearchdb.open()){
        QSqlQuery query = QSqlQuery(dbSearchdb);
        QString qs = QString::fromStdString(qry);
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

            //creating a pet with the information above
            Pet p = Pet(id, name, species, breed, age, size, temperament, gender, goodWith, shelter, bio);
            if(distance == false){
                matchingPets.push_back(p);
            } else {
                //get zipcode and make it into the right format.
                int zip = p.getOwner(filepath).getZipCode();
                string zipString = to_string(zip);
                if(zipString.size() == 4){
                    zipString = "0" + zipString;
                }
                for(int a = 0; a < (int) zips.size(); a++){
                    if(zips.at(a) == zipString){
                        matchingPets.push_back(p);
                    }
                }
            }



            count++;
        }

    } else {
        return -1; // -1 will indicate that the database couldn't open
    }

    return count;
}

/*!
 * \brief getPetVec
 * \return matchingPets vector
 */
vector<Pet> DBSearch::getPetVec(){
    return matchingPets;
}

/*!
 * \brief getPetVecSize
 * \return size of matchingPets vector
 */
int DBSearch::getPetVecSize(){
    return (int) matchingPets.size();
}

/*!
 * \brief printMatchingVec, prints matches for testing

void DBSearch::printMatchingVec(){
    for(int i = 0; i < (int) matchingPets.size(); i++){
        cout << matchingPets.at(i).getName() << endl;
    }
}
 */

/*!
 * \brief randomShuffle the matchingPets vector
 */

void DBSearch::randomShuffle(bool dist){

    search(""); //step 1
    runNewQuery(dist); //step 2

    //a seed dependant on time
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (matchingPets.begin(), matchingPets.end(), std::default_random_engine(seed));

}

/*!
 * \brief openDB, opens a connection to the database
 */
void DBSearch::openDB(){
    dbSearchdb = QSqlDatabase::addDatabase("QSQLITE", "dbsearch");
    string fullName = filepath;
    dbSearchdb.setDatabaseName(QString::fromStdString(fullName));
    if(!dbSearchdb.open()){
        std::cerr << "Database does not open -- "
                  << dbSearchdb.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from DBSearch class)\n";
    }
}


/*!
 * \brief fillVecsFromDB, fills the categories that have dynamic attributes
 */
void DBSearch::fillVecsFromDB(){
    if(dbSearchdb.open()){
    QSqlQuery query = QSqlQuery(dbSearchdb);

    //species
    QString qs = "SELECT DISTINCT species FROM pets";
    query.exec(qs);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainSpecies.push_back(s);
    }

    //breed
    QString qs2 = "SELECT DISTINCT breed FROM pets";
    query.exec(qs2);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainBreeds.push_back(s);
    }

    //temperament
    QString qs3 = "SELECT DISTINCT temperament FROM pets";
    query.exec(qs3);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainTemperaments.push_back(s);
    }


    //goodWith
    QString qs4 = "SELECT DISTINCT goodWith FROM pets";
    query.exec(qs4);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainGoodWith.push_back(s);
    }


    //shelter
    QString qs5 = "SELECT DISTINCT shelter FROM pets";
    query.exec(qs5);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        mainShelters.push_back(s);
    }

    //name
    QString qs6 = "SELECT DISTINCT name FROM pets";
    query.exec(qs6);
    while(query.next()){
        string s = query.value(0).toString().toStdString();
        names.push_back(s);
    }

    }
}


/*!
 * \brief fillStaticVecs, fills the static vectors needed for this class
 */
void DBSearch::fillStaticVecs(){
    mainAges = {"young", "adult","senior"};
    mainGenders = {"male", "female"};
    mainSizes = {"small", "medium", "large"};

    matchingPets = vector<Pet>();
    attributes = {"species", "breed", "age",
                  "size", "temperament", "gender", "goodWith", "shelter", "name"};
    constraints.resize(9, vector<string>(0)); //8 attributes to compare
}


/*!
 * \brief getIndex, helper method to add/remove attributes
 * \param category category to search for
 * \return index of that category in the constraint vector
 */
int DBSearch::getIndex(string category){
    if (category == "species"){
        return 0;
    } else if (category == "breed"){
        return 1;
    } else if (category == "age"){
        return 2;
    } else if (category == "size"){
        return 3;
    } else if (category == "temperament"){
        return 4;
    } else if (category == "gender"){
        return 5;
    } else if (category == "goodWith"){
        return 6;
    } else if (category == "shelter"){
        return 7;
    } else if (category == "name"){
        return 8;
    }else {
        return -1;
    }
}


vector<string> DBSearch::parseFile(){

    vector<string> zips;


    QString os = QSysInfo::productVersion();

    QString filename;
    if(os == "10.16"){
        filename = "../../../../../csvs/zip.txt";

    } else {
        //default picture
        filename = "../../csvs/zip.txt";

    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        cerr << "Error: file not opened" << endl;
    }
    QTextStream in(&file);

    int lineNumber = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList zipOutput = line.split(",");
        if(lineNumber != 0){
            string zip = zipOutput.at(0).toStdString();
            zips.push_back(zip);
        }
        lineNumber++;

    }

    file.close();
    for(int i = 0; i < (int) zips.size(); i++){
        cout << "From zips" << zips.at(i) << endl;
    }



    return zips;

}

