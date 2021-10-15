//
// Created by Kacper Marczewski on 14/10/2021.
//

#ifndef BOXING_BOXER_H
#define BOXING_BOXER_H

#include <map>

struct boxer {
    std::string name;
    std::map<std::string, int> val;
};

const std::string COMMENT("#");
const std::string START("start=");

std::string NAMES[] = {
        std::string("height="),
        std::string("reach="),
        std::string("weight="),
        std::string("strength=")
};

const int NAMES_LEN = 4;

int test_line(std::string line, std::string param) {
    return !line.compare(0, param.length(), param);
}

int line_to_val(std::string line, std::string param) {
    return std::stoi(line.substr(param.length()));
}

void parse_line(std::string line, struct boxer *b) {
    for (int i = 0; i < NAMES_LEN; i++) {
        if (test_line(line, NAMES[i]))
            b->val[NAMES[i]] = line_to_val(line, NAMES[i]);
    }
}

void print_boxer(struct boxer b) {
    std::cout << b.name << std::endl;
    for (int i = 0; i < NAMES_LEN; i++)
        std::cout << "\t" << NAMES[i] << b.val[NAMES[i]] << std::endl;
}

#endif //BOXING_BOXER_H
