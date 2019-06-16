/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:44:50 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 12:44:56 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory() {}

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

Factory::~Factory() {}

Factory::Factory(Factory const& copy) {
    *this = copy;
};

Factory& Factory::operator=(Factory const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}