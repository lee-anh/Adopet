#include "../Pets/pet.h"
#include <iostream>

#include "gtest/gtest.h"


class PetsTest : public ::testing::Test {

 protected:



    PetsTest() {



     }

     virtual ~PetsTest() {

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

TEST(PetsTest, testTemperaments){
    Pet* p = new Pet();
    p->setAge("4");
    p->setName("Davies");
    p->setBreed("Beagle");
    p->setGender("Male");
    p->setSpecies("Dog");

    ASSERT_EQ(p->getName(), "Davies") << p->getName() << " should be Davies";
    ASSERT_EQ(p->getAge(), "4") << p->getAge() << " should be 4";
    ASSERT_EQ(p->getBreed(), "Beagle") << p->getName() << " should be Beagle";
    ASSERT_EQ(p->getSpecies(), "Dog") << p->getName() << " should be Dog";
    ASSERT_EQ(p->getGender(), "Male") << p->getName() << " should be Male";
}


//Testing object setters and getters
TEST(PetsTest, getters){
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

    Pet* p = new Pet(name, species, breed, age, size, temp, gender, gw, sh, bio);

    ASSERT_EQ(p->getName(), "Alex") << p->getName() << " should be Alex";
    ASSERT_EQ(p->getAge(), "Young") << p->getAge() << " should be Young";
    ASSERT_EQ(p->getBreed(), "Siamese") << p->getName() << " should be Siamese";
    ASSERT_EQ(p->getSpecies(), "Cat") << p->getName() << " should be Cat";
    ASSERT_EQ(p->getGender(), "Male") << p->getName() << " should be Male";
    ASSERT_EQ(p->getSize(), "Medium") << p->getName() << " should be Medium";
    ASSERT_EQ(p->getBio(), "Lorem Ipsum") << p->getBio() << " should be Lorem Ipsum";
    ASSERT_EQ(p->getTemperament(), "Passive") << p->getTemperament() << " should be Male";
    ASSERT_EQ(p->getGoodWith(), "Kids") << p->getGoodWith() << " should be Kids";
}

TEST(PetsTest, setters){
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "petsshelter";
    string bio = "Lorem Ipsum";
    string size = "Medium";

    Pet* p = new Pet();

    p->setID(1);
    p->setAge(age);
    p->setBio(bio);
    p->setName(name);
    p->setSize(size);
    p->setGender(gender);
    p->setBio(bio);
    p->setSpecies(species);
    p->setBreed(breed);
    p->setTemperament(temp);
    p->setGoodWith(gw);
    p->setShelter(sh);

    ASSERT_EQ(p->getID(), 1) << p->getID() << " should be 1";
    ASSERT_EQ(p->getShelter(), sh) << p->getShelter() << " should be petsshelter";
    ASSERT_EQ(p->getName(), "Alex") << p->getName() << " should be Alex";
    ASSERT_EQ(p->getAge(), "Young") << p->getAge() << " should be Young";
    ASSERT_EQ(p->getBreed(), "Siamese") << p->getName() << " should be Siamese";
    ASSERT_EQ(p->getSpecies(), "Cat") << p->getName() << " should be Cat";
    ASSERT_EQ(p->getGender(), "Male") << p->getName() << " should be Male";
    ASSERT_EQ(p->getSize(), "Medium") << p->getName() << " should be Medium";
    ASSERT_EQ(p->getBio(), "Lorem Ipsum") << p->getBio() << " should be Lorem Ipsum";
    ASSERT_EQ(p->getTemperament(), "Passive") << p->getTemperament() << " should be Male";
    ASSERT_EQ(p->getGoodWith(), "Kids") << p->getGoodWith() << " should be Kids";
}

TEST(PetsTest, getowner){
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "generic_owner";
    string bio = "Lorem Ipsum";
    string size = "Medium";

    Pet* p = new Pet(name, species, breed, age, size, temp, gender, gw, sh, bio);

    Owner o = p->getOwner("../../testDB.sqlite");
    EXPECT_EQ(o.getEmail(),"abc@xyz");

}

TEST(PetsTest, IDconstructor){
    string age = "Young";
    string name = "Alex";
    string gender = "Male";
    string species = "Cat";
    string breed = "Siamese";
    string temp = "Passive";
    string gw = "Kids";
    string sh = "generic_owner";
    string bio = "Lorem Ipsum";
    string size = "Medium";

    Pet* p = new Pet(101,name, species, breed, age, size, temp, gender, gw, sh, bio);
    EXPECT_EQ(p->getID(), 101) << p->getID() << " should be 101";
    EXPECT_EQ(p->getShelter(), sh) << p->getShelter() << " should be petsshelter";
    EXPECT_EQ(p->getName(), "Alex") << p->getName() << " should be Alex";
    EXPECT_EQ(p->getAge(), "Young") << p->getAge() << " should be Young";
    EXPECT_EQ(p->getBreed(), "Siamese") << p->getName() << " should be Siamese";
    EXPECT_EQ(p->getSpecies(), "Cat") << p->getName() << " should be Cat";
    EXPECT_EQ(p->getGender(), "Male") << p->getName() << " should be Male";
    EXPECT_EQ(p->getSize(), "Medium") << p->getName() << " should be Medium";
    EXPECT_EQ(p->getBio(), "Lorem Ipsum") << p->getBio() << " should be Lorem Ipsum";
    EXPECT_EQ(p->getTemperament(), "Passive") << p->getTemperament() << " should be Male";
    EXPECT_EQ(p->getGoodWith(), "Kids") << p->getGoodWith() << " should be Kids";
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

