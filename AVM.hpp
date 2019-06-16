/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:01 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/16 19:03:40 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
#define AVM_HPP

#include <fstream>
#include "IOperand.hpp"

class AVM {
   private:
   public:
    class AVMException : std::exception {
       public:
        AVMException(void);
        AVMException(AVMException const &);
        AVMException &operator=(AVMException const &);
        virtual const char *what() const throw();
    };

    AVM();
    AVM(AVM const &);
    AVM &operator=(AVM const &);
    ~AVM();
};

#endif  //AVM_HPP