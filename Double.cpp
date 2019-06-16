/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:34:17 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 08:47:56 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

#include "Double.hpp"

Double::Double() {}

Double::DoubleException::DoubleException() {}

Double::DoubleException::DoubleException(Double::DoubleException const& copy) {
    *this = copy;
}

const char* Double::DoubleException::what() const throw() {
    return ("\033[31mSome Exception\033[0m");
}

Double::DoubleException& Double::DoubleException::operator=(Double::DoubleException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

Double::~Double() {}

Double::Double(Double const& copy) {
    *this = copy;
};

Double& Double::operator=(Double const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

// int getPrecision(void) const {
//     return this->_precision;
// };
Double const* Double::operator+(Double const& rhs) const {

};
Double const* Double::operator-(Double const& rhs) const {

};
Double const* Double::operator*(Double const& rhs) const {

};
Double const* Double::operator/(Double const& rhs) const {

};
Double const* Double::operator%(Double const& rhs) const {

};
// std::string const& toString(void) const {

// };