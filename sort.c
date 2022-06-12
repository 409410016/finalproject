#include "people.h"
#include <malloc.h>

void sort()
{
    int No;
    printf("which data do you want to sort: ");
    printf("(1) name (2) ID\n");
    printf("data type number: ");
    scanf("%d", &No);
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
        printf("%s %s %c %d %d\n", root->data->ID, root->data->name, root->data->sex,
               root->data->age, root->data->remain_day);
        traversal(root->right);
    }
}
// front為當前節點(node)的上節點
// node為當前節點，遞迴到最後為插入節點的位置
// tmp指向新資料(people型態)的指標
// element為排序的基準，name或ID
// big代表front和node的關係 0代表front = node = root; -1代表node為front的左子節點; 1代表node為front的右子節點
void insert(ptrTree front, ptrTree node, struct people *tmp, char *element, int big)
{
    //愈檢索位置無node，將其插入
    if (node == NULL)
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
    // tree為空
    else if (node->data == NULL)
        node->data = tmp;
    // insert進以name排序的BST
    else if (strcmp(element, "name") == 0)
    {
        if (strcmp(tmp->name, node->data->name) < 0)
            insert(node, node->left, tmp, element, -1);
        else if (strcmp(tmp->name, node->data->name) > 0)
            insert(node, node->right, tmp, element, 1);
    }
    // insert進以ID排序的BST
    else if (strcmp(element, "ID") == 0)
    {
        if (strcmp(tmp->ID, node->data->ID) < 0)
            insert(node, node->left, tmp, element, -1);
        else if (strcmp(tmp->ID, node->data->ID) > 0)
            insert(node, node->right, tmp, element, 1);
    }
}
// front為當前節點(node)的上節點
// node為當前節點，遞迴到最後為欲刪除的節點的位置
// name為欲刪除節點的name資料
// big代表front和node的關係 0代表front = node = root; -1代表node為front的左子節點; 1代表node為front的右子節點
void find_in_nameTree(ptrTree front, ptrTree nowNode, char *name, int big)
{
    //無此資料
    if (nowNode == NULL)
        printf("invaild input\n");
    //目標資料小於當前節點
    else if (strcmp(name, nowNode->data->name) < 0)
        find_in_nameTree(nowNode, nowNode->left, name, -1);
    //目標資料大於當前節點
    else if (strcmp(name, nowNode->data->name) > 0)
        find_in_nameTree(nowNode, nowNode->right, name, 1);
    //目標資料等於當前節點
    else if (strcmp(name, nowNode->data->name) == 0)
    {
        //節點為根節點且只有一個子節點
        if (front == nowNode && (!(front->left && front->right)))
            rootName = (rootName->left) ? (rootName->left) : (rootName->right);
        else
            delete_in_tree (front, nowNode, big);
    }
}

//同find_in_nameTree 比對目標改為ID
void find_in_IDTree(ptrTree front, ptrTree nowNode, struct people* target, int big)
{
    //無此資料
    if (nowNode == NULL)
        printf("invaild input\n");
    //目標資料小於當前節點
    else if (strcmp(target -> ID, nowNode->data->ID) < 0)
        find_in_IDTree(nowNode, nowNode->left, target, -1);
    //目標資料大於當前節點
    else if (strcmp(target -> ID, nowNode->data->ID) > 0)
        find_in_IDTree(nowNode, nowNode->right, target, 1);
    //目標資料等於當前節點
    else if (strcmp(target -> ID, nowNode->data->ID) == 0)
    {
        //節點為根節點且只有一個子節點
        if (front == nowNode && (!(front->left && front->right)))
            rootID = (rootID->left) ? (rootID->left) : (rootID->right);
        else
            delete_in_tree (front, nowNode, big);
    }
}

void delete_in_tree (ptrTree front, ptrTree nowNode, int big)
{
    //該節點為葉節點
    if (!nowNode->left && !nowNode->right)
    {
        if (big == -1)
            front->left = NULL;
        else if (big == 1)
            front->right = NULL;
        free(nowNode);
    }
    //該節點只有一個左節點
    else if (nowNode->left && !nowNode->right)
    {
        if (big == -1)
            front->left = nowNode->left;
        else if (big == 1)
            front->right = nowNode->left;
        free(nowNode);
    }
    //該節點只有一個右節點
    else if (!nowNode->left && nowNode->right)
    {
        if (big == -1)
            front->left = nowNode->right;
        else if (big == 1)
            front->right = nowNode->right;
        free(nowNode);
    }
    //該節點有兩個子節點
    else if (nowNode->left && nowNode->right)
    {
        //用其右子樹中最小的點target代替，並刪除target原本的位置
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
