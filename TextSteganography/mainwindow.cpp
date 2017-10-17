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
//    printMapAlphabetToEncode();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMapAlphabetToEncode()
{
    // create group 1
    mMapAlphabetToEncode.insert('C', "00");
    mMapAlphabetToEncode.insert('F', "00");
    mMapAlphabetToEncode.insert('G', "00");
    mMapAlphabetToEncode.insert('J', "00");
    mMapAlphabetToEncode.insert('L', "00");
    mMapAlphabetToEncode.insert('N', "00");
    mMapAlphabetToEncode.insert('P', "00");
    mMapAlphabetToEncode.insert('Q', "00");
    mMapAlphabetToEncode.insert('R', "00");
    mMapAlphabetToEncode.insert('Z', "00");

    // create group 2
    mMapAlphabetToEncode.insert('B', "01");
    mMapAlphabetToEncode.insert('D', "01");
    mMapAlphabetToEncode.insert('E', "01");
    mMapAlphabetToEncode.insert('K', "01");
    mMapAlphabetToEncode.insert('S', "01");

    // create group 3
    mMapAlphabetToEncode.insert('A', "10");
    mMapAlphabetToEncode.insert('M', "10");
    mMapAlphabetToEncode.insert('T', "10");
    mMapAlphabetToEncode.insert('U', "10");
    mMapAlphabetToEncode.insert('V', "10");
    mMapAlphabetToEncode.insert('W', "10");
    mMapAlphabetToEncode.insert('Y', "10");

    // create group 4
    mMapAlphabetToEncode.insert('H', "11");
    mMapAlphabetToEncode.insert('I', "11");
    mMapAlphabetToEncode.insert('O', "11");
    mMapAlphabetToEncode.insert('X', "11");
}

void MainWindow::printMapAlphabetToEncode()
{
    for (QMap<QChar, QString>::const_iterator iter = mMapAlphabetToEncode.begin(); iter != mMapAlphabetToEncode.end(); ++iter) {
        qDebug() << "key: " << iter.key() << " value: " << iter.value();
    }
}

QStringList MainWindow::convertSecretMessageToBinaryBitStreams(const QString &secretMessage)
{
    QStringList binaryBitStreams;
    for (int i = 0; i < secretMessage.size(); ++i) {
        QString characterInBits = QString::number(int(secretMessage.at(i).toLatin1()), 2);
        characterInBits.push_front("0");
        for (int j = 0; j < characterInBits.size(); j = j + 2) {
            QString pairBits = QString(characterInBits.at(j)) + QString(characterInBits.at(j + 1));
            binaryBitStreams << pairBits;
        }
    }
    return binaryBitStreams;
}

void MainWindow::on_pushButton_encoding_clicked()
{
    QString secretMessage = ui->lineEdit_secret_message->text();
    QStringList binaryBitStreams = convertSecretMessageToBinaryBitStreams(secretMessage);
    for (int i = 0; i < binaryBitStreams.size(); ++i) {
        qDebug() << binaryBitStreams.at(i);
    }

}
