#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <string>

#include <QDebug>



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


void MainWindow::on_btnCalc_clicked()
{
    text = ui->textCode->toPlainText().toStdString();

    std::string lexems[100];
    std::string buf = "0";

    lexer = new Lexer();
    Lexer::Token tokens[100];

    int k = 0;
    bool flag = true;
    Lexer::TokenType *expectedTokens;

    expectedTokens = new Lexer::TokenType[9];
    expectedTokens[0] = Lexer::TokenType::local_var;
    expectedTokens[1] = Lexer::TokenType::global_var;
    expectedTokens[3] = Lexer::TokenType::comment;
    expectedTokens[4] = Lexer::TokenType::cycle;
    expectedTokens[5] = Lexer::TokenType::func;
    expectedTokens[6] = Lexer::TokenType::oper;
    expectedTokens[7] = Lexer::TokenType::s_expr;
    expectedTokens[8] = Lexer::TokenType::forx;

    QString errorText = "Error is in string ";
    buf = getSentence();
    bool legality = true;
    while (buf != ""){
         lexems[k] = buf;
         tokens[k] = lexer->getTokens(lexems[k]);

         flag = isLegalToken(expectedTokens, tokens[k].type);

         if (flag == false){
             errorText += QString::number(k + 1) + ", ";
             legality = false;
         }

         expectedTokens = searchNextToken(tokens[k].type);

         flag = true;
         k++;
         buf = getSentence();
    }
    errorText[errorText.length() - 2] = ' ';
    if (legality == true)
         ui->textErrors->setText("Code is good");
    else
         ui->textErrors->setText(errorText);

}

bool MainWindow::isLegalToken(Lexer::TokenType tokens[8], Lexer::TokenType type){
    for (int i = 0; i < 9; i++) {
        if (tokens[i] == type)
            return true;
    }
    return false;
}


Lexer::TokenType *MainWindow::searchNextToken(Lexer::TokenType type){
    Lexer::TokenType *arr;
    arr = new Lexer::TokenType[9];
    switch(type){
        case Lexer::TokenType::global_var:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::local_var:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::other:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::forx:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::oper:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::s_expr:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::func:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::comment:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;
        case Lexer::TokenType::cycle:
            arr[0] = Lexer::TokenType::local_var;
            arr[1] = Lexer::TokenType::global_var;
            arr[3] = Lexer::TokenType::comment;
            arr[4] = Lexer::TokenType::cycle;
            arr[5] = Lexer::TokenType::func;
            arr[6] = Lexer::TokenType::oper;
            arr[7] = Lexer::TokenType::s_expr;
            arr[8] = Lexer::TokenType::forx;
        break;

    }
    return arr;
}

std::string MainWindow::getSentence(){
    std::string buf = "";
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] != '^'){
            if (text[i] != '\n'){
                buf += text[i];
                text[i] = '^';
            }
            else{
               text[i] = '^';
               break;
            }
        }
    }
    return buf;
}
