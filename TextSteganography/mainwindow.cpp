/**
 * \author thanhtung thanhtungpfiev@gmail.com
 *
 * \date 16 - 10 - 2017
 *
 * \class MainWindow
 *
 * \brief
 *
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Text Steganography Simulation"));

    initMapAlphabetToEncode();
    printMapAlphabetToEncode();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMapAlphabetToEncode()
{
    // create group 1
    mapAlphabetToEncode.insert('C', "00");
    mapAlphabetToEncode.insert('F', "00");
    mapAlphabetToEncode.insert('G', "00");
    mapAlphabetToEncode.insert('J', "00");
    mapAlphabetToEncode.insert('L', "00");
    mapAlphabetToEncode.insert('N', "00");
    mapAlphabetToEncode.insert('P', "00");
    mapAlphabetToEncode.insert('Q', "00");
    mapAlphabetToEncode.insert('R', "00");
    mapAlphabetToEncode.insert('Z', "00");
}

void MainWindow::printMapAlphabetToEncode()
{
    for (QMap<QChar, QString>::const_iterator iter = mapAlphabetToEncode.begin(); iter != mapAlphabetToEncode.end(); ++iter) {
        qDebug() << "key: " << iter.key() << " value: " << iter.value();
    }
}
