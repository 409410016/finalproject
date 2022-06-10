#include "main.c"

void mergeSort(ptr_people *, int, int, char *);
void merge(ptr_people *, int, int, int, char *);

void sort()
{
    int No;
    printf("which data do you want to sort: ");
    printf("(1) name (2) ID\n");
    printf("data type number: ");
    scanf("%d", &No);
    if (No == 1)
        mergeSort(dataArray, 0, num_of_people - 1, "name");
    else if (No == 2)
        mergeSort(dataArray, 0, num_of_people - 1, "ID");
    //印出
    for(int i = 0; i<num_of_people; i++)
    {

    }
}

// array為main function中的dataArray
// front為陣列開頭; end為陣列尾端
// element為進行排序的目標參數(name, ID)
void mergeSort(ptr_people *array, int front, int end, char *element)
{
    if (front < end) // 矩陣範圍是有效的
    {
        int mid = (front + end) / 2;
        mergeSort(array, front, mid, element);           // 繼續divide矩陣的前半段subarray
        mergeSort(array, mid + 1, end, element);         // 繼續divide矩陣的後半段subarray
        merge(array, front, mid, end, element); // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

// array為main function中的dataArray
// front為愈排序子陣列開頭; mid為該陣列中間; end為該陣列尾端
//以mid為中點，將array中愈排序的子陣列段分割成左右子陣列
// element為進行排序的目標參數(name, ID)
void merge(ptr_people *array, int front, int mid, int end, char *element)
{
    ptr_people *LeftSub, *RightSub;
    LeftSub = malloc((mid - front + 1) * sizeof(ptr_people));
    RightSub = malloc((end - mid) * sizeof(ptr_people));

    int lenLeft = 0, lenRight = 0; //子陣列長度
    int idxLeft = 0, idxRight = 0; //子陣列檢索到的位置

    //將array區段的值分配至左右子陣列; 排序左右子陣列，由小到大插回array中(改變array的值)
    if (strcmp(element, "name") == 0)
    {
        //初始化
        for (int i = front; i <= mid; i++)
            strncpy(LeftSub[lenLeft++]->name, array[i]->name, strlen(array[i]->name));
        for (int i = mid + 1; i <= end; i++)
            strncpy(RightSub[lenRight++]->name, array[i]->name, strlen(array[i]->name));
        //排序
        for (int i = front; i <= end; i++)
        {
            if (strcmp(LeftSub[idxLeft]->name, RightSub[idxRight]->name) < 0)
            {
                strncpy(array[i]->name, LeftSub[idxLeft]->name, strlen(LeftSub[idxLeft]->name));
                idxLeft++;
            }
            else
            {
                strncpy(array[i]->name, RightSub[idxRight]->name, strlen(RightSub[idxRight]->name));
                idxRight++;
            }
        }
    }
    else if (strcmp(element, "ID") == 0)
    {
        //初始化
        for (int i = front; i <= mid; i++)
            strncpy(LeftSub[lenLeft++]->ID, array[i]->ID, strlen(array[i]->ID));
        for (int i = mid + 1; i <= end; i++)
            strncpy(RightSub[lenRight++]->ID, array[i]->ID, strlen(array[i]->ID));
        //排序
        for (int i = front; i <= end; i++)
        {
            if (lenLeft < lenRight)
            {
                strncpy(array[i]->ID, LeftSub[idxLeft]->ID, strlen(LeftSub[idxLeft]->ID));
                idxLeft++;
            }
            else if(lenLeft > lenRight)
            {
                strncpy(array[i]->ID, RightSub[idxRight]->ID, strlen(RightSub[idxRight]->ID));
                idxRight++;
            }
            else if(lenLeft == lenRight)
            {

            }
        }
    }
}