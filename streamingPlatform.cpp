//María Fernanda Argueta Wolke A00830194
//Noemí Abigail Curiel López A01655892
//cStreamingPaltform.cpp
//CPP class of StreamingPaltform 
#include "streamingPlatform.h"

float StreamingPlatform::getAverage(){
    vector<float> allRatings;
    vector<Series>::iterator it;
    for(it = series.begin(); it != series.end(); ++it){
        vector<Episode> epsds;
        epsds = (*it).getEpisodes();
        vector<Episode>::iterator it2;
        for(it2 = epsds.begin(); it2 != epsds.end(); ++it2){
            float rtt = (*it2).getRating();
            allRatings.push_back(rtt);
        }
    }

    vector<Movie>::iterator it3;
    for(it3 = movies.begin(); it3 != movies.end(); ++it3){
            float rtt = (*it3).getRating();
            allRatings.push_back(rtt);
        }

    float totalSum = 0;
    for(int i = 0; i<allRatings.size(); i++){
        totalSum += allRatings[i];
    }

    float allAverage = totalSum/allRatings.size();
    return allAverage;
}

void StreamingPlatform::showSeriesAverage(){
    
    for (size_t i = 0; i < series.size(); i++) {
        cout<<series[i].getName()<<endl;
        cout<<"\t"<<endl;
        cout<<series[i].getAverage()<<"\n"<<endl;
    }
}

vector<Series> StreamingPlatform::getAllSeries(){
    return series;
}

vector<Series> StreamingPlatform::getVectorSeries(){
    return series;
}

int StreamingPlatform::getSeries(string name){
    int pos;
    for (int i = 0; i < series.size(); i++) {
        if(series[i].getName()== name){
            pos = i;
            break;
        }
    }
    return pos;
}

vector<Movie> StreamingPlatform::getMovies(){
    return movies;
}

void StreamingPlatform::showMoviesRating(float num1, float num2){
    for (int i = 0; i <= movies.size(); i++) {
        if(movies[i].getRating()>=num1 && movies[i].getRating()<=num2){
            cout<<movies[i].showByRating()<<endl;
        }
    }
}

void StreamingPlatform::showMoviesRating(string name,float num1, float num2){
    
    for (int i = 0; i <= movies.size(); i++) {
        if(movies[i].getName()== name){
            if(movies[i].getRating()>=num1 && movies[i].getRating()<=num2){
            cout<<movies[i].showByRating()<<endl;
            }
        }
    }
}

void StreamingPlatform::showMoviesGenre(string genre){
    int count = 0;
    for (int i = 0; i <= movies.size(); i++) {
        if(movies[i].getGenre() == genre){
            cout<<movies[i].showByGenre()<<endl;
            count = count+1;
        }
    }
    if(count == 0 ){
        cout<<"There are no movies with that genre"<<endl;
    }
}

void StreamingPlatform::showEpisodesGenre(string gen){
    for (int i = 0; i < series.size(); i++) {
        series[i].showSeriesGenre(gen);
    }
    
}

void StreamingPlatform::showEpisodesRating(string name, float num1, float num2){
    
    int pos = getSeries(name);
    vector<Episode> seriesNow = series[pos].getEpisodes();
    for (int i = 0; i < seriesNow.size(); i++) {
        if(seriesNow[i].getRating()>=num1 && seriesNow[i].getRating()<=num2){
            series[i].showSeriesRating();
        }
    }
}
void StreamingPlatform::showEpisodesRating(float num1, float num2){
    
    for (int i = 0; i < series.size(); i++) {
        cout<<series[i].getName()<<endl;
        series[i].showSeriesRating();
    }
}

void StreamingPlatform::showVidRating(float num1, float num2){
    showMoviesRating(num1,num2);
    showEpisodesRating(num1,num2);

}



void StreamingPlatform::addMovie(Movie movie){
    movies.push_back(movie);
}

void StreamingPlatform::addSeries(Series _series){
    series.push_back(_series);
}

/*
bool StreamingPlatform::exists(string name){
    bool val = false;
    for (size_t i = 0; i < series.size(); i++){
        if(series[i].getName() == name){
            cout<<"true"<<endl;
            val = true;
}
    }
}
*/

bool StreamingPlatform::exists(string name){
    bool val = false;
    for (int i = 0; i < series.size(); i++){
        if(series[i].getName() == name){
            val = true;
            break;
        }
    }
    return val;
}

string StreamingPlatform::rate(string videosName, float videoRating){
    float rateo;
    int ratorsNumber;
    float newRating;
    string txt;
    for (size_t i = 0; i < movies.size(); i++) {
        if(movies[i].getName() == videosName){
            rateo = movies[i].getRating();
            ratorsNumber = movies[i].getRators();
            newRating = ((videoRating*ratorsNumber) + rateo)/ratorsNumber+1;
            movies[i].setRating(newRating);
            movies[i].setRators(ratorsNumber+1);
        }
    }
    txt += "Thanks to your rating:\tRators: " + to_string(ratorsNumber);
    txt += "\tNew rating: " + to_string(newRating);
    txt += "\nThank you for rating!";
    return txt;
}

