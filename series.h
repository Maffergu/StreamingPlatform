//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cSeries.h
//Headder of class Series 
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "episode.h"
using namespace std;

class Series{
    protected:
        vector<Episode> episodes;
        string name;
        float rating;

    public:
        Series();
        Series(vector<Episode> _episodes);
        void setSeries(vector<Episode> _episodes);
        void setRating(float _rating);
        void addEpisode(Episode* episode);
        void showSeriesRating();
        void showSeriesGenre(string gen);
        void setName(string _name);
        float getAverage();
        vector<Episode> getEpisodes();
        string getName();
        void showSeriesEpisodes();
        int getEpisodesId();
        
};