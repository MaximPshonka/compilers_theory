#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lexer.h"

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
    void on_btnCalc_clicked();


private:
    Ui::MainWindow *ui;
    Lexer *lexer;
    std::string text;


    std::string getSentence();
    Lexer::TokenType *searchNextToken(Lexer::TokenType type);
    bool isLegalToken(Lexer::TokenType tokens[8], Lexer::TokenType type);


};
#endif // MAINWINDOW_H
