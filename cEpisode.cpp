//María Fernanda Argueta Wolke A00830194
//Episode.cpp
//CPP class of episode 
#include "cEpisode.h"
Episode::Episode(){
    title = " ";
    season = 1;
}
void Episode::setTitle(string _title){
    title = _title;
}
void Episode::setSeason(int _season){
    season = _season;
}
void Episode::setEpisode(int _episode){
    episode = _episode;
}
string Episode::getTitle(){
    return title;
}
int Episode::getSeason(){
    return season;
}
int Episode::getEpisode(){
    return episode;
}