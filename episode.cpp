//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//Episode.cpp
//CPP class of episode 
#include "episode.h"
Episode::Episode(){
    rating = 0;
}

Episode::Episode(int _id, string _name, int _length, string _genre, float _rating, int _rators, string _title, int _season, int _episodeNumber):Video(_id, _name, _length, _genre, _rating, _rators){
    title = _title;
    season = _season;
    episodeNumber = _episodeNumber;
}

Episode::~Episode(){

}

void Episode::setTitle(string _title){
    title = _title;
}

void Episode::setSeason(int _season){
    season = _season;
}

void Episode::setEpisode(int _episodeNumber){
    episodeNumber = _episodeNumber;
}

string Episode::getTitle(){
    return title;
}

int Episode::getSeason(){
    return season;
}

int Episode::getEpisodeNumber(){
    return episodeNumber;
}

string Episode::showByRating(){
    string txt =" " ;
    txt = txt+ getTitle();
    txt = txt + "        ";
    string rate = to_string(rating);
    txt += rate;
    txt+="fghtfdcc ";
    return txt;
}

string Episode::showByGenre(){
    string txt = title;
    txt += '\t';
    txt += genre;
    return txt;
}