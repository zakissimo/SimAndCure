#include "Lookup.hpp"
#include "Tokenizer.hpp"

void usage(const string& program) {
    cout << "Usage: " << program << " <input_file>" << endl;
    exit(1);
}

struct Word {
    string s;
    size_t v;
};

int main(int argc, char** argv) {

    if (argc != 2) {
        usage(argv[0]);
    }

    ifstream input(argv[1]);

    if (!input.is_open()) {
        cerr << "Error: cannot open file " << argv[1] << endl;
        exit(1);
    }

    LookUp LookUp;
    Tokenizer tokenizer(input);

    vector<Word> v;
    set<string> seen;
    size_t total = 0;
    while (!tokenizer.isConsumed()) {
        string s = tokenizer.next();
        if (seen.find(s) == seen.end()) {
            v.push_back({.s = s, .v = LookUp.getWordValue(s)});
            total += v.back().v;
        }
        seen.insert(s);
    }

    sort(v.begin(), v.end(),
         [](const Word& a, const Word& b) { return a.v < b.v; });

    string filename = string(argv[1]);
    int dotPos = filename.find_last_of('.');
    filename = filename.substr(0, dotPos) + ".count.txt";

    ofstream output(filename);

    if (!output.is_open()) {
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }

    for (const Word& w : v) {
        output << w.s << ", " << w.v << endl;
    }

    cout << "Found " << v.size() << " unique 'words' for a total score of "
         << total << endl;

    return 0;
}
