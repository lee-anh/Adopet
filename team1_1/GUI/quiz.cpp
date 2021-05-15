#include "quiz.h"
#include "ui_quiz.h"

/*!
 * \brief Quiz Constructor
 * \param parent
 */
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

/*!
 * \brief startQuiz gui setup for quiz elements,
 * sets up pictures, database elements
 */
void Quiz::startQuiz(){
    ui->finishquiz->setVisible(false);
    ui->previouspage->setVisible(false);
    ui->nextpage->setVisible(true);


    //CURRENTLY OMITTING DIRECT BREED QUESTIONS

    ui->dogs->setVisible(false);
    ui->cats->setVisible(false);
    ui->rabbits->setVisible(false);
    ui->rodents->setVisible(false);
    ui->fish->setVisible(false);
    ui->birds->setVisible(false);

    dog = ui->stackedWidget->widget(5);
    cat = ui->stackedWidget->widget(6);
    rabbit = ui->stackedWidget->widget(7);
    rodent = ui->stackedWidget->widget(8);
    fish = ui->stackedWidget->widget(10);
    bird = ui->stackedWidget->widget(9);

    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(1));
    currentPageNum = 0;
    lastPage = 3;
    ui->stackedWidget->setCurrentIndex(currentPageNum);


    //pictures
    QString os = QSysInfo::productVersion();

    QString path;
    if(os == "10.16"){
       path = "../../../../../pictures/";
    } else {
        path = "../../pictures/";

    }
    QPixmap dogPix(path + "dog1.jpeg");
    ui->dogPic->setPixmap(dogPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap catPix(path + "cat1.jpeg");
    ui->catPic->setPixmap(catPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap rabbitPix(path + "rabbit1.jpeg");
    ui->rabbitPic->setPixmap(rabbitPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap rodentPix(path + "rodent1.jpeg");
    ui->rodentPic->setPixmap(rodentPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap fishPix(path + "fish1.jpeg");
    ui->fishPic->setPixmap(fishPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap birdPix(path + "bird1.jpeg");
    ui->birdsPic->setPixmap(birdPix.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap angora(path + "angora.jpeg");
    ui->angoraPic->setPixmap(angora.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap sf(path + "silverFox.jpeg");
    ui->silverFoxPic->setPixmap(sf.scaled(100, 100, Qt::KeepAspectRatio));

}

/*!
 * \brief displayQuiz manages the buttons for quiz navigation
 * determines which should be displayed and which should be hidden
 */
void Quiz::displayQuiz(){
    ui->stackedWidget->setCurrentIndex(currentPageNum);

    if (currentPageNum == lastPage){ //last page
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

/*!
 * \brief breedsCheckbox handles state changes for breed checkboxes
 * \param s the breed name
 * \param arg1 0 = unchecked, 2 = checked
 */
void Quiz::breedsCheckbox(string s, int arg1){
    if(arg1 == 2){
        pref->removeBreed(s);
        pref->addBreed(s);
    } else if(arg1 == 0){
        pref->removeBreed(s);
    }
}
/*!
 * \brief breedRadio handles state changes for radio buttons
 * \param s breed
 * \param b
 */
void Quiz::breedRadio(string s, bool b){
    if(b == true){
        pref->removeBreed(s);
        pref->addBreed(s);
    } else {
        pref->removeBreed(s);
    }
}

/*!
 * \brief on_nextpage_clicked advance the quiz
 */
void Quiz::on_nextpage_clicked()
{
    if(currentPageNum==lastPage){
        return;
    }
    if(currentPageNum == 1){
        ui->previouspage->setVisible(true);
    }
    currentPageNum++;
    displayQuiz();
}

/*!
 * \brief on_previouspage_clicked go back on the quiz
 */
void Quiz::on_previouspage_clicked()
{
    if(currentPageNum==0){
        emit backToPreference(*pref); // should never get here, but just in case
        return;
    }
    currentPageNum--;
    displayQuiz();
}





/*!
 * \brief speciesCheckbox handels state changes of all the species checkboxes,
 * determines which additional pages to add.
 * \param s the species name
 * \param arg1 0 = unchecked, 2 = checked
 */
void Quiz::speciesCheckbox(string s, int arg1){
    // 0 unchecked
    // 1 partially checked
    // 2 checked
    int page = 0;



    if(arg1 == 2){
        pref->removeSpecies(s);
        pref->addSpecies(s);

        if(s == "dog"){
            ui->dogs->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, dog);
            lastPage++;
        } else if (s == "cat"){
            ui->cats->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, cat);
            lastPage++;
        } else if (s == "rabbit"){
            ui->rabbits->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, rabbit);
            lastPage++;
        } else if (s == "rodent"){
            ui->rodents->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, rodent);
            lastPage++;
        } else if (s == "fish"){
            ui->fish->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, fish);
            lastPage++;
        } else if (s == "bird"){
            ui->birds->setVisible(true);
            page++;
            ui->stackedWidget->insertWidget(page, bird);
            lastPage++;
        }
    } else if (arg1 == 0){
        pref->removeSpecies(s);
        if(s == "dog"){
            ui->dogs->setVisible(false);
            page--;
            ui->stackedWidget->removeWidget(dog);
            lastPage--;
        } else if (s == "cat"){
            ui->cats->setVisible(false);

            page--;
            ui->stackedWidget->removeWidget(cat);
            lastPage--;

        } else if (s == "rabbit"){
            ui->rabbits->setVisible(false);

            page--;
            ui->stackedWidget->removeWidget(rabbit);
            lastPage--;

        } else if (s == "rodent"){
            ui->rodents->setVisible(false);

            page--;
            ui->stackedWidget->removeWidget(rodent);
            lastPage--;

        } else if (s == "fish"){
            ui->fish->setVisible(false);

            page--;
            ui->stackedWidget->removeWidget(fish);
            lastPage--;

        } else if (s == "bird"){
            ui->birds->setVisible(false);

            page--;
            ui->stackedWidget->removeWidget(bird);
            lastPage--;
        }
    }
}


void Quiz::on_finishquiz_clicked()
{
    currentPageNum=0;
    emit backToPreference(*pref);
}




void Quiz::on_activeYes_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("active");
        pref->addTemperament("active");
    }
}


void Quiz::on_activeNo_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("active");
    }
}

