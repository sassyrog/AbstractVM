/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:46:02 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 14:16:29 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDS_HPP
#define OPERANDS_HPP

#include "IOperand.hpp"

template <typename T>
class Operands : public IOperand {
   private:
    T _val;
    eOperandType _type;
    std::string _string;

   public:
    class OperandsException : std::exception {
       public:
        OperandsException(std::string exc) : _exc(exc){};
        OperandsException(OperandsException const& copy) : _exc(copy._exc) {
            *this = copy;
            return;
        };
        OperandsException& operator=(OperandsException const& rhs) {
            if (this != &rhs) {
                this->_exc = rhs.getExc();
            }
        };
        std::string getExc(void) {
            return this->_exc;
        }
        const char* what() const throw() {
            return (this->_exc.c_str());
        };

       private:
        std::string _exc;
    };

    Operands(){};
    Operands(Operands const&){};
    Operands& operator=(Operands const&){};
    ~Operands(){};

    int getPrecision(void) const {

    };

    eOperandType getType(void) const {
        return this->_type;
    };
    IOperand const* operator+(IOperand const& rhs) const {

    };
    IOperand const* operator-(IOperand const& rhs) const {

    };
    IOperand const* operator*(IOperand const& rhs) const {

    };
    IOperand const* operator/(IOperand const& rhs) const {

    };
    IOperand const* operator%(IOperand const& rhs) const {

    };
    std::string const& toString(void) const {
        return this->_string;
    };
};

#endif  //OPERANDS_HPP