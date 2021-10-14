#include <iostream>
#include <fstream>
#include <string>
#include "model.h"

void verify_input(int argc);

void load_match(std::string file, boxer b[]);

int set_boxer(std::string line, int *i, boxer b[]);

int main(int argc, char *argv[]) {
    verify_input(argc);
    std::string file(argv[1]);
    boxer b[2];
    b[0].name = std::string(argv[2]);
    b[1].name = std::string(argv[3]);
    load_match(file, b);
    model(b);
    return 0;
}

void verify_input(int argc) {
    if (argc != 4) {
        std::cout << "Three arguments required !" << std::endl;
        exit(0);
    }
}

void load_match(std::string file, boxer b[]) {
    std::ifstream infile(file);
    std::string line;
    int i = 0;
    int on = 0;
    while (std::getline(infile, line)) {
        if (line.empty() | test_line(line, COMMENT))
            continue;
        if (test_line(line, START)) {
            on = set_boxer(line, &i, b);
        } else {
            if (on) {
                parse_line(line, b + i);
            }
        }
    }
}

int set_boxer(std::string line, int *i, boxer b[]) {
    for (int j = 0; j < 2; j++) {
        if (!line.compare(START.length(), b[j].name.length(), b[j].name)) {
            *i = j;
            return 1;
        }
    }
    return 0;
}
