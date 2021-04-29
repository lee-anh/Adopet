#ifndef TAGGUIDE_H
#define TAGGUIDE_H

#include <QDialog>

namespace Ui {
class TagGuide;
}

class TagGuide : public QDialog
{
    Q_OBJECT

public:
    explicit TagGuide(QWidget *parent = nullptr);
    ~TagGuide();

private:
    Ui::TagGuide *ui;
};

#endif // TAGGUIDE_H
