/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:08:13 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 12:08:58 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "IOperand.hpp"

class Double : public IOperand {
   private:
   public:
    class DoubleException : std::exception {
       public:
        DoubleException(void);
        DoubleException(DoubleException const &);
        DoubleException &operator=(DoubleException const &);
        virtual const char *what() const throw();
    };

    Double();
    Double(Double const &);
    Double &operator=(Double const &);
    ~Double();
};

#endif  //DOUBLE_HPP