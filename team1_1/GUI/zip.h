#ifndef ZIP_H
#define ZIP_H

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <string>
#include <iostream>
#include <fstream>

//just including this to get a good namespace
#include "../Owner/owner.h"

namespace Ui {
class Zip;
}

class Zip : public QWidget
{
    Q_OBJECT

public:
    explicit Zip(QWidget *parent = nullptr);
    ~Zip();
    void zip(string code, string distance);
    vector<string> getZipCodes();



private:
    Ui::Zip *ui;
    QNetworkAccessManager* manager;
    string results;
    vector<string> zipCodes;

    void writeToFile();

    vector<string> parseResults();

    QString filename;


};

#endif // ZIP_H
