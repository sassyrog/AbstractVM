/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:01 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/23 11:14:39 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
#define AVM_HPP

#include "Parser.hpp"

class AVM {
   private:
    std::string _command;
    Parser *_parser;

   public:
    class AVMException : std::exception {
       private:
        std::string _exc;

       public:
        AVMException(void);
        AVMException(std::string);
        AVMException(AVMException const &);
        AVMException &operator=(AVMException const &);
        virtual const char *what() const throw();
        virtual ~AVMException();
    };

    AVM();
    // AVM(std::string);
    AVM(AVM const &);
    AVM &operator=(AVM const &);
    ~AVM();

    void init();
    void initFile();
};

void trim(std::string &);

#endif  //AVM_HPP