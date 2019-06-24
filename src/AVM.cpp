/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/24 10:18:41 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AVM.hpp"

void trim(std::string& str) {
    while (str.compare(0, 1, " ") == 0)
        str.erase(str.begin());  // remove leading whitespaces
    while (str.size() > 0 && str.compare(str.size() - 1, 1, " ") == 0)
        str.erase(str.end() - 1);  // remove trailing whitespaces
}

AVM::AVM() {
    this->_parser = new Parser();
    this->init();
}

AVM::AVM(std::string file) {
    this->_parser = new Parser();
    try {
        trim(file);
        if (std::regex_match(file, std::regex(".*?\\.avm"))) {
            this->initFile(file);
        } else {
            throw ErrorException("(" + file + ") File must have .avm extension and be a valid file");
        }
    } catch (const ErrorException& e) {
        std::cerr << e.what() << '\n';
    }
}

AVM::~AVM() {
    delete _parser;
}

AVM::AVM(AVM const& copy) {
    *this = copy;
};

AVM& AVM::operator=(AVM const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void AVM::init(void) {
    try {
        int lineCount = 0;
        std::regex actRe(
            "(\\W+|^)(push|assert|min|max)\\W+((int(8|16|32)|double|float)(\\([-0-9.fd]*\\)))(\\W+;.*?$|$)");
        std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump|exit)(\\W+;.*?$|$)");
        std::regex commRe("(\\W+|^)(;)((.*)(\\S+|$))");

        while (1) {
            std::getline(std::cin, this->_command);
            trim(_command);
            lineCount++;
            if (_command == ";;") {
                if (_parser->getExit()) {
                    _parser->eval(false);
                    break;
                } else {
                    throw ErrorException("No last exit command");
                }
                _command = "";
                continue;
            }
            if (std::regex_match(_command, actRe)) {
                new Parser(_command, 1, lineCount);
            } else if (std::regex_match(_command, mathRe)) {
                if (_command == "exit")
                    _parser->setExit(true);
                new Parser(_command, 2, lineCount);
            } else if (std::regex_match(_command, commRe)) {
                new Parser(_command, 3, lineCount);
            } else {
                new Parser(_command, -1, lineCount);
            }
        }
    } catch (const ErrorException& e) {
        std::cerr << e.what() << '\n';
    }
}

void AVM::initFile(std::string file) {
    std::ifstream ifs(file);
    if (ifs.fail()) {
        std::cout << "\033[31mFailed to open file " << file << "\033[0m" << std::endl;
        return;
    }

    try {
        int lineCount = 0;
        bool hasExit = false;
        std::string tempCmd;

        std::regex actRe(
            "(\\W+|^)(push|assert|min|max)\\W+((int(8|16|32)|double|float)(\\([-0-9.fd]*\\)))(\\W+;.*?$|$)");
        std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump|exit)(\\W+;.*?$|$)");
        std::regex commRe("(\\W+|^)(;)((.*)(\\S+|$))");
        while (std::getline(ifs, this->_command)) {
            trim(_command);
            if (_command != "")
                tempCmd = _command;
            lineCount++;
            if (_parser->getExit())
                break;
            if (std::regex_match(_command, actRe)) {
                new Parser(_command, 1, lineCount);
            } else if (std::regex_match(_command, mathRe)) {
                hasExit = (_command == "exit") ? true : false;
                new Parser(_command, 2, lineCount);
            } else if (std::regex_match(_command, commRe)) {
                new Parser(_command, 3, lineCount);
            } else {
                new Parser(_command, -1, lineCount);
            }
        }
        if (hasExit || tempCmd == "exit")
            _parser->eval(true);
        else {
            throw ErrorException("No last exit command");
        }
    } catch (const ErrorException& e) {
        std::cerr << e.what() << '\n';
    }
}