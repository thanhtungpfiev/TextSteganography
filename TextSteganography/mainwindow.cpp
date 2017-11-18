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
#include <QMessageBox>
#include <QFileDialog>

const int MainWindow::NUMBER_OF_SECRET_MESSAGE_CHARACTERS_MAX = 10;
const int MainWindow::NUMBER_OF_BITS_OF_CHARACTER_ASCII = 8;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Text Steganography Simulation"));

    initMapAlphabetToEncode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMapAlphabetToEncode()
{
    // create group 1 - no reflaction
    mMapAlphabetToEncode.insert('F', "00");
    mMapAlphabetToEncode.insert('G', "00");
    mMapAlphabetToEncode.insert('J', "00");
    mMapAlphabetToEncode.insert('L', "00");
    mMapAlphabetToEncode.insert('N', "00");
    mMapAlphabetToEncode.insert('P', "00");
    mMapAlphabetToEncode.insert('Q', "00");
    mMapAlphabetToEncode.insert('R', "00");
    mMapAlphabetToEncode.insert('S', "01");
    mMapAlphabetToEncode.insert('Z', "00");

    // create group 2 - reflaction based on axis X
    mMapAlphabetToEncode.insert('B', "01");
    mMapAlphabetToEncode.insert('C', "00");
    mMapAlphabetToEncode.insert('D', "01");
    mMapAlphabetToEncode.insert('E', "01");
    mMapAlphabetToEncode.insert('K', "01");

    // create group 3 - reflaction based on axis Y
    mMapAlphabetToEncode.insert('A', "10");
    mMapAlphabetToEncode.insert('M', "10");
    mMapAlphabetToEncode.insert('T', "10");
    mMapAlphabetToEncode.insert('U', "10");
    mMapAlphabetToEncode.insert('V', "10");
    mMapAlphabetToEncode.insert('W', "10");
    mMapAlphabetToEncode.insert('Y', "10");

    // create group 4 - both reflaction
    mMapAlphabetToEncode.insert('H', "11");
    mMapAlphabetToEncode.insert('I', "11");
    mMapAlphabetToEncode.insert('O', "11");
    mMapAlphabetToEncode.insert('X', "11");
}

QStringList MainWindow::convertSecretMessageToBinaryBitStreams(const QString &secretMessage)
{
    QStringList binaryBitStreams;
    for (int i = 0; i < secretMessage.size(); ++i) {
        QString characterInBits = convertCharacterToBinaryAscii8bits(secretMessage.at(i));
        binaryBitStreams << splitBitStreamsToPairBits(characterInBits);
    }
    return binaryBitStreams;
}

QString MainWindow::convertCharacterToBinaryAscii8bits(const QChar &character)
{
    QString characterInBits = QString::number(int(character.toLatin1()), 2);
    if (characterInBits.size() < NUMBER_OF_BITS_OF_CHARACTER_ASCII) {
        int oldSize = characterInBits.size();
        for (int k = 0; k < NUMBER_OF_BITS_OF_CHARACTER_ASCII - oldSize; ++k) {
            characterInBits.push_front("0");
        }
    }
    return characterInBits;
}

QStringList MainWindow::splitBitStreamsToPairBits(const QString &bitStreams)
{
    QStringList binaryBitStreams;
    if (bitStreams.size() == NUMBER_OF_BITS_OF_CHARACTER_ASCII) {
        for (int j = 0; j < bitStreams.size(); j = j + 2) {
            QString pairBits = QString(bitStreams.at(j)) + QString(bitStreams.at(j + 1));
            binaryBitStreams << pairBits;
        }
    }
    return binaryBitStreams;
}

QStringList MainWindow::convertTextToSentences(const QString &text)
{
    QStringList sentences;
    QRegExp rx("(\\.|\\?|\\!)");
    sentences = text.split(rx);
    return sentences;
}

void MainWindow::convertPairBitsToStegoText(const QString &pairBits, QStringList &sentences)
{
    qDebug() << "pairBits: " << pairBits;
    qDebug() << "before sentences: " << sentences;

    int i;
    for (i = 0; i < sentences.size(); ++i) {
        QString sentence = sentences.at(i);
        QChar firstCharacter;
        QString firstWord = sentence.split(" ").at(0).trimmed();
        if ((firstWord == "A" || firstWord == "The") && (sentence.split(" ").size() > 2) ) {
            QString secondWord = sentence.split(" ").at(1).trimmed();
            firstCharacter = secondWord.at(0).toUpper();
        } else {
            firstCharacter = firstWord.at(0).toUpper();
        }

        if (pairBits == mMapAlphabetToEncode.value(firstCharacter)) {
            qDebug() << sentences.at(i);
            mSummary << sentences.at(i);
            break;
        }
    }
    if (i >= sentences.size()) {
        i = sentences.size() - 1;
    }
    QStringList listToDelete;
    for (int j = 0; j <= i; ++j) {
        listToDelete << sentences.at(j);
    }
    remove(sentences, listToDelete);
    qDebug() << "listToDelete: " << listToDelete;
    qDebug() << "after sentences: " << sentences;
}

