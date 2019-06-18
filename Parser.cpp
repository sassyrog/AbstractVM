/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:37:41 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 15:15:10 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Lexer Parser::_lexer;

Parser::Parser() {
    _lexFuncs[DUMP] = &Parser::pDump;
    _lexFuncs[PUSH] = &Parser::pPush;
    _lexFuncs[POP] = &Parser::pPop;
    _lexFuncs[ASSERT] = &Parser::pAssert;
    _lexFuncs[ADD] = &Parser::pAdd;
    _lexFuncs[SUB] = &Parser::pSub;
    _lexFuncs[MUL] = &Parser::pMul;
    _lexFuncs[DIV] = &Parser::pDiv;
    _lexFuncs[MOD] = &Parser::pMod;
    _lexFuncs[COMMENT] = &Parser::pComment;
    _lexFuncs[PRINT] = &Parser::pPrint;
    _lexFuncs[EXIT] = &Parser::pExit;
    _lexFuncs[EXEC] = &Parser::pExecute;
    this->_lexers = _lexer.getLexers();
}

Parser::Parser(std::string expr, short int exprType, int line) {
    this->_lexer.lexExpression(expr, exprType, line);
    this->_lexers = _lexer.getLexers();
}

Parser::ParserException::ParserException() {}

Parser::ParserException::ParserException(Parser::ParserException const& copy) {
    *this = copy;
}

const char* Parser::ParserException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
}

Parser::ParserException& Parser::ParserException::operator=(Parser::ParserException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

Parser::~Parser() {
    std::cout << "----->" << std::endl;
}

Parser::Parser(Parser const& copy) {
    *this = copy;
};

Parser& Parser::operator=(Parser const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void Parser::pDump() {
}
void Parser::pPush() {
    std::cout << "Hello there! - JG Zuma" << std::endl;
}
void Parser::pPop() {
    if (_stack.size() < 1)
        throw Parser::ParserException();
    std::cout << "pop------------------>" << std::endl;
}
void Parser::pAssert() {
}
void Parser::pAdd() {
}
void Parser::pSub() {
}
void Parser::pMul() {
}
void Parser::pDiv() {
}
void Parser::pMod() {
}
void Parser::pComment() {
}
void Parser::pPrint() {
}
void Parser::pExit() {
}
void Parser::pExecute() {
}

void Parser::eval() {
    try {
        this->_lexers = _lexer.getLexers();
        for (unsigned long i = 0; i < _lexers.size(); i++) {
            lexFunctions::iterator it;
            it = this->_lexFuncs.find(_lexers[i].lexE);
            if (it != _lexFuncs.end()) {
                (this->*it->second)();
            }
        }
    } catch (Parser::ParserException& e) {
        std::cerr << e.what() << '\n';
    }
}