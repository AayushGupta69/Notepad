#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_aboutMe_clicked()
{
    QString resume;
    resume += "<b>Name:</b> Aayush Gupta<br><br>";
    resume += "<b>Email:</b> aayushguptaworks@gmail.com<br>";
    resume += "<b>Mob:</b> 9310297267<br>";
    resume += "<b>Education:</b> B.Tech in Computer Science and Engineering from Dronacharya College of Engineering, Gurugram. (CGPA: 7.7)<br>";
    resume += "<b>GitHub:</b> <a href=\"https://github.com/AayushGupta69\">https://github.com/AayushGupta69</a><br>";
    resume += "<b>Skills:</b><br>C, C++, Python, Linux, Git, GitHub, Build Automation<br>";
    resume += "<b>Interests:</b><br>Operating Systems, Artificial Intelligence<br>";

    QMessageBox::information(this, "About Me", resume, QMessageBox::Ok, QMessageBox::Information);


}


void MainWindow::on_superscript_clicked()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);

    QTextCursor cursor(ui->textEdit->textCursor());
    if (cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSuperScript) {
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    }
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_subscript_clicked()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSubScript);

    QTextCursor cursor(ui->textEdit->textCursor());
    if (cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSubScript) {
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    }
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

