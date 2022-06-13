//María Fernanda Argueta Wolke A00830194
//cVideo.h
//Headder of class Video 
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Video{
    public:
        int id;
        string name;
        int length;
        string genre;
        int rating;
        int rators;
        Video();
        void setId(int _id);
        void setName(string _name);
        void setLength(int _length);
        void setGenre(string _genre);
        void setRating(int _rating);
        void setRators(int _rators);
        int getId();
        string getName();
        int getLength();
        string getGenre();
        int getRating();
        int getRators();

        

};
