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

    ASSERT_EQ(p->getName(), "Davies") << p->getName() << " should be Davies";
    ASSERT_EQ(p->getAge(), 4) << p->getAge() << " should be 4";
    ASSERT_EQ(p->getBreed(), "Beagle") << p->getName() << " should be Beagle";
    ASSERT_EQ(p->getSpecies(), "Dog") << p->getName() << " should be Dog";
    ASSERT_EQ(p->getGender(), "Male") << p->getName() << " should be Male";
}

//Testing object setters and getters
TEST(unitTest, settersAndGetters){
    Pet* (p);

}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

