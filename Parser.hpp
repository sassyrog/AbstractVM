/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:24:31 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/18 13:49:25 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Lexer.hpp"

class Parser {
   private:
    static Lexer lexer;

   public:
    class ParserException : std::exception {
       public:
        ParserException(void);
        ParserException(ParserException const &);
        ParserException &operator=(ParserException const &);
        virtual const char *what() const throw();
    };

    Parser(std::string);
    Parser(Parser const &);
    Parser &operator=(Parser const &);
    ~Parser();
};

#endif  //PARSER_HPP