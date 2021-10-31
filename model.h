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

float get_punch(boxer *a, boxer *b) {

    // TODO dodać degradację parametrów wraz z upływem czasu (STAMINA)

    // TODO dodać zmianę parametrów wraz z kumulacją ciosow

    float diff = a->val[ATTACK] - b->val[DEFENCE] + a->val[SPEED] - b->val[SPEED] + a->val[LEGWORK] - a->val[LEGWORK];
    float w_diff = a->val[WEIGHT] / b->val[WEIGHT];
    float impact = a->val[STRENGTH] * w_diff * a->val[POWER] * a->val[PRECISION];
    return (1 + diff) * impact;
}

void boxer_action(int round, int seconds, boxer *a, boxer *b) {
    float fq = a->val[FREQUENCY];
    float punch;
    if (fq > r(mt)) {
        punch = get_punch(a, b);
        b->val[RESILIENCE] -= punch;
        b->val[CHIN] -= punch;
        std::cout << "\t\t" << a->name << " PUNCH " << punch << " " << b->name << " RESILIENCE " << b->val[RESILIENCE] << " CHIN " << b->val[CHIN] << std::endl;
    }
}

void model_round(int round, struct boxer b[], struct settings s) {

    // TODO dodać regenerację parametrów po przerwie między rundami (STAMINA)

    int round_len = std::stoi(s.val[ROUND_LEN]);
    int sampling = std::stoi(s.val[SAMPLING]);
    int i;
    for (i = 0; i < round_len; i += sampling) {
        std::cout << "\t" << i << " seconds" << std::endl;
        boxer_action(round, i, b, b + 1);
        boxer_action(round, i, b + 1, b);
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
