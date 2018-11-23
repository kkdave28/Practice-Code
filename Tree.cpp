#include <bits/stdc++.h>

struct BST
{
    int key;
    BST * left, * right;
};
void insert(BST ** root, int key)
{
    if(!(*root))
    {
        BST * temp = new BST;
        temp->key = key;
        (*root) = temp;
        temp->left = temp->right = nullptr;
        return;
    }
    if((*root)->key > key)
        insert(&(*root)->left, key);
    else if((*root)->key < key)
        insert(&(*root)->right, key);
}
void inorder(BST * tree)
{
    if(!tree)
        return;
    if(tree->left)
        inorder(tree->left);
    std::cout<<tree->key<<std::endl;
    if(tree->right)
        inorder(tree->right);

}
void free_tree(BST* tree)
{
    if(!tree)
        return;
    if(tree->left)
        free_tree(tree->left);
    if(tree->right)
        free_tree(tree->right);
    delete(tree);
}
int greatest(BST * root)
{
    root = root->left;
    while(root->right)
        root = root->right;
    return root->key;
}
int least(BST * root)
{
    root = root->right;
    while(root->left)
        root = root->left;
    return root->key;
}
bool isBST(BST* root) {
    if(!root)
        return true;
    if((!root->left || greatest(root) < root->key)&& (!root->right || least(root) > root->key) )
        return isBST(root->left) && isBST(root->right);
    else
        return false;
}
void leftView(BST * tree)
{
    if(!tree)
        return;
    std::cout<<tree->key<<std::endl;
    if(tree->left)
        leftView(tree->left);
}
BST * get_rightmostnode(BST * root)
{
    if(!root->right)
        return root;
    return get_rightmostnode(root->right);

}
BST * getLeftmostNode(BST* root)
{
        if(!root->left)
        return root;
    return getLeftmostNode(root->left);
}
void deleteNode(BST ** tree, int key)
{
    if(!(*tree))
        return;
    if((*tree)->key == key)
    {
        BST * node_to_purge = nullptr;
        if(!(*tree)->left)
        {
            node_to_purge = (*tree)->right;
            delete((*tree));
            (*tree) = node_to_purge;
        }
        else if(!(*tree)->right)
        {
            node_to_purge = (*tree)->left;
            delete(*tree);
            (*tree) = node_to_purge;
        }
        else
        {
            node_to_purge = getLeftmostNode((*tree)->right);
            (*tree)->key = node_to_purge->key;
            deleteNode(&(*tree)->right, node_to_purge->key);
        }
        return;
    }
    else if((*tree)->key > key)
    {
        deleteNode(&(*tree)->left, key);
    }
    else
        deleteNode(&(*tree)->right, key);
}
int main()
{
    BST * tree = nullptr;
    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 6);
    insert(&tree, 1);
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 8);

    deleteNode(&tree, 4);
    inorder(tree);
    free_tree(tree);
    return 0;
}