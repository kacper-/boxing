//
// Created by Kacper Marczewski on 15/10/2021.
//

#ifndef BOXING_MODEL_H
#define BOXING_MODEL_H

#include "boxer.h"

void model(struct boxer b[], int rounds) {
    std::cout << rounds << " rounds of boxing" << std::endl;
    std::cout << b[0].name << " vs " << b[1].name << std::endl;
}

#endif //BOXING_MODEL_H
