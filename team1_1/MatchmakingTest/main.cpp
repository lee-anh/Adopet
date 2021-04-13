#include <iostream>
#include "gtest/gtest.h"
#include "../Matchmaking/matchmaking.h"

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

//Testing if the pets vector is fille correctly with pets in the database
TEST(unitTest, fillPets){
    Matchmaking* m = new Matchmaking();
    ASSERT_EQ(m->getAllPets().size(), 0) << "The vector is empty in the beginning";
    m->fillPets();
    ASSERT_NE(m->getAllPets().size(), 0) << "The vector is no longer empty after fillPets()";
}

//Testing if the <Pet, integer> pair sorter algorithm works properly
TEST(unitTest, PetSorting){
    Matchmaking* m = new Matchmaking();

    vector<pair<Pet*, int>> list;
    vector<pair<Pet*, int>> sortedList;

    //setting up
    Pet* p1 = new Pet();
    Pet* p2 = new Pet();
    Pet* p3 = new Pet();
    int i1 = 5;
    int i2 = 24;
    int i3 = 9;
    list.push_back(make_pair(p1, i1));
    list.push_back(make_pair(p2, i2));
    list.push_back(make_pair(p3, i3));
    sortedList.push_back(make_pair(p2, i2));
    sortedList.push_back(make_pair(p3, i3));
    sortedList.push_back(make_pair(p1, i1));

    ASSERT_EQ(list.size(), sortedList.size()) << "The vectors have the same size";
    ASSERT_NE(list.at(0).second, sortedList.at(0).second) << "The first element of the vectors is differnt";

    sort(list.begin(), list.end(), m->customPetResultSort);

    for (int i = 0; i < (int)list.size(); i++) {
       ASSERT_EQ(list.at(i).second, sortedList.at(i).second) << "Both vectors have the same element at index " << i;
    }
}

//Testing if the <Adopter, integer> pair sorter algorithm works properly
TEST(unitTest, AdopterSorting){
    Matchmaking* m = new Matchmaking();

    vector<pair<Adopter*, int>> list;
    vector<pair<Adopter*, int>> sortedList;

    //setting up
    Adopter* a1 = new Adopter();
    Adopter* a2 = new Adopter();
    Adopter* a3 = new Adopter();
    int i1 = 66;
    int i2 = 2;
    int i3 = 43;
    list.push_back(make_pair(a1, i1));
    list.push_back(make_pair(a2, i2));
    list.push_back(make_pair(a3, i3));
    sortedList.push_back(make_pair(a2, i1));
    sortedList.push_back(make_pair(a3, i3));
    sortedList.push_back(make_pair(a1, i2));

    ASSERT_EQ(list.size(), sortedList.size()) << "The vectors have the same size";
    ASSERT_NE(list.at(2).second, sortedList.at(2).second) << "The first element of the vectors is differnt";

    sort(list.begin(), list.end(), m->customAdopterResultSort);

    for (int i = 0; i < (int)list.size(); i++) {
       ASSERT_EQ(list.at(i).second, sortedList.at(i).second) << "Both vectors have the same element at index " << i;
    }
}

//Testing if makePet() works properly
TEST(unitTest, makePet){
    Matchmaking* m = new Matchmaking();
    QSqlQuery query = QSqlQuery();
    QString s = "SELECT * FROM pets";
    query.exec(s);
    query.next();
    string name = query.value(1).toString().toStdString();
    string species = query.value(2).toString().toStdString();
    string breed = query.value(3).toString().toStdString();
    string age = query.value(4).toString().toStdString();
    string size = query.value(5).toString().toStdString();
    string temperament = query.value(6).toString().toStdString();
    string gender = query.value(7).toString().toStdString();
    string goodWith = query.value(8).toString().toStdString();
    string shelter = query.value(9).toString().toStdString();
    string bio = query.value(10).toString().toStdString();

    Pet* pet = m->makePet(query);

    ASSERT_EQ(name, pet->getName()) << "Checking the pet name is correct";
    ASSERT_EQ(species, pet->getSpecies()) << "Checking the pet species is correct";
    ASSERT_EQ(breed, pet->getBreed()) << "Checking the pet breed is correct";
    ASSERT_EQ(age, pet->getAge()) << "Checking the pet age is correct";
    ASSERT_EQ(size, pet->getSize()) << "Checking the pet size is correct";
    ASSERT_EQ(temperament, pet->getTemperament()) << "Checking the pet temperament is correct";
    ASSERT_EQ(gender, pet->getGender()) << "Checking the pet gender is correct";
    ASSERT_EQ(goodWith, pet->getGoodWith()) << "Checking the pet goodWith is correct";
    ASSERT_EQ(shelter, pet->getShelter()) << "Checking the pet shelter is correct";
    ASSERT_EQ(bio, pet->getBio()) << "Checking the pet bio is correct";
}

//Testing if fillPreference() works properly
TEST(unitTest, fillPreference){
    Matchmaking* m = new Matchmaking();
    Preferences* p = new Preferences();

    m->fillPreference(p, "dog", "species");
    m->fillPreference(p, "fish", "species");
    m->fillPreference(p, "cat", "species");
    m->fillPreference(p, "male", "gender");

    ASSERT_EQ(p->getGender(), "male") << "Checking that the gender preference is set correctly";
    ASSERT_EQ(p->getSpecies().size(), 3) << "Checking that the size of the species preference is set correctly";
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


