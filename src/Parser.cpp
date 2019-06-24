/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:37:41 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 11:02:24 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Parser.hpp"

Lexer Parser::_lexer;
std::vector<const IOperand*> Parser::_stack = {};
bool Parser::_exit = false;
bool Parser::_isFile = false;

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
    _lexFuncs[INVALID] = &Parser::pInvalid;
    _lexFuncs[MIN] = &Parser::pMin;
    _lexFuncs[MAX] = &Parser::pMax;
    this->_lexers = _lexer.getLexers();
}

Parser::Parser(std::string expr, short int exprType, int line) {
    this->_lexer.lexExpression(expr, exprType, line);
    this->_lexers = _lexer.getLexers();
}

Parser::~Parser() {
    for (std::vector<const IOperand*>::iterator i = _stack.end(); i-- != _stack.begin();) {
        delete *i;
    }
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
    for (std::vector<const IOperand*>::iterator i = _stack.end(); i-- != _stack.begin();) {
        std::cout << "\033[32m" << (*i)->toString() << "\033[0m" << std::endl;
    }
}
void Parser::pPush() {
    const IOperand* tmpIop = _factory.createOperand(_currLex.type, _currLex.value);
    if (tmpIop != nullptr)
        this->_stack.push_back(tmpIop);
    else {
        delete tmpIop;
        this->_exit = (this->_isFile) ? false : true;
    }
}
void Parser::pPop() {
    if (_stack.size() < 1)
        throw ErrorException("Can't pop on an empty stack");
    else {
        _stack.erase(_stack.end() - 1);
    }
}
void Parser::pAssert() {
    if (_stack.size() > 0) {
        const IOperand* tmpIop = _factory.createOperand(_currLex.type, _currLex.value);
        const IOperand* tmpIop2 = _stack.back();
        if (tmpIop->getType() != tmpIop2->getType())
            throw ErrorException("Assertion failed because of different types");
        if (tmpIop->toString() != tmpIop2->toString())
            throw ErrorException("Assertion failed because of different values");
        delete tmpIop;
    } else {
        throw ErrorException("Can't assert on empty stack");
    }
}
void Parser::pAdd() {
    if (_stack.size() > 1) {
        const IOperand* op1 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* op2 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* tmpIop = *op1 + *op2;
        if (tmpIop != nullptr)
            this->_stack.push_back(tmpIop);
        else {
            delete tmpIop;
            this->_exit = (this->_isFile) ? false : true;
        }
        delete op1;
        delete op2;
    } else {
        throw ErrorException("Stack must have at least two items to add");
    }
}
void Parser::pSub() {
    if (_stack.size() > 1) {
        const IOperand* op1 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* op2 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* tmpIop = *op1 - *op2;
        if (tmpIop != nullptr)
            this->_stack.push_back(tmpIop);
        else {
            delete tmpIop;
            this->_exit = (this->_isFile) ? false : true;
        }
        delete op1;
        delete op2;
    } else {
        throw ErrorException("Stack must have at least two items to sub");
    }
}
void Parser::pMul() {
    if (_stack.size() > 1) {
        const IOperand* op1 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* op2 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* tmpIop = *op1 * *op2;
        if (tmpIop != nullptr)
            this->_stack.push_back(tmpIop);
        else {
            delete tmpIop;
            this->_exit = (this->_isFile) ? false : true;
        }
        delete op1;
        delete op2;
    } else {
        throw ErrorException("Stack must have at least two items to mul");
    }
}
void Parser::pDiv() {
    if (_stack.size() > 1) {
        const IOperand* op1 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* op2 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* tmpIop = *op1 / *op2;
        if (tmpIop != nullptr)
            this->_stack.push_back(tmpIop);
        else {
            delete tmpIop;
            this->_exit = (this->_isFile) ? false : true;
        }
        delete op1;
        delete op2;
    } else {
        throw ErrorException("Stack must have at least two items to div");
    }
}
void Parser::pMod() {
    if (_stack.size() > 1) {
        const IOperand* op1 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* op2 = *(_stack.begin());
        _stack.erase(_stack.begin());
        const IOperand* tmpIop = *op1 % *op2;
        if (tmpIop != nullptr)
            this->_stack.push_back(tmpIop);
        else {
            delete tmpIop;
            this->_exit = (this->_isFile) ? false : true;
        }
        delete op1;
        delete op2;
    } else {
        throw ErrorException("Stack must have at least two items to mod");
    }
}
void Parser::pComment() {
    // std::cout << "---> ;" << _currLex.value << std::endl;
}

void Parser::pMin() {
    if (_stack.size() > 0) {
        const IOperand* tmpIop = _factory.createOperand(_currLex.type, _currLex.value);
        const IOperand* tmpIop2 = _stack.back();
        if (tmpIop->getType() != tmpIop2->getType())
            throw ErrorException("Min check failed because of different types");
        if (std::stold(tmpIop->toString()) < std::stold(tmpIop2->toString())) {
            this->pPop();
            _stack.push_back(tmpIop);
        } else {
            delete tmpIop;
        }
    } else {
        throw ErrorException("Can't assert on empty stack");
    }
}

void Parser::pMax() {
    if (_stack.size() > 0) {
        const IOperand* tmpIop = _factory.createOperand(_currLex.type, _currLex.value);
        const IOperand* tmpIop2 = _stack.back();
        if (tmpIop->getType() != tmpIop2->getType())
            throw ErrorException("Max check failed because of different types");
        if (std::stold(tmpIop->toString()) < std::stold(tmpIop2->toString())) {
            this->pPop();
            _stack.push_back(tmpIop);
        } else {
            delete tmpIop;
        }
    } else {
        throw ErrorException("Can't assert on empty stack");
    }
}

void Parser::pPrint() {
    if (_stack.size() > 0) {
        const IOperand* tmpIop = _stack.back();
        if (tmpIop->getType() != Int8)
            throw ErrorException("Can only print 8 bit integers aka chars");
        std::cout << static_cast<char>(std::stoi(tmpIop->toString())) << std::endl;
    } else {
        throw ErrorException("Can't print if the stack is empty");
    }
}
void Parser::pExit() {
    this->_exit = true;
}
void Parser::pExecute() {
    this->eval(true);
}
void Parser::pInvalid() {
    std::stringstream s;
    s << "line " << _currLex.line << " : Invalid syntax";
    throw ErrorException(s.str());
}

bool Parser::getExit() {
    return this->_exit;
}

void Parser::setExit(bool exit) {
    this->_exit = exit;
};

void Parser::eval(bool isfile) {
    this->_isFile = isfile;
    if (!_isFile) {
        try {
            this->_lexers = _lexer.getLexers();
            for (unsigned long i = 0; i < _lexers.size(); i++) {
                lexFunctions::iterator it;
                it = this->_lexFuncs.find(_lexers[i].lexE);
                if (it != _lexFuncs.end()) {
                    _currLex = _lexers[i];
                    (this->*it->second)();
                }
            }
            this->_lexer.clearLexers();
        } catch (ErrorException& e) {
            std::cerr << e.what() << '\n';
            this->_lexer.clearLexers();
            this->_exit = (this->_isFile) ? false : true;
        }
    } else {
        this->_lexers = _lexer.getLexers();
        for (unsigned long i = 0; i < _lexers.size(); i++) {
            try {
                lexFunctions::iterator it;
                it = this->_lexFuncs.find(_lexers[i].lexE);
                if (it != _lexFuncs.end()) {
                    _currLex = _lexers[i];
                    (this->*it->second)();
                }
            } catch (const ErrorException& e) {
                std::cerr << e.what() << '\n';
            }
        }
    }
}