#include "Tree.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

Tree::Tree()
{
    //ctor
    root = NULL;
}

Tree::~Tree()
{
    //dtor
}

TreeNode* Tree::searchGames(TreeNode* x, string title, string system, string genre)
{
    if(title != "N/A" && system == "N/A" && genre == "N/A")
    {
        if( x == NULL)
        {
            cout << "Game not found" << endl;
            return NULL;
        }
        else
        {


            if(title == x->title)
            {
                return x;

            }
            else if(title.compare(x->title) < 0)
            {
                return searchGames(x->leftChild, title, "N/A", "N/A");
            }
            else
            {
                return searchGames(x->rightChild, title, "N/A", "N/A");
            }

        }
    }
    else if(title != "N/A" && system != "N/A" && genre == "N/A") //if they have given a system and no genre
    {
        bool found = false;

        std::vector<TreeNode*> tempList = getSystemVector(system);

        for(int i = 0; i < tempList.size(); i++)
        {
            if(tempList[i]->title == title)
            {
                found = true;
                return tempList[i];
            }
        }

        if (found == false)
        {
            cout << "Game not found" << endl;
            return NULL;
        }
    }
    else if(title != "N/A" && system == "N/A" && genre != "N/A") //given a genre and no system
    {
        bool found = false;

        vector<TreeNode*> tempList = getGenreVector(genre);

        for(int i = 0; i < tempList.size(); i++)
        {
            if(tempList[i]->title == title)
            {
                found = true;
                return tempList[i];
            }
        }

        if (found == false)
        {
            cout << "Game not found" << endl;
            return NULL;
        }

    }
    else if(title != "N/A" && system != "N/A" && genre != "N/A") //if they have given everything
    {
        bool found = false;

        std::vector<TreeNode*> tempList = getSystemVector(system);

        for(int i = 0; i < tempList.size(); i++)
        {
            if(tempList[i]->title == title)
            {
                found = true;
                return tempList[i];
            }
        }

        if (found == false)
        {
            cout << "Game not found" << endl;
            return NULL;
        }
    }

}

std::vector<TreeNode*> Tree::getSystemVector(string system)
{
    if(system == "XB360")
    {
      return XB360list;
    }
    else if(system == "XBONE")
    {
        return XBONElist;
    }
    else if(system == "PS3")
    {
        return PS3list;
    }
    else if(system == "PS4")
    {
        return PS4list;
    }


}

std::vector<TreeNode*> Tree::getGenreVector(string genre)
{
    if(genre == "Shooter")
    {
        return Shooterlist;
    }
    else if(genre == "RPG")
    {
        return RPGList;
    }
    else if(genre == "Action")
    {
        return ActionList;
    }
    else if(genre == "Fighting")
    {
        return Fightlist;
    }


}

void Tree::addNode(string title, string system, string genre, int quantity, int rating)
{
    //cout << system << endl;
   int systemID = hashSum(system);

   TreeNode *x = root;
    TreeNode *y = NULL;

        while(x != NULL)
        {
            y = x;
            if(title.compare(x->title) < 0)
            {
                x = x->leftChild;

            }else{
                x = x->rightChild;
            }
        }
    //x = new TreeNode(ranking, name, released, stock);
    x = new TreeNode(title, genre, quantity, rating, systemID);
    x->parent = y;
    x->leftChild = NULL;
    x->rightChild = NULL;
    if( y == NULL)
        {
            root = x;

        }
    else if(title.compare(y->title) <  0)
        {
            y->leftChild = x;

    }else{
            y->rightChild = x;

        }

    sortVectors(x);

    /*
    // Create node
    TreeNode * newGame = new TreeNode(title, type, quantity, rating, systemID);
    TreeNode * x = root;
    TreeNode * y = NULL;

    // if tree == empty
    if (root == NULL)
    {
        root = newGame;
    }

    // if tree != empty
    else
    {
        while (x != NULL)
        {
            y = x;
            cout << "new game ::" << newGame->title << endl;
            cout << "compare game :: " << x->title << endl;
            if(newGame->title.compare(x->title) < 0)
                x = x->leftChild;
            else
                x = x->rightChild;

        }
        // set parent.
        newGame->parent = y;

        // Determine children
        if (newGame->title.compare(y->title) < 0)
            y->leftChild = newGame;
        else
            y->rightChild = newGame;
    }
    */

}

void Tree::printInventory()
{
        printInventory(root, 0);
}

void Tree::printInventory(TreeNode* node, int rating)
{
    if(node->leftChild != NULL)
    {
        printInventory(node->leftChild, rating);
    }
    if(node->rating >= rating)
    {
        std::cout << "Game: " << node->title << std::endl;
    }

    if(node->rightChild != NULL)
    {
        printInventory(node->rightChild, rating);
    }
}

