/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:10:09 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 21:39:59 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"

class Int8 {
   private:
   public:
    class Int8Exception : std::exception {
       public:
        Int8Exception(void);
        Int8Exception(Int8Exception const&);
        Int8Exception& operator=(Int8Exception const&);
        virtual const char* what() const throw();
    };

    Int8();
    Int8(Int8 const&);
    Int8& operator=(Int8 const&);
    ~Int8();

    int getPrecision(void) const;
    Int8 const* operator+(Int8 const& rhs) const;
    Int8 const* operator-(Int8 const& rhs) const;
    Int8 const* operator*(Int8 const& rhs) const;
    Int8 const* operator/(Int8 const& rhs) const;
    Int8 const* operator%(Int8 const& rhs) const;
    std::string const& toString(void) const;
};

#endif  //INT8_HPP