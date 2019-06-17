/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/17 12:59:40 by Roger Ndaba      ###   ########.fr       */
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
    std::regex act("\\W+(push|assert)\\W+((int(8|16|32)|double|float)(\\([0-9.fd]*\\)))(\\W+|$)");
    // std::regex act("(push|pop|assert)\\W+((int(8|16|32)|double|float)(\\([0-9.fd]*\\)))(\\W+|$)");
    while (1) {
        std::getline(std::cin, this->_command);
        if (std::regex_match(_command, act))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}