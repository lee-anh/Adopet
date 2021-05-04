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
    void startQuiz();

private slots:
    void on_nextpage_clicked();
    void on_previouspage_clicked();

    void on_finishquiz_clicked();



    void on_yesspace_toggled(bool checked);

    void on_nospace_toggled(bool checked);

    void on_yesperspace_toggled(bool checked);

    void on_old_toggled(bool checked);

    void on_young_toggled(bool checked);

    void on_mature_toggled(bool checked);

    void on_noage_toggled(bool checked);

    void on_yeschild_toggled(bool checked);

    void on_yespet_toggled(bool checked);

    void on_smallfam_toggled(bool checked);

    void on_bigfam_toggled(bool checked);

    void on_medfam_toggled(bool checked);

    void on_onlyme_toggled(bool checked);

signals:
    void backToPreference(Preferences p);

private:
    Ui::Quiz *ui;
    int currentPageNum;
    Preferences *pref;
};

#endif // QUIZ_H
