#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewActionTriggered();
    void onOpenActionTriggered();
    void onSaveActionTriggered();
    void onExitActionTriggered();
    void onCopyActionTriggered();
    void onCutActionTriggered();
    void onPasteActionTriggered();
    void onUndoActionTriggered();
    void onRedoActionTriggered();
    void onFontActionTriggered();
    void on_aboutMe_clicked();
    void on_superscript_clicked();
    void on_subscript_clicked();
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
