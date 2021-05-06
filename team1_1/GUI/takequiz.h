#ifndef TAKEQUIZ_H
#define TAKEQUIZ_H

#include <QDialog>

namespace Ui {
class TakeQuiz;
}

class TakeQuiz : public QDialog
{
    Q_OBJECT

public:
    explicit TakeQuiz(QWidget *parent = nullptr);
    ~TakeQuiz();

private slots:
    void on_No_clicked();

    void on_Yes_clicked();

private:
    Ui::TakeQuiz *ui;
signals:
    void takeQuiz();
};

#endif // TAKEQUIZ_H
