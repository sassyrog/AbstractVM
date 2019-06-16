/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:58:28 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 09:30:05 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>
#include <vector>

template <class eOperandType>
class IOperand {
   public:
    IOperand();
    IOperand(IOperand const&);
    IOperand& operator=(IOperand const&);
    virtual int getPrecision(void) const = 0;
    virtual eOperandType getType(void) const = 0;
    virtual IOperand const* operator+(IOperand const& rhs) const = 0;
    virtual IOperand const* operator-(IOperand const& rhs) const = 0;
    virtual IOperand const* operator*(IOperand const& rhs) const = 0;
    virtual IOperand const* operator/(IOperand const& rhs) const = 0;
    virtual IOperand const* operator%(IOperand const& rhs) const = 0;
    virtual std::string const& toString(void) const = 0;
    virtual ~IOperand(void) {}
};
#endif  // !IOPERAND_HPP