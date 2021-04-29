#ifndef MYPETS_H
#define MYPETS_H

#include <QWidget>
#include "petadopted.h"
#include <algorithm>

#include "../Owner/owner.h"
#include "../Pets/pet.h"
#include "petgallery.h"
#include "tagguide.h"

namespace Ui {
class MyPets;
}

class MyPets : public QWidget
{
    Q_OBJECT

public:
    explicit MyPets(QWidget *parent = nullptr);
    ~MyPets();

    void setOwner(Owner *o);
    void goToUploadPet();
    void goToMyPets();

private:
    Ui::MyPets *ui;
    Owner *owner;
    PetGallery petgal;
    PetAdopted petAdopted;

    int previousPage;

    void galleryMode();
    void listMode();

    void toEditPet(Pet p);

    void getIndex(string attribute, string type);

    string mode;
    int whichPet;
    Pet currentPet;

    void clearAll();

private slots:
    void on_markAsAdopted_clicked();

    //for signal
    void backToMyPets();


    void on_singleUploadButton_clicked();
    void on_saveChangesButton_clicked();

    //gallery mode
    void on_previous_clicked();
    void on_next_clicked();
    void on_backButton_clicked();
    void on_link1_clicked();
    void on_link2_clicked();
    void on_link3_clicked();
    void on_link4_clicked();


    void on_link1a_clicked();
    void on_link2a_clicked();
    void on_link3a_clicked();
    void on_link4a_clicked();
    void on_link5a_clicked();
    void on_link6a_clicked();
    void on_link7a_clicked();
    void on_link8a_clicked();
    void on_previousa_clicked();
    void on_nexta_clicked();

    void on_viewMode_currentIndexChanged(int index);
    void on_viewModea_currentIndexChanged(int index);



    //list mode
    void on_speciesComboBox_currentIndexChanged(int index);
    void on_breedComboBox_currentIndexChanged(int index);
    void on_temperamentComboBox_currentIndexChanged(int index);
    void on_genderComboBox_currentIndexChanged(int index);
    void on_sizeComboBox_currentIndexChanged(int index);
    void on_goodWithComboBox_currentIndexChanged(int index);
    void on_ageComboBox_currentIndexChanged(int index);
    void on_speciesLine_textEdited(const QString &arg1);
    void on_breedLine_textEdited(const QString &arg1);
    void on_temperamentLine_textEdited(const QString &arg1);
    void on_goodWithLine_textEdited(const QString &arg1);
    void on_bioBox_textChanged();
    void on_multimediaBox_textChanged();

    void on_toBulkUpload_clicked();
    void on_pushButton_3_clicked();
};

#endif // MYPETS_H