string StreamingPlatform::rate(string seriesName, string episodeName, float videoRating){
    float rateo;
    float ratorsNumber;
    float newRating;
    string txt; 
    for (int i = 0; i < series.size(); i++) {
        if(series[i].getName() == seriesName){
            vector<Episode> eps =series[i].getEpisodes();
             cout<<"ENTROIF"<<endl;
            for (int i = 0; i < eps.size(); i++) {
                if(eps[i].getTitle()== episodeName){
                   
                    rateo = eps[i].getRating();
                    cout<<"Rateo"<<rateo<<endl;
                    ratorsNumber = eps[i].getRators();
                    cout<<"rators"<<ratorsNumber<<endl;
                    newRating = ((videoRating*ratorsNumber) + rateo)/ratorsNumber+1;
                    eps[i].setRating(newRating);
                    eps[i].setRators(ratorsNumber+1);  
                }
            }
            series[i].setSeries(eps); //actualizar el listado de episodios
        }
    }

    txt += "Thanks to your rating:\tRators: " + to_string(ratorsNumber);
    txt += "\tNew rating: " + to_string(newRating);
    txt += "\nThank you for rating!";
    return txt;
}

void StreamingPlatform::displayMenu(){
    cout<<"MOVIELAND STREAMING PLATFORM \n"<<endl;
    int option;
    
    do {
        cout<<"\nSelect an option from below: \n 1: Show videos of an specific rating \n 2: Show videos of an specific genre \n 3: Show Episodes of a Series with an specific rating \n 4: Show Movies with an specific rating \n 5: Rate a video \n 6: Show Average rating of videos \n 7: Exit \n"<<endl;
        cin >> option;
        cout<<""<<endl;
        if (option == 1){

            float ratm;
            float ratM;
            cout<<"Minimum Rating?\n";
            cin>>ratm;
            cout<<"Maximum Rating?\n";
            cin>>ratM;
            cout<<"Rating: "<<to_string(ratm)<<" - "<<to_string(ratM)<<"\n";
            showVidRating(ratm, ratM);
        } else if (option == 2){
            string gen;
            cout<<"For which genre would you like to see the videos?: ";
            cin>>gen;
            string txt = "\nGenre: ";
            txt += gen + '\n';
            cout<< txt<< endl;
            showMoviesGenre(gen);
            showEpisodesGenre(gen);
        } else if (option == 3){
            int op2;
            float ratm;
            float ratM;
            cout<<"From which series would you like to see the available episodes? Select a Series Title: \n "<<endl;
            cout<<"Select an option from below: \n 1: Peaky Blinders \n 2: How I Met your Mother \n 3: Game of Thrones \n 4: The Walking Dead "<<endl;
            cin>>op2;
            if(op2 == 1){
                showEpisodes("Peaky Blinders");
            }else if(op2 == 2){
                showEpisodes("How I Met your Mother");
            }else if(op2 == 3){
                showEpisodes("Game of Thrones");
            }else if(op2 == 4){
                showEpisodes("The Walking Dead");
            }else{
                cout<<" You chose an unexisting option"<<endl;
            }
            
            
        } else if (option == 4){
            float ratm;
            float ratM;
            cout<<"Minimum Rating?: ";
            cin>>ratm;
            cout<<"\nMaximum Rating?: ";
            cin>>ratM;
            cout<<"\nRating: "<<to_string(ratm)<<" - "<<to_string(ratM)<<"\n \n";
            showMoviesRating(ratm, ratM);
        } else if (option == 5){
            int videoOption;
            string videoName;
            string seriesName;
            float personalRating;
            cout<<"Would you like to rate a movie or an episode? Select an option \n 1: Movie \n 2: Episode\n "<<endl;
            cin>>videoOption;
            if(videoOption==1){
                cout<<"Which is the name of the Movie you want to rate? \n"<<endl;
                cin>>videoName;
                cout<<"Which is your rating? \n "<<endl;
                cin>>personalRating;
                cout<<rate(videoName, personalRating);
            } else if (videoOption==2){
                cout<<"Which is the name of the Series you want to rate? \n"<<endl;
                cin>>seriesName;
                cout<<"Which is the name of the Episode you want to rate? \n"<<endl;
                cin>>videoName;
                cout<<"Which is your rating? \n"<<endl;
                cin>>personalRating;
                cout<<rate(seriesName, videoName, personalRating)<<endl;
            }
        } else if (option==6){
            cout<<"The average rating of all videos is: \n"<<endl;
            cout<<getAverage()<<endl<<endl;
            cout<<"The average rating of each series is: \n"<<endl;
            showSeriesAverage();
        } else if (option == 7){
            cout<<"Goodbye! \n"<<endl;
            break;
        } else {
            cout << "Invalid  option,  please input a valid option. \n";
        }
    } while (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6 || option != 7);
}


void StreamingPlatform::showEpisodes(string name){
    int num = getSeries(name);
    series[num].showSeriesEpisodes();
}