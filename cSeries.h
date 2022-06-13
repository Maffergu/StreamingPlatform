//María Fernanda Argueta Wolke A00830194
//cSeries.h
//Headder of class Series 
#pragma once
#include <iostream>
#include <string>
#include<vector>
//#include "cEpisode.cpp"
using namespace std;
class Series{
private:
    vector<Episode*> series;
public:
    Series();
    //void setSeries(vector<Episode*> _series);
    //void addEpisode(Episode episode);
};