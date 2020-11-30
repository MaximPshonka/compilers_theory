#include "lexer.h"
#include <QDebug>
#include <regex>

using namespace std;

Lexer::Lexer()
{

}


Lexer::Token Lexer::getTokens(std::string lexem){
    tokens = new Token();
    tokens->lexeme = lexem;
    tokens->type = getTokenType(lexem);
    return *tokens;
}

Lexer::TokenType Lexer::getTokenType(std::string lexem){
    //3. global var
    std::regex reg3("\(setq [a-z]+([0-9]|[a-z])* ([0-9]+|\"([a-z]|[0-9])*\")\)");
    if (regex_search(lexem.begin(), lexem.end(), reg3))
        return global_var;

    //4. local var
    std::regex reg4("\\(let \\((\\([a-z]+([a-z]|[0-9])* \\`([a-z]+|([a-z]*|[0-9]*))\\))+\\)");
    if (regex_search(lexem.begin(), lexem.end(), reg4))
        return local_var;

    std::regex reg5("\\(loop for [a-z]+([a-z]|[0-9])* ((from[0-9]* to [0-9]*)|in)");
    if (regex_search(lexem.begin(), lexem.end(), reg5))
        return cycle;

    std::regex reg9("for [a-z]+([a-z]|[0-9])* (\\=|from) ");
    if (regex_search(lexem.begin(), lexem.end(), reg9))
        return forx;

    std::regex reg6("car|cdr|collect|cons|atom|quote|self|write|print|read-line|when|do|until|return");
    if (regex_search(lexem.begin(), lexem.end(), reg6))
        return oper;

    std::regex reg1("\\((-|\\+|\\*|\\/|>|<|=)( [a-z]+([a-z]|[0-9])*)+\\)");
    if (regex_search(lexem.begin(), lexem.end(), reg1))
        return s_expr;

    std::regex reg2("\\((defun|defvar) [a-z]+([a-z]|[0-9])*( |\\()*(([a-z]|[0-9])*(\\,| )*)*\\)");
    if (regex_search(lexem.begin(), lexem.end(), reg2))
        return func;

    std::regex reg7("\".*\"");
    if (regex_search(lexem.begin(), lexem.end(), reg7))
        return comment;


    return other;

}


/*

  global : \(setq [a-z]+([0-9]|[a-z])* ([0-9]+|\"([a-z]|[0-9])*\")\)
    (setq xfds 10)
    (setq xfds "hgjh")

  local : \\(let \\((\\([a-z]+([a-z]|[0-9])* \\`([a-z]+|([a-z]*|[0-9]*))\\))+\\)
    (let ((x `a))
    (let ((x `a)(d `f))


*/


