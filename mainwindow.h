#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "car.h"
#include "client.h"
#include "clientview.h"
#include "carview.h"
#include "rent.h"
#include "rentview.h"
#include "blacklistview.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QLocale>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addCarButton_clicked();

    void on_editCarButton_clicked();

    void on_deleteCarButton_clicked();

    void on_addClientButton_clicked();

    void on_editClientButton_clicked();

    void on_deleteClientButton_clicked();

    void on_rentOutCarButton_clicked();

    void on_editRentButton_clicked();

    void on_returnFromRentalButton_clicked();

    void on_addBlacklistButton_clicked();

    void on_deleteFromBlacklistButton_clicked();

public slots:
    void update();

private:
    Ui::MainWindow *ui;

    CarView *carView;
    ClientView *clientView;
    RentView *rentView;
    BlacklistView *blacklistView;

signals:
    void notifyObservers();
};

#endif // MAINWINDOW_H