void Tree::printGenreInventory(string type)
{
    if(type == "Shooter")
    {
        printGenreInventory(Shooterlist);
    }
    else if (type == "RPG")
    {
        printGenreInventory(RPGList);
    }
    else if (type == "Action")
    {
        printGenreInventory(ActionList);
    }
    else if (type == "Fighting")
    {
        printGenreInventory(Fightlist);
    }
}

void Tree::printGenreInventory(vector<TreeNode*> genreList)
{
    for(int i = 0; i < genreList.size(); i++)
    {
        cout << genreList[i]->title << endl;
    }
}

void Tree::printConsolInventory(string type)
{
    if(type == "XB360")
    {
        printConsolInventory(XB360list);
    }
    else if(type == "XBONE")
    {
        printConsolInventory(XBONElist);
    }
    else if(type == "PS3")
    {
        printConsolInventory(PS3list);
    }
    else if(type == "PS4")
    {
        printConsolInventory(PS4list);
    }
}

void Tree::printConsolInventory(vector<TreeNode*> consolList)
{
    for(int i; i < consolList.size(); i++)
    {
        cout << consolList[i]->title << endl;
    }
}

int Tree::countNodes()
{
    int counter0 = countNodes(root);

    return counter0;
}

int Tree::countNodes(TreeNode* node)
{
    int thecount = 1;

    if(node->quantity > 0 && node != NULL)
    {

        if(node->leftChild != NULL)
        {
            thecount = thecount + countNodes(node->leftChild);
        }


        if(node->rightChild != NULL)
        {
            thecount = thecount + countNodes(node->rightChild);
        }
    }
    else if(node->quantity == 0 && node != NULL)
    {
        if(node->leftChild != NULL)
        {
            thecount = countNodes(node->leftChild);
        }


        if(node->rightChild != NULL)
        {
            thecount = countNodes(node->rightChild);
        }
    }

    return thecount;
}

void Tree::removeGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "N/A"); //should we have searchVector or just change search Tree???

    if(x != NULL)
    {
        x->quantity = 0;
        cout << x->title << " has been remove from stock" << endl;
    }
}

void Tree::findGame(string title, string system, string genre)
{
      TreeNode *x = searchGames(root, title, system, genre); //should we have searchVector or just change search Tree???
      if(x != NULL)
      {

         cout << "Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title: " << x->title << endl;
         cout << "Genre: " << x->genre << endl;
         cout << "Quantity: " << x->quantity << endl;
         cout << "Rating: " << x->rating << endl;
      }
}

void Tree::rentGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "N/A");
    if(x->quantity == 0)
    {
        cout << "Game not available" << endl;
    }
    else if( x != NULL)
    {
         cout << "Game has been rented." << endl;
         cout << "Game Info: " << endl;
         cout << "===========" << endl;
         cout << "Title: " << x->title << endl;
         cout << "Genre: " << x->genre << endl;
         x->quantity = x->quantity - 1;
         cout <<"Quantity: " << x->quantity << endl;
         cout << "Rating: " << x->rating << endl;
    }

}

void Tree::returnGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "");
    if(x == NULL)
    {
        cout << "Game not found" << endl;
    }
    else if( x != NULL)
    {
         cout << "Game has been returned." << endl;
         cout << "Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title:" << x->title << endl;
         cout << "Genre:" << x->genre << endl;

         x->quantity = (x->quantity + 1);
         cout <<"Quantity:" << x->quantity << endl;
         cout << "Rating:" << x->rating << endl;
    }

}

void Tree::tradeGame(string title, string titlesystem, string trade, string tradesystem)
{
    TreeNode *x = searchGames(root, title, titlesystem, "N/A");
    TreeNode *y = searchGames(root, trade, tradesystem, "N/A");
    if(x == NULL || y == NULL)
    {
        cout << "One of the games not found" << endl;
    }
    else if( x != NULL && y != NULL)
    {
         cout << "Game has been traded." << endl;
         cout << "Old Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title:" << x->title << endl;
         cout << "Genre:" << x->genre << endl;

         x->quantity = (x->quantity + 1);
         cout <<"Quantity:" << x->quantity << endl;
         cout << "Rating:" << x->rating << endl;
         cout << endl;
         cout << "New Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title:" << y->title << endl;
         cout << "Genre:" << y->genre << endl;

         y->quantity = (y->quantity - 1);
         cout <<"Quantity:" << y->quantity << endl;
         cout << "Rating:" << y->rating << endl;
    }

}


void Tree::DeleteAll(TreeNode* node)
{

}

