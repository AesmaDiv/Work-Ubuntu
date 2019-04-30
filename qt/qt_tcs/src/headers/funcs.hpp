#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <QQmlEngine>
#include <QQmlComponent>
#include <QStandardItemModel>
#include <QObject>
#include <QQmlContext>

#include <vector>
#include <string>

#include "./globals.hpp"
#include "./database.hpp"

namespace Funcs {
    namespace Tools {
        std::string Combine(const std::vector<std::string> &input, const std::string delimiter);
    }
}

std::string Funcs::Tools::Combine(const std::vector<std::string> &input, const std::string delimiter) {
    std::string result = "";
    size_t s = input.size();
    if (s > 0) {
        result.append(input[0]);
        for(size_t i = 1; i < s; ++i){
            result.append(delimiter);
            result.append(input[i]);
        }
    }

    return result;
}



#endif // FUNCS_HPP
