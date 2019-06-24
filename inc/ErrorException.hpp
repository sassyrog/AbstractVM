/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 08:16:47 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 08:29:53 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROREXCEPTION_HPP
#define ERROREXCEPTION_HPP

#include <cmath>
#include <fstream>
#include <iostream>

class ErrorException : public std::exception {
   private:
    std::string _exc;

   public:
    ErrorException();
    ErrorException(std::string);
    ErrorException(ErrorException const &);
    ErrorException &operator=(ErrorException const &);
    virtual const char *what() const throw();
    virtual ~ErrorException();
};

#endif  //ERROREXCEPTION_HPP