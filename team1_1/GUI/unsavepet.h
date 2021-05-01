#ifndef UNSAVEPET_H
#define UNSAVEPET_H

#include <QDialog>

namespace Ui {
class UnsavePet;
}


/*!
 * \brief The UnsavePet class creates a QDialog that serves as a warning
 * to let users know what results from them unsaving a pet
 */
class UnsavePet : public QDialog
{
    Q_OBJECT

public:

    /*!
     * \brief UnsavePet constructor
     * \param parent
     */
    explicit UnsavePet(QWidget *parent = nullptr);

    /*!
     * \brief UnsavePet destructor
     */
    ~UnsavePet();

private slots:
    /*!
     * \brief on_no_clicked, don't unsave
     */
    void on_no_clicked();

    /*!
     * \brief on_yes_clicked, unsave the pet
     */
    void on_yes_clicked();

private:
    Ui::UnsavePet *ui;

signals:
    /*!
     * \brief unsavePet, signal to emit
     */
    void unsavePet();
};

#endif // UNSAVEPET_H
