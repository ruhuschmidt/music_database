#include "artists.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

//CONSTRUCTOR
artistsDatabase::artistsDatabase(){

}
//DESTRUCTOR
artistsDatabase::~artistsDatabase(){

}

//ADD VERTEX
void artistsDatabase::addV(string name, string genre){
  artist art;
  art.name=name;
  art.genre=genre;
  verts.push_back(art);
}

//ADD EDGE
void artistsDatabase::addE(string name, string genre){
  for(int i=0;i<verts.size();i++){
    if(verts[i].name==name){
      for(int j=0;j<verts.size();j++){
        if(verts[j].genre==genre&&j!=i){
          artGenre gen;
          gen.A=&verts[j];
          verts[i].edges.push_back(gen);
        }
      }
    }
  }

}

//FIND VERTEX
artist* artistsDatabase::find(string name){
  for(int i=0;i<verts.size();i++){
    if(verts[i].name==name){
      return &verts[i];
    }
  }
}

//FIND RELATED ARTIST
void artistsDatabase::related(string name){
  queue<artist*> que;
  artist* vert = find(name);
  vert->visited=true;
  que.push(vert);

while(!que.empty()){
  vert=que.front();
  que.pop();
  for(int i=0; i<vert->edges.size();i++){
    if(vert->edges[i].A->visited!=true){
      vert->edges[i].A->visited =true;
      que.push(vert->edges[i].A);
      cout<<vert->edges[i].A->name<<", ";
    }
  }
}

} //BFS search?
string artistsDatabase::genre(string genre){

}//BFS  search?
string artistsDatabase::viewLibray(){

}
string artistsDatabase::addArtist(string name, string genre){

}
string artistsDatabase::displayLibrary(){

}
string artistsDatabase::addToMyLibrary(string name, string genre){

}
string artistsDatabase::removeFromMyLibrary(string name){

}


void artistsDatabase::displayEdges(){
  for (int i=0;i<verts.size();i++) {
   cout<<verts[i].name<<" ->";
   for (int j = 0;j<verts[i].edges.size();j++){
     cout<<verts[i].edges[j].A->name<<"->";
   }
   cout<<endl;
 }
}


int main(int argc, char*argv[]){
    artistsDatabase yay;
   ifstream myfile("artFile.txt");
  string line;
  if(myfile.is_open()){
    while(getline(myfile,line)){
      stringstream comp;
      comp<<line;
      string genre;
      string name;
      int count=0;
      while(getline(comp, line, ',')){
        if (count == 0) {
  				name =line;
  			}
  			else if (count == 1) {
  				genre = line;
  			}
  			count++;
  		}
    //cout<<name<<" "<<genre;
     yay.addV(name, genre);
     yay.addE(name,genre);
   }
  }
  else{
    cout<<"failed to open file"<<endl;
  }
   yay.displayEdges();
    // MENU

    string choice;
    string name;
    string genre;

    cout<<"======Main Menu======"<<endl;
    cout<<"1. Search for Related Artists"<<endl;
    cout<<"2. Search Genre"<<endl;
    cout<<"3. View My Libray"<<endl;
    cout<<"4. Add an Artist to the Database"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>choice;
    while(choice!="5"){
        if(choice=="1"){
          cout<<"Enter Artist Name: ";
          cin>>name;
          yay.related(name);
        }
        if(choice=="2"){
          cout<<"Enter Genre: ";
          cin>>genre;
          yay.genre(genre);


        }
        if(choice=="3"){
          string choice2;
          string name2;
          string genre2;
          cout<<"======My Library======"<<endl;
          cout<<"1. Dispaly My Library"<<endl;
          cout<<"2. Add an Artist to My Library"<<endl;
          cout<<"3. Remove an Artist from My Libray"<<endl;
          cout<<"4. Exit to Main Menu"<<endl;
          cin>>choice2;
          while(choice2!="4"){
              if(choice2=="1"){
                yay.displayLibrary();
              }
              if(choice2=="2"){
                cout<<"Enter Name: ";
                cin>>name2;
                cout<<"Enter Genre: ";
                cin>>genre2;
                yay.addToMyLibrary(name2, genre2);
              }
              if(choice2=="3"){
                cout<<"Enter Name of Artist to Remove: ";
                cin>>name2;
                yay.removeFromMyLibrary(name2);
              }
              if(choice2=="4"){
                cout<<"Goodbye!";
              }
            }
          }
    if(choice=="4"){
      cout<<"Enter Name: ";
      cin>>name;
      cout<<"Enter Genre";
      cin>>genre;
      yay.addArtist(name,genre);
    }
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Search for Related Artists"<<endl;
    cout<<"2. Search Genre"<<endl;
    cout<<"3. View My Libray"<<endl;
    cout<<"4. Add an Artist to the Database"<<endl;
    cout<<"5. Quit"<<endl;
    cin>>choice;
    }

    if(choice=="5"){
      cout<<"Goodbye!"<<endl;
}

    return 0;
}
