#ifndef PETADOPTED_H
#define PETADOPTED_H

#include <QDialog>

namespace Ui {
class PetAdopted;
}

/*!
 * \brief The PetAdopted class creates a QDialog for owners to mark their
 * pets as adopted
 */
class PetAdopted : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief PetAdopted constructor
     * \param parent
     */
    explicit PetAdopted(QWidget *parent = nullptr);

    /*!
     * \brief PetAdopted destructor
     */
    ~PetAdopted();

private slots:
    /*!
     * \brief on_yes_clicked, yes remove the pet
     */
    void on_yes_clicked();

    /*!
     * \brief on_no_clicked, don't remove the pet
     */
    void on_no_clicked();

signals:
    /*!
    * \brief yesAdopted, indicate that the current pet should be removed
    */
   void yesAdopted();

private:
    Ui::PetAdopted *ui;
};

#endif // PETADOPTED_H
