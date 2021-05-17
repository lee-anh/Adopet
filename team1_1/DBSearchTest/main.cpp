#include <iostream>

#include "gtest/gtest.h"

#include "../DBSearch/dbsearch.h"

#include "../Pets/pet.h"


// The fixture for testing class Foo.

class DBSearchTest : public ::testing::Test {

 protected:

    DBSearch* dbs;

    DBSearchTest() {



     }

     virtual ~DBSearchTest() {

     // You can do clean-up work that doesn't throw exceptions here.

     }

     // If the constructor and destructor are not enough for setting up

     // and cleaning up each test, you can define the following methods:



     virtual void SetUp() override{
        dbs = new DBSearch("../../testDB.sqlite");
     }

     virtual void TearDown() override{
        delete dbs;
     }

     // Objects declared here can be used by all tests in the test case for Foo.
};




TEST_F(DBSearchTest, SearchingTwoKeywords) {
    //DBSearch* dbs = new DBSearch("../../testDB.sqlite");
    dbs->search("rodent hamster");
    dbs->runNewQuery(false);
    vector<Pet> result = dbs->getPetVec();
    EXPECT_EQ(dbs->getPetVecSize(), 4) << "Size should be 4";
    EXPECT_EQ(result.at(0).getName(), "Scarlett") << result.at(0).getName() << " should be Scarlett";
}

TEST_F(DBSearchTest, SearchingOneKeyword) {
    //DBSearch* dbs = new DBSearch("../../testDB.sqlite");
    dbs->search("rodent");
    dbs->runNewQuery(false);
    vector<Pet> result = dbs->getPetVec();
    EXPECT_EQ(dbs->getPetVecSize(), 14) << "Size should be 14";
    EXPECT_EQ(result.at(0).getName(), "Hazel") << result.at(0).getName() << " should be Hazel";
    EXPECT_EQ(result.at(1).getName(), "Isabelle") << result.at(0).getName() << " should be Isabelle";
    EXPECT_EQ(result.at(2).getName(), "Olivia") << result.at(0).getName() << " should be Olivia";
}

TEST_F(DBSearchTest, SearchingThreeKeywords){
    //DBSearch* dbs = new DBSearch("../../testDB.sqlite");
    dbs->search("rodent hamster female");
    dbs->runNewQuery(false);
    vector<Pet> result = dbs->getPetVec();
    EXPECT_EQ(dbs->getPetVecSize(), 2) << "Size should be 2";
    EXPECT_EQ(result.at(0).getName(), "Scarlett") << result.at(0).getName() << " should be Scarlett";
    EXPECT_EQ(result.at(1).getName(), "Lucas") << result.at(0).getName() << " should be Lucas";
}

TEST_F(DBSearchTest, SearchingNull){
    //DBSearch* dbs = new DBSearch("../../testDB.sqlite");
    dbs->search("dragon");
    dbs->runNewQuery(false);
    vector<Pet> result = dbs->getPetVec();
    cout << "Size of vec: " << dbs->getPetVecSize() << endl;
    cout << "First member: " << result.at(0).getName() << endl;
    EXPECT_EQ(dbs->getPetVecSize(), 100) << "Size should be 100";
    //Test failing because the vector size is the entire database.
}

TEST_F(DBSearchTest, Shuffling){
    //DBSearch* dbs = new DBSearch("../../testDB.sqlite");
    dbs->randomShuffle(false);
    vector<Pet> result = dbs->getPetVec();
    EXPECT_EQ(dbs->getPetVecSize(), 100) << "Size should be 100";
    EXPECT_NE(result.at(0).getName(), "Alex") << "First entry is no longer Alex. "
                                                 "If fail runs again since there is a 1% chance shuffling keeps Alex at top.";
}

TEST_F(DBSearchTest, RemoveFrmAtt){
    dbs->search("rodent hamster female");
    dbs->removeFromAttributes("female","gender");
    string cons = dbs->getConstraints();
    EXPECT_EQ(cons, "rodent, hamster,") << endl;
    dbs->runNewQuery(false);
    vector<Pet> result = dbs->getPetVec();
    EXPECT_EQ(dbs->getPetVecSize(), 4) << "Size should be 4" << endl;
    EXPECT_EQ(result.at(0).getName(), "Scarlett") << result.at(0).getName() << " should be Scarlett";
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



