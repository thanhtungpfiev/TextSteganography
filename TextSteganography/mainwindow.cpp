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
const int MainWindow::NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_I = 16;
const int MainWindow::NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_II = 24;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Text Steganography Simulation"));

    initMapAlphabetVietnameseToEncode();
    initMapAlphabetVietnameseWithUtf8Value();
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
    mMapAlphabetVietnameseToEncode.insert(trUtf8("Ỉ"), "00");
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

void MainWindow::initMapAlphabetVietnameseWithUtf8Value()
{
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Á"), "1100001110000001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("À"), "1100001110000000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ã"), "1100001110000011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ạ"), "111000011011101010100000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ả"), "111000011011101010100010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ă"), "1100010010000010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ắ"), "111000011011101010101110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ằ"), "111000011011101010110000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẵ"), "111000011011101010110100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ặ"), "111000011011101010110110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẳ"), "111000011011101010110010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Â"), "1100001110000010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ấ"), "111000011011101010100100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ầ"), "111000011011101010100110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẫ"), "111000011011101010101010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ậ"), "111000011011101010101100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẩ"), "111000011011101010101000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Đ"), "1100010010010000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("É"), "1100001110001001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("È"), "1100001110001000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẽ"), "111000011011101010111100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẹ"), "111000011011101010111000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ẻ"), "111000011011101010111010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ê"), "1100001110001010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ế"), "111000011011101010111110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ề"), "111000011011101110000000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ễ"), "111000011011101110000100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ệ"), "111000011011101110000110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ể"), "111000011011101110000010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Í"), "1100001110001101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ì"), "1100001110001100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ĩ"), "1100010010101000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ị"), "111000011011101110001010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỉ"), "111000011011101110001000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ó"), "1100001110010011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ò"), "1100001110010010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Õ"), "1100001110010101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ọ"), "111000011011101110001100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỏ"), "111000011011101110001110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ô"), "1100001110010100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ố"), "111000011011101110010000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ồ"), "111000011011101110010010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỗ"), "111000011011101110010110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ộ"), "111000011011101110011000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ổ"), "111000011011101110010100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ơ"), "1100011010100000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ớ"), "111000011011101110011010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ờ"), "111000011011101110011100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỡ"), "111000011011101110100000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ợ"), "111000011011101110100010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ở"), "111000011011101110011110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ú"), "1100001110011010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ù"), "1100001110011001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ũ"), "1100010110101000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ụ"), "111000011011101110100100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ủ"), "111000011011101110100110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ư"), "1100011010101111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ứ"), "111000011011101110101000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ừ"), "111000011011101110101010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ữ"), "111000011011101110101110");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ự"), "111000011011101110110000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ử"), "111000011011101110101100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ý"), "1100001110011101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỳ"), "111000011011101110110010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỹ"), "111000011011101110111000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỵ"), "111000011011101110110100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("Ỷ"), "111000011011101110110110");

    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("á"), "1100001110100001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("à"), "1100001110100000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ã"), "1100001110100011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ạ"), "111000011011101010100001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ả"), "111000011011101010100011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ă"), "1100010010000011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ắ"), "111000011011101010101111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ằ"), "111000011011101010110001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẵ"), "111000011011101010110101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ặ"), "111000011011101010110111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẳ"), "111000011011101010110011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("â"), "1100001110100010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ấ"), "111000011011101010100101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ầ"), "111000011011101010100111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẫ"), "111000011011101010101011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ậ"), "111000011011101010101101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẩ"), "111000011011101010101001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("đ"), "1100010010010001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("é"), "1100001110101001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("è"), "1100001110101000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẽ"), "111000011011101010111101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẹ"), "111000011011101010111001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ẻ"), "111000011011101010111011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ê"), "1100001110101010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ế"), "111000011011101010111111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ề"), "111000011011101110000001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ễ"), "111000011011101110000101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ệ"), "111000011011101110000111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ể"), "111000011011101110000011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("í"), "1100001110101101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ì"), "1100001110101100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ĩ"), "1100010010101001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ị"), "111000011011101110001011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỉ"), "111000011011101110001001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ó"), "1100001110110011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ò"), "1100001110110010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("õ"), "1100001110110101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ọ"), "111000011011101110001101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỏ"), "111000011011101110001111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ô"), "1100001110110100");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ố"), "111000011011101110010001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ồ"), "111000011011101110010011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỗ"), "111000011011101110010111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ộ"), "111000011011101110011001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ổ"), "111000011011101110010101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ơ"), "1100011010100001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ớ"), "111000011011101110011011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ờ"), "111000011011101110011101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỡ"), "111000011011101110100001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ợ"), "111000011011101110100011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ở"), "111000011011101110011111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ú"), "1100001110111010");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ù"), "1100001110111001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ũ"), "1100010110101001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ụ"), "111000011011101110100101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ủ"), "111000011011101110100111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ư"), "1100011010110000");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ứ"), "111000011011101110101001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ừ"), "111000011011101110101011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ữ"), "111000011011101110101111");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ự"), "111000011011101110110001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ử"), "111000011011101110101101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ý"), "1100001110111101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỳ"), "111000011011101110110011");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỹ"), "111000011011101110111001");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỵ"), "111000011011101110110101");
    mMapAlphabetVietnameseWithUtf8Value.insert(trUtf8("ỷ"), "111000011011101110110111");
}

