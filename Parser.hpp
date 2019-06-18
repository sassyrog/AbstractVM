/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:24:31 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 14:18:53 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Lexer.hpp"

typedef void (Parser::*F)(void) const;
typedef std::map<LexE, F> lexFunctions;

class Parser {
   private:
    static Lexer _lexer;
    std::vector<LexerT> _lexers;
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
};

#endif  //PARSER_HPP