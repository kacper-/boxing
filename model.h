//
// Created by Kacper Marczewski on 15/10/2021.
//

#ifndef BOXING_MODEL_H
#define BOXING_MODEL_H

#include <string>
#include "boxer.h"
#include "settings.h"

float WD[] = {
        0,
        46.27,
        47.63,
        48.99,
        50.80,
        52.16,
        53.52,
        55.34,
        57.15,
        58.97,
        61.23,
        63.50,
        66.68,
        69.85,
        72.57,
        76.20,
        79.38,
        90.72,
        100000
};

std::string WD_NAMES[] = {
        "Atomweight",
        "Strawweight",
        "Junior flyweight",
        "Flyweight",
        "Junior bantamweight",
        "Bantamweight",
        "Junior featherweight",
        "Featherweight",
        "Junior lightweight",
        "Lightweight",
        "Super lightweight",
        "Welterweight",
        "Junior middleweight",
        "Middleweight",
        "Super middleweight",
        "Light heavyweight",
        "Cruiserweight",
        "Heavyweight"
};

int calc_wd(struct boxer b) {
    for (int i = 1; i < 19; i++) {
        if (WD[i] >= b.val[WEIGHT] & WD[i - 1] < b.val[WEIGHT])
            return i - 1;
    }
    return 0;
}

void model_round(struct boxer b[], struct settings s) {
    int round_len = std::stoi(s.val[ROUND_LEN]);
    for (int i = 0; i < round_len; i++) {
        // TODO implement boxers actions and their impact
    }
}

void model(struct boxer b[], struct settings s) {
    int rounds = std::stoi(s.val[ROUNDS]);
    std::cout << rounds << " rounds of boxing in " << WD_NAMES[calc_wd(b[0])] << " category" << std::endl;
    std::cout << b[0].name << " vs " << b[1].name << std::endl;
    for (int i = 0; i < rounds; i++) {
        std::cout << "round " << i + 1 << " of " << rounds << std::endl;
        model_round(b, s);
    }
}

#endif //BOXING_MODEL_H
