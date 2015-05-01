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
/*
Function prototype:
TreeNode* Tree::searchGames(TreeNode* x, string title, string system, string genre);

Function description:
This function will find a game by taking in the root of the tree, the title, system, and genre.
Based on the amount of information given, it will either search the tree or get the vector that the node
would be a part of based on the system and/or genre

Example:
TreeNode* game = searchGames(root, "Titanfall", "XBONE", "Shooter")

Pre-conditions: tree and vectors have been built and added to
Post-conditions: returns a TreeNode pointer

*/
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
        if(tempList.size() != 0)
        {
            for(int i = 0; i < tempList.size(); i++)
            {
                if(tempList[i]->title == title)
                {
                    found = true;
                    return tempList[i];
                }
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
        if(tempList.size() != 0)
        {
            for(int i = 0; i < tempList.size(); i++)
            {
                if(tempList[i]->title == title)
                {
                    found = true;
                    return tempList[i];
                }
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
        if(tempList.size() != 0)
        {
            for(int i = 0; i < tempList.size(); i++)
            {
                if(tempList[i]->title == title)
                {
                    found = true;
                    return tempList[i];
                }
            }
        }

        if (found == false)
        {
            cout << "Game not found" << endl;
            return NULL;
        }
    }

}
/*
Function prototype:
vector<TreeNode*> Tree::getSystemVector(string system);

Function description:
This function finds the system vector that is associated with the string given

Example:
vector<TreeNode*> tempVector = getSystemVector("PS3");

Pre-conditions: a system that has been read from the test file
Post-conditions: returns a vector of Tree node pointers
*/

vector<TreeNode*> Tree::getSystemVector(string system)
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
    else
    {
        vector<TreeNode*> nullVect;
        return nullVect;
    }


}
/*
Function prototype:
vector<TreeNode*> Tree::getGenreVector(string system);

Function description:
This function finds the genre vector that is associated with the string given

Example:
vector<TreeNode*> tempVector = getGenreVector("PS3");

Pre-conditions: a genre that has been read from the test file
Post-conditions: returns a vector of Tree node pointers
*/

vector<TreeNode*> Tree::getGenreVector(string genre)
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
    else
    {
        vector<TreeNode*> nullVect;
        return nullVect;
    }


}

/*
Function Prototype:
void Tree::addNode(string title, string system, string genre, int quantity, int rating);

Function description:
This function takes the information from the line in the text file, turns it into a node,
and adds it to the tree.

Example:
Tree T;
T->addNode("Portal 2", "PS3/XB360", "action", "8", "10")

Pre-conditions: tree must have a root
Post-conditions: tree has new node
*/

void Tree::addNode(string title, string system, string genre, int quantity, int rating)
{
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
}
/*
Function prototype:
void Tree::printInventory();

Function description:
This function calls printInventory with a root and a rating of 0

Example:
Tree T
T->printInventory()

Pre-conditions: tree as been built
Post-conditions: prints all nodes
*/

void Tree::printInventory()
{
        printInventory(root, 0);
}
/*
Function prototype:
void Tree::printInventory(TreeNode* node, int rating);

Function description:
This function traverses the tree and prints the inventory that has rating >= given rating

Example:
printInventory(root, 5)

Pre-conditions: tree as been built
Post-conditions: prints all nodes with given rating
*/

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

/*
Function prototype:
void Tree::printGenreInventory(string type);

Function description:
This function sends the vector to the private printGenreInventory function to print all nodes in
the vector

Example:
Tree T
T->printGenreInventory("Shooter")

Pre-conditions: type is a valid string
Post-conditions: prints the inventory
*/

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
/*
Function prototype:
void Tree::printGenreInventory(vector<TreeNode*> genreList);

Function description:
Using the given vector and printing it elements

Example:
printGenreInventory(ActionList)

Pre-conditions: the vector consists of GameNode*
Post-conditions: prints the inventory
*/

void Tree::printGenreInventory(vector<TreeNode*> genreList)
{
    for(int i = 0; i < genreList.size(); i++)
    {
        cout << genreList[i]->title << endl;
    }
}

/*
Function prototype:
void Tree::printConsolInventory(string type);

Function description:
This function sends the vector to the private printConsolInventory function to print all nodes in
the vector

Example:
Tree T
T->printConsolInventory("XBONE")

Pre-conditions: type is a valid string
Post-conditions: prints the inventory
*/

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

/*
Function prototype:
void Tree::printConsolInventory(vector<TreeNode*> genreList);

Function description:
Using the given vector and printing it elements

Example:
printConsolInventory(XBONEList)

Pre-conditions: the vector consists of GameNode*
Post-conditions: prints the inventory
*/

void Tree::printConsolInventory(vector<TreeNode*> consolList)
{
    for(int i; i < consolList.size(); i++)
    {
        cout << consolList[i]->title << endl;
    }
}

/*
Function prototype:
int Tree::countNodes()

Function description:
This function calls private countNpdes and returns the amount of nodes in the Tree

Example:
Tree T
int number = T->countNodes()

Pre-conditions: tree has been built
Post-conditions: returns a non-negative integer
*/

int Tree::countNodes()
{
    int counter0 = countNodes(root);

    return counter0;
}
/*
Function prototype:
int Tree::countNodes(TreeNode* node)

Function description:
This function traverses the tree and counts amount of nodes in tree

Example:
countNodes(root)

Pre-conditions: tree has been built
Post-conditions: returns a non-negative integer
*/

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

int Tree::gamesInStock()
{
	gamesInStock(root);
}

