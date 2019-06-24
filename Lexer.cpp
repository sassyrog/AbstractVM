/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:32:09 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 08:52:52 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
// #include ""

Lexer::Lexer() {
    _lexMap["dump"] = LexE::DUMP;
    _lexMap["push"] = LexE::PUSH;
    _lexMap["pop"] = LexE::POP;
    _lexMap["assert"] = LexE::ASSERT;
    _lexMap["add"] = LexE::ADD;
    _lexMap["sub"] = LexE::SUB;
    _lexMap["mul"] = LexE::MUL;
    _lexMap["div"] = LexE::DIV;
    _lexMap["mod"] = LexE::MOD;
    _lexMap[";"] = LexE::COMMENT;
    _lexMap["print"] = LexE::PRINT;
    _lexMap["exit"] = LexE::EXIT;
    _lexMap[";;"] = LexE::EXEC;
    _lexMap["invalid"] = LexE::INVALID;
    _lexMap["min"] = LexE::MIN;
    _lexMap["max"] = LexE::MAX;

    _operandMap["int8"] = eOperandType::Int8;
    _operandMap["int16"] = eOperandType::Int16;
    _operandMap["int32"] = eOperandType::Int32;
    _operandMap["float"] = eOperandType::Float;
    _operandMap["double"] = eOperandType::Double;
}

Lexer::~Lexer() {}

Lexer::Lexer(Lexer const& copy) {
    *this = copy;
};

Lexer& Lexer::operator=(Lexer const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void Lexer::lexExpression(std::string exp, short int reg, int line) {
    LexerT lexerT;
    if (reg == 1) {
        size_t beg, pos = 0;
        std::vector<std::string> strParts;
        while ((beg = exp.find_first_not_of(std::string(" ()"), pos)) != std::string::npos) {
            pos = exp.find_first_of(std::string(" ()"), beg + 1);
            strParts.push_back(exp.substr(beg, pos - beg));
        }
        lexerT.lexE = _lexMap[strParts[0]];
        lexerT.line = line;
        lexerT.type = _operandMap[strParts[1]];
        lexerT.value = strParts[2];
        _lexers.push_back(lexerT);
    } else if (reg == 2) {
        std::string tempStr = (exp.find(' ') != std::string::npos)
                                  ? exp.substr(0, exp.find(' '))
                                  : exp;
        lexerT.lexE = _lexMap[tempStr];
        _lexers.push_back(lexerT);
    } else if (reg == 3) {
        lexerT.lexE = _lexMap[";"];
        lexerT.value = exp;
        _lexers.push_back(lexerT);
    } else if (reg == -1 && exp != "") {
        lexerT.lexE = _lexMap["invalid"];
        lexerT.line = line;
        lexerT.value = exp;
        _lexers.push_back(lexerT);
    }
}

std::vector<LexerT>& Lexer::getLexers() {
    return this->_lexers;
}

void Lexer::clearLexers() {
    this->_lexers.clear();
}