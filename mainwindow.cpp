#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *fileMenu = ui->menubar->addMenu(tr("File"));

    QAction *newAction = new QAction(tr("New"), this);
    newAction->setIcon(QIcon(":/icons/new.png"));
    fileMenu->addAction(newAction);

    QAction *openAction = new QAction(tr("Open"), this);
    openAction->setIcon(QIcon(":/icons/open.png"));
    fileMenu->addAction(openAction);

    QAction *saveAction = new QAction(tr("Save"), this);
    saveAction->setIcon(QIcon(":/icons/save.png"));
    fileMenu->addAction(saveAction);

    QAction *exitAction = new QAction(tr("Exit"), this);
    exitAction->setIcon(QIcon(":/icons/exit.png"));
    fileMenu->addAction(exitAction);

    connect(newAction, &QAction::triggered, this, &MainWindow::onNewActionTriggered);
    connect(openAction, &QAction::triggered, this, &MainWindow::onOpenActionTriggered);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onSaveActionTriggered);
    connect(exitAction, &QAction::triggered, this, &MainWindow::onExitActionTriggered);
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


void MainWindow::on_pushButton_clicked()
{
    QTextCharFormat format;
    format.setFontWeight(ui->textEdit->fontWeight());

    QTextCursor cursor(ui->textEdit->textCursor());
    if (cursor.charFormat().fontWeight() == QFont::Bold) {
        format.setFontWeight(QFont::Normal);
    } else {
        format.setFontWeight(QFont::Bold);
    }
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::onNewActionTriggered()
{
    ui->textEdit->clear();
}

void MainWindow::onOpenActionTriggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
        }
    }
}

void MainWindow::onSaveActionTriggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
        }
    }
}

void MainWindow::onExitActionTriggered()
{
    QApplication::quit();
}
