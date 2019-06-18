/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:37:41 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 13:49:09 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(std::string expr) {
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

Parser::~Parser() {}

Parser::Parser(Parser const& copy) {
    *this = copy;
};

Parser& Parser::operator=(Parser const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}