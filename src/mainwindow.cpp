#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QMenuBar>
#include <unistd.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int user;

    user = geteuid();

    if (user == 0){
        QMessageBox::information(this,"Arch Updater","Press OK to update Arch.\nNo output will be visible\nMight take a while.");

        system("yes | sudo -S pacman -Scc");
        system("yes | sudo pacman -Qtdq");
        system("yes | sudo pacman -Rns $(pacman -Qtdq)");
        system("yes | rm -rf ~/.cache/*");
        system("yes | sudo journalctl --vacuum-time=2weeks");
        system("yes | sudo pacman -Syu");
        QMessageBox::information(this,"Arch Updater","Arch Linux updated!");
    }
    else{
        QMessageBox::information(this,"Arch Updater","Please run program as root!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int user2;

    user2 = geteuid();
    if (user2 == 0){
        QMessageBox::information(this,"Arch Updater","Press OK to update AUR packages (Yay).");
        system("yes | yay");
        system("yes | yay -Scc");
        system("yes | yay -Yc");
        QMessageBox::information(this,"Arch Updater","AUR packages updated!");
    }
    else{
        QMessageBox::information(this,"Arch Updater","Please run program as root!");
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"Arch Updater","Arch Updater\nMade by Ouxiez/Zoofyiscool\nVersion 1.0.0");
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

