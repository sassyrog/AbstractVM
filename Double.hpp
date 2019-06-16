/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:08:13 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 09:30:18 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "IOperand.hpp"

class Double : public IOperand<double> {
   private:
    double _val;

   public:
    class DoubleException : std::exception {
       public:
        DoubleException(void);
        DoubleException(DoubleException const&);
        DoubleException& operator=(DoubleException const&);
        virtual const char* what() const throw();
    };

    Double();
    Double(Double const&);
    Double& operator=(Double const&);
    ~Double();

    int getPrecision(void) const;
    Double const* operator+(Double const& rhs) const;
    Double const* operator-(Double const& rhs) const;
    Double const* operator*(Double const& rhs) const;
    Double const* operator/(Double const& rhs) const;
    Double const* operator%(Double const& rhs) const;
    std::string const& toString(void) const;
};

#endif  //DOUBLE_HPP