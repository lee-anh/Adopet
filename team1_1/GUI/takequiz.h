#ifndef TAKEQUIZ_H
#define TAKEQUIZ_H

#include <QDialog>

namespace Ui {
class TakeQuiz;
}

/*!
 * \brief The TakeQuiz class QDialog class making sure users want
 * to take the quiz and reset their preferences
 */
class TakeQuiz : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief TakeQuiz Constructor
     * \param parent
     */
    explicit TakeQuiz(QWidget *parent = nullptr);
    ~TakeQuiz();

private slots:
    /*!
     * \brief on_No_clicked close dialog, do nothing
     */
    void on_No_clicked();

    /*!
     * \brief on_Yes_clicked close dialog, bring users to quiz
     */
    void on_Yes_clicked();

private:
    Ui::TakeQuiz *ui;
signals:
    void takeQuiz();
};

#endif // TAKEQUIZ_H
