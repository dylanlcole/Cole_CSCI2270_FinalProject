#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Tree.h"

using namespace std;

int main(int argc, char * argv[])
{
    ifstream file;
    string tempLine;//full line
    if (argc == 1) file.open("gameList.txt");//open gameList.txt if no other file names are provided
    else file.open(argv[1]);//otherwise open what is provided in the call
    if(file.fail()) { return -1; }

    Tree *T = new Tree;

    //////////////////////////////////////////
    ////////Read in text file to get games////
    ////////and all of their traits.//////////
    /////Will run automatically, no///////////
    ////pre-condition needed.  Post-condition/
    ////is a filled tree, through use of add//
    //////////////////////////////////////////
    while (getline(file,tempLine)) {
        string title, format, type, tempWord;
        int rating, stock;
        stringstream line;
        line<<tempLine; //convert lines into stringstreams to get each delimited section
        //cout<<tempLine<<endl;
        getline(line,title,',');
        getline(line,format,',');
        getline(line,type,',');
        getline(line,tempWord,',');
        stock = atoi (tempWord.c_str());
        getline(line,tempWord);
        rating = atoi (tempWord.c_str());
        //cout<<title<<format<<type<<rating<<stock<<endl;
        //cout << "about to add " << title << endl;
        T->addNode(title,format,type,stock, rating);

       // cout << "added " << title << endl;

    }

    //T->sortVectors();
    //T->printInventory();
    T->printAllVectors();
   // T->printGenreInventory("Fighting");


    return 0;
}
