#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("qt");
    db.setUserName("testuser");
    db.setPassword("testuser");

    if(db.open())
    {
        qDebug() << "Connect";
    }
    else
    {
        qDebug() << "Failed to connect";

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();
    QString password = ui->passwordInput->text();
    qDebug() << username << password;

    QString command = "SELECT * FROM user WHERE username = '"+ username + "' AND password = '" + password + "' AND status = 0";
    QSqlQuery query(db);
    if(query.exec(command))
    {

        if (query.size() > 0)
        {
           QMessageBox::information(this, "Login success", "You have seuccessfully logged in");
        }
        else {
           QMessageBox::information(this, "Login failed", "Login failed. Please try again...");
        }
    }
}
