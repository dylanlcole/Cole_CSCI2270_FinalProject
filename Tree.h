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
    std::vector<std::string> system;
    std::string genre;
    int quantity;
    int rating;
    TreeNode *parent;
    TreeNode *leftChild;
    TreeNode *rightChild;

    TreeNode(){};

    TreeNode(std::string in_title, std::string in_genre, int in_quantity, int in_rating, std::vector<std::string> in_system)
    {
        //ranking = in_ranking;
        title = in_title;
        genre = in_genre;
        quantity = in_quantity;
        rating = in_rating;
        system = in_system;
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
        void deleteNode(std::string title); //should we have this or just have it say out of stock?
        void addNode(std::string title, std::string type, int quantity, int rating, std::vector<std::string> systems);
        void findGame(std::string title);
        void rentGame(std::string title);
        void returnGame(std::string title);
        void tradeGame(std::string title);
        void recommendGame(int rating, std::string type, std::vector<std::string> system);
       // void updateGame(std::string title, std::string type, int rating, std::string newsystem);


    protected:
    private:
        TreeNode* findMin(TreeNode * node);
        void swapNode(TreeNode *oldnode, TreeNode *newnode);
        void DeleteAll(TreeNode * node); //use this for the post-order traversal deletion of the tree
        void printInventory(TreeNode * node);
        void printGenreInventory(TreeNode * node);
        void printConsolInventory(TreeNode * node);
        int countNodes(TreeNode *node);
        //vector<std::string> recommendGame();
        TreeNode* searchTree(TreeNode * node, std::string title, std::string system, std::string genre);
        TreeNode *root;
        std::vector<TreeNode*> XBONElist;
        std::vector<TreeNode*> PS4list;
        std::vector<TreeNode*> Shooterlist;
        std::vector<TreeNode*> RPGList;
        std::vector<TreeNode*> ActionList;
        std::vector<TreeNode*> SimList;

};

#endif // TREE_H
