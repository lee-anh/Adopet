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

/*!
 * \brief The Zip class manages network interaction with zipcode api
 */
class Zip : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Zip constructor
     * \param parent
     */
    explicit Zip(QWidget *parent = nullptr);
    ~Zip();

    /*!
     * \brief zip intiates the api call
     * \param code zipcode
     * \param distance in miles, string
     */
    void zip(string code, string distance);




private:
    Ui::Zip *ui;
    QNetworkAccessManager* manager;
    string results;
    vector<string> zipCodes;

    /*!
     * \brief writeToFile write api response results to file
     */
    void writeToFile();

    /*!
     * \brief parseResults parses the output file
     * \return vector of zipcodes in strings
     */
    vector<string> parseResults();

    QString filename;
signals:
    void finishedCall();


};

#endif // ZIP_H
