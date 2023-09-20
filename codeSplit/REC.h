#ifndef REC_H
#define REC_H

#include <iostream>
#include <vector>
#include <cmath>

class Rec {
private:

public:
    std::vector<double> userInput;

    Rec(std::istream& is);
    void add_item(double item);

    double cosine_similarity(std::vector<double> v1, std::vector<double> v2) const;
    int matchUser(std::vector<std::vector<double>> a, std::vector<double> b) const;
    int matchSong(std::vector<double> a, std::vector<double> b) const;

    void write_to(std::ostream& os) const;
    void print_rec(std::ostream& os) const;
};

#endif // REC_H