void Quiz::on_friendly_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("friendly");
        pref->removeTemperament("introverted");
        pref->addTemperament("friendly");
    }
}

void Quiz::on_friendlyORIntroverted_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("friendly");
        pref->removeTemperament("introverted");
        pref->addTemperament("friendly");
        pref->addTemperament("introverted");
    }
}

void Quiz::on_introverted_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("friendly");
        pref->removeTemperament("introverted");
        pref->addTemperament("introverted");
    }
}

void Quiz::on_happy_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("happy");
        pref->removeTemperament("vigilant");
        pref->addTemperament("happy");
    }
}



void Quiz::on_vigilant_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("happy");
        pref->removeTemperament("vigilant");
        pref->addTemperament("vigilant");
    }
}



void Quiz::on_happyOrVigilant_toggled(bool checked)
{
    if(checked){
        pref->removeTemperament("happy");
        pref->removeTemperament("vigilant");
        pref->addTemperament("vigilant");
        pref->addTemperament("happy");
    }
}

void Quiz::on_young_toggled(bool checked)
{
    if(checked){
        pref->removeAge("young");
        pref->removeAge("adult");
        pref->removeAge("senior");
        pref->addAge("young");
    }
}

void Quiz::on_adult_toggled(bool checked)
{
    if(checked){
        pref->removeAge("young");
        pref->removeAge("adult");
        pref->removeAge("senior");
        pref->addAge("adult");
    }
}

void Quiz::on_old_toggled(bool checked)
{
    if(checked){
        pref->removeAge("young");
        pref->removeAge("adult");
        pref->removeAge("senior");
        pref->addAge("senior");
    }
}

