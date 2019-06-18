/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 11:49:16 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM.hpp"

AVM::AVM() {
    this->init();
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

AVM::~AVM() {}

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
        "(\\W+|^)(push|assert)\\W+((int(8|16|32)|double|\
        float)(\\([0-9.fd]*\\)))(\\W+|$)");
    std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump)(\\W+|$)");
    while (1) {
        std::getline(std::cin, this->_command);
        lineCount++;
        if (std::regex_match(_command, actRe) || std::regex_match(_command, mathRe)) {
            size_t beg, pos = 0;
            while ((beg = _command.find_first_not_of(std::string(" ()"), pos)) != std::string::npos) {
                pos = _command.find_first_of(std::string(" ()"), beg + 1);
                std::cout << _command.substr(beg, pos - beg) << std::endl;
            }
            std::cout << "Yes" << std::endl;
        } else
            std::cout << "line " << lineCount << " - No" << std::endl;
    }
}