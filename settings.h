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

std::string PARAMS[] = {
        ROUND_LEN,
        ROUNDS
};

void parse_settings_line(const std::string& line, struct settings *s) {
    for (auto & i : PARAMS) {
        if (test_line(line, i))
            s->val[i] = line.substr(i.length());
    }
}

#endif //BOXING_SETTINGS_H
