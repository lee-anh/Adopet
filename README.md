# Adopet

Adopet is a pet searching desktop application that helps adopters find a pet and helps owners find adopters for their pets.

<h2> <b> Running Adopet </b> </h2>

This project runs on QT Creator and is coded primarily in C++. To run the program, install the latest verstion of QT Creator, open and configure the project, and run it from QT. Please also make sure that you have sqlite3 installed. 

Depending on your operating system and version of QT, there are a few important instructions to be aware of. 

First, if you are running Adopet on Linux (ie. lab server) or Windows, Adopet won't have video playing capabilities. Please use the latest version of Adopet that is tagged as Adopet for Linux and Windows. Please note that the GUI formatting may look a little bit off because the GUI was designed on a Mac. 

If you are running Adopet on Mac with the latest version of QT, then you'll be able to play the videos. Please use the latest version of Adopet that is tagged as Adopet for Mac. Adopet's GUI actually looks the best on Mac as it was designed on a Mac. 

We also used ZipCodeApi's Zip Codes in Radius API to determine shelters near a certain user's location. We are operating on a free account. Until 5/22/2021, we can have 50 calls per hour. After that, we will have only 10 calls per hour. Therefore, please try to limit the amount of times you call the api by not changing the location of a search very frequently. If the location services stop working, it it probably because we exceeded the call limit for the hour, so please try again after an hour. 


<h2> <b> Testing Adopet </b> </h2>
We wrote the tests using gtest, Google's test suite for C++. You must have gtest installed on your machine to run the tests. You will also need lcov. 


<h2> <b> Key accounts </b> </h2>
Currently, Adopet is filled with dummy data. To add more dummy data for 

We have 3 shelters right now. One is located in San Jose, CA and two are located in Easton, PA. When testing the queries to the Zipcode API (location), please 

Feel free to also make a shelter with another zipcode, add some pets, and see how that affects queries on the adopter side. 
  
Key Sheleter Accounts:
username:shelter1

password:pwd1

username:shelter2

password:pwd2

username:shelter3

password:pwd3

All of these shelters have the same functionalities, they are just in different locations. Feel free to change their zipcode to other valid zipcodes. 

Key Adopter Accounts:
username: 
password:

Finally, please note that when you are running the program you might get "duplicate connection" warnings from the QSqlPrivateDatabase. These are simply warnings and do not affect the performance of the system in anyway. 

