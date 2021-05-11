#ifndef FINDMATCHFORPETS_H
#define FINDMATCHFORPETS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <QCompleter>

#include "../Matchmaking/matchmaking.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"





namespace Ui {
class FindMatchForPets;
}

/*!
 * \brief The FindMatchForPets class allows shelter owners to
 * find an adopter for one pet or for multiple pets.
 */
class FindMatchForPets : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief FindMatchForPets constructor
     * \param parent
     */
    explicit FindMatchForPets(QWidget *parent = nullptr);

    /*!
     * \brief ~FindMatchForPets destructor
     * \param parent
     */
    ~FindMatchForPets();

    /*!
     * \brief toMainPage brings users to the main page for Find Match
     * \param owner
     */
    void toMainPage(Owner* owner);

private:
    Ui::FindMatchForPets *ui;

    Owner* currentOwner;
    Matchmaking mat;
    /*!
     * \brief setup for both modes
     */
    void setup();


    /*!
     * \brief forOnePet setup for one pet
     * \param owner
     */
    void forOnePet(Owner* owner);

    /*!
     * \brief forMultiPets setup for all pets
     * \param owner
     */
    void forMultiPets(Owner* owner);




    /*!
     * \brief displayPeople on list for one pet
     * \param start index
     */
    void displayPeople(int start);

    /*!
     * \brief displayPeopleMulti on list for all pets
     * \param start index
     */
    void displayPeopleMulti(int start);

    /*!
     * \brief next, go forward on list
     */
    void next();

    /*!
     * \brief previous, go backward on list
     */
    void previous();

    /*!
     * \brief setPageNum set page number
     * \param p
     */
    void setPageNum(int p);

    /*!
     * \brief clearAll clear all relavent labels
     */
    void clearAll();


    int numToDisplay;
    int nextStartIndex;
    int displayPageNumber;

    string mode;


    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> scoreLabels;
    vector<QLabel*> infoLabels;
    vector<QLabel*> petNameLabels;

    vector<pair<Adopter, int>> matResults;

    vector<pair<Pet, pair<Adopter, int>>> multiMat;


private slots:
    /*!
     * \brief on_searchOne_clicked searches for matches for pet selected
     */
    void on_searchOne_clicked();

    /*!
     * \brief on_previousOne_clicked go back on owner list, one pet
     */
    void on_previousOne_clicked();

    /*!
     * \brief on_nextOne_clicked go forward on owner list, one pet
     */
    void on_nextOne_clicked();

    /*!
     * \brief on_previousAll_clicked go back on owner list, all pets
     */
    void on_previousAll_clicked();

    /*!
     * \brief on_nextAll_clicked go forward on owner list, all pets
     */
    void on_nextAll_clicked();

    /*!
     * \brief on_toAllPets_clicked brings user to all Pets page
     */
    void on_toAllPets_clicked();

    /*!
     * \brief on_toOnePet_clicked brings user to One pet page
     */
    void on_toOnePet_clicked();

    /*!
     * \brief on_petName_returnPressed search for one pet
     */
    void on_petName_returnPressed();





};

#endif // FINDMATCHFORPETS_H
