#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Collection {
protected:
    vector<string> items;

public:
    Collection(istream& is);
    void add_item(string item);
    void write_to(ostream& os) const;
    bool remove_item(string item);
    void print_records(ostream& os) const;
};

#endif
