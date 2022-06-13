//María Fernanda Argueta Wolke A00830194
//cEpisode.h
//Headder of class Episode
#pragma once
#include <iostream>
#include <string>
#include "cVideo.h"
using namespace std;
class Episode: public Video{
    private:
        string title;
        int season;
        int episode;
    public:
        Episode();
        void setTitle(string _title);
        void setSeason(int _season);
        void setEpisode(int _episode);
        string getTitle();
        int getSeason();
        int getEpisode();

        
};