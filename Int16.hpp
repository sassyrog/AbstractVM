/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:10:36 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 21:40:13 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
#define INT16_HPP

#include "IOperand.hpp"

class Int16 : public IOperand {
   private:
   public:
    class Int16Exception : std::exception {
       public:
        Int16Exception(void);
        Int16Exception(Int16Exception const&);
        Int16Exception& operator=(Int16Exception const&);
        virtual const char* what() const throw();
    };

    Int16();
    Int16(Int16 const&);
    Int16& operator=(Int16 const&);
    ~Int16();

    int getPrecision(void) const;
    Int16 const* operator+(Int16 const& rhs) const;
    Int16 const* operator-(Int16 const& rhs) const;
    Int16 const* operator*(Int16 const& rhs) const;
    Int16 const* operator/(Int16 const& rhs) const;
    Int16 const* operator%(Int16 const& rhs) const;
    std::string const& toString(void) const;
};

#endif  //INT16_HPP