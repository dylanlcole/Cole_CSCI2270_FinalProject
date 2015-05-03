#ifndef TREE_H
#define TREE_H

#include<string>
#include<vector>


struct GenreNode;
struct SystemNode;
struct StartNode;

struct TreeNode{
    //int ranking;
    std::string title;
    int systems;
    std::string genre;
    int quantity;
    int rating;
    TreeNode *parent;
    TreeNode *leftChild;
    TreeNode *rightChild;

    TreeNode(){};

    TreeNode(std::string in_title, std::string in_genre, int in_quantity, int in_rating, int in_system)
    {
        //ranking = in_ranking;
        title = in_title;
        genre = in_genre;
        quantity = in_quantity;
        rating = in_rating;
        systems = in_system;
    }

};


class Tree
{
    public:
        Tree();
        virtual ~Tree();
        void printInventory();
        void printGenreInventory(std::string type);
        void printConsolInventory(std::string type);
        int countNodes();
        void removeGame(std::string title, std::string system);
        void addNode(std::string title, std::string systems, std::string type, int quantity, int rating);
        void findGame(std::string title, std::string system, std::string genre);
        void rentGame(std::string title, std::string system);
        void returnGame(std::string title, std::string system);
        void tradeGame(std::string title, std::string titlesystem, std::string trade, std::string tradesystem);
        void recommendGame(int rating, std::string type, std::string system);
		int gamesInStock(TreeNode *node);
		int gamesInStock();
        void printAllVectors();

    protected:
    private:

        void sortVectors(TreeNode * node);
        void printInventory(TreeNode * node, int rating);
        void printGenreInventory(std::vector<TreeNode*> genreList);
        void printConsolInventory(std::vector<TreeNode*> consolList);
        int countNodes(TreeNode *node);

        TreeNode* searchGames(TreeNode * x, std::string title, std::string system, std::string genre);
        std::vector<TreeNode*> getSystemVector(std::string system);
        std::vector<TreeNode*> getGenreVector(std::string genre);
        int hashSum(std::string title);
        std::vector<TreeNode*> bubbleSort(std::vector<TreeNode*> currentVect);
        std::vector<TreeNode*> shellSort(std::vector<TreeNode*> currentVect);
        TreeNode *root;
        std::vector<TreeNode*> XBONElist;
        std::vector<TreeNode*> PS4list;
        std::vector<TreeNode*> XB360list;
        std::vector<TreeNode*> PS3list;
        std::vector<TreeNode*> Shooterlist;
        std::vector<TreeNode*> RPGList;
        std::vector<TreeNode*> ActionList;
        std::vector<TreeNode*> Fightlist;



};

#endif // TREE_H
