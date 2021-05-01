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
    void saveQuiz();

private slots:
    void on_nextpage_clicked();
    void on_previouspage_clicked();

    void on_finishquiz_clicked();

signals:
    void backToPreference(Preferences p);

private:
    Ui::Quiz *ui;
    int currentPageNum;
    Preferences *pref;
};

#endif // QUIZ_H
