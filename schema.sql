create table pets (
      id            INT NOT NULL UNIQUE,
      name          CHAR NOT NULL,
      species       CHAR NOT NULL,
      breed         CHAR NOT NULL,
      age           CHAR NOT NULL,
      size          CHAR NOT NULL, 
      temperament   CHAR NOT NULL,
      gender        CHAR NOT NULL,
      goodWith      CHAR, 
      shelter       CHAR NOT NULL, 
      bio           CHAR

);

create table accounts(
      username  CHAR NOT NULL UNIQUE,
      password  CHAR NOT NULL,
      accountType CHAR NOT NULL

);

create table owner(
      username CHAR NOT NULL UNIQUE,
      name     CHAR NOT NULL UNIQUE,
      phoneNumber BIGINT NOT NULL,
      emailAddress CHAR NOT NULL,
      ownerAddress CHAR NOT NULL, 
      zip         INT NOT NULL
);

create table adopter(
      username  CHAR NOT NULL UNIQUE,
      firstName CHAR NOT NULL,
      lastName CHAR NOT NULL,
      emailAddress CHAR NOT NULL, 
      zip         INT NOT NULL
      

);

create table preferences(
      adopterUsername CHAR NOT NULL, 
      attribute     CHAR NOT NULL, 
      attributeType CHAR NOT NULL

);

create table savedPets(
      username CHAR NOT NULL,
      petID INT NOT NULL

);

create table media(
      petID INT NOT NULL, 
      filename CHAR NOT NULL,
      mediaType CHAR NOT NULL
);
      
create table species (
      speciesType   CHAR NOT NULL
);

create table breed (
      breedType     CHAR NOT NULL,
      speciesType   CHAR NOT NULL
);


create table temperament (
      temperamentType   CHAR NOT NULL
);

create table goodWith (
      goodWithType  CHAR NOT NULL
);

create table shelter (
      shelterType   CHAR NOT NULL
);



.separator ","
.mode csv
.import "csvs/pets.csv" pets
.import "csvs/species.csv" species
.import "csvs/media.csv" media
.import "csvs/breed.csv" breed
.import "csvs/temperament.csv" temperament
.import "csvs/good_with.csv" goodWith
.import "csvs/shelter.csv" shelter
.import "csvs/accounts.csv" accounts
.import "csvs/adopters.csv" adopter
.import "csvs/preferences.csv" preferences
.import "csvs/owner.csv" owner
