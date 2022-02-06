//
// Created by bhanu on 06-Feb-22.
//

#include "util.h"

std::string readFileIntoString(const std::string &path) {
    auto ss = std::ostringstream{};
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
                  << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

