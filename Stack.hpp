/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:25:52 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 21:28:44 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Double.hpp"
#include "Float.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int8.hpp"

class Stack {
   private:
    std::vector<IOperand *> _types;

   public:
    class StackException : std::exception {
       public:
        StackException(void);
        StackException(StackException const &);
        StackException &operator=(StackException const &);
        virtual const char *what() const throw();
    };

    Stack();
    Stack(Stack const &);
    Stack &operator=(Stack const &);
    ~Stack();
};

#endif  //STACK_HPP