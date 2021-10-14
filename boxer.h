//
// Created by Kacper Marczewski on 14/10/2021.
//

#ifndef BOXING_BOXER_H
#define BOXING_BOXER_H

struct boxer {
    std::string name;
    int height;
    int reach;
    int weight;
};

const std::string COMMENT("#");
const std::string START("start=");
const std::string HEIGHT("height=");
const std::string REACH("reach=");
const std::string WEIGHT("weight=");

int test_line(std::string line, std::string param) {
    return !line.compare(0, param.length(), param);
}

int line_to_val(std::string line, std::string param) {
    return std::stoi(line.substr(param.length()));
}

void parse_line(std::string line, struct boxer *b) {
    if (test_line(line, HEIGHT)) {
        b->height = line_to_val(line, HEIGHT);
    }
    if (test_line(line, REACH)) {
        b->reach = line_to_val(line, REACH);
    }
    if (test_line(line, WEIGHT)) {
        b->weight = line_to_val(line, WEIGHT);
    }
}

void print_boxer(struct boxer b) {
    std::cout << b.name << std::endl;
    std::cout << "\t" << b.height << std::endl;
    std::cout << "\t" << b.reach << std::endl;
    std::cout << "\t" << b.weight << std::endl;
}

#endif //BOXING_BOXER_H
