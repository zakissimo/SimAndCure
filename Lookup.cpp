#include "Lookup.hpp"

size_t LookUp::getWordValue(const string& w) const {
    size_t value = 0;

    for (const char& c : w) {
        if (asciiTable.find(c) != asciiTable.end()) {
            value += asciiTable.at(c);
        }
    }

    for (auto& utfChar : utfTable) {
        int pos = -1;
        while ((pos = w.substr(pos + 1).find(utfChar.first)) != string::npos) {
            value += utfChar.second;
        }
    }
    return value;
}
