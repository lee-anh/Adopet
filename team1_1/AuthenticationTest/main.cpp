#include <iostream>

#include "gtest/gtest.h"
#include "../Authentication/authentication.h"

#include "../Adopter/adopter.h"
#include "../Adopter/preferences.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"


class AuthTest : public ::testing::Test {

 protected:



    AuthTest() {



     }

     virtual ~AuthTest() {

     // You can do clean-up work that doesn't throw exceptions here.

     }

     // If the constructor and destructor are not enough for setting up

     // and cleaning up each test, you can define the following methods:



     virtual void SetUp(){

     // Code here will be called immediately after the constructor (right

     // before each test).

     }

     virtual void TearDown() {

     // Code here will be called immediately after each test (right

     // before the destructor).

     }

     // Objects declared here can be used by all tests in the test case for Foo.





};

TEST(AuthTest, testLogin){
    Authentication auth = Authentication("../../testDB.sqlite");
    int login = auth.logIn("user1","password1");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0"<< endl;
}

TEST(AuthTest, testLoginFail){
    Authentication auth = Authentication("../../testDB.sqlite");
    int login = auth.logIn("user10","password10");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0" << endl;
}


//Testing object setters and getters
TEST(AuthTest, signUpAdopter){
    Authentication auth = Authentication("../../testDB.sqlite");
    bool signup = auth.signUp("user10","password10", "adopter");
    EXPECT_EQ(signup,true) << "Should create new adopter " << signup << "should be 1" << endl;
    int login = auth.logIn("user10","password10");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0" << endl;
    Adopter* adpt = auth.getAuthenticatedAdopter();
    if(!adpt){
        FAIL() << "Owner is null even already signed up!" << endl;
    }
}

TEST(AuthTest, signUpOwner){
    Authentication auth = Authentication("../../testDB.sqlite");
    bool signup = auth.signUp("user11","password11", "owner");
    EXPECT_EQ(signup,0) << "Should create new owner " << signup << "should be 1" << endl;
    int login = auth.logIn("user11","password11");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0" << endl;
    Owner* owner = auth.getAuthenticatedOwner();
    if(!owner){
        FAIL() << "Owner is null even already signed up!" << endl;
    }

}

TEST(AuthTest, signUpAdopterFail){
    Authentication auth = Authentication("../../testDB.sqlite");
    bool signup = auth.signUp("user10","password10", "adopter");
    EXPECT_EQ(signup,false) << "Should create new adopter " << signup << "should be 1" << endl;
}

TEST(AuthTest, signUpOwnerFail){

}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

