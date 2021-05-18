# Adopet

Adopet is a pet searching desktop application that helps adopters find a pet and helps owners find adopters for their pets.

<h2> <b> Running Adopet </b> </h2>

This project runs on QT Creator and is coded primarily in C++. To run the program, install the latest verstion of QT Creator, open and configure the project, and run it from QT. Please also make sure that you have sqlite3 installed. 

<h3>Operating System</h3>

If you are running Adopet on Linux or Windows, Adopet won't have video playing capabilities. Please use the latest version of Adopet that is tagged as Adopet for Linux and Windows. Please note that the GUI formatting may look a little bit off because the GUI was designed on a Mac. 

If you are running Adopet on Mac with the latest version of QT, then you'll be able to play the videos. You will have to uncomment videoplayer.cpp, videoplayer.h, lines 151 to 163 in gui.cpp, and lines 10 and 11 in gui.pro. Because of a bug in QT, you will have to give an absolute filepath for the videos. Change the string called videoFile to fit your system (it should be around line 156 of gui.cpp in the GUI subproject). Please use the latest version of Adopet that is tagged as Adopet for Mac. Adopet's GUI actually looks the best on Mac as it was designed on a Mac. 

<h3>Database Setup</h3>

No matter what operating system you are using, you will have to set up the database! Please set up the database in the top level directory of this repo and call it <b>projectDB.sqlite</b>. Feed in schema.sql to set up the database and deleteTables.sql to clear the database. 

<h3>Other Important Info</h3>
We also used ZipCodeApi's Zip Codes in Radius API to determine shelters near a certain user's location. We are operating on a free account. Until midnight on 5/21/2021, we can have 50 calls per hour. After that, we will have only 10 calls per hour. Therefore, please try to limit the amount of times you call the api by not changing the location of a search very frequently. If the location services stop working, it it probably because we exceeded the call limit for the hour, so please try again after an hour. 

Finally, please note that when you are running the program you might get "duplicate connection" warnings from the QSqlPrivateDatabase. These are simply warnings and do not affect the performance of the system in anyway. 

<h2> <b> Testing Adopet </b> </h2>
We wrote the tests using gtest, Google's test suite for C++. You must have gtest installed on your machine to run the tests. The tests are written in their own subprojects. To run the test coverage, follow this tutorial: https://kelvinsp.medium.com/generating-code-coverage-with-qt-5-and-gcov-on-mac-os-4999857f4676


<h2> <b> Key accounts </b> </h2>
Currently, Adopet is filled with dummy data. We have 100 pets and 100 adopters loaded into the system. We have 3 dummy owners (shelters). One is located in San Jose, CA and two are located in Easton, PA.

Feel free to make other adopter and owner (don't forget to upload some pets)!

<h3>Key Adopter Accounts:</h3>

*Adopter from San Jose:*

username: user1

password: password1


*Adopter from Bethlehem:*

username:user2

password: password2


*Adopter from Easton:*

username: user3

password: password3

All of these adopter accounts have the same functionalities, they are just in different locations. Feel free to change their zipcodes to to other valid zipcodes (my info)

<h3>Key Owner Accounts:</h3>


*Easton Shelters:*

username: shelter1

password: pwd1

username: shelter2

password: pwd2


*San Jose Shelter:*

username: shelter3

password: pwd3

All of these owner accounts have the same functionalities, they are just in different locations. Feel free to change their zipcodes to other valid zipcodes (my info)  

*IMPORTANT*

When uploading pets by bulk, make sure you place the csv in the csv folder of this project before trying to upload it. For a demo bulk upload csv, use demo.csv.

When media (pictures and videos for pets) make sure to only use jpeg or mp4. Any pictures you intend to use should be placed in the pictures folder of this project, and any videos should be placed in the vidoes folder. For test pictures, use any animal from bird, cat, dog, fish, rabbit, or rodent + any number 1 - 8 (inclusive) + jpeg. Ex. dog7.jpeg, rodent3.jpeg. For test videos use any animal from bird, cat, dog, fish, rabbit, or rodent + either 1 or 2 + mp4. Ex. bird1.mp4, cat2.mp4. The test picture and video files are already in their respective folders.