void MainWindow::remove(QStringList &list, const QStringList &toDelete)
{
    QStringListIterator iter(toDelete);
    while(iter.hasNext()){
        list.removeAll(iter.next());
    }
}

QStringList MainWindow::convertStegoTextToPairBits(const QStringList &sentences)
{
    QStringList binaryBitStreams;
    for (int i = 0; i < sentences.size(); ++i) {
        QString sentence = sentences.at(i);
        QChar firstCharacter;
        QString firstWord = sentence.split(" ").at(0).trimmed();
        if ((firstWord == "A" || firstWord == "The") && (sentence.split(" ").size() > 2) ) {
            QString secondWord = sentence.split(" ").at(1).trimmed();
            firstCharacter = secondWord.at(0).toUpper();
        } else {
            firstCharacter = firstWord.at(0).toUpper();
        }
        binaryBitStreams << mMapAlphabetToEncode.value(firstCharacter);
    }
    return binaryBitStreams;
}

int MainWindow::convertBinaryAsciiToInt(const QString &binaryAscii)
{
    int number = 0;
    for (int i = 0; i < binaryAscii.length(); ++i) {
        number += QString(binaryAscii.at(i)).toInt() * pow(2, binaryAscii.length() - 1 - i);
    }
    return number;
}

void MainWindow::resetApp()
{
    ui->lineEdit_secret_message->clear();
    ui->plainTextEdit_cover_text->clear();
    ui->plainTextEdit_cover_text->clear();
    ui->lineEdit_secret_message_result->clear();
    mSummary.clear();
}

bool MainWindow::checkConditionOfSecretMessge(const QString &secretMessage)
{
    if (secretMessage.isEmpty()) {
        QMessageBox message(QMessageBox::Warning, "Notification", "Secret message is not empty");
        message.exec();
        return false;
    }

    if (secretMessage.size() > NUMBER_OF_SECRET_MESSAGE_CHARACTERS_MAX) {
        QMessageBox message(QMessageBox::Warning, "Notification", "Secret message is not longer than 10 characters");
        message.exec();
        return false;
    }

    return true;
}

bool MainWindow::checkConditionOfCoverText(const QString &coverText)
{
    if (coverText.isEmpty()) {
        QMessageBox message(QMessageBox::Warning, "Notification", "Cover text is not empty");
        message.exec();
        return false;
    }
    return true;
}

void MainWindow::on_pushButton_encoding_clicked()
{
    mSummary.clear();
    ui->plainTextEdit_stego_text->clear();

    QString secretMessage = ui->lineEdit_secret_message->text();

    if (!checkConditionOfSecretMessge(secretMessage)) {
        return;
    }

    QStringList binaryBitStreams = convertSecretMessageToBinaryBitStreams(secretMessage);

    QString coverText = ui->plainTextEdit_cover_text->toPlainText();

    if (!checkConditionOfCoverText(coverText)) {
        return;
    }
    QStringList sentences = convertTextToSentences(coverText);
    QStringList simplifiedSentences;
    for (int i = 0; i < sentences.size(); ++i) {
        if (sentences.at(i).simplified() == "") {
            continue;
        }
        simplifiedSentences << sentences.at(i).simplified();
    }
    for (int i = 0; i < binaryBitStreams.size(); ++i) {
        QString pairBits = binaryBitStreams.at(i);
        convertPairBitsToStegoText(pairBits, simplifiedSentences);
        if (i != binaryBitStreams.size() - 1) {
            if (simplifiedSentences.isEmpty()) {
                QMessageBox message(QMessageBox::Warning, "Notification", "Cover text is not enough capacity to stego secret message");
                message.exec();
                return;
            }
        }
    }
    qDebug() << "summary: "  << mSummary;
    for (int i = 0; i < mSummary.size(); ++i) {
        QString tempString = mSummary.at(i);
        ui->plainTextEdit_stego_text->appendPlainText(tempString.append("."));
    }
}

void MainWindow::on_pushButton_decoding_clicked()
{
    QStringList binaryBitStreams = convertStegoTextToPairBits(mSummary);
    QString secretMessageResult;
    for (int i = 0; i < binaryBitStreams.size(); i = i + 4) {
        QString tempCharAtBit = binaryBitStreams.at(i) + binaryBitStreams.at(i + 1)
                + binaryBitStreams.at(i + 2) + binaryBitStreams.at(i + 3);
        secretMessageResult += QString(QChar(convertBinaryAsciiToInt(tempCharAtBit)));
    }
    ui->lineEdit_secret_message_result->setText(secretMessageResult);
}

void MainWindow::on_pushButton_browse_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), qApp->applicationDirPath(), tr("Text Files (*.txt)"));
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox message(QMessageBox::Critical, "Notification", "Cannot find this file");
        message.exec();
        return;
    }
    QTextStream in(&f);
    ui->plainTextEdit_cover_text->document()->setPlainText(in.readAll());
    f.close();
}
