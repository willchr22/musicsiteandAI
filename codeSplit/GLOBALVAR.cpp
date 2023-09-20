#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include"/usr/local/cs/cs251/react.h"
#include "WISHLIST.h"
#include "COLLECTION.h"
#include "FUNCTIONS.h"
#include "REC.h"
#include "REGISTER.h"
#include "LOGIN.h"
#include "GLOBALVAR.h"

std::string text[39];
const int limit = 39;  // final screens
bool react = true;
const int input_index = 2, prompt_index = 25;

std::string user;
std::string pass;
std::string name;
std::string email;
std::string add;

vector<vector<double>> matrix
    {
        
    /*Will C*/    {4.5, 3.0, 5.0, 4.8, 5.0, 4.7, 4.2, 4.0, 3.7, 4.0, 2.2, 4.8, 5.0, 4.7, 4.8},
    /*Will A*/    {0.0, 2.3, 0.0, 3.9, 0.0, 3.7, 3.5, 3.6, 2.0, 4.0, 1.0, 0.0, 0.0, 0.0, 0.0},
    /*Ethan*/     {0.0, 3.1, 4.3, 4.7, 0.0, 4.2, 0.0, 2.9, 0.0, 2.7, 1.8, 0.0, 4.8, 0.0, 3.2},
    /*Peter*/     {0.0, 1.3, 0.0, 0.0, 0.0, 3.1, 3.8, 3.5, 4.3, 4.1, 2.4, 4.1, 4.8, 0.0, 0.0},
    /*Marcy*/     {4.9, 3.5, 0.0, 4.5, 0.0, 0.0, 4.0, 3.9, 3.7, 2.5, 2.3, 0.0, 3.7, 4.7, 5.0},
    /*Yoni*/      {0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 4.6, 4.7, 4.3, 4.5, 4.1, 4.8, 4.5, 0.0, 3.9},
    /*Evan*/      {0.0, 2.7, 0.0, 0.0, 0.0, 0.0, 3.8, 4.3, 2.5, 4.5, 4.0, 0.0, 0.0, 0.0, 0.0}
    };

vector<std::string> titles {"Heroes - David Bowie", "Party in the USA - Miley Cyrus", "The Blacker the Berry - Kendrick Lamar", "1979 - The Smashing Pumpkins", "All My Friends - LCD Soundsystem", "Hollywood Baby - 100 Gecs", "Come Together - The Beatles", "Billie Jean - Michael Jackson", "Imagine - John Lennon", "Smells Like Teen Spirit - Nirvana", "Sweet Child O'Mine - Guns N' Roses", "What's Going On - Marvin Gaye", "White Ferrari - Frank Ocean", "Andromeda - Weyes Blood", "Motion Sickness - Phoebe Bridgers"};