vector<TreeNode*> Tree::bubbleSort(vector<TreeNode*> currentVect)
{
    //printAllVectors();
    bool didSort = false;
    do
    {
        didSort = false;
    for(int i = 0; i < currentVect.size(); i++)
    {
        if(i != currentVect.size()-1)
        {

        if(currentVect[i]->title.compare(currentVect[i+1]->title) > 0)
        {
            TreeNode *temp = currentVect[i+1];
            currentVect[i+1] = currentVect[i];
            currentVect[i] = temp;
            didSort = true;
        }
        }
    }
    } while(didSort == true);
    return currentVect;
}
void Tree::sortVectors(TreeNode * node)
{
                                                //HASH VALUES
                                                    //All Consols  = 11
                                                    //Old Gen = 8
                                                    //Next Gen = 12
                                                    //Xboxes = 6
                                                    //Playstations = 0
                                                    //PS3 = 4
                                                    //XB360  = 13
                                                    //PS4 = 5
                                                    //XBONE = 2
        //Sort into system vectors

       // cout << "sorting" << node->title << endl;

        int currentsystem = node->systems;

        if(currentsystem == 11) //Everything
        {
            PS3list.push_back(node);
            PS4list.push_back(node);
            XBONElist.push_back(node);
            XB360list.push_back(node);

            PS3list = bubbleSort(PS3list);
            XB360list = bubbleSort(XB360list);
            PS4list = bubbleSort(PS4list);
            XBONElist = bubbleSort(XBONElist);


        }
        else if(currentsystem == 8) //Old gen Only
        {
            PS3list.push_back(node);
            XB360list.push_back(node);

            PS3list = bubbleSort(PS3list);
            XB360list = bubbleSort(XB360list);

        }
        else if(currentsystem == 12) //Next gen only
        {
            PS4list.push_back(node);
            XBONElist.push_back(node);

            PS4list = bubbleSort(PS4list);
            XBONElist = bubbleSort(XBONElist);
        }
        else if(currentsystem == 6) //Xbox only
        {
            XBONElist.push_back(node);
            XB360list.push_back(node);


            XB360list = bubbleSort(XB360list);

            XBONElist = bubbleSort(XBONElist);
        }
        else if(currentsystem == 0) //playstations only
        {
            PS3list.push_back(node);
            PS4list.push_back(node);

            PS3list = bubbleSort(PS3list);

            PS4list = bubbleSort(PS4list);

        }
        else if(currentsystem == 4) //PS3 Only
        {
            PS3list.push_back(node);

            PS3list = bubbleSort(PS3list);

        }
        else if(currentsystem == 13) //XB360 Only
        {
            XB360list.push_back(node);

            XB360list = bubbleSort(XB360list);

        }
        else if(currentsystem == 5) //PS4 ONLY
        {
            PS4list.push_back(node);

            PS4list = bubbleSort(PS4list);

        }
        else if(currentsystem == 2) //XBONE ONLY
        {
            XBONElist.push_back(node);

            XBONElist = bubbleSort(XBONElist);
        }



    //Sort into genre vector

    string currrentgenre = node->genre;

    if(currrentgenre == "rpg")
    {
        RPGList.push_back(node);

        RPGList = bubbleSort(RPGList);
    }
    else if(currrentgenre == "fighting")
    {
        Fightlist.push_back(node);

        Fightlist = bubbleSort(Fightlist);
    }
    else if(currrentgenre == "shooter")
    {
        Shooterlist.push_back(node);

        Shooterlist = bubbleSort(Shooterlist);
    }
    else if(currrentgenre == "action")
    {
        ActionList.push_back(node);

        ActionList = bubbleSort(ActionList);
    }

}

int Tree::hashSum(string title)
{
    int hashSize = 14;
    int sum  = 0;
    for(int i = 0; i < title.length(); i++)
    {
        sum = sum + title[i];
        //cout << sum << endl;
    }
    sum = sum % hashSize;
    return sum;
}

void Tree::printAllVectors()
{
    cout <<"360" << endl;
    for(int i = 0; i < XB360list.size(); i++)
    {
        cout << XB360list[i]->title << endl;
    }

    cout << "++++++++++++++++++++++++++++++" <<endl;
    cout <<"ps3" << endl;
    for(int i = 0; i < PS3list.size(); i++)
    {
       cout << PS3list[i]->title << endl;
    }

        cout << "++++++++++++++++++++++++++++++" <<endl;
        cout << "ps4" << endl;
    for(int i = 0; i < PS4list.size(); i++)
    {
       cout << PS4list[i]->title << endl;
    }

        cout << "++++++++++++++++++++++++++++++" <<endl;
        cout << "XBONE" << endl;
    for(int i = 0; i < XBONElist.size(); i++)
    {
        cout << XBONElist[i]->title << endl;
    }


}

void Tree::recommendGame(int rating, string genre, string system)
{
    vector<TreeNode*> GameList;
    bool useVect = false;
    if(genre != "N/A")
    {
        GameList = getGenreVector(genre);
        useVect = true;
    }
    else if(system != "N/A")
    {
        GameList = getSystemVector(system);
        useVect = true;
    }


    if(useVect == true)
    {
        for(int i = 0; i < GameList.size(); i++)
        {
            if(GameList[i]->rating >= rating)
            {
                cout << GameList[i]->title << endl;
            }
        }
    }
    else
    {
        //print inventory with restrictions
        printInventory(root, rating);
    }


}
