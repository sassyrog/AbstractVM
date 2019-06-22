/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:08:41 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/22 16:52:04 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "IOperand.hpp"
class Factory {
    typedef IOperand const *(Factory::*F)(std::string const &value) const;
    typedef std::map<eOperandType, F> Creators;

   private:
    Creators _creators;

    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;

   public:
    class FactoryException : std::exception {
       public:
        FactoryException(void);
        FactoryException(FactoryException const &);
        FactoryException &operator=(FactoryException const &);
        virtual const char *what() const throw();
    };

    Factory();
    Factory(Factory const &);
    Factory &operator=(Factory const &);
    ~Factory();

    IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif  //FACTORY_HPP