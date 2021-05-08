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
    EXPECT_EQ(check, "dog");
    EXPECT_EQ(check2, "cat");

}

TEST(general, REMOVESPECIESTRUE) {

    Preferences *p = new Preferences();

    p->addSpecies("dog");
    p->addSpecies("cat");
    p->addSpecies("turtle");


    EXPECT_EQ(p->removeSpecies("cat"), true);

    //make sure cat has been removed
    EXPECT_EQ(p->getSpecies().at(1), "turtle");

}

TEST(general, REMOVESPECIESFALSE) {

    Preferences *p = new Preferences();

    p->addSpecies("dog");
    p->addSpecies("cat");

    EXPECT_EQ(p->removeSpecies("turtle"), false);

}

TEST(general, ADDBREED) {

    Preferences *p = new Preferences();
    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    string check = p->getBreed().at(0);
    string check2 = p->getBreed().at(1);
    EXPECT_EQ(check, "golden retriever");
    EXPECT_EQ(check2, "boston terrier");

}

TEST(general, REMOVEBREEDTRUE) {

    Preferences *p = new Preferences();

    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    p->addBreed("chiwawa");


    EXPECT_EQ(p->removeBreed("golden retriever"), true);

    //make sure boston terrier has been removed
    EXPECT_EQ(p->getBreed().at(0), "boston terrier");

}

TEST(general, REMOVEBREEDFALSE) {

    Preferences *p = new Preferences();

    p->addBreed("golden retriever");
    p->addBreed("boston terrier");
    p->addBreed("chiwawa");

    EXPECT_EQ(p->removeBreed("maine coon"), false);

}




TEST(general, ADDAGE) {

    Preferences *p = new Preferences();
    p->addAge("young");
    p->addAge("old");

    EXPECT_EQ(p->getAge().at(0), "young");
    EXPECT_EQ(p->getAge().at(1), "old");

}

TEST(general, REMOVEAGETRUE) {

    Preferences *p = new Preferences();

    p->addAge("old");
    p->addAge("young");
    p->addAge("adult");

    EXPECT_EQ(p->removeAge("adult"), true);

    //make sure cat has been removed
    EXPECT_EQ(p->getAge().size(), 2);

}

TEST(general, REMOVEAGEFALSE) {

    Preferences *p = new Preferences();

    p->addAge("old");
    p->addAge("young");
    p->addAge("adult");

    EXPECT_EQ(p->removeAge("dead"), false);

}

TEST(general, ADDSIZE) {

    Preferences *p = new Preferences();
    p->addSize("small");
    p->addSize("large");

    EXPECT_EQ(p->getSize().at(0), "small");
    EXPECT_EQ(p->getSize().at(1), "large");

}

TEST(general, REMOVEADDTRUE) {

    Preferences *p = new Preferences();

    p->addSize("small");
    p->addSize("large");
    p->addSize("medium");

    EXPECT_EQ(p->removeSize("large"), true);

    //make sure cat has been removed
    EXPECT_EQ(p->getSize().size(), 2);

}

TEST(general, REMOVESIZEFALSE) {

    Preferences *p = new Preferences();

    p->addSize("small");
    p->addSize("large");
    p->addSize("medium");

    EXPECT_EQ(p->removeSize("mini"), false);

}

TEST(general, ADDTEMPERAMENT) {

    Preferences *p = new Preferences();
    p->addTemperament("happy");
    p->addTemperament("hyper");

    EXPECT_EQ(p->getTemperament().at(0), "happy");
    EXPECT_EQ(p->getTemperament().at(1), "hyper");

}

TEST(general, REMOVETEMPERAMENTTRUE) {

    Preferences *p = new Preferences();

    p->addTemperament("happy");
    p->addTemperament("hyper");
    p->addTemperament("timid");

    EXPECT_EQ(p->removeTemperament("happy"), true);

    //make sure cat has been removed
    EXPECT_EQ(p->getTemperament().size(), 2);

}

TEST(general, REMOVETEMPERAMENTFALSE) {

    Preferences *p = new Preferences();

    p->addTemperament("happy");
    p->addTemperament("hyper");
    p->addTemperament("timid");

    EXPECT_EQ(p->removeTemperament("annoying"), false);

}


TEST(general, SETGENDER) {

    Preferences *p = new Preferences();
    p->addGender("female");
    EXPECT_EQ(p->getGender().at(0), "female");

}



TEST(general, ADOPTERSETTERS) {
    Adopter *a = new Adopter();
    a->setUsername("m.francis");
    a->setPassword("scaryfairy");
    a->setFirstName("Millie");
    a->setLastName("Francis");
    a->setEmailAddress("francis@gmail.com");
    a->setZipCode(55555);

    EXPECT_EQ(a->getUsername(), "m.francis");
    EXPECT_EQ(a->getPassword(), "scaryfairy");
    EXPECT_EQ(a->getFirstName(), "Millie");
    EXPECT_EQ(a->getLastName(), "Francis");
    EXPECT_EQ(a->getEmailAddress(), "francis@gmail.com");
    EXPECT_EQ(a->getZipCode(), 55555);


}

TEST(general, FILLPREF){
    Adopter *a = new Adopter();
    a->fillPreference("dog", "species");
    a->fillPreference("beagle", "breed");
    a->fillPreference("medium", "size");
    a->fillPreference("friendly", "temperament");
    a->fillPreference("male","gender");
    a->fillPreference("kids","goodWith");
    a->fillPreference("PetsShelter","shelter");
    a->fillPreference("young","age");

    Preferences p = a->getPreferences();
    EXPECT_EQ(p.getAge().at(0),"young");
    EXPECT_EQ(p.getTemperament().at(0),"friendly");
    EXPECT_EQ(p.getBreed().at(0),"beagle");
    EXPECT_EQ(p.getShelter().at(0),"petsshelter");
    EXPECT_EQ(p.getSpecies().at(0),"dog");
    EXPECT_EQ(p.getGoodWith().at(0),"kids");
    EXPECT_EQ(p.getGender().at(0),"male");
}

TEST(general, REMMOVEPREF){
    Adopter *a = new Adopter();
    a->fillPreference("dog", "species");
    a->fillPreference("beagle", "breed");
    a->fillPreference("medium", "size");
    a->fillPreference("friendly", "temperament");
    a->fillPreference("male","gender");
    a->fillPreference("kids","goodWith");
    a->fillPreference("petsshelter","shelter");
    a->fillPreference("young","age");

    a->removePreference("male","gender");
    a->removePreference("petsshelter","shelter");
    //Case sensitive issues:
    //Everything lowercase except for username, password and bio

    Preferences p = a->getPreferences();
    EXPECT_EQ(p.getGender().size(),0);
    EXPECT_EQ(p.getShelter().size(),0);
}

TEST(general, ADDPREF){
    Adopter *a = new Adopter();
    a->fillPreference("dog", "species");
    a->fillPreference("beagle", "breed");
    a->fillPreference("medium", "size");
    a->fillPreference("friendly", "temperament");
    a->fillPreference("male","gender");
    a->fillPreference("kids","goodWith");
    a->fillPreference("PetsShelter","shelter");
    a->fillPreference("young","age");

    a->addPreference("female","gender");
    a->addPreference("PetsShelter","shelter");

    Preferences p = a->getPreferences();
    EXPECT_EQ(p.getGender().size(),2);
    EXPECT_EQ(p.getShelter().size(),2);
}

    int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);

     return RUN_ALL_TESTS();

    }



