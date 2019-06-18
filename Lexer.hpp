/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:31:18 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 12:05:31 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "IOperand.hpp"

typedef enum {
    DUMP,
    PUSH,
    POP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    COMMENT,
    PRINT,
    EXIT,
    EXEC
} LexE;

typedef struct LexerS {
    LexE lexE;
    eOperandType type;
    std::string value;
    int line;
} LexerT;

class Lexer {
   private:
    std::vector<LexerT> _lexers;
    std::map<std::string, LexE> _lexMap;
    std::map<std::string, eOperandType> _operandMap;

   public:
    class LexerException : std::exception {
       public:
        LexerException(void);
        LexerException(LexerException const &);
        LexerException &operator=(LexerException const &);
        virtual const char *what() const throw();
    };

    Lexer();
    Lexer(Lexer const &);
    Lexer &operator=(Lexer const &);
    ~Lexer();
    void lexExpression(std::string, short int, int);
};

#endif  //LEXER_HPP