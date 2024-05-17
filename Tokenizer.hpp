#pragma once

#include <bits/stdc++.h>
using namespace std;

class Tokenizer {
  public:
    Tokenizer(istream& input);
    ~Tokenizer() = default;

    string next();
    bool isConsumed();

    Tokenizer() = delete;
    Tokenizer(Tokenizer&&) = delete;
    Tokenizer(const Tokenizer&) = delete;
    Tokenizer& operator=(Tokenizer&&) = delete;
    Tokenizer& operator=(const Tokenizer&) = delete;

  private:
    void skipSep();
    bool isSep(char c) const;

    istream& input;
};
