/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:24:31 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 14:39:09 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Lexer.hpp"

class Parser {
    typedef void (Parser::*F)(void);
    typedef std::map<LexE, F> lexFunctions;

   private:
    static Lexer _lexer;
    std::vector<LexerT> _lexers;
    // std::vector<std::function<void(int)>> _toExecute;
    lexFunctions _lexFuncs;
    std::vector<IOperand *> _stack;

    void pDump();
    void pPush();
    void pPop();
    void pAssert();
    void pAdd();
    void pSub();
    void pMul();
    void pDiv();
    void pMod();
    void pComment();
    void pPrint();
    void pExit();
    void pExecute();

   public:
    class ParserException : std::exception {
       public:
        ParserException(void);
        ParserException(ParserException const &);
        ParserException &operator=(ParserException const &);
        virtual const char *what() const throw();
    };

    Parser();
    Parser(std::string, short int, int);
    Parser(Parser const &);
    Parser &operator=(Parser const &);
    ~Parser();
    void eval();
};

#endif  //PARSER_HPP