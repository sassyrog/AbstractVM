/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 08:19:06 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 10:09:26 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ErrorException.hpp"

ErrorException::ErrorException() {}
ErrorException::ErrorException(std::string exc) {
    this->_exc = "\033[31m" + exc + "\033[0m";
}

ErrorException::ErrorException(ErrorException const& copy) {
    *this = copy;
}

const char* ErrorException::what() const throw() {
    return (this->_exc.c_str());
}

ErrorException& ErrorException::operator=(ErrorException const& rhs) {
    if (this != &rhs) {
        this->_exc = rhs._exc;
    }
    return *this;
}

ErrorException::~ErrorException() {
}
