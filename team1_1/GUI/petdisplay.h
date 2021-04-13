#ifndef PETDISPLAY_H
#define PETDISPLAY_H

#include <QWidget>

namespace Ui {
class PetDisplay;
}

class PetDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit PetDisplay(QWidget *parent = nullptr);
    ~PetDisplay();

private slots:
    void on_more1_clicked();

private:
    Ui::PetDisplay *ui;
};

#endif // PETDISPLAY_H
