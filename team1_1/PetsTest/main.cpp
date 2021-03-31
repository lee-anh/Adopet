#include "../Pets/pet.h"
#include <iostream>

#include "gtest/gtest.h"


class FooTest : public ::testing::Test {

 protected:



    FooTest() {



     }

     virtual ~FooTest() {

     // You can do clean-up work that doesn't throw exceptions here.

     }

     // If the constructor and destructor are not enough for setting up

     // and cleaning up each test, you can define the following methods:



     virtual void SetUp() {

     // Code here will be called immediately after the constructor (right

     // before each test).

     }

     virtual void TearDown() {

     // Code here will be called immediately after each test (right

     // before the destructor).

     }

     // Objects declared here can be used by all tests in the test case for Foo.





};

TEST(unitTest, testTemperaments){
    Pet* p;
    p->setAge(4);
    p->setName("Davies");
    p->setBreed("Beagle");
    p->setGender("Male");
    p->setSpecies("Dog");
    ASSERT_EQ(o1.getAddress(), "111 Quad Drive") << p.getName() << " should be Davies";

//Testing object setters and getters
TEST(unitTest, settersAndGetters){
    pet o1("Shelter Owner");
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

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

