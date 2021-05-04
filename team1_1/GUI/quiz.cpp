#include "quiz.h"
#include "ui_quiz.h"

Quiz::Quiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quiz)
{
    ui->setupUi(this);
    ui->finishquiz->setVisible(false);
    pref = new Preferences();
}

Quiz::~Quiz()
{
    delete ui;
}

void Quiz::startQuiz(){
    ui->finishquiz->setVisible(false);
    currentPageNum = 0;
    ui->stackedWidget->setCurrentIndex(currentPageNum);
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
    currentPageNum=0;
    emit backToPreference(*pref);
}

void Quiz::on_yesspace_toggled(bool checked)
{
    if(checked){
        pref->removeSpecies("dog");
        pref->removeSpecies("hamster");
        pref->addSpecies("rabbit");
    }
    else{
        pref->removeSpecies("rabbit");
    }
}

void Quiz::on_nospace_toggled(bool checked)
{
    if(checked){
        pref->removeSpecies("dog");
        pref->removeSpecies("rabbit");
        pref->addSpecies("hamster");
    }
    else{
        pref->removeSpecies("hamster");
    }
}

void Quiz::on_yesperspace_toggled(bool checked)
{
    if(checked){
        pref->removeSpecies("hamster");
        pref->removeSpecies("rabbit");
        pref->addSpecies("dog");
    }
    else{
        pref->removeSpecies("dog");
    }
}

void Quiz::on_old_toggled(bool checked)
{
    if(checked){
        pref->removeAge("young");
        pref->removeAge("mature");
        pref->addAge("old");
    }
    else{
        pref->removeAge("old");
    }
}

void Quiz::on_young_toggled(bool checked)
{
    if(checked){
        pref->removeAge("old");
        pref->removeAge("mature");
        pref->addAge("young");
    }
    else{
        pref->removeAge("young");
    }
}

void Quiz::on_mature_toggled(bool checked)
{
    if(checked){
        pref->removeAge("old");
        pref->removeAge("young");
        pref->addAge("mature");
    }
    else{
        pref->removeAge("mature");
    }
}



void Quiz::on_noage_toggled(bool checked)
{
    if(checked){
        pref->removeAge("old");
        pref->removeAge("young");
        pref->removeAge("mature");
    }
}

void Quiz::on_yeschild_toggled(bool checked)
{
    if(checked){
        pref->addGoodWith("kids");
    }
    else{
        pref->removeGoodWith("kids");
    }
}


void Quiz::on_yespet_toggled(bool checked)
{
    if(checked){
        pref->addGoodWith("animals");
    }
    else{
        pref->removeGoodWith("animals");
    }
}

void Quiz::on_smallfam_toggled(bool checked)
{
    if(checked){
        pref->addTemperament("happy");
        pref->addTemperament("vigilant");
    }
    else{
        pref->removeTemperament("happy");
        pref->removeTemperament("vigilant");
    }
}

void Quiz::on_bigfam_toggled(bool checked)
{
    if(checked){
        pref->addTemperament("friendly");
        pref->addTemperament("active");
    }
    else{
        pref->removeTemperament("friendly");
        pref->removeTemperament("active");
    }
}

void Quiz::on_medfam_toggled(bool checked)
{
    if(checked){
        pref->addTemperament("happy");
        pref->addTemperament("active");
    }
    else{
        pref->removeTemperament("happy");
        pref->removeTemperament("active");
    }
}



void Quiz::on_onlyme_toggled(bool checked)
{
    if(checked){
        pref->addTemperament("introverted");
        pref->addTemperament("vigilant");
    }
    else{
        pref->removeTemperament("introverted");
        pref->removeTemperament("vigilant");
    }
}
