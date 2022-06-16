//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//Movie.cpp
//CPP class of episode 
#include "movie.h"

Movie::Movie(int _id, string _name, int _length, string _genre, float _rating, int _rators) : Video(_id, _name, _length, _genre, _rating, _rators){

}

Movie::~Movie(){

}

string Movie::showByRating(){
    string txt = name;
    txt += '\t';
    txt += "(Movie)";
    txt += '\t';
    txt += to_string(rating);
    return txt;
}

string Movie::showByGenre(){
    string txt = name;
    txt += "\t";
    txt += "(Movie)";
    txt += '\t';
    txt += genre;
    return txt;
}