#include "Tokenizer.hpp"

Tokenizer::Tokenizer(istream& input) : input(input) {}

string Tokenizer::next() {
    string s;

    skipSep();
    while (!input.eof() && !isSep(input.peek())) {
        s += input.get();
    }
    return s;
}

bool Tokenizer::isConsumed() {
    skipSep();
    return input.eof();
}

void Tokenizer::skipSep() {
    while (!input.eof() && isSep(input.peek())) {
        input.get();
    }
}

bool Tokenizer::isSep(char c) const { return ispunct(c) || isspace(c); }
