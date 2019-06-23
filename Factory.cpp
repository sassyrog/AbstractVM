/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:44:50 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/23 13:06:45 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operands.hpp"

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

    try {
        it = this->_creators.find(type);
        if (it != _creators.end()) {
            io = (this->*it->second)(value);
        }
    } catch (const Operands<char>::OperandsException& e) {
        std::cerr << "INT8 " << e.what() << "\n";
    } catch (const Operands<short>::OperandsException& e) {
        std::cerr << "INT16 " << e.what() << "\n";
    } catch (const Operands<int>::OperandsException& e) {
        std::cerr << "INT32 " << e.what() << "\n";
    } catch (const Operands<float>::OperandsException& e) {
        std::cerr << "FLOAT " << e.what() << "\n";
    } catch (const Operands<double>::OperandsException& e) {
        std::cerr << "DOUBLE " << e.what() << "\n";
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

Factory::~Factory(void) {
}

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
