/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbmain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmil.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:26:54 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/15 17:05:16 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

void printlines(std::vector<std::string> lines) {
    for (long i = 0; i < (long)lines.size(); i++) {
        std::string buf;                 // Have a buffer string
        std::stringstream ss(lines[i]);  // Insert the string into a stream
        while (ss >> buf) {
            if (std::regex_match(buf, std::regex("print")))
                attron(COLOR_PAIR(1));
            printw("%s ", buf.c_str());
            refresh();
            attroff(COLOR_PAIR(1));
        }
        printw("\b\n");
    }
}

int main() {
    std::vector<std::string> lines;
    std::string buffer;
    int ch;

    initscr();            /* Start curses mode 		*/
    keypad(stdscr, TRUE); /* We get F1, F2 etc..		*/
    noecho();             /* Don't echo() while we do getch */
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    clear();
    while ((ch = getch())) {
        if (ch == '\n' && !buffer.empty()) {
            lines.push_back(buffer);
            if (buffer == "exit") {
                clear();
                refresh();
                printlines(lines);
                printw(buffer.c_str());
                sleep(10);
                break;
            }
            buffer = "";
        } else {
            buffer.push_back(ch);
        }
        clear();
        refresh();
        printlines(lines);
        printw(buffer.c_str());
    }

    endwin();

    return 0;
}
