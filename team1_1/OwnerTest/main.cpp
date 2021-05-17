#include <iostream>
#include "gtest/gtest.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"


// The fixture for testing class Foo.
class OwnerTests : public ::testing::Test{

protected:
    Owner* owner;
    Pet* pet;
    QSqlDatabase petsDB;

    OwnerTests(){
        // You can do set-up work for each test here.
    }
    virtual ~OwnerTests(){
        // You can do clean-up work that doesn't throw exceptions here.
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp(){
        // Code here will be called immediately after the constructor (right
        // before each test).
        owner = new Owner("../../testDB.sqlite", "generic_owner", "111 Quad Drive", 18042, 123, "abc@xyz");
        pet = new Pet(101,"name1", "species1", "breed1", "age1", "size1", "temp1", "gender1", "gw1", "sh1", "bio1");
        petsDB = QSqlDatabase::addDatabase("QSQLITE", "ownterTestCxn");
        string fullName = "../../testDB.sqlite";
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

    virtual void TearDown(){
        // Code here will be called immediately after each test (right
        // before the destructor).
        QSqlQuery qry = QSqlQuery(petsDB);
        QString qrstring = "DELETE FROM pets WHERE id=101";
        if(petsDB.open()){
            qry.exec(qrstring);
        }
    }
    // Objects declared here can be used by all tests in the test case for Foo.


};

//Testing object setters and getters
TEST(unitTest, settersAndGetters){
    Owner o1;
    o1.setAddress("111 Quad Drive");
    o1.setEmail("example@gmail.com");
    o1.setName("John Doe");
    o1.setPhoneNumber(1234567890);
    o1.setZipCode(12345);

    ASSERT_EQ(o1.getAddress(), "111 Quad Drive") << o1.getAddress() << " should be 111 Quad Drive";
    ASSERT_EQ(o1.getEmail(), "example@gmail.com") << o1.getEmail() << " should be example@gmail.com";
    ASSERT_EQ(o1.getName(), "John Doe") << o1.getName() << " should be John Doe";
    ASSERT_EQ(o1.getPhoneNumber(), 1234567890) << o1.getPhoneNumber() << " should be 1234567890";
    ASSERT_EQ(o1.getZipCode(), 12345) << o1.getZipCode() << " should be 12345";
}

//Testing the function of filling in the owner's pets
TEST(unitTest, fillPets){
    Owner o1;
    o1.setName("best friends");

    vector<Pet> before = o1.getPets();
    ASSERT_EQ(before.empty(), true) << before.size() << " should be empty";

    o1.fillPets();

    vector<Pet> after = o1.getPets();
    ASSERT_EQ(after.empty(), false) << after.size() << " should not be empty";
    ASSERT_NE(after.size(), 0) << after.size() << " should not be 0";
}


//Testing the function of uploading a single pet onto the database
TEST_F(OwnerTests, uploadPet){
    owner->uploadPet(*pet);
    QSqlQuery qry = QSqlQuery(petsDB);
    QString qrstring = "SELECT * FROM pets WHERE id = 101;";
    if(petsDB.open()){
        qry.exec(qrstring);
        while(qry.next()){
            QString res = qry.value(1).toString();
            if(res == "name1") SUCCEED();
        }
    }
}

TEST_F(OwnerTests, removePet){
    owner->uploadPet(*pet);
    QSqlQuery qry = QSqlQuery(petsDB);
    QString qrstring = "SELECT * FROM pets WHERE id = 101;";
    owner->removePet(*pet);
    if(petsDB.open()){
        qry.exec(qrstring);
        while(qry.next()){
            QString res = qry.value(1).toString();
            if(res == "name1") FAIL();
        }
    }
}

TEST_F(OwnerTests, updatePet){
    owner->uploadPet(*pet);
    pet->setName("Booyah");
    QSqlQuery qry = QSqlQuery(petsDB);
    QString qrstring = "SELECT * FROM pets WHERE id = 101;";
    owner->updatePet(*pet);
    if(petsDB.open()){
        qry.exec(qrstring);
        while(qry.next()){
            QString res = qry.value(1).toString();
            if(res == "Booyah") SUCCEED();
        }
    }
}

TEST_F(OwnerTests, uploadBulk){
    owner->uploadPets("../../testUpload.txt");
    QSqlQuery qry = QSqlQuery(petsDB);
    QString qrstring = "SELECT * FROM pets WHERE id = 101;";
    if(petsDB.open()){
        qry.exec(qrstring);
        while(qry.next()){
            QString res = qry.value(1).toString();
            if(res != "Booyah") FAIL();
        }
    }
}



TEST_F(OwnerTests, constructors){
    Owner* o1 = new Owner("John Doe", "111 Quad Drive", 12345, 1234567890, "example@gmail.com");
    EXPECT_EQ(o1->getAddress(), "111 Quad Drive") << o1->getAddress() << " should be 111 Quad Drive";
    EXPECT_EQ(o1->getEmail(), "example@gmail.com") << o1->getEmail() << " should be example@gmail.com";
    EXPECT_EQ(o1->getName(), "John Doe") << o1->getName() << " should be John Doe";
    EXPECT_EQ(o1->getPhoneNumber(), 1234567890) << o1->getPhoneNumber() << " should be 1234567890";
    EXPECT_EQ(o1->getZipCode(), 12345) << o1->getZipCode() << " should be 12345";

    Owner* o2 = new Owner("../../testDB.sqlite", "John Doe", "111 Quad Drive", 12345, 1234567890, "example@gmail.com");
    EXPECT_EQ(o2->getAddress(), "111 Quad Drive") << o1->getAddress() << " should be 111 Quad Drive";
    EXPECT_EQ(o2->getEmail(), "example@gmail.com") << o1->getEmail() << " should be example@gmail.com";
    EXPECT_EQ(o2->getName(), "John Doe") << o1->getName() << " should be John Doe";
    EXPECT_EQ(o2->getPhoneNumber(), 1234567890) << o1->getPhoneNumber() << " should be 1234567890";
    EXPECT_EQ(o2->getZipCode(), 12345) << o1->getZipCode() << " should be 12345";
    delete o1;
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
