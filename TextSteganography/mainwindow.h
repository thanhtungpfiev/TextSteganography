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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QObject>
#include <QString>

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
    void on_pushButton_encoding_clicked();

    void on_pushButton_decoding_clicked();

    void on_pushButton_browse_file_clicked();

private:
    void initMapAlphabetVietnameseToEncode();
    void initMapAlphabetVietnameseWithUtf8Value();
    QStringList convertSecretMessageToBinaryBitStreams(const QString &secretMessage);
    QString convertCharacterToBinaryAscii8bits(const QChar &character);
    QStringList splitBitStreamsToPairBits(const QString &bitStreams);
    QStringList convertTextToSentences(const QString &text);
    void convertPairBitsToStegoText(const QString &pairBits, QStringList &sentences);
    void remove(QStringList& list, const QStringList& toDelete);
    QStringList convertStegoTextToPairBits(const QStringList &sentences);
    int convertBinaryAsciiToInt(const QString &binaryAscii);
    void resetApp();

    // validate
    bool checkConditionOfSecretMessge(const QString &secretMessage);
    bool checkConditionOfCoverText(const QString &coverText);

private:
    QMap<QString, QString> mMapAlphabetVietnameseToEncode;
    QMap<QString, QString> mMapAlphabetVietnameseWithUtf8Value;
    QStringList mSummaryBlob;
    QList<QStringList> mSummary;

private:
    static const int NUMBER_OF_SECRET_MESSAGE_CHARACTERS_MAX;
    static const int NUMBER_OF_BITS_OF_CHARACTER_ASCII;
    static const int NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_I;
    static const int NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_II;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
