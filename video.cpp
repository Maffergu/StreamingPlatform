//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cVideo.cpp
//CPP class of Video 
#include "video.h"
Video::Video(){
    id = 0;
    name = "";
    length = 0;
    genre = "";
    rating = 0.0;
    rators = 0;
}

Video::Video(int _id, string _name, int _length, string _genre, float _rating, int _rators){
    id = _id;
    name = _name;
    length = _length;
    genre = _genre;
    rating = _rating;
    rators = _rators;
}

Video::~Video(){

}

void Video::setId(int _id){
    id = _id;
}

void Video::setName(string _name){
    name = _name;
}

void Video::setLength(int _length){
    length = _length;
}

void Video::setGenre(string _genre){
    genre = _genre;
}

void Video::setRating(float _rating){
    rating = _rating;
}

void Video::setRators(int _rators){
    rators = _rators;
}

int Video::getId(){
    return id;
}

string Video::getName(){
    return name;
}

int Video::getLength(){
    return length;
}

string Video::getGenre(){
    return genre;
}

float Video::getRating(){
    return rating;
}

int Video::getRators(){
    return rators;
}

float Video::operator + (const Video &v2){
    return rating + v2.rating;
}

