//
// Created by Kacper Marczewski on 15/10/2021.
//

#ifndef BOXING_SETTINGS_H
#define BOXING_SETTINGS_H

struct settings {
    std::map<std::string, std::string> val;
};

const std::string ROUND_LEN("round_len=");
const std::string ROUNDS("rounds=");
const std::string SAMPLING("sampling=");
const std::string CONSTANT_DIFF("constant_diff=");
const std::string STAMINA_DROP("stamina_drop=");

std::string PARAMS[] = {
        ROUND_LEN,
        ROUNDS,
        SAMPLING,
        CONSTANT_DIFF,
        STAMINA_DROP
};

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

void parse_settings_line(const std::string& line, struct settings *s) {
    for (auto & i : PARAMS) {
        if (test_line(line, i))
            s->val[i] = line.substr(i.length());
    }
}

#endif //BOXING_SETTINGS_H
