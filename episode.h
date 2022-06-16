//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//cEpisode.h
//Headder of class Episode
#pragma once
#include <iostream>
#include <string>
#include "video.h"
using namespace std;

class Episode: public Video{
    protected:
        string title;
        int season;
        int episodeNumber;
    public:
        Episode();
        Episode(int _id, string _name, int _length, string _genre, float _rating, int _rators, string _title, int _season, int _episodeNumber);
        ~Episode();
        void setTitle(string _title);
        void setSeason(int _season);
        void setEpisode(int _episodeNumber);
        string getTitle();
        int getSeason();
        int getEpisodeNumber();
        string showByRating();
        string showByGenre();
        
};