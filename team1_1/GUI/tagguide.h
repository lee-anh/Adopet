#ifndef TAGGUIDE_H
#define TAGGUIDE_H

#include <QDialog>

namespace Ui {
class TagGuide;
}

/*!
 * \brief The TagGuide class creates a QDialog that displays
 * all the reccomended tags for owners to use when uploading pets
 */
class TagGuide : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief TagGuide constructor
     * \param parent
     */
    explicit TagGuide(QWidget *parent = nullptr);
    /*!
     * \brief TagGuide destructor
     */
    ~TagGuide();

private:
    Ui::TagGuide *ui;
};

#endif // TAGGUIDE_H
