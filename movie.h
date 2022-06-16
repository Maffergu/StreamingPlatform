//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cMovie.h
//Headder of class Movie
#pragma once
#include <iostream>
#include <string>
#include "video.h"
using namespace std;

class Movie: public Video{
    public:
        Movie(int _id, string _name, int _length, string _genre, float _rating, int _rators);
        ~Movie();
        string showByRating();
        string showByGenre();
        
};