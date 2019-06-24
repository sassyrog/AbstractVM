/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:24:31 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 08:25:41 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Factory.hpp"
#include "Lexer.hpp"

class Parser {
    typedef void (Parser::*F)(void);
    typedef std::map<LexE, F> lexFunctions;

   private:
    static Lexer _lexer;
    static std::vector<const IOperand *> _stack;
    static bool _exit;
    static bool _isFile;
    std::vector<LexerT> _lexers;
    LexerT _currLex;
    Factory _factory;
    lexFunctions _lexFuncs;

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
    void pInvalid();

   public:
    class ParserException : public ErrorException {
       private:
        std::string _exc;

       public:
        ParserException(std::string);
        ParserException(ParserException const &);
        ParserException &operator=(ParserException const &);
        virtual const char *what() const throw();
    };

    Parser();
    Parser(std::string, short int, int);
    Parser(Parser const &);
    Parser &operator=(Parser const &);
    ~Parser();
    void eval(bool);
    bool getExit();
};

#endif  //PARSER_HPP