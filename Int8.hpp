/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:10:09 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 12:10:31 by Roger Ndaba      ###   ########.fr       */
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
        Int8Exception(Int8Exception const &);
        Int8Exception &operator=(Int8Exception const &);
        virtual const char *what() const throw();
    };

    Int8();
    Int8(Int8 const &);
    Int8 &operator=(Int8 const &);
    ~Int8();
};

#endif  //INT8_HPP