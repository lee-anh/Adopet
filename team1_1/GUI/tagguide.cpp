#include "tagguide.h"
#include "ui_tagguide.h"

/*!
 * \brief TagGuide constructor
 * \param parent
 */
TagGuide::TagGuide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TagGuide)
{
    ui->setupUi(this);
}

/*!
 * \brief TagGuide destructor
 */
TagGuide::~TagGuide()
{
    delete ui;
}
