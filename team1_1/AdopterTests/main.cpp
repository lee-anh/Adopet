#include <iostream>

#include "gtest/gtest.h"

#include "../Adopter/adopter.h"
#include "../Adopter/preferences.h"


// The fixture for testing class Foo.

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




TEST(general, ADDSPECIES) {

    Preferences *p = new Preferences();
    string s = "dog";
    string c = "cat";

    p->addSpecies(s);
    p->addSpecies(c);
    string check = p->getSpecies().at(0);
    string check2 = p->getSpecies().at(1);
    ASSERT_EQ(check, "dog");
    ASSERT_EQ(check2, "cat");

}

TEST(general, REMOVESPECIESTRUE) {

    Preferences *p = new Preferences();

    p->addSpecies("dog");
    p->addSpecies("cat");
    p->addSpecies("turtle");


    ASSERT_EQ(p->removeSpecies("cat"), true);

    //make sure cat has been removed
    ASSERT_EQ(p->getSpecies().at(1), "turtle");

}

TEST(general, REMOVESPECIESFALSE) {

    Preferences *p = new Preferences();

    p->addSpecies("dog");
    p->addSpecies("cat");

    ASSERT_EQ(p->removeSpecies("turtle"), false);

}

TEST(general, ADDBREED) {

    Preferences *p = new Preferences();
    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    string check = p->getBreed().at(0);
    string check2 = p->getBreed().at(1);
    ASSERT_EQ(check, "golden retriever");
    ASSERT_EQ(check2, "boston terrier");

}

TEST(general, REMOVEBREEDTRUE) {

    Preferences *p = new Preferences();

    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    p->addBreed("chiwawa");


    ASSERT_EQ(p->removeBreed("golden retriever"), true);

    //make sure boston terrier has been removed
    ASSERT_EQ(p->getBreed().at(0), "boston terrier");

}

TEST(general, REMOVEBREEDFALSE) {

    Preferences *p = new Preferences();

    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    p->addBreed("chiwawa");

    ASSERT_EQ(p->removeBreed("maine coon"), false);

}




TEST(general, ADDAGE) {

    Preferences *p = new Preferences();
    p->addAge("young");
    p->addAge("old");

    ASSERT_EQ(p->getAge().at(0), "young");
    ASSERT_EQ(p->getAge().at(1), "old");

}

TEST(general, REMOVEAGETRUE) {

    Preferences *p = new Preferences();

    p->addAge("old");
    p->addAge("young");
    p->addAge("adult");

    ASSERT_EQ(p->removeAge("adult"), true);

    //make sure cat has been removed
    ASSERT_EQ(p->getAge().size(), 2);

}

TEST(general, REMOVEAGEFALSE) {

    Preferences *p = new Preferences();

    p->addAge("old");
    p->addAge("young");
    p->addAge("adult");

    ASSERT_EQ(p->removeAge("dead"), false);

}

TEST(general, ADDSIZE) {

    Preferences *p = new Preferences();
    p->addSize("small");
    p->addSize("large");

    ASSERT_EQ(p->getSize().at(0), "small");
    ASSERT_EQ(p->getSize().at(1), "large");

}

TEST(general, REMOVEADDTRUE) {

    Preferences *p = new Preferences();

    p->addSize("small");
    p->addSize("large");
    p->addSize("medium");

    ASSERT_EQ(p->removeSize("large"), true);

    //make sure cat has been removed
    ASSERT_EQ(p->getSize().size(), 2);

}

TEST(general, REMOVESIZEFALSE) {

    Preferences *p = new Preferences();

    p->addSize("small");
    p->addSize("large");
    p->addSize("medium");

    ASSERT_EQ(p->removeSize("mini"), false);

}

TEST(general, ADDTEMPERAMENT) {

    Preferences *p = new Preferences();
    p->addTemperament("happy");
    p->addTemperament("hyper");

    ASSERT_EQ(p->getTemperament().at(0), "happy");
    ASSERT_EQ(p->getTemperament().at(1), "hyper");

}

TEST(general, REMOVETEMPERAMENTTRUE) {

    Preferences *p = new Preferences();

    p->addTemperament("happy");
    p->addTemperament("hyper");
    p->addTemperament("timid");

    ASSERT_EQ(p->removeTemperament("happy"), true);

    //make sure cat has been removed
    ASSERT_EQ(p->getTemperament().size(), 2);

}

TEST(general, REMOVETEMPERAMENTFALSE) {

    Preferences *p = new Preferences();

    p->addTemperament("happy");
    p->addTemperament("hyper");
    p->addTemperament("timid");

    ASSERT_EQ(p->removeTemperament("annoying"), false);

}

/*
TEST(general, SETGENDER) {

    Preferences *p = new Preferences();
    p->setGender("female");
    ASSERT_EQ(p->getGender(), "female");

}
*/


TEST(general, ADOPTERSETTERS) {
    Adopter *a = new Adopter();
    a->setUsername("m.francis");
    a->setPassword("scaryfairy");
    a->setFirstName("Millie");
    a->setLastName("Francis");
    a->setEmailAddress("francis@gmail.com");
    a->setZipCode(55555);

    ASSERT_EQ(a->getUsername(), "m.francis");
    ASSERT_EQ(a->getPassword(), "scaryfairy");
    ASSERT_EQ(a->getFirstName(), "Millie");
    ASSERT_EQ(a->getLastName(), "Francis");
    ASSERT_EQ(a->getEmailAddress(), "francis@gmail.com");
    ASSERT_EQ(a->getZipCode(), 55555);


}




    int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);

     return RUN_ALL_TESTS();

    }