int Tree::gamesInStock(TreeNode *node)
{
	int count = 0;
	if(node != NULL)
	{
		count = node->quantity;
		if(node->leftChild != NULL)
		{
			count += gamesInStock(node->leftChild);
		}
		if(node->rightChild != NULL)
		{
			count += gamesInStock(node->rightChild);
		}
	}
	return count;
}
/*
Function prototype:
void Tree::removeGame(string title, string system)

Function description:
This function updates a specific node to have an inventory of 0

Example:
Tree T
T->removeGame("Rambo")

Pre-conditions: title and system is a valid string
Post-conditions: updates the node to have inventory of 0
*/
void Tree::removeGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "N/A");

    if(x != NULL)
    {
        x->quantity = 0;
        cout << x->title << " has been removed from stock" << endl;
    }
}

/*
Function prototype:
void Tree::findGame(string title, string system, string genre)

Function description:
This function looks for a game in the tree and displays its information

Example:
Tree T
T->findGame("Portal 2", "XB360", "N/A")

Pre-conditions: title, system and genre are valid strings
Post-condition: prints the node information
*/

void Tree::findGame(string title, string system, string genre)
{
      TreeNode *x = searchGames(root, title, system, genre);
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

/*
Function prototype:
void Tree::rentGame(string title, string system)

Function description:
This function finds a gameNode and removes one from the inventory.

Example:
Tree T
T->rentGame("Portal 2", "PS3")

Pre-conditions: title and system are valid string
Post-conditions: updates the inventory
*/

void Tree::rentGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "N/A");
    if(x->quantity == 0)
    {
        cout << "Game not available" << endl;
    }
    else if( x != NULL)
    {
         cout << "Game has been rented" << endl;
         cout << "Game Info: " << endl;
         cout << "===========" << endl;
         cout << "Title: " << x->title << endl;
         cout << "Genre: " << x->genre << endl;
         x->quantity = x->quantity - 1;
         cout <<"Quantity: " << x->quantity << endl;
         cout << "Rating: " << x->rating << endl;
    }

}

/*
Function prototype:
void Tree::returnGame(string title, string system)

Function description:
This function finds a gameNode and adds one to the inventory.

Example:
Tree T
T->returnGame("Portal 2", "PS3")

Pre-conditions: title and system are valid string
Post-conditions: updates the inventory
*/
void Tree::returnGame(string title, string system)
{
    TreeNode *x = searchGames(root, title, system, "N/A");
    if(x == NULL)
    {
        //cout << "Game not found" << endl;
    }
    else if( x != NULL)
    {
         cout << "Game has been returned" << endl;
         cout << "Game Info:" << endl;
         cout << "===========" << endl;
         cout << "Title:" << x->title << endl;
         cout << "Genre:" << x->genre << endl;

         x->quantity = (x->quantity + 1);
         cout <<"Quantity:" << x->quantity << endl;
         cout << "Rating:" << x->rating << endl;
    }

}

/*
Function Prototype:
void Tree::tradeGame(string title, string titlesystem, string trade, string tradesystem)

Function description:
This function updates the inventory of two games of the users choosing by increasing the one by one
and decreasing the other by one.

Example:
Tree T
T->tradeGame("Portal 2", "PS3", "Rambo", "XB360")

Pre-conditions: the strings are valid strings
Post-conditions: the two games are updated
*/
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
         cout << "Game has been traded" << endl;
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

/*
Function prototype:
vector<TreeNode*> Tree::bubbleSort(vector<TreeNode*> currentVect)

Function description:
This functions sorts the vector the the nodes are in alphabetical order

Example:
bubbleSort(XB360list);

Pre-condition: currentVect is a valid vector
Post-condition: vector has been updated
*/
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

/*
Function prototype:
void Tree::sortVectors(TreeNode * node)

Function description:
This function sorts the given node into the correct vectors based on genre and systems

Example:
sortVectors(gameNode)

Pre-conditions: node has non-NULL variables
Post-conditions: node is added to the vectors

*/
void Tree::sortVectors(TreeNode * node)
{

        //Sort into system vectors

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

/*
Function Prototype:
int Tree::hashSum(string title)

Function description:
This functions finds the hashSum for all of the possible system options

Example:
hashSum("XBONE")

Pre-conditions: title is a valid string
Post-conditions: returns a non-negative integer
*/
int Tree::hashSum(string title)
{
    int hashSize = 14;
    int sum  = 0;
    for(int i = 0; i < title.length(); i++)
    {
        sum = sum + title[i];
    }
    sum = sum % hashSize;
    return sum;
}

/*
Function prototype:
void Tree::printAllVectors()

Function description:
This function was used for debugging to see what existed in each vector.

Example:
Tree T
T->printAllVectors()

Pre-conditions: vectors have been made and nodes added to them
Post-conditions: prints out contents of vectors
*/
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

/*
Function prototype:
void Tree::recommendGame(int rating, string genre, string system)

Function description:
This function will find games that fit the parameters that the user give it.  Rating given is a
minimum number for the nodes.

Example:
Tree T
T->recommendGame(4, "Action", "PS3")

Pre-conditions: rating is a integer >=0.  genre and system are valid strings
Post-conditions: prints out all games that have at least the given rating
*/
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

    bool foundGame = false;
    if(useVect == true)
    {
        for(int i = 0; i < GameList.size(); i++)
        {
            if(GameList[i]->rating >= rating)
            {
                cout << GameList[i]->title << endl;
                foundGame = true;
            }
        }

        if(foundGame == false)
        {
            cout << "Was unable to find games to recommend" << endl;
        }
    }
    else
    {
        //print inventory with restrictions
        printInventory(root, rating);
    }


}