void Quiz::on_noage_toggled(bool checked)
{
    if(checked){
        pref->removeAge("young");
        pref->removeAge("adult");
        pref->removeAge("senior");
        pref->addAge("young");
        pref->addAge("adult");
        pref->addAge("senior");
    }
}

void Quiz::on_male_toggled(bool checked)
{
    if(checked){
        pref->removeGender("male");
        pref->removeGender("female");
        pref->addGender("male");
    }
}

void Quiz::on_female_toggled(bool checked)
{
    if(checked){
        pref->removeGender("male");
        pref->removeGender("female");
        pref->addGender("female");
    }
}

void Quiz::on_maleOrFemale_toggled(bool checked)
{
    if(checked){
        pref->removeGender("male");
        pref->removeGender("female");
        pref->addGender("male");
        pref->addGender("female");
    }
}

void Quiz::on_bestFriends_toggled(bool checked)
{
    if(checked){
        pref->removeShelter("best friends");
        pref->removeShelter("animal welfare league");
        pref->removeShelter("humane society");
        pref->addShelter("best friends");
    }
}

void Quiz::on_humaneSociety_toggled(bool checked)
{
    if(checked){
        pref->removeShelter("best friends");
        pref->removeShelter("animal welfare league");
        pref->removeShelter("humane society");
        pref->addShelter("humane society");
    }
}

void Quiz::on_animalWelfareLeague_toggled(bool checked)
{
    if(checked){
        pref->removeShelter("best friends");
        pref->removeShelter("animal welfare league");
        pref->removeShelter("humane society");
        pref->addShelter("animal welfare league");
    }
}

void Quiz::on_anyShelter_toggled(bool checked)
{
    if(checked){
        pref->removeShelter("best friends");
        pref->removeShelter("animal welfare league");
        pref->removeShelter("humane society");
        pref->addShelter("animal welfare league");
        pref->addShelter("best friends");
        pref->addShelter("humane society");
    }
}

void Quiz::on_animalsYes_toggled(bool checked)
{
    if(checked){
        pref->removeGoodWith("animals");
        pref->addGoodWith("animals");
    }
}

void Quiz::on_animalsNo_toggled(bool checked)
{
    if(checked){
        pref->removeGoodWith("animals");
    }
}

void Quiz::on_childrenYes_toggled(bool checked)
{
    if(checked){
        pref->removeGoodWith("kids");
        pref->addGoodWith("kids");
    }
}

void Quiz::on_childrenNo_toggled(bool checked)
{
    if(checked){
        pref->removeGoodWith("kids");
    }
}




void Quiz::on_dogCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("dog", arg1);
}

void Quiz::on_catCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("cat", arg1);
}

void Quiz::on_rabbitCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("rabbit", arg1);
}

void Quiz::on_rodentCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("rodent", arg1);
}
void Quiz::on_birdCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("bird", arg1);
}

void Quiz::on_fishCheckBox_stateChanged(int arg1)
{
    speciesCheckbox("fish", arg1);
}


