/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:58:28 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 11:39:06 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>
#include <vector>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Doble
};

class IOperand {
   public:
    virtual int getPrecision(void) const = 0;                          // Precision of the type of the instance
    virtual eOperandType getType(void) const = 0;                      // Type of the instance
    virtual IOperand const* operator+(IOperand const& rhs) const = 0;  // Sum
    virtual IOperand const* operator-(IOperand const& rhs) const = 0;  // Difference
    virtual IOperand const* operator*(IOperand const& rhs) const = 0;  // Product
    virtual IOperand const* operator/(IOperand const& rhs) const = 0;  // Quotient
    virtual IOperand const* operator%(IOperand const& rhs) const = 0;  // Modulo
    virtual std::string const& toString(void) const = 0;               // String representation of the instance
    virtual ~IOperand(void) {}
};
#endif  // !IOPERAND_HPP