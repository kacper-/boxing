#include <iostream>
#include <fstream>
#include "model.h"

void verify_input(int argc);

void load_match(const std::string &file, boxer b[]);

int set_boxer(const std::string &line, int *i, boxer b[]);

void load_settings(const std::string &file, settings *s);

int main(int argc, char *argv[]) {
    verify_input(argc);
    std::string settings_file(argv[1]);
    std::string boxers_file(argv[2]);
    boxer b[2];
    settings s;
    b[0].name = std::string(argv[3]);
    b[1].name = std::string(argv[4]);
    load_settings(settings_file, &s);
    load_match(boxers_file, b);
    model(b, s);
    return 0;
}

void verify_input(int argc) {
    if (argc != 5) {
        std::cout << "Four arguments required !" << std::endl;
        exit(0);
    }
}

void load_settings(const std::string &file, settings *s) {
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty() | test_line(line, COMMENT))
            continue;
        parse_settings_line(line, s);
    }
}

void load_match(const std::string &file, boxer b[]) {
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

int set_boxer(const std::string &line, int *i, boxer b[]) {
    for (int j = 0; j < 2; j++) {
        if (!line.compare(START.length(), b[j].name.length(), b[j].name)) {
            *i = j;
            return 1;
        }
    }
    return 0;
}
