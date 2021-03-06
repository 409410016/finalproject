#include "people.h"
#include <malloc.h>

void update_city()
{
    for (int i = 0; i < 5; i++)
    {
        cities[i].inflected_rate = (float)cities[i].inflected_people / (float)cities[i].total_people;
    }
    return;
}

void add()
{ //add persom、caculate total people、update city information at the end(1 Amy F 18 A (id))
    char temp[1024];
    fgets(temp, 1024, fp); // input file
    char *id, *name, *age, *sex, *city, *chop, *pre_id;
    chop = strtok(temp, " \0");
    id = chop;
    chop = strtok(NULL, " \0");
    name = chop;
    chop = strtok(NULL, " \0");
    sex = chop;
    if (*sex != 'F' && *sex != 'M')
    {
        printf("invalid input!\n");
        return;
    }
    chop = strtok(NULL, " \0");
    age = chop;
    for (int i = 0;; i++)
    {
        if (*(age + i) > 47 && *(age + i) < 58)
        {
            continue;
        }
        else if (*(age + i) == '\0')
        {
            break;
        }
        else
        {
            printf("invalid input!\n");
            return;
        }
    }
    chop = strtok(NULL, " ");
    city = chop;
    if (*city != 'A' && *city != 'B' && *city != 'C' && *city != 'D' && *city != 'E')
    {
        printf("invalid input!\n");
        return;
    }
    if(city_state[(*city)-65] == 1){
        return;
    }
    chop = strtok(NULL," \0\n\r");
    pre_id = chop;
    people_node qtr;
    qtr = head->next;
    int check = 0;
    if (*pre_id != '*')
    {
        while (qtr != NULL)
        {
            if (strncmp(pre_id, qtr->ID, 3) == 0)
            {
                check = 1;
                break;
            }
            qtr = qtr->next;
        }
        if (check == 0)
        {
            printf("invalid input!\n");
            return;
        }
    }
    people_node ptr, temptr, preinflect;
    ptr = (people_node)malloc(sizeof(struct people));
    temptr = head;
    while (temptr->next != NULL)
    { //add node from the back
        temptr = temptr->next;
    }
    temptr->next = ptr;
    ptr->next = NULL;
    ptr->prev = temptr;
    temptr = head->next;
    if (*pre_id == '*')
    {
        ptr->pre_inflect_people = NULL;
    }
    else
    {
        while (strncmp(temptr->ID, pre_id, 3) != 0)
        { //source of inflection
            temptr = temptr->next;
        }
        ptr->pre_inflect_people = temptr;
    }
    strcpy(ptr->ID, id);
    strcpy(ptr->name, name);
    ptr->age = atoi(age);
    ptr->sex = *sex;
    ptr->city = *city;
    cities[ptr->city - 65].inflected_people++;
    ptr->remain_day = 7;
    ptr->state = isolation;
    update_city();
    // insert node into tree
    rootName = insert(rootName, rootName, rootName, ptr, "name", 0);
    rootID = insert(rootID, rootID, rootID, ptr, "ID", 0);
    return;
}

//刪除分chain刪除(有無傳染源)跟鏈上刪除

void delete ()
{ //search and delete any node      update city information at the end
    people_node ptr, temp, qtr;
    char name[50];
    printf("Please input a name you want to delete : ");
    scanf("%s", name);
    ptr = head->next;
    while(ptr != NULL){
        if(strcmp(name,ptr->name)==0){
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("invalid input!!\n");
        return;
    }
    qtr = ptr->pre_inflect_people;
    cities[ptr->city - 65].inflected_people--;
    //delete from tree
    find_in_nameTree(rootName, rootName, name, 0); //the node want to delete
    find_in_IDTree(rootID, rootID, ptr, 0);
    if(ptr->next != NULL){
    ptr->prev->next = ptr->next; //delete from chain
    ptr->next->prev = ptr->prev;
    }else{
        ptr->prev->next = NULL;
    }
    temp = head -> next;
    while (temp != NULL){
        if (strcmp(temp->ID, ptr->ID) == 0){
            temp->pre_inflect_people = qtr;
        }
        temp = temp ->next;
    }
    free(ptr);
    update_city();
    return;
}

void release(int day)
{
    today++;
    people_node ptr;
    ptr = head->next;
    while (ptr != NULL)
    {
        if (ptr->remain_day > day)
        {
            ptr->remain_day -= day;
        }
        else if (ptr->remain_day == day && ptr->state == 0)
        {
            ptr->remain_day = 7;
            ptr->state = 1;
        }
        else if (ptr->remain_day == day && ptr->state == 1)
        {
            ptr->remain_day = -1;
            ptr->state = 2;
            cities[ptr->city - 65].inflected_people--;
            update_city();
        }
        ptr = ptr->next;
    }
    return;
}

void add_user()
{ // 1 Amy F 18 A (id)
    char temp[1024];
    printf("If there is no previous inflected person, please input \"*\".\n");
    printf("Please input the information of inflected people in the next line!!\n");
    fflush(stdin);
    fgets(temp, 1024, stdin);

    char *id, *name, *age, *sex, *city, *chop, *pre_id;
    chop = strtok(temp, " ");
    id = chop;
    chop = strtok(NULL, " ");
    name = chop;
    chop = strtok(NULL, " ");
    sex = chop;
    if (*sex != 'F' && *sex != 'M')
    {
        printf("invalid input!\n");
        return;
    }
    chop = strtok(NULL, " ");
    age = chop;
    for (int i = 0;; i++)
    {
        if (*(age + i) > 47 && *(age + i) < 58)
        {
            continue;
        }
        else if (*(age + i) == '\0')
        {
            break;
        }
        else
        {
            printf("invalid input!\n");
            return;
        }
    }
    chop = strtok(NULL, " ");
    city = chop;
    if (*city != 'A' && *city != 'B' && *city != 'C' && *city != 'D' && *city != 'E')
    {
        printf("invalid input!\n");
        return;
    }
    chop = strtok(NULL, " \n\r");
    pre_id = chop;
    people_node qtr;
    qtr = head->next;
    int check = 0;
    if (*pre_id != '*')
    {
        while (qtr != NULL)
        {
            if (strncmp(pre_id, qtr->ID, 3) == 0)
            {
                check = 1;
                break;
            }
            qtr = qtr->next;
        }
        if (check == 0)
        {
            printf("invalid input!\n");
            return;
        }
    }
    people_node ptr, temptr, preinflect;
    ptr = (people_node)malloc(sizeof(struct people));
    temptr = head;
    while (temptr->next != NULL)
    { //add node from back
        temptr = temptr->next;
    }
    temptr->next = ptr;
    ptr->next = NULL;
    ptr->prev = temptr;
    temptr = head->next;
    if (*pre_id == '*')
    {
        ptr->pre_inflect_people = NULL;
    }
    else
    {
        while (strncmp(temptr->ID, pre_id, 3) != 0)
        { //dource of inflection
            temptr = temptr->next;
        }
        ptr->pre_inflect_people = temptr;
    }
    strcpy(ptr->ID, id);
    strcpy(ptr->name, name);
    ptr->age = atoi(age);
    ptr->sex = *sex;
    ptr->city = *city;
    cities[ptr->city - 65].inflected_people++;
    ptr->remain_day = 7;
    ptr->state = isolation;
    update_city();
    // insert node into tree
    rootName = insert(rootName, rootName, rootName, ptr, "name", 0);
    rootID = insert(rootID, rootID, rootID, ptr, "ID", 0);
    return;
}
