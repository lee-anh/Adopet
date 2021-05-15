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

/*!
 * \brief The MyPets class is the gui class for uploading and viewing pets
 */
class MyPets : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief MyPets constructor
     * \param parent
     */
    explicit MyPets(QWidget *parent = nullptr);
    ~MyPets();

    /*!
     * \brief setOwner sets the owner object class
     * \param o
     */
    void setOwner(Owner *o);

    /*!
     * \brief goToUploadPet page
     */
    void goToUploadPet();

    /*!
     * \brief goToMyPets page
     */
    void goToMyPets();

private:
    Ui::MyPets *ui;
    Owner *owner;
    PetGallery petgal;
    PetAdopted petAdopted;

    int previousPage;

    /*!
     * \brief galleryMode set up for gallery mode
     */
    void galleryMode();

    /*!
     * \brief listMode set up for list mode
     */
    void listMode();


    /*!
     * \brief toEditPet, set up for edit pet page
     * \param p
     */
    void toEditPet(Pet p);

    /*!
     * \brief getIndex given an attribute, set the correct indexes for
     * the combo boxes, loading info for edit pet
     * \param attribute
     * \param type
     */
    void getIndex(string attribute, string type);

    string mode;
    int whichPet;
    Pet currentPet;

    /*!
     * \brief clearAll clear all the labels in the edit pet page
     */
    void clearAll();

    /*!
     * \brief imageProcessor parse image filenames
     * \param s
     */
    void imageProcessor(string s);

    /*!
     * \brief videoProcessor parse video filenames
     * \param s
     */
    void videoProcessor(string s);

signals:
    /*!
     * \brief goToMeetPet, preview pet
     * \param p
     */
    void goToMeetPet(Pet p);

private slots:

    /*!
     * \brief on_markAsAdopted_clicked remove a pet from the database
     */
    void on_markAsAdopted_clicked();

    //for signal
    /*!
     * \brief backToMyPets go back to my pets page
     */
    void backToMyPets();


    /*!
     * \brief on_singleUploadButton_clicked got to upload one pet page
     */
    void on_singleUploadButton_clicked();

    /*!
     * \brief on_saveChangesButton_clicked uploads changes to pet
     */
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


    /*!
     * \brief on_viewMode_currentIndexChanged change view mode, gallery view
     * \param index
     */
    void on_viewMode_currentIndexChanged(int index);
    /*!
     * \brief on_viewModea_currentIndexChanged change view mode, list view
     * \param index
     */
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
    void on_videoFile_textChanged(const QString &arg1);
    void on_bioBox_textChanged();
    void on_multimediaBox_textChanged();


    /*!
     * \brief on_toBulkUpload_clicked navigate to bulk upload page
     */
    void on_toBulkUpload_clicked();

    /*!
     * \brief on_pushButton_3_clicked pull up tag guide
     */
    void on_pushButton_3_clicked();

    /*!
     * \brief on_bulkUpload_2_clicked upload the csv and send state message
     */
    void on_bulkUpload_2_clicked();

    //preview buttons
    void on_prev1_clicked();
    void on_prev2_clicked();
    void on_prev3_clicked();
    void on_prev4_clicked();

    void on_prev1a_clicked();
    void on_prev2a_clicked();
    void on_prev3a_clicked();
    void on_prev4a_clicked();
    void on_prev5a_clicked();
    void on_prev6a_clicked();
    void on_prev7a_clicked();
    void on_prev8a_clicked();


};

#endif // MYPETS_H
