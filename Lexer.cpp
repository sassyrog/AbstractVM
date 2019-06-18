/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:32:09 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 08:59:54 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer() {}

Lexer::LexerException::LexerException() {}

Lexer::LexerException::LexerException(Lexer::LexerException const& copy) {
    *this = copy;
}

const char* Lexer::LexerException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
}

Lexer::LexerException& Lexer::LexerException::operator=(Lexer::LexerException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
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
}