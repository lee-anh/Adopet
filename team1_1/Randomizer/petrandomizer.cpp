#include "petrandomizer.h"

PetRandomizer::PetRandomizer()
{
    //default 10 people are created
    numOfPets = 10;
    openDB();
    initializeNameVecs();

    //clear old data in csvs
    writePetsCsv.open("../../csvs/pets.csv", ofstream::out | ofstream::trunc);
    writePetsCsv.close();

    writeMediaCsv.open("../../csvs/media.csv", ofstream::out | ofstream::trunc);
    writeMediaCsv.close();

    srand(time(0));
}

PetRandomizer::PetRandomizer(int num){
    numOfPets = num;
    openDB();
    initializeNameVecs();

    writePetsCsv.open("../../csvs/pets.csv", ofstream::out | ofstream::trunc);
    writePetsCsv.close();

    writeMediaCsv.open("../../csvs/media.csv", ofstream::out | ofstream::trunc);
    writeMediaCsv.close();

    srand(time(0));
}

/*
 * Opening a database connection
*/
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

/*
 * Initializing vectors that hold information to randomize from.
*/
void PetRandomizer::initializeNameVecs(){
    //static information, arbitrarily chosen
    names = {
        "bailey", "max", "charlie", "buddy", "rocky", "jake", "jack", "toby", "cody",
        "buster", "duke", "cooper", "riley", "harley", "bear", "tucker", "murphy",
        "lucky", "sam", "oscar", "teddy", "winston", "sammy", "bella",
        "molly", "daisy", "maggie", "sophie", "sadie", "lola", "zoe", "abby",
        "coco", "sasha", "angel", "princess", "annie", "rosie", "ruby", "rusty",
        "shadow", "gizmo", "bentley", "zeus", "baxter", "bandit", "gus", "samson",
        "rudy", "louie", "hunter", "casey", "rocco", "sparky", "joey", "bruno",
        "beau", "dakota", "maximus", "romeo", "boomer", "luke", "lady", "missy",
        "katie" "mia", "zoey", "madison", "stella", "penny", "belle", "samantha",
        "holly", "lexi", "lulu", "meimei", "brandy", "jasmine", "shelby", "sandy",
        "roxie", "pepper", "poppy", "heidi", "dixie", "honey", "rey", "kylo", "han",
        "poe", "leia", "anakin", "padme", "obi-wan", "chewie", "yoda", "olaf",
        "elsa", "maggie", "homer", "spock", "kirk", "uhura", "scottie", "bennie",
        "jelly", "jam", "prince", "king", "queen", "cassie", "xavier", "manny",
        "squishy", "snoopy", "orion", "sophie", "raj", "watson", "bobum", "boba",
       "oliver", "liam", "ethan", "aiden", "gabriel", "caleb", "theo", "owen",
        "elijah", "henry", "jackson", "grayson", "levi", "ben", "miles", "alex",
        "sebastian", "leo", "landon", "emmett", "everett", "milo", "jasper",
        "lucas", "noah", "harrison", "charlotte", "ava", "amelia", "olivia",
        "aurora", "violet", "luna", "hazel", "chloe", "aria", "scarlett",
        "abigail", "freya", "adeline", "sophia", "nora", "adelaide", "emma",
        "mila", "lily", "grace", "maeve", "ivy", "ella", "audrey",
        "genevieve", "iris", "isabelle", "lucy", "minty", "nick", "sugar", "puff"
    };
    age = {"young", "adult","senior"};
    gender = {"male", "female"};
    size = {"small", "medium", "large"};
    imageFileNames = {"bird1.jpeg", "bird2.jpeg", "bird3.jpeg", "bird4.jpeg", "bird5.jpeg", "bird6.jpeg", "bird7.jpeg", "bird8.jpeg",
                     "cat1.jpeg", "cat2.jpeg", "cat3.jpeg", "cat4.jpeg", "cat5.jpeg", "cat6.jpeg", "cat7.jpeg", "cat8.jpeg",
                     "dog1.jpeg", "dog2.jpeg", "dog3.jpeg", "dog4.jpeg", "dog5.jpeg", "dog6.jpeg", "dog7.jpeg", "dog8.jpeg",
                     "fish1.jpeg", "fish2.jpeg", "fish3.jpeg", "fish4.jpeg", "fish5.jpeg", "fish6.jpeg", "fish7.jpeg", "fish8.jpeg",
                     "rabbit1.jpeg", "rabbit2.jpeg", "rabbit3.jpeg", "rabbit4.jpeg", "rabbit5.jpeg", "rabbit6.jpeg", "rabbit7.jpeg", "rabbit8.jpeg",
                     "rodent1.jpeg", "rodent2.jpeg", "rodent3.jpeg", "rodent4.jpeg", "rodent5.jpeg", "rodent6.jpeg", "rodent7.jpeg", "rodent8.jpeg"};

    videoFileNames = {"bird1.mp4", "bird2.mp4",
                      "cat1.mp4", "cat2.mp4",
                      "dog1.mp4", "dog2.mp4",
                      "fish1.mp4", "fish2.mp4",
                      "rabbit1.mp4", "rabbit2.mp4",
                      "rodent1.mp4", "rodent2.mp4"};

    if(db.open()){
        QSqlQuery query = QSqlQuery();

        //species
        QString qs = "SELECT speciesType FROM species";
        query.exec(qs);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            //cout << s << endl;
            species.push_back(s);
        }

        //breed
        QString qs2 = "SELECT breedType, speciesType FROM breed";
        query.exec(qs2);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            string t = query.value(1).toString().toStdString();
            //cout << s << endl;
            //cout << t << endl;
            breed.push_back(make_pair(s,t));
        }

        //temperament
        QString qs3 = "SELECT temperamentType FROM temperament";
        query.exec(qs3);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            //cout << s << endl;
            temperament.push_back(s);
        }

        //goodWith
        QString qs4 = "SELECT goodWithType FROM goodWith";
        query.exec(qs4);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            //cout << s << endl;
            goodWith.push_back(s);
        }

        //shelter
        QString qs5 = "SELECT shelterType FROM shelter";
        query.exec(qs5);
        while(query.next()){
            string s = query.value(0).toString().toStdString();
            //cout << s << endl;
            shelter.push_back(s);
        }
    }
}

