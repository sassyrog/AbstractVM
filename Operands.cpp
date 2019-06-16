/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:45:36 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 10:45:43 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operands.hpp"

Operands::Operands() {}

Operands::OperandsException::OperandsException() {}

Operands::OperandsException::OperandsException(Operands::OperandsException const& copy) {
    *this = copy;
}

const char* Operands::OperandsException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
}

Operands::OperandsException& Operands::OperandsException::operator=(Operands::OperandsException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

Operands::~Operands() {}

Operands::Operands(Operands const& copy) {
    *this = copy;
};

Operands& Operands::operator=(Operands const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}