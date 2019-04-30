//
// Created by aesma on 11.04.19.
//

#ifndef ADAM_TCP_AESMAFUNCS_H
#define ADAM_TCP_AESMAFUNCS_H

#include <cstring>
#include <sstream>
#include <vector>
#include <iostream>

class AesmaFuncs {
public:
    static std::string bytes_to_hex(const char* bytes, const int &len);
    static std::vector<std::string> split_string(const std::string &source, const std::string &delimiter);
};


#endif //ADAM_TCP_AESMAFUNCS_H
