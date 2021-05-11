#include <iostream>

#include "gtest/gtest.h"

#include "../SavedList/savedlist.h"

#include "../Pets/pet.h"


// The fixture for testing class Foo.

class SavedListTest : public ::testing::Test {

 protected:



    SavedListTest() {



     }

     virtual ~SavedListTest() {

     // You can do clean-up work that doesn't throw exceptions here.

     }

     // If the constructor and destructor are not enough for setting up

     // and cleaning up each test, you can define the following methods:



     virtual void SetUp() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","authTestConnection");
        string fullName = "../../testDB.sqlite";
        db.setDatabaseName(QString::fromStdString(fullName));
        if(!db.open()){
            std::cerr << "Database does not open -- "
                      << db.lastError().text().toStdString()
                      << std::endl;

            std::cerr << "  File -- " << fullName << std::endl;
            exit(0);
        } else {
            std::cerr << "Opened database successfully (from Authentication class)\n";
        }

        if(db.open()){
            QSqlQuery qry = QSqlQuery(db);
            QString qs = "INSERT INTO savedPets(username, petID) values(\"user1\",2);" ;
            qry.exec(qs);
            qs = "INSERT INTO savedPets(username, petID) values(\"user1\",6);" ;
            qry.exec(qs);
            cout << "Added user 1 savedPets" << endl;
        }
     }

     virtual void TearDown() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","authTestConnection");
        string fullName = "../../testDB.sqlite";
        db.setDatabaseName(QString::fromStdString(fullName));
        if(!db.open()){
            std::cerr << "Database does not open -- "
                      << db.lastError().text().toStdString()
                      << std::endl;

            std::cerr << "  File -- " << fullName << std::endl;
            exit(0);
        } else {
            std::cerr << "Opened database successfully (from Authentication class)\n";
        }

        if(db.open()){
            QSqlQuery qry = QSqlQuery(db);
            QString qs = "DELETE FROM savedPets WHERE username=\"user1\";" ;
            qry.exec(qs);
            cout << "Deleted user 1 savedPets" << endl;
        }
     }

     // Objects declared here can be used by all tests in the test case for Foo.
};




TEST_F(SavedListTest, SavingPets) {
    SavedList* savedList = new SavedList("../../testDB.sqlite", "user1");
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "Big";
    string bio = "Lorem Ipsum";
    string size = "Medium";
    Pet* testPet1 = new Pet(101,name, species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet2 = new Pet(102,"John", species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet3 = new Pet(103,"Connor", species, breed, age, size, temp, gender, gw, sh, bio);

    savedList->savePet(*testPet1);
    savedList->savePet(*testPet2);
    savedList->savePet(*testPet3);
    vector<Pet> savedVec = savedList->getPetVec();
    EXPECT_EQ(savedVec.at(2).getName(), "Alex") << savedVec.at(0).getName() << " should be Alex";
    EXPECT_EQ(savedVec.at(3).getName(), "John") << savedVec.at(0).getName() << " should be John";
    EXPECT_EQ(savedVec.at(4).getName(), "Connor") << savedVec.at(0).getName() << " should be Connor";

    delete savedList;
    delete testPet1;
    delete testPet2;
    delete testPet3;
}

TEST_F(SavedListTest, UnsavingPets){
    SavedList* savedList = new SavedList("../../testDB.sqlite", "user1");
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "Big";
    string bio = "Lorem Ipsum";
    string size = "Medium";
    Pet* testPet1 = new Pet(101,name, species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet2 = new Pet(102,"John", species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet3 = new Pet(103,"Connor", species, breed, age, size, temp, gender, gw, sh, bio);

    savedList->savePet(*testPet1);
    savedList->savePet(*testPet2);
    savedList->savePet(*testPet3);
    vector<Pet> savedVec = savedList->getPetVec();
    EXPECT_EQ(savedVec.at(2).getName(), "Alex") << savedVec.at(0).getName() << " should be Alex";
    EXPECT_EQ(savedVec.at(3).getName(), "John") << savedVec.at(0).getName() << " should be John";
    EXPECT_EQ(savedVec.at(4).getName(), "Connor") << savedVec.at(0).getName() << " should be Connor";
    savedList->unsavePet(*testPet3);
    savedVec = savedList->getPetVec();
    EXPECT_EQ(savedVec.size(), 4) << "Size of vector should be 4";
    EXPECT_EQ(savedVec.at(2).getName(), "Alex") << savedVec.at(0).getName() << " should be Alex";
    EXPECT_EQ(savedVec.at(3).getName(), "John") << savedVec.at(0).getName() << " should be John";

    delete savedList;
    delete testPet1;
    delete testPet2;
    delete testPet3;
}

TEST_F(SavedListTest, checkIsSaved){
    SavedList* savedList = new SavedList("../../testDB.sqlite", "");
    savedList->setUsername("user1");
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "Big";
    string bio = "Lorem Ipsum";
    string size = "Medium";
    Pet* testPet1 = new Pet(101,name, species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet2 = new Pet(102,"John", species, breed, age, size, temp, gender, gw, sh, bio);
    Pet* testPet3 = new Pet(103,"Connor", species, breed, age, size, temp, gender, gw, sh, bio);

    savedList->savePet(*testPet1);
    savedList->savePet(*testPet2);
    savedList->savePet(*testPet3);
    vector<Pet> savedVec = savedList->getPetVec();
    bool result = savedList->isSavedPet(*testPet1);
    EXPECT_EQ(result, true) << result << " should be 1";

    delete savedList;
    delete testPet1;
    delete testPet2;
    delete testPet3;
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



