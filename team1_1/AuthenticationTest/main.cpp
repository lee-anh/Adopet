#include <iostream>

#include "gtest/gtest.h"
#include "../Authentication/authentication.h"

#include "../Adopter/adopter.h"
#include "../Adopter/preferences.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"
#include <QtSql>


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
        auth = Authentication("../../testDB.sqlite");

     }

     virtual void TearDown() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","authTestConnection");
        string fullName = "../../testDB.sqlite";
        db.setDatabaseName(QString::fromStdString(fullName));
        if(!db.open()){
            std::cerr << "Database does not open -- "
                      << db.lastError().text().toStdString()
                      << std::endl;

            std::cerr << "  File -- " << fullName << std::endl;
            exit(0);
        } else {
            std::cerr << "Opened database successfully (from Authentication class)\n";
        }

        if(db.open()){
            QSqlQuery qry = QSqlQuery(db);
            QString qs = "DELETE FROM accounts WHERE username=\"user11\";" ;
            qry.exec(qs);
            cout << "Deleted user 11" << endl;
            qs = "DELETE FROM accounts WHERE username=\"user12\";" ;
            qry.exec(qs);
            cout << "Deleted user 12" << endl;
            qs = "DELETE FROM adopters WHERE username=\"user11\";" ;
            qry.exec(qs);
            qs = "DELETE FROM owners WHERE username=\"user12\";" ;
        }
     }

     // Objects declared here can be used by all tests in the test case for Foo.
    Authentication auth;





};

TEST_F(AuthTest, testLogin){
    int login = auth.logIn("user1","password1");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0"<< endl;
}

TEST_F(AuthTest, testLoginFail){
    int login = auth.logIn("user11","password10");
    EXPECT_EQ(login,-1) << "Should not grant access " << login << "should be -1" << endl;
}


//Testing object setters and getters
TEST_F(AuthTest, signUpAdopter){
    bool signup = auth.signUp("user11","password11", "adopter");
    EXPECT_EQ(signup,true) << "Should create new adopter " << signup << "should be 1" << endl;
    int login = auth.logIn("user11","password11");
    EXPECT_EQ(login,0) << "Should grant access " << login << "should be 0" << endl;
    Adopter* adpt = auth.getAuthenticatedAdopter();
    if(!adpt){
        FAIL() << "Owner is null even already signed up!" << endl;
    }
}

TEST_F(AuthTest, signUpOwner){
    bool signup = auth.signUp("user12","password12", "owner");
    EXPECT_EQ(signup,true) << "Should create new owner " << signup << "should be 1" << endl;
    int login = auth.logIn("user12","password12");
    EXPECT_EQ(login,1) << "Should grant access " << login << "should be 1" << endl;
    Owner* owner = auth.getAuthenticatedOwner();
    if(!owner){
        FAIL() << "Owner is null even already signed up!" << endl;
    }

}

TEST_F(AuthTest, signUpAdopterFail){
    bool signup = auth.signUp("user10","password10", "adopter");
    EXPECT_EQ(signup,false) << "Should not create new adopter " << signup << "should be 0" << endl;
}

TEST_F(AuthTest, signUpOwnerFail){
    bool signup = auth.signUp("user10","password10", "owner");
    EXPECT_EQ(signup,false) << "Should not create new adopter " << signup << "should be 0" << endl;
}


TEST_F(AuthTest, updateAdopter){
    auth.signUp("user11","password11", "adopter");
    auth.logIn("user11","password11");
    auth.updateAdopter("user11", "Evan", "Vu", "vuc@laf.edu", "18042");
    Adopter* adptr = auth.getAuthenticatedAdopter();
    EXPECT_EQ(adptr->getFirstName(),"Evan");
}

TEST_F(AuthTest, updateOwner){
    auth.signUp("user12","password12", "owner");
    auth.logIn("user12","password12");
    auth.updateOwner("user12", "Cuong", "12345", "vuc@laf.edu", "111 Quad Drive", "18042");
    Owner* adptr = auth.getAuthenticatedOwner();
    EXPECT_EQ(adptr->getName(),"Cuong");
}

TEST_F(AuthTest, insertOwner){
    auth.insertOwnerToDB("user12","Evan","123","abc@xyz","111 Quad","18042");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","authTestConnection");
    string fullName = "../../testDB.sqlite";
    db.setDatabaseName(QString::fromStdString(fullName));
    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from Authentication class)\n";
    }

    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "SELECT FROM owner WHERE username=\"user12\";" ;
        qry.exec(qs);
        while(qry.next()){
            EXPECT_EQ(qry.value(1).toString(), "Evan");
        }
    }
}

TEST_F(AuthTest, insertAdpt){
    auth.insertAdopterToDB("user11","Eve","Vu","abc@xyz","18042");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","authTestConnection");
    string fullName = "../../testDB.sqlite";
    db.setDatabaseName(QString::fromStdString(fullName));
    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << fullName << std::endl;
        exit(0);
    } else {
        std::cerr << "Opened database successfully (from Authentication class)\n";
    }

    if(db.open()){
        QSqlQuery qry = QSqlQuery(db);
        QString qs = "SELECT FROM owner WHERE username=\"user11\";" ;
        qry.exec(qs);
        while(qry.next()){
            EXPECT_EQ(qry.value(1).toString(), "Eve");
        }
    }
}



int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

