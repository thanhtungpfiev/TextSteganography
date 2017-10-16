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

private:
    void initMapAlphabetToEncode();
    void printMapAlphabetToEncode();

private:
    QMap<QChar, QString> mapAlphabetToEncode;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
