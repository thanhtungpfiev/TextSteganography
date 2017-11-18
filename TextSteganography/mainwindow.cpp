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

    initMapAlphabetVietnameseToEncode();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMapAlphabetVietnameseToEncode()
{
    // create group 1 - no reflaction
    mMapAlphabetVietnameseToEncode.insert('Á', "00");
    mMapAlphabetVietnameseToEncode.insert('À', "00");
    mMapAlphabetVietnameseToEncode.insert('Ã', "00");
    mMapAlphabetVietnameseToEncode.insert('Ả', "00");
    mMapAlphabetVietnameseToEncode.insert('Ắ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ằ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẵ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẳ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ấ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ầ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẫ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẩ', "00");
    mMapAlphabetVietnameseToEncode.insert('C', "00");
    mMapAlphabetVietnameseToEncode.insert('É', "00");
    mMapAlphabetVietnameseToEncode.insert('È', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẽ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẹ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ẻ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ê', "00");
    mMapAlphabetVietnameseToEncode.insert('Ế', "00");
    mMapAlphabetVietnameseToEncode.insert('Ề', "00");
    mMapAlphabetVietnameseToEncode.insert('Ễ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ệ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ể', "00");
    mMapAlphabetVietnameseToEncode.insert('Í', "00");
    mMapAlphabetVietnameseToEncode.insert('Ì', "00");
    mMapAlphabetVietnameseToEncode.insert('Ĩ', "00");
    mMapAlphabetVietnameseToEncode.insert('G', "00");
    mMapAlphabetVietnameseToEncode.insert('L', "00");
    mMapAlphabetVietnameseToEncode.insert('N', "00");
    mMapAlphabetVietnameseToEncode.insert('Ó', "00");
    mMapAlphabetVietnameseToEncode.insert('Ò', "00");
    mMapAlphabetVietnameseToEncode.insert('Õ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỏ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ố', "00");
    mMapAlphabetVietnameseToEncode.insert('Ồ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỗ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ổ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ơ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ớ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ờ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỡ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ợ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ở', "00");
    mMapAlphabetVietnameseToEncode.insert('P', "00");
    mMapAlphabetVietnameseToEncode.insert('Q', "00");
    mMapAlphabetVietnameseToEncode.insert('R', "00");
    mMapAlphabetVietnameseToEncode.insert('Ú', "00");
    mMapAlphabetVietnameseToEncode.insert('Ù', "00");
    mMapAlphabetVietnameseToEncode.insert('Ũ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ủ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ư', "00");
    mMapAlphabetVietnameseToEncode.insert('Ứ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ừ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ữ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ự', "00");
    mMapAlphabetVietnameseToEncode.insert('Ử', "00");
    mMapAlphabetVietnameseToEncode.insert('Ý', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỳ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỹ', "00");
    mMapAlphabetVietnameseToEncode.insert('Ỷ', "00");

    // create group 2 - reflaction based on axis X
    mMapAlphabetVietnameseToEncode.insert('B', "01");
    mMapAlphabetVietnameseToEncode.insert('D', "01");
    mMapAlphabetVietnameseToEncode.insert('Đ', "01");
    mMapAlphabetVietnameseToEncode.insert('E', "01");
    mMapAlphabetVietnameseToEncode.insert('K', "01");
    mMapAlphabetVietnameseToEncode.insert('S', "01");

    // create group 3 - reflaction based on axis Y
    mMapAlphabetVietnameseToEncode.insert('A', "10");
    mMapAlphabetVietnameseToEncode.insert('Ạ', "10");
    mMapAlphabetVietnameseToEncode.insert('Ă', "10");
    mMapAlphabetVietnameseToEncode.insert('Ặ', "10");
    mMapAlphabetVietnameseToEncode.insert('Â', "10");
    mMapAlphabetVietnameseToEncode.insert('Ậ', "10");
    mMapAlphabetVietnameseToEncode.insert('Ị', "00");
    mMapAlphabetVietnameseToEncode.insert('M', "10");
    mMapAlphabetVietnameseToEncode.insert('Ọ', "10");
    mMapAlphabetVietnameseToEncode.insert('Ô', "10");
    mMapAlphabetVietnameseToEncode.insert('Ộ', "10");
    mMapAlphabetVietnameseToEncode.insert('T', "10");
    mMapAlphabetVietnameseToEncode.insert('U', "10");
    mMapAlphabetVietnameseToEncode.insert('Ụ', "10");
    mMapAlphabetVietnameseToEncode.insert('V', "10");
    mMapAlphabetVietnameseToEncode.insert('Y', "10");
    mMapAlphabetVietnameseToEncode.insert('Ỵ', "10");

    // create group 4 - both reflaction
    mMapAlphabetVietnameseToEncode.insert('H', "11");
    mMapAlphabetVietnameseToEncode.insert('I', "11");
    mMapAlphabetVietnameseToEncode.insert('O', "11");
    mMapAlphabetVietnameseToEncode.insert('X', "11");
}

QStringList MainWindow::convertSecretMessageToBinaryBitStreams(const QString &secretMessage)
{
    QStringList binaryBitStreams;
    for (int i = 0; i < secretMessage.size(); ++i) {
        QString characterInBits = QString::number(int(secretMessage.at(i).toLatin1()), 2);
        if (characterInBits.size() < NUMBER_OF_BITS_OF_CHARACTER_ASCII) {
            int oldSize = characterInBits.size();
            for (int k = 0; k < NUMBER_OF_BITS_OF_CHARACTER_ASCII - oldSize; ++k) {
                characterInBits.push_front("0");
            }
        }
        for (int j = 0; j < characterInBits.size(); j = j + 2) {
            QString pairBits = QString(characterInBits.at(j)) + QString(characterInBits.at(j + 1));
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

    if (!checkConditionOfSecretMessge(ui->lineEdit_secret_message->text())) {
        return;
    }

    QStringList binaryBitStreams = convertSecretMessageToBinaryBitStreams(secretMessage);


    for (int i = 0; i < binaryBitStreams.size(); ++i) {
        qDebug() << binaryBitStreams.at(i);
    }

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
