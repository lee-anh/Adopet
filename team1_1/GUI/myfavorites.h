#ifndef MYFAVORITES_H
#define MYFAVORITES_H

#include <QWidget>
#include <QtSql>

#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"

namespace Ui {
class MyFavorites;
}

/*!
 * \brief The MyFavorites class, gallery mode for MyFavorites
 */
class MyFavorites : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief MyFavorites constructor
     * \param parent
     */
    explicit MyFavorites(QWidget *parent = nullptr);

    /*!
     * \brief MyFavorites destructor
     */
    ~MyFavorites();

    /*!
     * \brief setSavedList
     * \param s
     */
    void setSavedList(SavedList s);

    /*!
     * \brief showGal shows pet gallery
     */
    void showGal();

private:
    Ui::MyFavorites *ui;
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
     * \brief on_viewModeComboBox_currentIndexChanged
     * \param index
     */
    void on_viewModeComboBox_currentIndexChanged(int index);

signals:

    /*!
     * \brief learnMoreClicked, go to meet pet
     * \param sendPet
     * \param b
     */
    void learnMoreClicked(Pet sendPet, bool b);

    /*!
     * \brief heartClicked, indicate if pet is saved
     * \param p
     * \param b
     */
    void heartClicked(Pet p, bool b);

    /*!
     * \brief toListMode, changes view modes
     */
    void toListMode();



};

#endif // MYFAVORITES_H
