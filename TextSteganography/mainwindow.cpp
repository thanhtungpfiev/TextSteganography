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
const int MainWindow::LIMIT_OF_CHARACTER_ASCII = 127;

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
        binaryBitStreams << characterInBits;
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

bool MainWindow::convertPairBitsToStegoText(const QString &pairBits, QStringList &sentences)
{
    bool result =  false;
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
            mSummaryBlob << sentences.at(i);
            result = true;
            break;
        }
    }
    if (result == true) {
        QStringList listToDelete;
        for (int j = 0; j <= i; ++j) {
            listToDelete << sentences.at(j);
        }
        remove(sentences, listToDelete);
    }
    return result;
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
    ui->plainTextEdit_stego_text->clear();
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

    for (int i = 0; i < secretMessage.size(); ++i) {
        if (secretMessage.at(i).unicode() > LIMIT_OF_CHARACTER_ASCII) {
            QMessageBox message(QMessageBox::Warning, "Notification", "Secret message has non-English character");
            message.exec();
            return false;
        }
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
    mSummaryBlob.clear();
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
        QString binaryBitStream = binaryBitStreams.at(i);
        QStringList pairBitstreams = splitBitStreamsToPairBits(binaryBitStream);
        for (int j = 0; j < pairBitstreams.size(); ++j) {
            QString pairBits = pairBitstreams.at(j);
            if (!convertPairBitsToStegoText(pairBits, simplifiedSentences)) {
                QMessageBox message(QMessageBox::Warning, "Notification", "Cover text is not enough capacity to stego secret message");
                message.exec();
                return;
            }
        }
//        for (int i = 0; i < mSummaryBlob.size(); ++i) {
//            QString tempString = mSummaryBlob.at(i);
//            ui->plainTextEdit_stego_text->appendPlainText(tempString.append("."));
//        }
        mSummary.push_back(mSummaryBlob);
        mSummaryBlob.clear();
    }

    QString generalSentence;
    for (int i = 0; i < mSummary.size(); ++i) {
        QStringList blobSentence = mSummary.at(i);
        for (int j = 0; j < blobSentence.size(); ++j) {
            QString tempString = blobSentence.at(j);
            generalSentence += tempString.append(". ");
        }
    }
    ui->plainTextEdit_stego_text->document()->setPlainText(generalSentence);
}


void MainWindow::on_pushButton_decoding_clicked()
{
    QString secretMessageResult;
    for (int i = 0; i < mSummary.size(); ++i) {
        QStringList blob = mSummary.at(i);
        QStringList binaryBitStreams = convertStegoTextToPairBits(blob);
        if (binaryBitStreams.size() == NUMBER_OF_BITS_OF_CHARACTER_ASCII / 2) {
            for (int j = 0; j < binaryBitStreams.size(); j = j + 4) {
                QString tempCharAtBit = binaryBitStreams.at(j) + binaryBitStreams.at(j + 1)
                        + binaryBitStreams.at(j + 2) + binaryBitStreams.at(j + 3);
                secretMessageResult += QString(QChar(convertBinaryAsciiToInt(tempCharAtBit)));
            }
        } else {
            continue;
        }
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