/*
 * Loops through the existing media files and
 * gets the the image file names pertaining to a specific pet species.
 * Returns a randomized image file name that depicts the specific pet species
 * @param petSpecies Pet species that the files relate to
 * @return Randomized image file name
*/
string PetRandomizer::getImageFileNameBySpecies(string petSpecies){
    vector<string> speciesRelatedFiles;

    for(int i = 0; i < (int)imageFileNames.size(); i++){
        //turning char* to string
        string fileName = imageFileNames.at(i);

        int start = 0;
        int end = fileName.size() - 6;
        string imageSpecies = fileName.substr(start, end);
        if(imageSpecies == petSpecies) speciesRelatedFiles.push_back(fileName);
    }

    int random = rand() % (int) speciesRelatedFiles.size();
    return speciesRelatedFiles.at(random);
}

/*
 * Loops through the existing video files and
 * gets the the video file names pertaining to a specific pet species.
 * Returns a randomized video file name that depicts the specific pet species
 * @param petSpecies Pet species that the files relate to
 * @return Randomized video file name
*/
string PetRandomizer::getVideoFileNameBySpecies(string petSpecies){
    vector<string> speciesRelatedFiles;

    for(int i = 0; i < (int)videoFileNames.size(); i++){
        //turning char* to string
        string fileName = videoFileNames.at(i);

        int start = 0;
        int end = fileName.size() - 5;
        string imageSpecies = fileName.substr(start, end);
        if(imageSpecies == petSpecies) speciesRelatedFiles.push_back(fileName);
    }

    int random = rand() % (int) speciesRelatedFiles.size();
    return speciesRelatedFiles.at(random);
}

/*
 * Checks if the file is an image or a video file
 * @param fileName Name of the media file
 * @returm either "image" or "video"
*/
string PetRandomizer::getMediaType(string fileName){
    //turning string to char array
    int size = fileName.size();
    char arr[size + 1];
    strcpy(arr, fileName.c_str());

    bool afterDot = false;

    string extension = "";
    for(int i = 0; i < size; i++){
        if(afterDot) extension += arr[i];
        if(arr[i] == '.') afterDot = true;
    }

    if(extension == "jpeg" || extension == "png") return "image";
    else return "video";
}

/*
 * Fills up the media and pets csv files with the randomized data
*/
void PetRandomizer::writeToCSV(){
    writeMediaCsv.open("../../csvs/media.csv", ios_base::app);
    writePetsCsv.open("../../csvs/pets.csv", ios_base::app);
    for(int i=1; i<numOfPets+1;i++){
        //randomizing pet tags
        int rand1 = rand() % (int) names.size();
        string petName = names.at(rand1);

        int rand2 = rand() % (int) age.size();
        string petAge = age.at(rand2);

        int rand3 = rand() % (int) gender.size();
        string petGen = gender.at(rand3);

        int rand4 = rand() % (int) size.size();
        string petSize = size.at(rand4);

        int rand5 = rand() % (int) goodWith.size();
        string petGoodWith = goodWith.at(rand5);

        int rand6 = rand() % (int) shelter.size();
        string petShelter = shelter.at(rand6);

        int rand7 = rand() % (int) temperament.size();
        string petTemp = temperament.at(rand7);

        //Do we need to fit breed with species for now?
        int rand8 = rand() % (int) breed.size();
        string petBreed = breed.at(rand8).first;
        string petSpecies = breed.at(rand8).second;

        writePetsCsv << i << ",";
        writePetsCsv << petName << "," << petSpecies << "," << petBreed << "," << petAge << "," << petSize << "," << petTemp
                 << "," << petGen << "," << petGoodWith << "," << petShelter << "," << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
        writePetsCsv << "\n";

        //randomizing images
        int rand9 = rand() % 8 + 1;
        for(int j = 0; j < rand9; j++){
            string fileName = getImageFileNameBySpecies(petSpecies);
            writeMediaCsv << i << "," << fileName << ",image" << "\n";
        }

        //randomizing videos
        int rand10 = rand() % 2 + 1;
        for(int k = 0; k < rand10; k++){
            string fileName = getVideoFileNameBySpecies(petSpecies);
            writeMediaCsv << i << "," << fileName << ",video" << "\n";
        }
    }

    writePetsCsv.close();
    writeMediaCsv.close();
}
