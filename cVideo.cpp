//María Fernanda Argueta Wolke A00830194
//cVideo.cpp
//CPP class of Video 
#include "cVideo.h"
Video::Video(){
    id = 0;
    name = "";
    length = 0;
    genre = "";
    rating = 0;
    rators = 0;
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
void Video::setRating(int _rating){
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
int Video::getRating(){
    return rating;
}
int Video::getRators(){
    return rators;
}