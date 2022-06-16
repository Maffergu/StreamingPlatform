//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cSeries.h
//Headder of class StreamingPlatform 

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "series.h"
#include "movie.h"
using namespace std;

class StreamingPlatform{
    protected:
        vector<Series> series;
        vector<Movie> movies;

    public:
        float getAverage();
        vector<Series> getVectorSeries();
        int getSeries(string name);
        vector<Series> getAllSeries();
        vector<Movie> getMovies();
        //void showSeries(float rating);
        void showSeriesAverage();
        void showMoviesRating(float num1, float num2);
        void showMoviesGenre(string genre);
        void showEpisodesGenre(string gen);
        void showMoviesRating(string name,float num1, float num2);
        void showEpisodesRating(string name, float num1, float num2);
        void showEpisodesRating(float num1, float num2);
        void showVidRating(float num1, float num2);
        void showEpisodes(string name);
        void addMovie(Movie movie);
        void addSeries(Series _series);
        bool exists(string name);
        string rate(string seriesName, string episodeName, float videoRating);
        string rate(string videosName,float videoRating);
        void displayMenu();
};