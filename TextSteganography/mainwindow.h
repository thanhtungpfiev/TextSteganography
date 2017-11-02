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

private:
    void initMapAlphabetToEncode();
    void printMapAlphabetToEncode();
    QStringList convertSecretMessageToBinaryBitStreams(const QString &secretMessage);
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
    QMap<QChar, QString> mMapAlphabetToEncode;
    QStringList mSummary;

private:
    static const int NUMBER_OF_SECRET_MESSAGE_CHARACTERS_MAX;
    static const int NUMBER_OF_BITS_OF_CHARACTER_ASCII;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
