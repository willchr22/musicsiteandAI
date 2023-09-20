#ifndef WISHLIST_H
#define WISHLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wishlist {
public:
    Wishlist(istream& is);
    void add_wish(string wish);
    void write_to(ostream& osi) const;
    void print_wishes(ostream& os) const;
    bool remove_wish(string wish);

private:
    vector<string> wishes;
};

#endif
