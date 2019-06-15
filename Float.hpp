/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:09:29 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 12:09:53 by Roger Ndaba      ###   ########.fr       */
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
        FloatException(FloatException const &);
        FloatException &operator=(FloatException const &);
        virtual const char *what() const throw();
    };

    Float();
    Float(Float const &);
    Float &operator=(Float const &);
    ~Float();
};

#endif  //FLOAT_HPP