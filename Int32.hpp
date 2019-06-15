/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:11:14 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 21:40:30 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include "IOperand.hpp"

class Int32 : public IOperand {
   private:
   public:
    class Int32Exception : std::exception {
       public:
        Int32Exception(void);
        Int32Exception(Int32Exception const&);
        Int32Exception& operator=(Int32Exception const&);
        virtual const char* what() const throw();
    };

    Int32();
    Int32(Int32 const&);
    Int32& operator=(Int32 const&);
    ~Int32();

    int getPrecision(void) const;
    Int32 const* operator+(Int32 const& rhs) const;
    Int32 const* operator-(Int32 const& rhs) const;
    Int32 const* operator*(Int32 const& rhs) const;
    Int32 const* operator/(Int32 const& rhs) const;
    Int32 const* operator%(Int32 const& rhs) const;
    std::string const& toString(void) const;
};

#endif  //INT32_HPP