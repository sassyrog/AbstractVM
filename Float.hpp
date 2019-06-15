/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:09:29 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 21:39:35 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
#define FLOAT_HPP
#include "IOperand.hpp"

class Float : public IOperand {
   private:
   public:
    class FloatException : std::exception {
       public:
        FloatException(void);
        FloatException(FloatException const&);
        FloatException& operator=(FloatException const&);
        virtual const char* what() const throw();
    };

    Float();
    Float(Float const&);
    Float& operator=(Float const&);
    ~Float();

    int getPrecision(void) const;
    Float const* operator+(Float const& rhs) const;
    Float const* operator-(Float const& rhs) const;
    Float const* operator*(Float const& rhs) const;
    Float const* operator/(Float const& rhs) const;
    Float const* operator%(Float const& rhs) const;
    std::string const& toString(void) const;
};

#endif  //FLOAT_HPP