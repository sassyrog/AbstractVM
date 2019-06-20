/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:44:50 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/20 10:05:31 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory() {
    _creators[Int8] = &Factory::createInt8;
    _creators[Int16] = &Factory::createInt16;
    _creators[Int32] = &Factory::createInt32;
    _creators[Float] = &Factory::createFloat;
    _creators[Double] = &Factory::createDouble;
}

IOperand const* Factory::createOperand(eOperandType type, std::string const& value) const {
    Creators::const_iterator it;
    IOperand const* io = nullptr;

    it = this->_creators.find(type);
    if (it != _creators.end()) {
        io = (it->second()(value));
    }
    return io;
};

Factory::FactoryException::FactoryException() {}

Factory::FactoryException::FactoryException(Factory::FactoryException const& copy) {
    *this = copy;
}

const char* Factory::FactoryException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
}

Factory::FactoryException&
Factory::FactoryException::operator=(Factory::FactoryException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

Factory::~Factory(void) {}

Factory::Factory(Factory const& copy) {
    *this = copy;
};

Factory& Factory::operator=(Factory const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

IOperand const* Factory::createInt8(std::string const& value) const {
    return (new Operands<char>(Int8, value, 0));
};
IOperand const* Factory::createInt16(std::string const& value) const {
    return (new Operands<short>(Int16, value, 0));
};
IOperand const* Factory::createInt32(std::string const& value) const {
    return (new Operands<int>(Int32, value, 0));
};
IOperand const* Factory::createFloat(std::string const& value) const {
    return (new Operands<float>(Float, value, 7));
};
IOperand const* Factory::createDouble(std::string const& value) const {
    return (new Operands<double>(Double, value, 15));
};
