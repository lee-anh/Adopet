#ifndef FINDMATCHFORADOPTERS_H
#define FINDMATCHFORADOPTERS_H

#include <QWidget>
#include "../Pets/pet.h"
#include "../Matchmaking/matchmaking.h"
#include "petgallery.h"

namespace Ui {
class FindMatchForAdopters;
}

class FindMatchForAdopters : public QWidget
{
    Q_OBJECT

public:
    explicit FindMatchForAdopters(QWidget *parent = nullptr);
    ~FindMatchForAdopters();

private:
    Ui::FindMatchForAdopters *ui;
    Matchmaking mat;

private slots:


};

#endif // FINDMATCHFORADOPTERS_H
