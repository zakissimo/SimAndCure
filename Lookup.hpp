#pragma once

#include <bits/stdc++.h>
using namespace std;

class LookUp {
  public:
    LookUp() = default;
    ~LookUp() = default;

    size_t getWordValue(const string& w) const;

    LookUp(LookUp&&) = delete;
    LookUp(const LookUp&) = delete;
    LookUp& operator=(LookUp&&) = delete;
    LookUp& operator=(const LookUp&) = delete;

  private:
    unordered_map<char, size_t> asciiTable = {
        {'A', 32}, {'B', 36}, {'C', 33}, {'D', 40}, {'E', 41}, {'F', 47},
        {'G', 31}, {'H', 27}, {'I', 49}, {'J', 28}, {'K', 30}, {'L', 42},
        {'M', 29}, {'N', 38}, {'O', 51}, {'P', 43}, {'Q', 45}, {'R', 39},
        {'S', 35}, {'T', 52}, {'U', 37}, {'V', 46}, {'W', 34}, {'X', 48},
        {'Y', 44}, {'Z', 50}, {'a', 1},  {'b', 4},  {'c', 5},  {'d', 8},
        {'e', 10}, {'f', 11}, {'g', 13}, {'h', 16}, {'i', 18}, {'j', 19},
        {'k', 21}, {'l', 21}, {'m', 23}, {'n', 2},  {'o', 3},  {'p', 6},
        {'q', 7},  {'r', 9},  {'s', 12}, {'t', 14}, {'u', 15}, {'v', 17},
        {'w', 20}, {'x', 24}, {'y', 25}, {'z', 26},
    };
    unordered_map<string, size_t> utfTable = {
        {"é", 60}, {"è", 61}, {"ê", 62}, {"à", 63}, {"â", 64},
        {"ë", 65}, {"û", 66}, {"ù", 67}, {"î", 68}, {"ç", 69},
        {"ô", 70}, {"ö", 71}, {"ü", 72},
    };
};
