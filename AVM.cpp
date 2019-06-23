/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:00:45 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/23 15:52:57 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM.hpp"

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
            throw AVM::AVMException("File must .avm and be a valid file");
        }
    } catch (const AVM::AVMException& e) {
        std::cerr << e.what() << '\n';
    }
}

AVM::AVMException::AVMException() : _exc("AVM Exception") {}
AVM::AVMException::AVMException(std::string exc) {
    this->_exc = "\033[31m" + exc + "\033[0m";
}

AVM::AVMException::AVMException(AVM::AVMException const& copy) {
    *this = copy;
}

const char* AVM::AVMException::what() const throw() {
    return (this->_exc.c_str());
}

AVM::AVMException& AVM::AVMException::operator=(AVM::AVMException const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

AVM::AVMException::~AVMException() {}

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
    int lineCount = 0;

    std::regex actRe(
        "(\\W+|^)(push|assert)\\W+((int(8|16|32)|double|float)(\\([-0-9.fd]*\\)))(\\W+;.*?$|$)");
    std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump|exit)(\\W+;.*?$|$)");
    std::regex commRe("(\\W+|^)(;)((.*)(\\S+|$))");

    while (1) {
        std::getline(std::cin, this->_command);
        trim(_command);
        lineCount++;
        if (_command == ";;") {
            _parser->eval(false);
            if (_parser->getExit())
                break;
            _command = "";
            continue;
        }
        if (std::regex_match(_command, actRe)) {
            new Parser(_command, 1, lineCount);
        } else if (std::regex_match(_command, mathRe)) {
            new Parser(_command, 2, lineCount);
        } else if (std::regex_match(_command, commRe)) {
            new Parser(_command, 3, lineCount);
        } else {
            new Parser(_command, -1, lineCount);
        }
    }
}

void AVM::initFile(std::string file) {
    std::ifstream ifs(file);
    if (ifs.fail()) {
        std::cout << "\033[31mFailed to open file " << file << "\033[0m" << std::endl;
        return;
    }

    int lineCount = 0;
    bool hasExit = false;

    std::regex actRe(
        "(\\W+|^)(push|assert)\\W+((int(8|16|32)|double|float)(\\([-0-9.fd]*\\)))(\\W+;.*?$|$)");
    std::regex mathRe("(\\W+|^)(pop|add|mul|sub|div|mod|print|dump|exit)(\\W+;.*?$|$)");
    std::regex commRe("(\\W+|^)(;)((.*)(\\S+|$))");
    while (std::getline(ifs, this->_command)) {
        trim(_command);
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
    if (hasExit)
        _parser->eval(true);
}