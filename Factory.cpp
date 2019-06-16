/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:44:50 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 15:08:57 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory() {
    creators[Int8] = &Factory::createInt8;
    creators[Int16] = &Factory::createInt16;
    creators[Int32] = &Factory::createInt32;
    creators[Float] = &Factory::createFloat;
    creators[Double] = &Factory::createDouble;
}

IOperand const* Factory::createOperand(eOperandType type, std::string const& value) const {
    Creators::const_iterator it;
    IOperand const* io;

    it = this->creators.find(type);
    if (it != creators.end()) {
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

Factory::FactoryException& Factory::FactoryException::operator=(Factory::FactoryException const& rhs) {
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
    return (new Operands<int8_t>());
};
IOperand const* Factory::createInt16(std::string const& value) const {
    return (new Operands<int16_t>());
};
IOperand const* Factory::createInt32(std::string const& value) const {
    return (new Operands<int>());
};
IOperand const* Factory::createFloat(std::string const& value) const {
    return (new Operands<float>());
};
IOperand const* Factory::createDouble(std::string const& value) const {
    return (new Operands<double>());
};
