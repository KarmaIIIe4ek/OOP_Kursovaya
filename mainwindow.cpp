#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <Qt>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    carView(new CarView(this)),
    clientView(new ClientView(this)),
    rentView(new RentView(this))
{
    ui->setupUi(this);
    ui->carTableView->setModel(carView);
    ui->clientTableView->setModel(clientView);
    ui->rentalsTableView->setModel(rentView);
    connect(this, SIGNAL(notifyObservers()), this, SLOT(update()));
    setWindowState(Qt::WindowMaximized);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    ui->lineEdit->setText(QString::number(rentView->rents.length()));
}

void MainWindow::on_addCarButton_clicked()
{
    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit numberEdit;
    QLineEdit brandEdit;
    QLineEdit colorEdit;
    QCheckBox availabilityCheck;

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("Номер авто:", &numberEdit);
    formLayout.addRow("Марка авто:", &brandEdit);
    formLayout.addRow("Цвет авто:", &colorEdit);
    formLayout.addRow("Наличие:", &availabilityCheck);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        int id = idEdit.text().toInt();
        QString number = numberEdit.text();
        QString brand = brandEdit.text();
        QString color = colorEdit.text();
        bool availability = availabilityCheck.isChecked();
        Car *car = new Car(id, number, brand, color, availability);
        Car *carWasCreated = carView->findCarById(car->getId());
        if (carWasCreated != nullptr) {
            QMessageBox::warning(this, "Ошибка", "Автомобиль с таким ID уже существует.");
            return;
        }
        carView->addCar(car);
    }

}

void MainWindow::on_editCarButton_clicked()
{
    QModelIndex index = ui->carTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбран автомобиль для редактирования.");
        return;
    }

    Car *car = carView->cars.at(index.row());

    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit numberEdit;
    QLineEdit brandEdit;
    QLineEdit colorEdit;
    QCheckBox availabilityCheck;

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("Номер авто:", &numberEdit);
    formLayout.addRow("Марка авто:", &brandEdit);
    formLayout.addRow("Цвет авто:", &colorEdit);
    formLayout.addRow("Наличие:", &availabilityCheck);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        Car *carWasCreated = carView->findCarById(idEdit.text().toInt());
        if (carWasCreated != nullptr && car->getId() != idEdit.text().toInt()) {
            QMessageBox::warning(this, "Ошибка", "Автомобиль с таким ID уже существует.");
            return;
        }
        car->setId(idEdit.text().toInt());
        car->setNumber(numberEdit.text());
        car->setBrand(brandEdit.text());
        car->setColor(colorEdit.text());
        car->setAvailability(availabilityCheck.isChecked());
    }
}

void MainWindow::on_deleteCarButton_clicked()
{
    QModelIndex index = ui->carTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбран автомобиль для удаления.");
        return;
    }
    bool temp = carView->removeCar(index.row(), rentView->rents);
    if (!temp){
        QMessageBox::warning(this, "Ошибка", "Нельзя удалить автомобиль, который находится в активной аренде.");
    }
}

void MainWindow::on_addClientButton_clicked()
{
    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit lastNameEdit;
    QLineEdit firstNameEdit;
    QLineEdit numberCLEdit;
    QLineEdit phoneEdit;

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("Фамилия:", &lastNameEdit);
    formLayout.addRow("Имя:", &firstNameEdit);
    formLayout.addRow("Номер ВУ:", &numberCLEdit);
    formLayout.addRow("Телефон:", &phoneEdit);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        int id = idEdit.text().toInt();
        QString lastName = lastNameEdit.text();
        QString firstName = firstNameEdit.text();
        QString numberCL = numberCLEdit.text();
        QString phone = phoneEdit.text();
        Client *client = new Client(id, lastName, firstName, numberCL, phone);
        Client *clientWasCreated = clientView->findClientById(client->getId());
        if (clientWasCreated != nullptr) {
            QMessageBox::warning(this, "Ошибка", "Клиент с таким ID уже существует.");
            return;
        }
        clientView->addClient(client);
    }
}

void MainWindow::on_editClientButton_clicked()
{
    QModelIndex index = ui->clientTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбран клиент для редактирования.");
        return;
    }

    Client *client = clientView->clients.at(index.row());

    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit lastNameEdit;
    QLineEdit firstNameEdit;
    QLineEdit numberCLEdit;
    QLineEdit phoneEdit;

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("Фамилия:", &lastNameEdit);
    formLayout.addRow("Имя:", &firstNameEdit);
    formLayout.addRow("Номер ВУ:", &numberCLEdit);
    formLayout.addRow("Телефон:", &phoneEdit);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        Client *clientWasCreated = clientView->findClientById(idEdit.text().toInt());
        if (clientWasCreated != nullptr && client->getId() != idEdit.text().toInt()) {
            QMessageBox::warning(this, "Ошибка", "Клиент с таким ID уже существует.");
            return;
        }
        client->setId(idEdit.text().toInt());
        client->setLastName(lastNameEdit.text());
        client->setFirstName(firstNameEdit.text());
        client->setNumberCL(numberCLEdit.text());
        client->setPhone(phoneEdit.text());
    }
}

