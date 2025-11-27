#include <iostream>
#include <string>

class TreeNode // deep copy semantics
{
public:

    TreeNode():
        value(), 
        count(0),
        left(nullptr),
        right(nullptr)
    {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }

    TreeNode(const TreeNode &other):
        value(other.value),
        count(other.count),
        left(other.left ? new TreeNode(*other.left) : nullptr),
        right(other.right ? new TreeNode(*other.right) : nullptr)
    {}

    TreeNode& operator=(const TreeNode &rhs)
    {
        if (this != &rhs)
        {
            delete left;
            delete right;

            value = rhs.value;
            count = rhs.count;
            
            left = (rhs.left ? new TreeNode(*rhs.left) : nullptr);
            right = (rhs.right ? new TreeNode(*rhs.right) : nullptr);
        }

        return *this;
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{

public:
    
    BinStrTree(): root(nullptr)
    {}

    ~BinStrTree()
    {
        delete root;
    }

    BinStrTree(const BinStrTree &other):
        root(other.root ? new TreeNode(*other.root) : nullptr)
    {}

    BinStrTree& operator=(const BinStrTree &rhs)
    {
        if (this != &rhs)
        {
            delete root;
            root = rhs.root ? new TreeNode(*rhs.root) : nullptr;
        }

        return *this;
    }

private:
    TreeNode *root;
};

int main()
{
    return EXIT_SUCCESS;
}