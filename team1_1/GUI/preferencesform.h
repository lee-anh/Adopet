#ifndef PREFERENCESFORM_H
#define PREFERENCESFORM_H

#include <QWidget>

namespace Ui {
class PreferencesForm;
}

class PreferencesForm : public QWidget
{
    Q_OBJECT

public:
    explicit PreferencesForm(QWidget *parent = nullptr);
    ~PreferencesForm();

private:
    Ui::PreferencesForm *ui;
};

#endif // PREFERENCESFORM_H
