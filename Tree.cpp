#include "Tree.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Tree::Tree()
{
    //ctor
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
        }
    }
    else if(title != "N/A" && system == "N/A" && genre != "N/A")
    {
        bool found = false;

        std::vector<TreeNode*> tempList = getGenreVector(genre);

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

void Tree::addNode(string title, string type, int quantity, int rating, vector<string> system)
{

    // Create node
    TreeNode * newGame = new TreeNode(title, type, quantity, rating, system);
    TreeNode * x = root;
    TreeNode * y = NULL;

    // if tree == empty
    if (root == NULL)
        root = newGame;

    // if tree != empty
    else
    {
        while (x != NULL)
        {
            y = x;
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
/*
    //Sort into system vectors
    for( int i = 0; i < newGame->systems.size(); i++)
    {
        string currentsystem = newGame->systems[i];

        if(currentsystem == "PS3")
        {
            PS3list.push_back(newGame);
        }
        else if(currentsystem == "XB360")
        {
            XB360list.push_back(newGame);
        }
        else if(currentsystem == "XBONE")
        {
            XBONElist.push_back(newGame);
        }
        else if(currentsystem == "PS4")
        {
            PS4list.push_back(newGame);
        }

    }

    //Sort into genre vector

    string currrentgenre = newGame->genre;

    if(currrentgenre == "rpg")
    {
        RPGList.push_back(newGame);
    }
    else if(currrentgenre == "fighting")
    {
        Fightlist.push_back(newGame);
    }
    else if(currrentgenre == "shooter")
    {
        Shooterlist.push_back(newGame);
    }
    else if(currrentgenre == "action")
    {
        ActionList.push_back(newGame);
    }
    */
}

void Tree::printInventory()
{
        printInventory(root);
}

void Tree::printInventory(TreeNode* node)
{
    if(node->leftChild != NULL)
    {
        printInventory(node->leftChild);
    }

    std::cout << "Game: " << node->title << std::endl;

    if(node->rightChild != NULL)
    {
        printInventory(node->rightChild);
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
        cout << genreList[i] << endl;
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
        cout << consolList[i] << endl;
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
         cout << "Title:" << x->title << endl;
         cout << "Genre:" << x->genre << endl;
         cout << "Quantity:" << x->quantity << endl;
         cout << "Rating:" << x->rating << endl;
      }
}

void Tree::rentGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "");
    if(x->quantity == 0)
    {
        cout << "Game not available" << endl;
    }
    else if( x != NULL)
    {
         cout << "Game has been rented." << endl;
         cout << "Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title:" << x->title << endl;
         cout << "Genre:" << x->genre << endl;

         x->quantity = (x->quantity - 1);
         cout <<"Quantity:" << x->quantity << endl;
         cout << "Rating:" << x->rating << endl;
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
    if(x == NULL && y == NULL)
    {
        cout << "One of the games not found" << endl;
    }
    else if( x != NULL)
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

void Tree::recommendGame(int rating, string type, vector<string> system)
{

}

void Tree::DeleteAll(TreeNode* node)
{

}

void Tree::sortVectors()
{
    sortVectors(root);
}

void Tree::sortVectors(TreeNode * node)
{
    if(node->leftChild != NULL)
    {
        printInventory(node->leftChild);
    }
        //Sort into system vectors
    for( int i = 0; i < node->systems.size(); i++)
    {
        string currentsystem = node->systems[i];

        if(currentsystem == "PS3")
        {
            PS3list.push_back(node);
        }
        if(currentsystem == "XB360")
        {
            XB360list.push_back(node);
        }
        if(currentsystem == "XBONE")
        {
            XBONElist.push_back(node);
        }
        if(currentsystem == "PS4")
        {
            PS4list.push_back(node);
        }

    }

    //Sort into genre vector

    string currrentgenre = node->genre;

    if(currrentgenre == "rpg")
    {
        RPGList.push_back(node);
    }
    else if(currrentgenre == "fighting")
    {
        Fightlist.push_back(node);
    }
    else if(currrentgenre == "shooter")
    {
        Shooterlist.push_back(node);
    }
    else if(currrentgenre == "action")
    {
        ActionList.push_back(node);
    }

    if(node->rightChild != NULL)
    {
        printInventory(node->rightChild);
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