QStringList MainWindow::convertSecretMessageToBinaryBitStreams(const QString &secretMessage)
{
    QStringList binaryBitStreams;
    for (int i = 0; i < secretMessage.size(); ++i) {
        QChar character = secretMessage.at(i);
        if (QString(character).toUtf8() == "Á"
                || QString(character).toUtf8() == "À"
                || QString(character).toUtf8() == "Ã"
                || QString(character).toUtf8() == "Ạ"
                || QString(character).toUtf8() == "Ả"
                || QString(character).toUtf8() == "Ă"
                || QString(character).toUtf8() == "Ắ"
                || QString(character).toUtf8() == "Ằ"
                || QString(character).toUtf8() == "Ẵ"
                || QString(character).toUtf8() == "Ặ"
                || QString(character).toUtf8() == "Ẳ"
                || QString(character).toUtf8() == "Â"
                || QString(character).toUtf8() == "Ấ"
                || QString(character).toUtf8() == "Ầ"
                || QString(character).toUtf8() == "Ẫ"
                || QString(character).toUtf8() == "Ậ"
                || QString(character).toUtf8() == "Ẩ"
                || QString(character).toUtf8() == "Đ"
                || QString(character).toUtf8() == "É"
                || QString(character).toUtf8() == "È"
                || QString(character).toUtf8() == "Ẽ"
                || QString(character).toUtf8() == "Ẹ"
                || QString(character).toUtf8() == "Ẻ"
                || QString(character).toUtf8() == "Ê"
                || QString(character).toUtf8() == "Ế"
                || QString(character).toUtf8() == "Ề"
                || QString(character).toUtf8() == "Ễ"
                || QString(character).toUtf8() == "Ệ"
                || QString(character).toUtf8() == "Ể"
                || QString(character).toUtf8() == "Í"
                || QString(character).toUtf8() == "Ì"
                || QString(character).toUtf8() == "Ĩ"
                || QString(character).toUtf8() == "Ị"
                || QString(character).toUtf8() == "Ỉ"
                || QString(character).toUtf8() == "Ó"
                || QString(character).toUtf8() == "Ò"
                || QString(character).toUtf8() == "Õ"
                || QString(character).toUtf8() == "Ọ"
                || QString(character).toUtf8() == "Ỏ"
                || QString(character).toUtf8() == "Ô"
                || QString(character).toUtf8() == "Ố"
                || QString(character).toUtf8() == "Ồ"
                || QString(character).toUtf8() == "Ỗ"
                || QString(character).toUtf8() == "Ộ"
                || QString(character).toUtf8() == "Ổ"
                || QString(character).toUtf8() == "Ơ"
                || QString(character).toUtf8() == "Ớ"
                || QString(character).toUtf8() == "Ờ"
                || QString(character).toUtf8() == "Ỡ"
                || QString(character).toUtf8() == "Ợ"
                || QString(character).toUtf8() == "Ở"
                || QString(character).toUtf8() == "Ú"
                || QString(character).toUtf8() == "Ù"
                || QString(character).toUtf8() == "Ũ"
                || QString(character).toUtf8() == "Ụ"
                || QString(character).toUtf8() == "Ủ"
                || QString(character).toUtf8() == "Ư"
                || QString(character).toUtf8() == "Ứ"
                || QString(character).toUtf8() == "Ừ"
                || QString(character).toUtf8() == "Ữ"
                || QString(character).toUtf8() == "Ự"
                || QString(character).toUtf8() == "Ử"
                || QString(character).toUtf8() == "Ý"
                || QString(character).toUtf8() == "Ỳ"
                || QString(character).toUtf8() == "Ỹ"
                || QString(character).toUtf8() == "Ỵ"
                || QString(character).toUtf8() == "Ỷ"
                || QString(character).toUtf8() == "á"
                || QString(character).toUtf8() == "à"
                || QString(character).toUtf8() == "ã"
                || QString(character).toUtf8() == "ạ"
                || QString(character).toUtf8() == "ả"
                || QString(character).toUtf8() == "ă"
                || QString(character).toUtf8() == "ắ"
                || QString(character).toUtf8() == "ằ"
                || QString(character).toUtf8() == "ẵ"
                || QString(character).toUtf8() == "ặ"
                || QString(character).toUtf8() == "ẳ"
                || QString(character).toUtf8() == "â"
                || QString(character).toUtf8() == "ấ"
                || QString(character).toUtf8() == "ầ"
                || QString(character).toUtf8() == "ẫ"
                || QString(character).toUtf8() == "ậ"
                || QString(character).toUtf8() == "ẩ"
                || QString(character).toUtf8() == "đ"
                || QString(character).toUtf8() == "é"
                || QString(character).toUtf8() == "è"
                || QString(character).toUtf8() == "ẽ"
                || QString(character).toUtf8() == "ẹ"
                || QString(character).toUtf8() == "ẻ"
                || QString(character).toUtf8() == "ê"
                || QString(character).toUtf8() == "ế"
                || QString(character).toUtf8() == "ề"
                || QString(character).toUtf8() == "ễ"
                || QString(character).toUtf8() == "ệ"
                || QString(character).toUtf8() == "ể"
                || QString(character).toUtf8() == "í"
                || QString(character).toUtf8() == "ì"
                || QString(character).toUtf8() == "ĩ"
                || QString(character).toUtf8() == "ị"
                || QString(character).toUtf8() == "ỉ"
                || QString(character).toUtf8() == "ó"
                || QString(character).toUtf8() == "ò"
                || QString(character).toUtf8() == "õ"
                || QString(character).toUtf8() == "ọ"
                || QString(character).toUtf8() == "ỏ"
                || QString(character).toUtf8() == "ô"
                || QString(character).toUtf8() == "ố"
                || QString(character).toUtf8() == "ồ"
                || QString(character).toUtf8() == "ỗ"
                || QString(character).toUtf8() == "ộ"
                || QString(character).toUtf8() == "ổ"
                || QString(character).toUtf8() == "ơ"
                || QString(character).toUtf8() == "ớ"
                || QString(character).toUtf8() == "ờ"
                || QString(character).toUtf8() == "ỡ"
                || QString(character).toUtf8() == "ợ"
                || QString(character).toUtf8() == "ở"
                || QString(character).toUtf8() == "ú"
                || QString(character).toUtf8() == "ù"
                || QString(character).toUtf8() == "ũ"
                || QString(character).toUtf8() == "ụ"
                || QString(character).toUtf8() == "ủ"
                || QString(character).toUtf8() == "ư"
                || QString(character).toUtf8() == "ứ"
                || QString(character).toUtf8() == "ừ"
                || QString(character).toUtf8() == "ữ"
                || QString(character).toUtf8() == "ự"
                || QString(character).toUtf8() == "ử"
                || QString(character).toUtf8() == "ý"
                || QString(character).toUtf8() == "ỳ"
                || QString(character).toUtf8() == "ỹ"
                || QString(character).toUtf8() == "ỵ"
                || QString(character).toUtf8() == "ỷ") {
            binaryBitStreams << mMapAlphabetVietnameseWithUtf8Value.value(QString(character).toUtf8());
        } else {
            binaryBitStreams << convertCharacterToBinaryAscii8bits(character);
        }
    }
    qDebug() << binaryBitStreams;
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
    if (bitStreams.size() == NUMBER_OF_BITS_OF_CHARACTER_ASCII
            || bitStreams.size() == NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_I
            || bitStreams.size() == NUMBER_OF_BITS_OF_CHARACTER_UTF8_TYPE_II) {
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
