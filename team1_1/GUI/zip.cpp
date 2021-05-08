#include "zip.h"
#include "ui_zip.h"

Zip::Zip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zip)
{
    ui->setupUi(this);


    manager = new QNetworkAccessManager();
    QString os = QSysInfo::productVersion();

    if(os == "10.16"){
        filename = "../../../../../csvs/zip.txt";

    } else {
        //default picture
        filename = "../../csvs/zip.txt";

    }

    connect(manager, &QNetworkAccessManager::finished, this, [&](QNetworkReply *reply){

        QByteArray data = reply->readAll();
        QString str = QString::fromLatin1(data);

        ui->result->setText(str);
        results = str.toStdString();

        //cout << results << endl;

        string fname = filename.toStdString();

        ofstream csv;

        //all relavent methods have to be called here
        //now the problem is how to get this information to a different class
        //ideas: using the file to pass information back and forth, emit a signal
        writeToFile();
        parseResults();




    });


}

Zip::~Zip()
{
    delete ui;
}


void Zip::zip(string code, string distance){


    //API keys (for when we exceed the number of free requests)
    //
    //"Pet Finder" XXuDakVCPsq0RGZ64Jq4SFodgwq4Wr3nEGLST7tMxOyS2Q2KShkmykJfbkVd3Zbm
    manager->get((QNetworkRequest(QUrl("https://www.zipcodeapi.com/rest/XXuDakVCPsq0RGZ64Jq4SFodgwq4Wr3nEGLST7tMxOyS2Q2KShkmykJfbkVd3Zbm/radius.csv/" +
                                       QString::fromStdString(code) + "/" + QString::fromStdString(distance) + "/mile"))));

}
vector<string> Zip::getZipCodes(){

    cout << "Zipcode vector size: " << zipCodes.size() << endl;
    for(int i = 0; i < (int) zipCodes.size(); i++){
        cerr << "from getter" << zipCodes.at(i) << endl;
    }

    return zipCodes;
}

void Zip::writeToFile(){
    string fname = filename.toStdString();

    ofstream csv;
    //clear the old file's contents
    csv.open(fname, ofstream::out | ofstream::trunc);
    csv.close();

    csv.open(fname, ios_base::app);
    csv << results;
    csv.close();

}

vector<string> Zip::parseResults(){

    vector<string> zips;


    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        cerr << "Error: file not opened" << endl;
    }
    QTextStream in(&file);

    int lineNumber = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList zipOutput = line.split(",");
        if(lineNumber != 0){
            string zip = zipOutput.at(0).toStdString();
            zips.push_back(zip);
        }
        lineNumber++;

    }

    file.close();
    zipCodes = zips;
    for(int i = 0; i < (int) zips.size(); i++){
        cout << "From zips" << zips.at(i) << endl;
    }

    for(int i = 0; i < (int) zipCodes.size(); i++){
        //cout << "From zipCodes" << zipCodes.at(i) << endl;
    }


    return zips;

}

