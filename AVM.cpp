/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/22 19:59:47 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM.hpp"

AVM::AVM() {
    this->_parser = new Parser();
    this->init();
    // _parser->eval();
}

AVM::AVMException::AVMException() : _exc("AVM Exception") {}
AVM::AVMException::AVMException(std::string exc) : _exc(exc) {}

AVM::AVMException::AVMException(AVM::AVMException const& copy) {
    *this = copy;
}

const char* AVM::AVMException::what() const throw() {
    return (this->_exc.c_str());
}

AVM::AVMException& AVM::AVMException::operator=(AVM::AVMException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

AVM::AVMException::~AVMException() {}

AVM::~AVM() {
    delete _parser;
}

AVM::AVM(AVM const& copy) {
    *this = copy;
};

AVM& AVM::operator=(AVM const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void AVM::init(void) {
    int lineCount = 0;

    std::regex actRe(
        "(\\W+|^)(push|assert)\\W+((int(8|16|32)|double|float)(\\([-0-9.fd]*\\)))(\\W+;.*?$|$)");
    std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump|exit)(\\W+;.*?$|$)");
    std::regex commRe("(\\W+|^)(;)((.*)(\\S+|$))");

    while (1) {
        std::getline(std::cin, this->_command);
        lineCount++;
        if (_command == ";;") {
            _parser->eval();
            if (_parser->getExit())
                break;
            _command = "";
            continue;
        }
        if (std::regex_match(_command, actRe)) {
            new Parser(_command, 1, lineCount);
        } else if (std::regex_match(_command, mathRe)) {
            new Parser(_command, 2, lineCount);
        } else if (std::regex_match(_command, commRe)) {
            new Parser(_command, 3, lineCount);
        } else {
            new Parser(_command, -1, lineCount);
        }
    }
}