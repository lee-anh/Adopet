#include <iostream>
#include "gtest/gtest.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"


// The fixture for testing class Foo.
class FooTest : public ::testing::Test{

protected:
    /*
    FooTest(){
        // You can do set-up work for each test here.
    }
    virtual ~FooTest(){
        // You can do clean-up work that doesn't throw exceptions here.
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp(){
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown(){
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.

    */
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

/*
//Testing the function of uploading a single pet onto the database
TEST(unitTest, uploadPet){
    Owner o1;
    o1.setName("best friends");

    o1.fillPets();
    int petAmountBefore = o1.getPets().size();

    Owner o2;
    o2.setName("best friends");
    Pet p = Pet("qwerty", "dog", "newBreed", "adult", "large", "happy", "male", "kids", "best friends", "loren ipsum");
    o2.uploadPet(p);

    o2.fillPets();
    int petAmountAfter = o2.getPets().size();

    ASSERT_EQ(petAmountAfter, petAmountBefore + 1) << "Pet amount should increase after uploading a pet";
    cout << "Pet amount before: " << petAmountBefore << endl;
    cout << "Pet amount after: " << petAmountAfter << endl;
}
*/


//Testing the function of uploading a single pet onto the database
TEST(unitTest, uploadPets){
    Owner o1;
    o1.setName("best friends");

   // o1.uploadPets();
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
