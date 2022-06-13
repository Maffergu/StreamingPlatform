#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "cVideo.h"
#include "cEpisode.h"
//#include "cSeries.h"
using namespace std;
 
int main(){
    string s;
    istringstream iss( s );
    string fname = "videos.csv";
    
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
    //Reading the whole document without the headders
    for(int i=1;i<content.size();i++){
        //push all new videos into video vector
        Video vid;
        int id;
        str = content[i][0];
        stringstream ss;  
        ss << str;  
        ss >> id;
        vid.setId(id);
        string name;
        name = content[i][1];
        vid.setName(name);
        int len;
        str = content[i][2]; 
        ss << str;  
        ss >> len;
        vid.setLength(len);
        string gen;
        gen = content[i][3]; 
        vid.setGenre(gen);
        /*int som;
        str = content[i][4]; 
        vid.setSom(som);*/
        //FALTA METERLOS AL VECTOR DE SERIES


    
        if(content[i][4]== "Series"){
            //push new series into series vector
            Episode episode;
            episode.setId(id);
            episode.setName(name);
            episode.setLength(len);
            episode.setGenre(gen);
            int ep;
            str = content[i][5]; 
            ss << str;  
            ss >> ep;
            episode.setEpisode(ep);
            string epT;
            epT = content[i][6]; 
            episode.setTitle(epT);
            int ssn;
            str = content[i][7]; 
            ss << str;  
            ss >> ssn;
            episode.setSeason(ssn);
            //FALTA METERLOS AL VECTOR DE SERIES

        }
        
        
        cout<<content[i][6]<<endl;
    /*    
    for(int j=0;j<content[i].size();j++){
        
        if(j == 0){
            int id;
            str = content[i][0];
            stringstream ss;  
            ss << str;  
            ss >> id;
            cout << id;
        }
        
    }*/
    }
    
    return 0;
}
 