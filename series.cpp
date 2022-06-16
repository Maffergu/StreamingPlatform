//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//cSeries.cpp
//CPP class of Series
#include "series.h"

Series::Series(){

}

Series::Series(vector<Episode> _episodes){
    episodes = _episodes;
}

void Series::setSeries(vector<Episode> _episodes){
    episodes = _episodes;
}

void Series::addEpisode(Episode* episode){
    episodes.push_back(*episode);
}

void Series::showSeriesRating(){
    for (int i = 0; i < episodes.size(); i++) {
        cout<<"\t Episode: "<<episodes[i].getTitle()<<endl;
        cout<<"\t Rating: "<<episodes[i].getRating()<<endl;
    }
}

void Series::showSeriesGenre(string gen){
    for (int i = 0; i < episodes.size(); i++) {
        if(episodes[i].getGenre() == gen){
            cout<<episodes[i].getName()<<'\t'<<"(Series)"<<'\t'<<episodes[i].getGenre()<<endl;
        }
    }
}

void Series::setName(string _name){
    name = _name;
}

float Series::getAverage(){
    vector<Episode>::iterator it;
    Episode ep;
    float totalSum = 0;
    float average;
    if(episodes.size()==1){
        average = episodes[0].getRating();
    } else {
        for(it = episodes.begin(); it != episodes.end(); ++it){
            float s = ep + (*it);
            totalSum += s;
        }
        average = totalSum/episodes.size();
    }
    this->setRating((float)average);
    return average;
}

string Series::getName(){
    return name;
}

void Series::setRating(float _rating){
    rating = _rating;
}

vector<Episode> Series::getEpisodes(){
    return episodes;
}

void Series::showSeriesEpisodes(){
    for (int i = 0; i < episodes.size(); i++) {
        cout<<episodes[i].getTitle()<<endl;
    }
}

int Series::getEpisodesId(){
    int idd;
    for (int i = 0; i < episodes.size(); i++) {
        idd =episodes[i].getId();
    }
    return idd;
}
