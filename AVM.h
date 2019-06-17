/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:22:28 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/17 12:52:31 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_H
#define AVM_H

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include "IOperand.hpp"

typedef struct S_AVM {
    std::string command;
    eOperandType type;
    std::string value;
} T_AVM;

#endif  //AVM_H