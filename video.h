//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cVideo.h
//Headder of class Video 
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Video{
    protected:
        int id;
        string name;
        int length;
        string genre;
        float rating;
        int rators;

    public:
        Video();
        Video(int _id, string _name, int _length, string _genre, float _rating, int _rators);
        ~Video();
        void setId(int _id);
        void setName(string _name);
        void setLength(int _length);
        void setGenre(string _genre);
        void setRating(float _rating);
        void setRators(int _rators);
        int getId();
        string getName();
        int getLength();
        string getGenre();
        float getRating();
        float operator + (const Video &v2);
        int getRators();
        virtual string showByGenre() = 0;
        virtual string showByRating() = 0;

};
