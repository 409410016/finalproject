#include "people.h"
#include <malloc.h>

void sort(ptrTree rootName, ptrTree rootID)
{
    int No;
    printf("which data do you want to sort: ");
    printf("(1) name (2) ID\n");
    printf("data type number: ");
    scanf("%d", &No);
    printf("ID\tNAME\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
    if (No == 1)
        traversal(rootName);
    else if (No == 2)
        traversal(rootID);
}

//中序走訪
void traversal(ptrTree root)
{
    if (root != NULL)
    {
        traversal(root->left);
        printf("%s\t%s\t%c\t%d\t%c\t%d\t\t", root -> data->ID, root -> data->name, root -> data->sex, \
        root -> data->age, root -> data->city, root -> data->remain_day);
        if(root -> data->state==0) printf("isolation\n");
        else if(root -> data->state==1) printf("quarantine\n");
        else if(root -> data->state==2) printf("release\n");
        traversal(root->right);
    }
}

// front is parent node of node
// node is basis of judgment,in Recursion end, it is the plasce to insert.
// tmp is a pointer that point to the new data (people)
// element is the standard of sort, name or ID.
// big represent the relative size of front and node
// 0 represent front = node = root; -1 represent node is left child node of front; 1 represent right child node
ptrTree insert(ptrTree root, ptrTree front, ptrTree node, struct people *tmp, char *element, int big)
{
    // tree is empty
    if (root == NULL)
    {
        root = malloc(sizeof(tree));
        root->data = tmp;
        root -> left = NULL;
        root -> right = NULL;
    }
    //insert the node
    else if (node == NULL)
    {
        node = malloc(sizeof(tree));
        node->data = tmp;
        node->left = NULL;
        node->right = NULL;
        if (big == -1)
            front->left = node;
        else if (big == 1)
            front->right = node;
    }

    // insert the BST of name
    else if (strcmp(element, "name") == 0)
    {
        if (strcmp(tmp->name, node->data->name) < 0)
            root = insert(root, node, node->left, tmp, element, -1);
            
        else if (strcmp(tmp->name, node->data->name) > 0)
            root = insert(root, node, node->right, tmp, element, 1);
            
    }
    // insert the BST of ID
    else if (strcmp(element, "ID") == 0)
    {
        if (strcmp(tmp->ID, node->data->ID) < 0)
            root = insert(root, node, node->left, tmp, element, -1);
        else if (strcmp(tmp->ID, node->data->ID) > 0)
            root = insert(root, node, node->right, tmp, element, 1);
    }
    return root;
}
// front is parent node of node.
// nowNode is basis of judgment,in Recursion end, it is the plasce to delete.
// name is the people data that user want to delete.
// big is the same as the insert function.
void find_in_nameTree(ptrTree front, ptrTree nowNode, char *name, int big)
{
    //no this data
    if (nowNode == NULL)
        printf("invaild input\n");
    //target data is less than current data
    else if (strcmp(name, nowNode->data->name) < 0)
        find_in_nameTree(nowNode, nowNode->left, name, -1);
    //target data is bigger than current data
    else if (strcmp(name, nowNode->data->name) > 0)
        find_in_nameTree(nowNode, nowNode->right, name, 1);
    //target data is equal to current data
    else if (strcmp(name, nowNode->data->name) == 0)
    {
        //node is root and it only has one child node
        if (front == nowNode && (!(front->left && front->right)))
            rootName = (rootName->left) ? (rootName->left) : (rootName->right);
        else
            delete_in_tree(front, nowNode, big);
    }
}

//is the same as the find_in_nameTree, change name to the pointer point to people.
void find_in_IDTree(ptrTree front, ptrTree nowNode, struct people *target, int big)
{
    //no this data
    if (nowNode == NULL)
        printf("invaild input\n");
    //target data is less than current data
    else if (strcmp(target->ID, nowNode->data->ID) < 0)
        find_in_IDTree(nowNode, nowNode->left, target, -1);
    //target data is bigger than current data
    else if (strcmp(target->ID, nowNode->data->ID) > 0)
        find_in_IDTree(nowNode, nowNode->right, target, 1);
    //target data is equal to current data
    else if (strcmp(target->ID, nowNode->data->ID) == 0)
    {
        //node is root and it only has one child node
        if (front == nowNode && (!(front->left && front->right)))
            rootID = (rootID->left) ? (rootID->left) : (rootID->right);
        else
            delete_in_tree(front, nowNode, big);
    }
}

// front is parent node of node.
// nowNode is the plasce to delete.
void delete_in_tree(ptrTree front, ptrTree nowNode, int big)
{
    //is leaf node
    if (!nowNode->left && !nowNode->right)
    {
        if (big == -1)
            front->left = NULL;
        else if (big == 1)
            front->right = NULL;
        free(nowNode);
    }
    //only has left child node
    else if (nowNode->left && !nowNode->right)
    {
        if (big == -1)
            front->left = nowNode->left;
        else if (big == 1)
            front->right = nowNode->left;
        free(nowNode);
    }
    //only has right child node
    else if (!nowNode->left && nowNode->right)
    {
        if (big == -1)
            front->left = nowNode->right;
        else if (big == 1)
            front->right = nowNode->right;
        free(nowNode);
    }
    //has two child node
    else if (nowNode->left && nowNode->right)
    {
        //use the smallest node target replace
        ptrTree taregetParent = nowNode;
        ptrTree target = nowNode->right;
        while (target != NULL && target->left != NULL)
        {
            taregetParent = target;
            target = target->left;
        }
        if (target->right == NULL)
        {
            nowNode->data = target->data;
            taregetParent->right = NULL;
            free(target);
        }
        else if (target->right != NULL)
        {
            nowNode->data = target->data;
            taregetParent->right = target->right;
            free(target);
        }
    }
}
