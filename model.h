//
// Created by Kacper Marczewski on 15/10/2021.
//

#ifndef BOXING_MODEL_H
#define BOXING_MODEL_H

#include <string>
#include <cmath>
#include <random>
#include "boxer.h"
#include "settings.h"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> r(0.0, 1.0);

float get_punch(boxer a) {
    return a.val[STRENGTH] * a.val[WEIGHT] * a.val[POWER] * a.val[PRECISION];
}

void boxer_action(int round, int seconds, boxer a, boxer b) {
    float fq = a.val[FREQUENCY];
    float diff = a.val[ATTACK] - b.val[DEFENCE] + a.val[SPEED] - b.val[SPEED];
    float punch = (1 + diff) * get_punch(a);
    if (fq > r(mt)) {
        std::cout << "\t\t" << a.name << " " << punch << std::endl;
    }
}

void model_round(int round, struct boxer b[], struct settings s) {
    int round_len = std::stoi(s.val[ROUND_LEN]);
    int sampling = std::stoi(s.val[SAMPLING]);
    int i;
    for (i = 0; i < round_len; i += sampling) {
        std::cout << "\tround " << round << " " << i << " seconds" << std::endl;
        boxer_action(round, i, b[0], b[1]);
        boxer_action(round, i, b[1], b[0]);
    }
}

void model(struct boxer b[], struct settings s) {
    int rounds = std::stoi(s.val[ROUNDS]);
    std::cout << rounds << " rounds of boxing in " << WD_NAMES[calc_wd(b[0])] << " category" << std::endl;
    std::cout << b[0].name << " vs " << b[1].name << std::endl << std::endl;
    for (int i = 0; i < rounds; i++) {
        std::cout << "round " << i + 1 << " of " << rounds << std::endl;
        model_round(i + 1, b, s);
    }
}

#endif //BOXING_MODEL_H
