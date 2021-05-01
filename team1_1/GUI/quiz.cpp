#include "quiz.h"
#include "ui_quiz.h"

Quiz::Quiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quiz)
{
    ui->setupUi(this);


    ui->finishquiz->setVisible(false);
    currentPageNum = 0;
    ui->stackedWidget->setCurrentIndex(currentPageNum);
    pref = new Preferences();
}

Quiz::~Quiz()
{
    delete ui;
}



void Quiz::on_nextpage_clicked()
{
    if(currentPageNum==5){
        return;
    }
    currentPageNum++;
    displayQuiz();
}

void Quiz::on_previouspage_clicked()
{
    if(currentPageNum==0){
        emit backToPreference(*pref);
        return;
    }
    currentPageNum--;
    displayQuiz();
}




void Quiz::displayQuiz(){
    ui->stackedWidget->setCurrentIndex(currentPageNum);

    if (currentPageNum==5){
        ui->finishquiz->setVisible(true);
        ui->nextpage->setVisible(false);
        ui->previouspage->setVisible(true);
    }
    else{
        ui->finishquiz->setVisible(false);
        ui->nextpage->setVisible(true);
        ui->previouspage->setVisible(true);
    }
}


void Quiz::on_finishquiz_clicked()
{
    emit backToPreference(*pref);
}
