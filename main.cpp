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
    int numIn;
    Tree *T = new Tree;

    //////////////////////////////////////////
    ////////Read in text file to get games////
    ////////and all of their traits.//////////
    /////Will run automatically, no///////////
    ////pre-condition needed.  Post-condition/
    ////is a filled tree, through use of add//
    //////////////////////////////////////////
    while (getline(file,tempLine)) {
        string title, system, type, tempWord;
        int rating, stock;
        stringstream line;
        line<<tempLine; //convert lines into stringstreams to get each delimited section
        //cout<<tempLine<<endl;
        getline(line,title,',');
        getline(line,system,',');
        getline(line,type,',');
        getline(line,tempWord,',');
        stock = atoi (tempWord.c_str());
        getline(line,tempWord);
        rating = atoi (tempWord.c_str());
        //cout<<title<<system<<type<<rating<<stock<<endl;
        //cout << "about to add " << title << endl;
        T->addNode(title,system,type,stock, rating);

       // cout << "added " << title << endl;

    }

    while (numIn != 12) {
        cout << "======Main Menu======" << endl;
        cout <<  "1. Print full inventory" << endl;
        cout <<  "2. Print inventory of specific genre" << endl;
        cout <<  "3. Print inventory of specific console" << endl;
        cout <<  "4. Count number of available" << endl;
        cout <<  "5. Remove game" << endl;
        cout <<  "6. Add game" << endl;
        cout <<  "7. Find game" << endl;
        cout <<  "8. Rent game" << endl;
        cout <<  "9. Return game" << endl;
        cout <<  "10. Trade game" << endl;
        cout <<  "11. Game recommend" << endl;
        cout <<  "12. Quit" << endl;

        cin>>numIn;

        if (numIn == 1) {
            T->printAllVectors();
        }
        if (numIn == 2) {
            cin.ignore();
            int choice;
            cout<<"Enter what genre:\n1:Shooter\n2:RPG\n3:Action\n4:Fighting"<<endl;
            cin>>choice;
            if (choice == 1) { T->printGenreInventory("Shooter"); }
            if (choice == 2) { T->printGenreInventory("RPG"); }
            if (choice == 3) { T->printGenreInventory("Action"); }
            if (choice == 4) { T->printGenreInventory("Fighting"); }
        }
        if (numIn == 3) {
            cin.ignore();
            int choice;
            cout<<"Enter what console:\n1:XB360\n2:XBONE\n3:PS3\n4:PS4"<<endl;
            cin>>choice;
            if (choice == 1) { T->printConsolInventory("XB360"); }
            if (choice == 2) { T->printConsolInventory("XBONE"); }
            if (choice == 3) { T->printConsolInventory("PS3"); }
            if (choice == 4) { T->printConsolInventory("PS4"); }
        }
        if (numIn == 4) {
            cout<<"Number of games: "<<T->countNodes()<<endl;
        }
        if (numIn == 5) {
            string title, console;
            cin.ignore();
            cout<<"Enter the title of the game:"<<endl;
            getline(cin,title);
            cout<<"Enter the console it is on:"<<endl;
            getline(cin,console);
            T->removeGame(title,console);
        }
       /* if (numIn == 11) {
            cout<<"Enter any of the following: Title, system, genre, or rating:"<<endl;
            string lineIn;
            getline(cin,lineIn);
            if (lineIn == "XB360" || lineIn == "XBONE" || lineIn == "PS4" || lineIn == "PS4") {
                T->findGame()
            }
        }*/


    }

    //T->sortVectors();
    //T->printInventory();
    //T->printAllVectors();
    //T->printGenreInventory("Fighting");
    //T->printConsolInventory("XBONE");
    //cout << T->countNodes() << endl;
    //T->removeGame("Titanfall", "XBONE");
    //T->removeGame("Destiny", "XB360");
    T->findGame("Dark Souls", "N/A", "N/A");
    //T->removeGame("Dark Souls", "PS3");
    //T->findGame("Dark Souls", "N/A", "N/A");
    T->rentGame("Dark Souls", "N/A");
    T->returnGame("Dark Souls", "XB360");
    T->tradeGame("Titanfall", "XBONE", "Dark Souls", "N/A");
    T->tradeGame("Titanfall", "XBONE", "XXXXXXXX", "N/A");


    return 0;
}
