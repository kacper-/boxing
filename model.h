//
// Created by Kacper Marczewski on 15/10/2021.
//

#ifndef BOXING_MODEL_H
#define BOXING_MODEL_H

#include <string>
#include "boxer.h"
#include "settings.h"

void model_round(struct boxer b[], struct settings s) {
    int round_len = std::stoi(s.val[ROUND_LEN]);
    for (int i = 0; i < round_len; i++) {
        // TODO implement boxers actions and their impact
    }
}

void model(struct boxer b[], struct settings s) {
    int rounds = std::stoi(s.val[ROUNDS]);
    std::cout << rounds << " rounds of boxing" << std::endl;
    std::cout << b[0].name << " vs " << b[1].name << std::endl;
    for (int i = 0; i < rounds; i++)
        model_round(b, s);
}

#endif //BOXING_MODEL_H