void Quiz::on_sporting_stateChanged(int arg1){
    breedsCheckbox("sporting", arg1);
}
void Quiz::on_hound_stateChanged(int arg1){
    breedsCheckbox("hound", arg1);
}
void Quiz::on_working_stateChanged(int arg1){
    breedsCheckbox("working", arg1);
}
void Quiz::on_terrier_stateChanged(int arg1){
    breedsCheckbox("terrier", arg1);
}
void Quiz::on_toy_stateChanged(int arg1){
    breedsCheckbox("toy", arg1);
}
void Quiz::on_nonsporting_stateChanged(int arg1){
    breedsCheckbox("non-sporting", arg1);
}
void Quiz::on_herding_stateChanged(int arg1){
    breedsCheckbox("herding", arg1);
}
void Quiz::on_siamese_stateChanged(int arg1){
    breedsCheckbox("siamese", arg1);
}
void Quiz::on_persian_stateChanged(int arg1){
    breedsCheckbox("persian", arg1);
}
void Quiz::on_maineCoon_stateChanged(int arg1){
    breedsCheckbox("maine coon", arg1);
}
void Quiz::on_ragdoll_stateChanged(int arg1){
    breedsCheckbox("ragdoll", arg1);
}
void Quiz::on_rex_stateChanged(int arg1){
    breedsCheckbox("rex", arg1);
}
void Quiz::on_lionhead_stateChanged(int arg1){
    breedsCheckbox("lionhead", arg1);
}
void Quiz::on_californian_stateChanged(int arg1){
    breedsCheckbox("californian", arg1);
}
void Quiz::on_angora_stateChanged(int arg1){
    breedsCheckbox("angora", arg1);
}
void Quiz::on_silverFox_stateChanged(int arg1){
    breedsCheckbox("silverFox", arg1);
}
void Quiz::on_hamster_stateChanged(int arg1){
    breedsCheckbox("hamster", arg1);
}
void Quiz::on_guineaPig_stateChanged(int arg1){
    breedsCheckbox("guinea pig", arg1);
}
void Quiz::on_gerbil_stateChanged(int arg1){
    breedsCheckbox("gerbil", arg1);
}
void Quiz::on_mouse_stateChanged(int arg1){
    breedsCheckbox("mouse", arg1);
}
void Quiz::on_rat_stateChanged(int arg1){
    breedsCheckbox("rat",arg1);
}
void Quiz::on_freshwater_stateChanged(int arg1){
    breedsCheckbox("freshwater",arg1);
}
void Quiz::on_saltwater_stateChanged(int arg1){
    breedsCheckbox("saltwater", arg1);
}
void Quiz::on_parakeet_stateChanged(int arg1){
    breedsCheckbox("parakeet", arg1);
}
void Quiz::on_lovebird_stateChanged(int arg1){
    breedsCheckbox("lovebird", arg1);
}
void Quiz::on_parrot_stateChanged(int arg1){
    breedsCheckbox("parrot", arg1);
}


void Quiz::on_toyDog_toggled(bool checked)
{
    breedRadio("toy", checked);
}

void Quiz::on_workingDog_toggled(bool checked)
{
    breedRadio("working", checked);
}

void Quiz::on_nonsportingDog_toggled(bool checked)
{
    breedRadio("non-sporting", checked);
}

void Quiz::on_terrierDog_toggled(bool checked)
{
    breedRadio("terrier", checked);
}

void Quiz::on_houndDog_toggled(bool checked)
{
    breedRadio("hound", checked);
}

void Quiz::on_sportingDog_toggled(bool checked)
{
    breedRadio("sporting", checked);
}

void Quiz::on_herdingDogs_toggled(bool checked)
{
    breedRadio("herding", checked);
}

void Quiz::on_lionHeadCaliRabbit_toggled(bool checked)
{
    breedRadio("lionhead", checked);
    breedRadio("californian", checked);
}

void Quiz::on_angoraRabbit_toggled(bool checked)
{
    breedRadio("angora", checked);
}

void Quiz::on_silverFoxRabbit_toggled(bool checked)
{
    breedRadio("silver fox", checked);
}

void Quiz::on_mouseRodent_toggled(bool checked)
{
    breedRadio("mouse", checked);
}

void Quiz::on_ratRodent_toggled(bool checked)
{
    breedRadio("rat", checked);
}

void Quiz::on_guineaPigRodent_toggled(bool checked)
{
    breedRadio("guinea pig", checked);
}

void Quiz::on_hamsterRodent_toggled(bool checked)
{
    breedRadio("hamster", checked);
}

void Quiz::on_gerbilRodent_toggled(bool checked)
{
    breedRadio("gerbil", checked);
}

void Quiz::on_parakeetBird_toggled(bool checked)
{
    breedRadio("parakeet", checked);
}

void Quiz::on_lovebirdBird_toggled(bool checked)
{
    breedRadio("lovebird", checked);
}

void Quiz::on_parrotBird_toggled(bool checked)
{
    breedRadio("parrot", checked);
}

void Quiz::on_saltwaterFish_toggled(bool checked)
{
    breedRadio("saltwater", checked);
}

void Quiz::on_freshwaterFish_toggled(bool checked)
{
    breedRadio("freshwater", checked);
}
