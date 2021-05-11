#ifndef FINDMATCHFORADOPTERS_H
#define FINDMATCHFORADOPTERS_H

#include <QWidget>
#include "../Pets/pet.h"
#include "../Matchmaking/matchmaking.h"
#include "../SavedList/savedlist.h"
#include "petgallery.h"
#include "zip.h"
#include <chrono>


namespace Ui {
class FindMatchForAdopters;
}

/*!
 * \brief The FindMatchForAdopters class
 */
class FindMatchForAdopters : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief FindMatchForAdopters constructor
     */
    explicit FindMatchForAdopters(QWidget *parent = nullptr);

    /*!
     * \brief FindMatchForAdopters destructor
     */
    ~FindMatchForAdopters();

    /*!
     * \brief setSavedList
     * \param s
     */
    void setSavedList(SavedList s);

    /*!
     * \brief setUser
     * \param username
     */
    void setUser(string username, string zipCode);


private:
    Ui::FindMatchForAdopters *ui;

    //objects
    Matchmaking mat;
    PetGallery petgal;
    SavedList sl;
    string user;
    Zip zp;

    string currentViewMode;
    string zip;



    /*!
     * \brief galleryMode for pet display
     */
    void galleryMode();

    /*!
     * \brief listMode for pet display
     */
    void listMode();

    \

    /*!
     * \brief loadSaveButtons
     * \param saveButtons
     */
    void loadSaveButtons(vector<QPushButton *> saveButtons);


    /*!
     * \brief saveButton
     * \param saveButton
     * \param index
     */
    void saveButton(QPushButton* saveButton, int index);

    /*!
     * \brief stateChange of view mode or location
     * \param viewMode
     * \param location
     */
    void stateChange(int viewMode, int location);

    /*!
     * \brief APICall call the zipcode api
     * \param distance
     */
    void APICall(string distance);


private slots:

    /*!
     * \brief finishedAPICall, display results using info from api call
     */
    void finishedAPICall();

    //GALLERY SLOTS

    /*!
     * \brief on_previous_clicked
     */
    void on_previous_clicked();

    /*!
     * \brief on_next_clicked
     */
    void on_next_clicked();

    /*!
     * \brief on_link1_clicked
     */
    void on_link1_clicked();

    /*!
     * \brief on_link2_clicked
     */
    void on_link2_clicked();

    /*!
     * \brief on_link3_clicked
     */
    void on_link3_clicked();

    /*!
     * \brief on_link4_clicked
     */
    void on_link4_clicked();

    /*!
     * \brief on_save1_clicked
     */
    void on_save1_clicked();

    /*!
     * \brief on_save2_clicked
     */
    void on_save2_clicked();

    /*!
     * \brief on_save3_clicked
     */
    void on_save3_clicked();

    /*!
     * \brief on_save4_clicked
     */
    void on_save4_clicked();



    //LIST VIEW

    /*!
     * \brief on_previousa_clicked
     */
    void on_previousa_clicked();

    /*!
     * \brief on_nexta_clicked
     */
    void on_nexta_clicked();

    /*!
     * \brief on_link1a_clicked
     */
    void on_link1a_clicked();

    /*!
     * \brief on_link2a_clicked
     */
    void on_link2a_clicked();

    /*!
     * \brief on_link3a_clicked
     */
    void on_link3a_clicked();

    /*!
     * \brief on_link4a_clicked
     */
    void on_link4a_clicked();

    /*!
     * \brief on_link5a_clicked
     */
    void on_link5a_clicked();

    /*!
     * \brief on_link6a_clicked
     */
    void on_link6a_clicked();

    /*!
     * \brief on_save1a_clicked
     */
    void on_save1a_clicked();

    /*!
     * \brief on_save2a_clicked
     */
    void on_save2a_clicked();

    /*!
     * \brief on_save3a_clicked
     */
    void on_save3a_clicked();

    /*!
     * \brief on_save4a_clicked
     */
    void on_save4a_clicked();

    /*!
     * \brief on_save5a_clicked
     */
    void on_save5a_clicked();

    /*!
     * \brief on_save6a_clicked
     */
    void on_save6a_clicked();


    /*!
     * \brief on_viewMode_currentIndexChanged
     * \param index
     */
    void on_viewMode_currentIndexChanged(int index);

    /*!
     * \brief on_viewModea_currentIndexChanged
     * \param index
     */
    void on_viewModea_currentIndexChanged(int index);




    /*!
     * \brief on_location_currentIndexChanged
     * \param index
     */
    void on_location_currentIndexChanged(int index);


    /*!
     * \brief on_locationa_currentIndexChanged
     * \param index
     */
    void on_locationa_currentIndexChanged(int index);

signals:

    /*!
     * \brief learnMoreClicked, emits that a pet to learn more about
     * \param sendPet
     * \param b
     */
    void learnMoreClicked(Pet sendPet, bool b);

    /*!
     * \brief heartClicked, emit that a saved button was clicked
     * \param p
     * \param b
     */
    void heartClicked(Pet p, bool b);

};

#endif // FINDMATCHFORADOPTERS_H