void MainWindow::on_deleteClientButton_clicked()
{
    QModelIndex index = ui->clientTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбран клиент для удаления.");
        return;
    }

    bool temp = clientView->removeClient(index.row(), rentView->rents);
    if (!temp){
        QMessageBox::warning(this, "Ошибка", "Нельзя удалить клиента, так как у него есть активная аренда.");
    }
    qDebug() << clientView->clients.length()<< Qt::endl;
}

void MainWindow::on_rentOutCarButton_clicked()
{
    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit clientIdEdit;
    QLineEdit carIdEdit;
    QDateEdit startDateEdit;
    QDateEdit endDateEdit;
    startDateEdit.setDate(QDate::currentDate());
    endDateEdit.setDate(QDate::currentDate().addDays(1));

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("ID клиента:   ", &clientIdEdit);
    formLayout.addRow("ID авто:      ", &carIdEdit);
    formLayout.addRow("Начало аренды:", &startDateEdit);
    formLayout.addRow("Конец аренды: ", &endDateEdit);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        int id = idEdit.text().toInt();
        int clientId = clientIdEdit.text().toInt();
        int carId = carIdEdit.text().toInt();
        QDate startDate = startDateEdit.date();
        QDate endDate = endDateEdit.date();
        Rent *rent = new Rent(id, clientId, carId, startDate, endDate);
        Client *clientWasCreated = clientView->findClientById(clientId);
        if (clientWasCreated == nullptr) {
            QMessageBox::warning(this, "Ошибка", "Клиент с таким ID не существует.");
            return;
        }
        Car *carWasCreated = carView->findCarById(carId);
        if (carWasCreated == nullptr) {
            QMessageBox::warning(this, "Ошибка", "Автомобиль с таким ID не существует.");
            return;
        }
        Rent *rentWasCreated = rentView->findRentById(id);
        if (rentWasCreated != nullptr) {
            QMessageBox::warning(this, "Ошибка", "Аренда с таким ID уже существует.");
            return;
        }
        if (startDate >= endDate) {
            QMessageBox::warning(this, "Ошибка", "Дата окончания аренды не может быть раньше даты начала");
            return;
        }
        Car* i = carView->cars.at(carView->changeAvailability(carId));
        if (!(i->getAvailability())) {
            QMessageBox::warning(this, "Ошибка", "Автомобиль недоступен");
            return;
        }
        rentView->addRent(rent);
        i->setAvailability(!i->getAvailability());

    }
    emit notifyObservers();
}

void MainWindow::on_editRentButton_clicked()
{
    QModelIndex index = ui->rentalsTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбрана запись для редактирования.");
        return;
    }

    Rent *rent = rentView->rents.at(index.row());
    QDialog dialog;
    QFormLayout formLayout(&dialog);

    QLineEdit idEdit;
    QLineEdit clientIdEdit;
    QLineEdit carIdEdit;
    QDateEdit startDateEdit;
    QDateEdit endDateEdit;
    startDateEdit.setDate(QDate::currentDate());
    endDateEdit.setDate(QDate::currentDate().addDays(1));

    formLayout.addRow("ID:", &idEdit);
    formLayout.addRow("ID клиента:   ", &clientIdEdit);
    formLayout.addRow("ID авто:      ", &carIdEdit);
    formLayout.addRow("Начало аренды:", &startDateEdit);
    formLayout.addRow("Конец аренды: ", &endDateEdit);

    QPushButton okButton("OK");
    formLayout.addRow(&okButton);
    QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    if (dialog.exec() == QDialog::Accepted) {
        Client *clientWasCreated = clientView->findClientById(clientIdEdit.text().toInt());
        if (clientWasCreated == nullptr) {
            QMessageBox::warning(this, "Ошибка", "Клиент с таким ID не существует.");
            return;
        }
        Car *carWasCreated = carView->findCarById(carIdEdit.text().toInt());
        if (carWasCreated == nullptr) {
            QMessageBox::warning(this, "Ошибка", "Автомобиль с таким ID не существует.");
            return;
        }
        Rent *rentWasCreated = rentView->findRentById(idEdit.text().toInt());
        if (rentWasCreated != nullptr && idEdit.text().toInt() != rent->getId()) {
            QMessageBox::warning(this, "Ошибка", "Аренда с таким ID уже существует.");
            return;
        }
        rent->setId(idEdit.text().toInt());
        rent->setClientId(clientIdEdit.text().toInt());
        rent->setCarId(carIdEdit.text().toInt());
        rent->setStartRent(startDateEdit.date());
        rent->setEndRent(endDateEdit.date());
    }
}

void MainWindow::on_returnFromRentalButton_clicked()
{
    QModelIndex index = ui->rentalsTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбрана запись для удаления.");
        return;
    }
    Rent *rent = rentView->rents.at(index.row());
    Car* i = carView->cars.at(carView->changeAvailability(rent->getId()));
    i->setAvailability(!i->getAvailability());
    rentView->removeRent(index.row());

    emit notifyObservers();
}

