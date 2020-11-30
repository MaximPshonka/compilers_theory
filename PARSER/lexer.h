#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <string>


class Lexer
{
public:
    Lexer();
//    Lexer(std::string *lexemss){
//        lexems = new std::string[100];
//        for (int i = 0; i < 1000; i++){
//            lexems[i] = *(lexemss + i);
//        }
//    }

    enum TokenType{
        s_expr = 1,      // http://homelisp.ru/help/lisp.html
        func = 2,        // https://coderlessons.com/tutorials/kompiuternoe-programmirovanie/uznaite-lisp/lisp-funktsii
        global_var = 3,  // https://coderlessons.com/tutorials/kompiuternoe-programmirovanie/uznaite-lisp/lisp-peremennye
        local_var = 4,   // https://coderlessons.com/tutorials/kompiuternoe-programmirovanie/uznaite-lisp/lisp-peremennye
        cycle = 5,       // http://lisper.ru/wiki/cookbook:loop
        oper = 6,        // key words
        comment = 7,
        other = 8,
        forx = 9
    };

    struct Token{
        std::string lexeme;
        TokenType type;
        std::string type_str(){
            switch(type){
                s_expr: return "s_expr";
                func: return "func";
                global_var: return "global_var";
                local_var: return "local_var";
                cycle: return "cycle";
                oper: return "oper";
                comment: return "comment";
                other: return "other";
                forx: return "forx";
            }
            return "NONE";
        }
    };

    Token getTokens(std::string lexem);
    TokenType getTokenType(std::string lexem);

private:
    std::string *lexems;
    Token *tokens;
};



#endif // LEXER_H
