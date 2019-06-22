/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:46:02 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/22 20:34:49 by Roger Ndaba      ###   ########.fr       */
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
        OperandsException(const std::string exc) : _exc(exc){};
        const char* what() const throw() {
            return (this->_exc.c_str());
        };

       private:
        std::string _exc;
    };

    Operands(){};
    Operands(eOperandType type, std::string value, int precision)
        : _type(type), _precision(precision) {
        try {
            if (type < Float) {
                long long tmpV = std::stoll(value);
                if (this->overflowCheck(tmpV, type)) {
                    throw Operands::OperandsException("Overflow");
                }
                this->_val = static_cast<T>(tmpV);
                _string = makeString(tmpV, _precision);
            } else {
                double tmpV = std::stold(value);
                if (this->overflowCheck(tmpV, type)) {
                    throw Operands::OperandsException("Overflow");
                }
                this->_val = static_cast<T>(tmpV);
                _string = makeString(tmpV, _precision);
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
            if (type >= Float) {
                double tmpVal = std::stold(_string) + std::stold(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            } else {
                long long tmpVal = std::stoll(_string) + std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    };

    IOperand const* operator-(IOperand const& rhs) const {
        try {
            eOperandType type = (_type >= rhs.getType()) ? _type : rhs.getType();
            int precision = (_precision >= rhs.getPrecision()) ? _precision : rhs.getPrecision();
            if (type >= Float) {
                double tmpVal = std::stold(_string) - std::stold(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            } else {
                long long tmpVal = std::stoll(_string) - std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    };

    IOperand const* operator*(IOperand const& rhs) const {
        try {
            eOperandType type = (_type >= rhs.getType()) ? _type : rhs.getType();
            int precision = (_precision >= rhs.getPrecision()) ? _precision : rhs.getPrecision();
            if (type >= Float) {
                double tmpVal = std::stold(_string) * std::stold(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            } else {
                long long tmpVal = std::stoll(_string) * std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    };

    IOperand const* operator/(IOperand const& rhs) const {
        try {
            eOperandType type = (_type >= rhs.getType()) ? _type : rhs.getType();
            int precision = (_precision >= rhs.getPrecision()) ? _precision : rhs.getPrecision();
            if (type >= Float) {
                double tmpVal = std::stold(_string) / std::stold(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            } else {
                long long tmpVal = std::stoll(_string) / std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    };

    IOperand const* operator%(IOperand const& rhs) const {
        try {
            eOperandType type = (_type >= rhs.getType()) ? _type : rhs.getType();
            int precision = (_precision >= rhs.getPrecision()) ? _precision : rhs.getPrecision();
            if (type >= Float) {
                double tmpVal = fmod(std::stold(_string), std::stold(rhs.toString()));
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            } else {
                long long tmpVal = std::stoll(_string) % std::stoll(rhs.toString());
                if (overflowCheck(tmpVal, type))
                    throw Operands::OperandsException("Overflow");
                return (_factory.createOperand(type, makeString(tmpVal, precision)));
            }
        } catch (const Operands::OperandsException& e) {
            std::cerr << e.what() << '\n';
        }
        return 0;
    };
    std::string const& toString(void) const {
        return this->_string;
    };

    template <typename H>
    bool overflowCheck(H val, eOperandType type) const {
        switch (type) {
            case 0:
                return (val < SCHAR_MIN || val > SCHAR_MAX);
            case 1:
                return (val < SHRT_MIN || val > SHRT_MAX);
            case 2:
                return (val < INT_MIN || val > INT_MAX);
            case 3:
                return (val < -FLT_MAX || val > FLT_MAX);
            case 4:
                return (val < -DBL_MAX || val > DBL_MAX);
        }
        return (false);
    }

    template <typename G>
    std::string makeString(G str, int prec) const {
        std::ostringstream ss(std::stringstream::out);
        if (prec)
            ss << std::setprecision(prec) << str;
        else
            ss << str;
        std::string s(ss.str());
        return s;
    }
};

#endif  //OPERANDS_HPP