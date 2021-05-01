#ifndef MYFAVORITESTWO_H
#define MYFAVORITESTWO_H

#include <QWidget>
#include <QtSql>

#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"

namespace Ui {
class MyFavoritesTwo;
}

/*!
 * \brief The MyFavoritesTwo class, displays my favorites in list mode
 */
class MyFavoritesTwo : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief MyFavoritesTwo constructor
     * \param parent
     */
    explicit MyFavoritesTwo(QWidget *parent = nullptr);

    /*!
     * \brief MyFavoritesTwo destructor
     */
    ~MyFavoritesTwo();

    /*!
     * \brief setSavedList
     * \param s
     */
    void setSavedList(SavedList s);

    /*!
     * \brief showGal shows the pet gallery
     */
    void showGal();

private:
    Ui::MyFavoritesTwo *ui;

    SavedList sl;
    PetGallery petgal;

    /*!
     * \brief saveButton, processes saved button actions
     * \param saveButton
     * \param index
     */
    void saveButton(QPushButton *saveButton, int index);

    /*!
     * \brief loadSaveButtons, renders saved buttons
     * \param saveButtons
     */
    void loadSaveButtons(vector<QPushButton*> saveButtons);
private slots:
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
     * \brief on_link5_clicked
     */
    void on_link5_clicked();
    /*!
     * \brief on_link6_clicked
     */
    void on_link6_clicked();
    /*!
     * \brief on_link7_clicked
     */
    void on_link7_clicked();
    /*!
     * \brief on_link8_clicked
     */
    void on_link8_clicked();

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
    /*!
     * \brief on_save5_clicked
     */
    void on_save5_clicked();
    /*!
     * \brief on_save6_clicked
     */
    void on_save6_clicked();

    /*!
     * \brief on_save7_clicked
     */
    void on_save7_clicked();

    /*!
     * \brief on_save8_clicked
     */
    void on_save8_clicked();


    /*!
     * \brief on_viewMode_currentIndexChanged
     * \param index
     */
    void on_viewMode_currentIndexChanged(int index);

signals:

    /*!
     * \brief learnMoreClicked, go to meet me
     * \param sendPet, pet to send
     * \param b, true if the pet is saved, false if unsaved
     */
    void learnMoreClicked(Pet sendPet, bool b);

    /*!
     * \brief heartClicked, send state of heart button
     * \param p, pet to send
     * \param b, true if the pet is saved, false if unsaved
     */
    void heartClicked(Pet p, bool b);

    /*!
     * \brief goToGallery, change to gallery mode
     */
    void goToGallery();


};

#endif // MYFAVORITESTWO_H
