/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:46:02 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/20 19:37:27 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDS_HPP
#define OPERANDS_HPP

#include "Factory.hpp"
#include "IOperand.hpp"

template <typename T>
class Operands : public IOperand {
   private:
    T _val;
    eOperandType _type;
    std::string _string;
    int _precision;
    Factory _factory;

   public:
    class OperandsException : std::exception {
       public:
        OperandsException(std::string exc) : _exc(exc){};
        OperandsException(OperandsException const& copy) {
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
    Operands(eOperandType type, std::string value, int precision)
        : _precision(precision), _type(type) {
        try {
            if (type < Float) {
                long long tmpV = std::stoll(value);
                if (this->overflowCheck(tmpV, type)) {
                    throw Operands::OperandsException("Overflow");
                }
                this->_val = static_cast<T>(tmpV);
                _string = makeString(_val, _precision);
            } else {
                double tmpV = std::stold(value);
                if (this->overflowCheck(tmpV, type)) {
                    throw Operands::OperandsException("Overflow");
                }
                this->_val = static_cast<T>(tmpV);
                _string = makeString(_val, _precision);
            }

        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return;
    };

    Operands(Operands const& copy) {
        *this = copy;
    };

    Operands& operator=(Operands const& rhs) {
        if (this != &rhs) {
            this->_val = rhs._val;
            this->_precision = rhs._precision;
            this->_type = rhs._type;
            this->_string = rhs._string;
        }
        return *this;
    };

    ~Operands(){};

    int getPrecision(void) const {
        return this->_precision;
    };

    eOperandType getType(void) const {
        return this->_type;
    };

    IOperand const* operator+(IOperand const& rhs) const {
        try {
            eOperandType type = (_type >= rhs.getType()) ? _type : rhs.getType();
            int precision = (_precision >= rhs.getPrecision()) ? _precision : rhs.getPrecision();
            if (type < Float) {
                long long tmpVal = std::stoll(_string) + std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory->createOperand(type, makeString(tmpVal, precision));
            } else {
                double tmpVal = std::stold(_string) + std::stold(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory->createOperand(type, makeString(tmpVal, precision));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return nullptr;
    };
    IOperand const* operator-(IOperand const& rhs) const {

    };
    // IOperand const* operator*(IOperand const& rhs) const {

    // };
    // IOperand const* operator/(IOperand const& rhs) const {

    // };
    // IOperand const* operator%(IOperand const& rhs) const {

    // };
    std::string const& toString(void) const {
        return this->_string;
    };

    bool overflowCheck(T val, eOperandType type) {
        switch (this->type) {
            case 0:
                return (val < CHAR_MIN || val > CHAR_MAX);
            case 1:
                return (val < SHRT_MIN || val > SHRT_MAX);
            case 2:
                return (val < INT_MIN || val > INT_MAX);
            case 3:
                return (val < FLT_MIN || val > FLT_MAX);
            case 4:
                return (val < DBL_MIN || val > DBL_MAX);
        }
        return (false);
    }

    template <typename G>
    std::string makeString(G str, int prec) {
        std::ostringstream ss;
        if (prec)
            ss << std::setprecision(prec) << str;
        else
            ss << str;
        std::string s(ss.str());
        return s;
    }
};

#endif  //OPERANDS_HPP