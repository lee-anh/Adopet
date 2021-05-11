#include <iostream>
#include "gtest/gtest.h"
#include "../Matchmaking/matchmaking.h"

// The fixture for testing class Foo.
class MatchmakingTest : public ::testing::Test{

protected:

    Matchmaking m;
    Matchmaking* mk = new Matchmaking("../../testDB.sqlite", "user1");

    MatchmakingTest(){
    // You can do set-up work for each test here.
    }
    virtual ~MatchmakingTest(){

        // You can do clean-up work that doesn't throw exceptions here.
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp(){
        m.openDB();
        // Code here will be called immediately after the constructor (right
        // before each test).

    }

    virtual void TearDown(){
        m.closeDB();
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.

};


//Testing if the pets vector is fille correctly with pets in the database
TEST_F(MatchmakingTest, fillPets){
    EXPECT_EQ(m.getAllPets().size(), 0) << "The vector is empty in the beginning";
    m.fillPets();
    EXPECT_NE(m.getAllPets().size(), 0) << "The vector is no longer empty after fillPets()";
}

//Testing if the <Pet, integer> pair sorter algorithm works properly
TEST_F(MatchmakingTest, PetSorting){
    vector<pair<Pet, int>> list1;
    vector<pair<Pet, int>> sortedList1;

    //setting up
    Pet p1 = Pet();
    Pet p2 = Pet();
    Pet p3 = Pet();
    int i1 = 5;
    int i2 = 24;
    int i3 = 9;
    list1.push_back(make_pair(p1, i1));
    list1.push_back(make_pair(p2, i2));
    list1.push_back(make_pair(p3, i3));
    sortedList1.push_back(make_pair(p2, i2));
    sortedList1.push_back(make_pair(p3, i3));
    sortedList1.push_back(make_pair(p1, i1));

    EXPECT_EQ(list1.size(), sortedList1.size()) << "The vectors have the same size";
    EXPECT_NE(list1.at(0).second, sortedList1.at(0).second) << "The first element of the vectors is differnt";

    sort(list1.begin(), list1.end(), m.customPetResultSort);

    for (int i = 0; i < (int)list1.size(); i++) {
       EXPECT_EQ(list1.at(i).second, sortedList1.at(i).second) << "Both vectors have the same element at index " << i;
    }
}

//Testing if the <Adopter, integer> pair sorter algorithm works properly
TEST_F(MatchmakingTest, AdopterSorting){
    vector<pair<Adopter, int>> list2;
    vector<pair<Adopter, int>> sortedList2;

    //setting up
    Adopter a1 = Adopter();
    Adopter a2 = Adopter();
    Adopter a3 = Adopter();
    int i1 = 66;
    int i2 = 2;
    int i3 = 43;

    list2.push_back(make_pair(a1, i1));
    list2.push_back(make_pair(a2, i2));
    list2.push_back(make_pair(a3, i3));
    sortedList2.push_back(make_pair(a1, i1));
    sortedList2.push_back(make_pair(a3, i3));
    sortedList2.push_back(make_pair(a2, i2));

    EXPECT_EQ(list2.size(), sortedList2.size()) << "The vectors have the same size";
    EXPECT_NE(list2.at(2).second, sortedList2.at(2).second) << "The first element of the vectors is differnt";

    sort(list2.begin(), list2.end(), m.customAdopterResultSort);

    for(int i = 0; i < (int)list2.size(); i++) {
       EXPECT_EQ(list2.at(i).second, sortedList2.at(i).second) << "Both vectors have the same element at index " << i;
    }
}

//Testing if makePet() works properly
TEST_F(MatchmakingTest, makePet){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "matchmakingTestCxn");
    string fullName = "../../testDB.sqlite";
    db.setDatabaseName(QString::fromStdString(fullName));
    if(db.open()){
        QSqlQuery query = QSqlQuery(db);
        QString s = "SELECT * FROM pets";
        query.exec(s);
        query.next();
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

        Pet pet = m.makePet(query);

        EXPECT_EQ(name, pet.getName()) << "Checking the pet name is correct";
        EXPECT_EQ(species, pet.getSpecies()) << "Checking the pet species is correct";
        EXPECT_EQ(breed, pet.getBreed()) << "Checking the pet breed is correct";
        EXPECT_EQ(age, pet.getAge()) << "Checking the pet age is correct";
        EXPECT_EQ(size, pet.getSize()) << "Checking the pet size is correct";
        EXPECT_EQ(temperament, pet.getTemperament()) << "Checking the pet temperament is correct";
        EXPECT_EQ(gender, pet.getGender()) << "Checking the pet gender is correct";
        EXPECT_EQ(goodWith, pet.getGoodWith()) << "Checking the pet goodWith is correct";
        EXPECT_EQ(shelter, pet.getShelter()) << "Checking the pet shelter is correct";
        EXPECT_EQ(bio, pet.getBio()) << "Checking the pet bio is correct";


        db.removeDatabase(db.connectionName());
        db.close();
    }
}

//Testing if fillPreference() works properly
TEST_F(MatchmakingTest, fillPreference){
    Preferences p = Preferences();

    p = m.fillPreference(p, "dog", "species");
    p = m.fillPreference(p, "fish", "species");
    p = m.fillPreference(p, "cat", "species");
    p = m.fillPreference(p, "male", "gender");
    p = m.fillPreference(p, "humane society", "shelter");

    EXPECT_EQ(p.getGender().at(0), "male") << "Checking that the gender preference is set correctly";
    EXPECT_EQ(p.getSpecies().size(), 3) << "Checking that the size of the species preference is set correctly";
}

TEST_F(MatchmakingTest, fillPreferenceAdpt){
    Preferences p = Preferences();

    p = m.fillPreferences("user2");

    EXPECT_EQ(p.getGender().at(0), "male") << "Checking that the gender preference is set correctly";
    EXPECT_EQ(p.getGoodWith().at(0), "animals") << "Checking that the size of the species preference is set correctly";
}

TEST_F(MatchmakingTest, petMatches){
    mk->openDB();
    mk->fillPets();
    vector<pair<Adopter,int>> result = mk->findMatchesForPet(1);
    EXPECT_EQ(result.at(0).first.getUsername(),"user2") << "Should be user 2";
}

TEST_F(MatchmakingTest, petBestMatch){
    mk->openDB();
    mk->fillPets();
    vector<pair<Adopter,int>> result = mk->findBestMatchForPet(mk->getAllPets().at(0));
    EXPECT_EQ(result.at(0).first.getUsername(),"user2") << "Should be user 2";
}

TEST_F(MatchmakingTest, petShelterMatch){
    mk->openDB();
    mk->fillPets();
    vector<pair<Pet, pair<Adopter, int>>> result = mk->findMatchesForPets("humane society");
    EXPECT_EQ(result.at(0).second.first.getUsername(), "user2") << "Should be user 2";
}

TEST_F(MatchmakingTest, adopterMatch){
    mk->openDB();
    mk->fillPets();
    vector<pair<Pet, int>> result = mk->findMatchesForAdopter("user2");
    EXPECT_EQ(result.at(0).first.getID(), 47) << "Should be petID 47";
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


