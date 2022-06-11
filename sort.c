#include "people.h"

void insert(ptrTree, ptrTree, struct people *, char *, int);
void traversal(ptrTree);
void delete (char *);
void sort(ptrTree, ptrTree);


void insert(ptrTree front, ptrTree root, struct people* tmp, char *element, int big)
{
    //愈檢索位置無node，將其插入
    if (root == NULL)
    {
        root = malloc(sizeof(tree));
        root->data = tmp;
        root->left = NULL;
        root->right = NULL;
        if(big==-1)
            front -> left = root;
        else if(big ==1 )
            front -> right = root;
    }
    // tree為空
    else if (root->data == NULL)
        root->data = tmp;
    // insert進以name排序的BST
    else if (strcmp(element, "name") == 0)
    {
        if (strcmp(tmp->name, root->data->name) < 0)
            insert(root, root->left, tmp, element, -1);
        else if (strcmp(tmp->name, root->data->name) > 0)
            insert(root, root->right, tmp, element, 1);
    }
    // insert進以ID排序的BST
    else if (strcmp(element, "ID") == 0)
    {
        //比較位數
        if (strlen(tmp->ID) < strlen(root->data->ID))
            insert(root, root->left, tmp, element, -1);
        else if (strlen(tmp->ID) > strlen(root->data->ID))
            insert(root, root->right, tmp, element, 0);
        else if (strlen(tmp->ID) == strlen(root->data->ID))
        {
            if (strcmp(tmp->ID, root->data->ID) < 0)
                insert(root, root->left, tmp, element, -1);
            else if (strcmp(tmp->ID, root->data->ID) > 0)
                insert(root, root->right, tmp, element, 1);
        }
    }
}

void sort(ptrTree rootName, ptrTree rootID)
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
    if(root != NULL)
    {
        traversal(root -> left);
        printf("%s %s %c %d %d\n", root->data->ID, root->data->name, root->data->sex,
               root->data->age, root->data->remain_day);
        traversal(root ->right);
    }
}
