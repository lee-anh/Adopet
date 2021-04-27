#ifndef FINDMATCHFORPETS_H
#define FINDMATCHFORPETS_H

#include <QWidget>
#include <QLabel>
#include <vector>

#include "../Matchmaking/matchmaking.h"





namespace Ui {
class FindMatchForPets;
}

class FindMatchForPets : public QWidget
{
    Q_OBJECT

public:
    explicit FindMatchForPets(QWidget *parent = nullptr);
    ~FindMatchForPets();

private:
    Ui::FindMatchForPets *ui;





};

#endif // FINDMATCHFORPETS_H
