//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//Adrián Lozano González A01661437
//main.cpp
//Main class for the whole project
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "video.h"
#include "episode.h"
#include "series.h"
#include "movie.h"
#include "streamingPlatform.h"

using namespace std;

int main(){
    StreamingPlatform videoL;
    Episode ep;
    Series series;
    //StreamingPlatform videoL;
    string s;
    istringstream iss( s );
    string fname = "okay.csv";
    
   vector<vector<string> > content;
    vector<string> row;
    string line, word;
    
    fstream file (fname, ios::in);
    if(file.is_open())
    {
    while(getline(file, line))
    {


    row.clear();
    
    stringstream str(line);
    
    while(getline(str, word, ','))
    row.push_back(word);
    content.push_back(row);
    }
    }
    else
    cout<<"Could not open the file\n";

    string str;
    
    //Series series;
    //Reading the whole document without the headders
    for(int i=1;i<content.size();i++){
        
       
        int id;
        str = content[i][0];
        stringstream ss;  
        ss << str;  
        ss >> id;

        string name;
        name = content[i][1];

        int len;
        str = content[i][2];
        stringstream s1; 
        s1 << str;  
        s1 >> len;
        
        string gen;
        gen = content[i][3];
        float rating;
        str = content[i][4]; 
        rating = stof(str);

        int rators;
        str = content[i][5];
        stringstream s2; 
        s2 << str;  
        s2 >> rators;
        if(content[i][6]== "Series"){
            
            Episode episode;
            episode.setId(id);
            episode.setName(name);
            episode.setLength(len);
            episode.setGenre(gen);
            episode.setRating(rating);
            episode.setRators(rators);
            int ep;
            str = content[i][8]; 
            stringstream s3; 
            s3 << str;
            s3 >> ep;
            episode.setEpisode(ep);
            string epT = content[i][9];
            episode.setTitle(epT);
            int ssn;
            str = content[i][7]; 
            stringstream s4; 
            s4 << str;  
            s4 >> ssn;
            episode.setSeason(ssn);
            series.addEpisode(&episode);
            
            if(videoL.exists(name)== true){
                //cout<<"truw"<<endl;
                int num = videoL.getSeries(name);
                cout<<"Este es num: "<<endl;
                cout<<num<<endl;
                videoL.getVectorSeries()[num].addEpisode(&episode);
                

            }else{
                Series series;
                series.addEpisode(&episode);
                series.setName(name);
                videoL.addSeries(series);
                
            }
            
        } else{
            Movie movie(id,name, len, gen, rating,rators);
            cout<<"MOVIE NAME: "<<movie.getName()<<endl;
            videoL.addMovie(movie);
            
        }

        
    }
    
    videoL.displayMenu();
    return 0;
}