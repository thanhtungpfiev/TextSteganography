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
const int MainWindow::NUMBER_OF_BITS_OF_CHARACTER_UTF8 = 16;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Text Steganography Simulation"));

    initMapAlphabetVietnameseToEncode();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMapAlphabetVietnameseToEncode()
{
    // create group 1 - no reflaction
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Á"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("À"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ã"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ả"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ắ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ằ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẵ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẳ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ấ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ầ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẫ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẩ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("C"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("É"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("È"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẽ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẹ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ẻ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ê"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ế"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ề"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ễ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ệ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ể"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Í"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ì"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ĩ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("G"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("L"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("N"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ó"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ò"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Õ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỏ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ố"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ồ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỗ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ổ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ơ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ớ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ờ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỡ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ợ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ở"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("P"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Q"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("R"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ú"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ù"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ũ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ủ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ư"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ứ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ừ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ữ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ự"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ử"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ý"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỳ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỹ"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỷ"), "00");

    // create group 2 - reflaction based on axis X
    mMapAlphabetVietnameseToEncode.insert(trUtf8("B"), "01");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("D"), "01");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Đ"), "01");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("E"), "01");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("K"), "01");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("S"), "01");

    // create group 3 - reflaction based on axis Y
    mMapAlphabetVietnameseToEncode.insert(trUtf8("A"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ạ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ă"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ặ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Â"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ậ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ị"), "00");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("M"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ọ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ô"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ộ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("T"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("U"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ụ"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("V"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Y"), "10");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỵ"), "10");

    // create group 4 - both reflaction
    mMapAlphabetVietnameseToEncode.insert(trUtf8("H"), "11");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("I"), "11");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("O"), "11");
    mMapAlphabetVietnameseToEncode.insert(trUtf8("X"), "11");
}

QStringList MainWindow::convertSecretMessageToBinaryBitStreams(const QString &secretMessage)
{
//    QStringList binaryBitStreams;
//    for (int i = 0; i < secretMessage.size(); ++i) {
//        QString character = secretMessage.at(i);
//        if (QObject::trUtf8(character) == "Á") {
//            binaryBitStreams << "1100001110000001";
//        }
//    }
//    qDebug() << binaryBitStreams;
//    return binaryBitStreams;
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

        if (pairBits == mMapAlphabetVietnameseToEncode.value(firstCharacter)) {
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
        binaryBitStreams << mMapAlphabetVietnameseToEncode.value(firstCharacter);
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
    in.setCodec("UTF-8");
    ui->plainTextEdit_cover_text->document()->setPlainText(in.readAll());
//    qDebug() << f.size() << in.readAll();
    f.close();
}
