/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 19:01:25 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM.hpp"

AVM::AVM() {}

AVM::AVMException::AVMException() {}

AVM::AVMException::AVMException(AVM::AVMException const& copy) {
    *this = copy;
}

const char* AVM::AVMException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
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