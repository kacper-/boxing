//
// Created by Kacper Marczewski on 14/10/2021.
//

#ifndef BOXING_BOXER_H
#define BOXING_BOXER_H

#include <map>

struct boxer {
    std::string name;
    std::map<std::string, float> val;
    std::map<std::string, float> original_val;
};

// comment constant
const std::string COMMENT("#");
// block start constant
const std::string START("start=");

// physical

const std::string HEIGHT("height=");
const std::string REACH("reach=");
const std::string WEIGHT("weight=");
const std::string STRENGTH("strength=");
const std::string SPEED("speed=");
const std::string STAMINA("stamina=");
const std::string RESILIENCE("resilience=");
const std::string CHIN("chin=");

// technical

const std::string DEFENCE("defence=");
const std::string ATTACK("attack=");
const std::string LEGWORK("legwork=");
const std::string POWER("power=");
const std::string PRECISION("precision=");
const std::string FREQUENCY("frequency=");
const std::string OUTSIDE_SKILL("outside_skill=");
const std::string INSIDE_SKILL("inside_skill=");

// tactics

const std::string BODY_PUNCH_SHARE("body_punch_share=");
const std::string HEAD_PUNCH_SHARE("head_punch_share=");
const std::string OUTSIDE_SHARE("outside_share=");
const std::string INSIDE_SHARE("inside_share=");

// psychological

const std::string IQ("iq=");

std::string NAMES[] = {
        HEIGHT,
        REACH,
        WEIGHT,
        STRENGTH,
        SPEED,
        STAMINA,
        RESILIENCE,
        CHIN,
        DEFENCE,
        ATTACK,
        LEGWORK,
        POWER,
        PRECISION,
        FREQUENCY,
        OUTSIDE_SKILL,
        INSIDE_SKILL,
        BODY_PUNCH_SHARE,
        HEAD_PUNCH_SHARE,
        OUTSIDE_SHARE,
        INSIDE_SHARE,
        IQ
};

int test_line(const std::string &line, const std::string &param) {
    return !line.compare(0, param.length(), param);
}

float line_to_val(const std::string &line, const std::string &param) {
    return std::stof(line.substr(param.length()));
}

void parse_line(const std::string &line, struct boxer *b) {
    for (auto &i: NAMES) {
        if (test_line(line, i)) {
            b->val[i] = line_to_val(line, i);
            b->original_val[i] = b->val[i];
        }
    }
}

void print_boxer(struct boxer b) {
    std::cout << b.name << std::endl;
    for (auto &i: NAMES)
        std::cout << "\t" << i << b.val[i] << std::endl;
}

#endif //BOXING_BOXER_H
