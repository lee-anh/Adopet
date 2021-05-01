#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include "../Adopter/preferences.h"

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();
    void displayQuiz();
    void setPreference(Preferences *p);

private slots:
    void on_nextpage_clicked();

    void on_previouspage_clicked();

private:
    Ui::Quiz *ui;
    int currentPageNum;
    Preferences *pref;
};

#endif // QUIZ_H
