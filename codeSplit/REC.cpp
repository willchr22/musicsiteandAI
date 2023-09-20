#include "REC.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include "WISHLIST.h"
#include "COLLECTION.h"
#include "REC.h"
#include "REGISTER.h"
#include "LOGIN.h"
#include "GLOBALVAR.h"
#include"/usr/local/cs/cs251/react.h"

        Rec::Rec(istream& is) {
            int i;
            string st;
            is >> i;
            is.get();
            for (int j = 1; j <= i; j++) {
                getline(is, st);
                userInput.push_back(stod(st));
            }
        }

        void Rec::add_item(double item) {
            userInput.push_back(item);
        }

    double Rec::cosine_similarity(vector<double> v1, vector<double> v2) const {
        double dot_product = 0.0;
        double norm1 = 0.0;
        double norm2 = 0.0;
        int n = v1.size();
        for (int i = 0; i < n; i++) {
            dot_product += v1[i] * v2[i];
            norm1 += v1[i] * v1[i];
            norm2 += v2[i] * v2[i];
        }
        return dot_product / (sqrt(norm1) * sqrt(norm2));
    }

int Rec::matchUser(vector<vector<double>> a, vector<double> b) const {
    double bestSim = -1.0;
    int bestSimIndex = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (cosine_similarity(a[i], b) > bestSim) {
            bestSim = cosine_similarity(a[i], b);
            bestSimIndex = i;
        }
    }
    return bestSimIndex;
}

int Rec::matchSong(vector<double> a, vector<double> b) const {
    int songIndex = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 3.0 && b[i] == 0.0) {
            songIndex = i;
        }
    }
    return songIndex;
}


        void Rec::write_to(ostream& os) const {
        os << userInput.size() << endl;
        for (unsigned int i = 0; i < userInput.size(); i++) {
            os << userInput[i] << endl;
        }
        }

        void Rec::print_rec(ostream& os) const {
        
        
            os << titles[matchSong(matrix[(matchUser(matrix, userInput))], userInput)] << endl;
        
        }