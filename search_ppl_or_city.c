#include "people.h"

void search(){
    int No;
    char condition[50];
    printf("which data do you want to search: ");
    printf("(1) name (2) ID (3) city\n");
    printf("data type number: ");
    scanf("%d", &No);
    scanf("%s",&condition);
    
    struct people *ptr;
    int point;
    if (No == 1){
        ptr=search_people_name(condition);
        printf("ID\tNAME\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
        printf("%s\t%s\t%c\t%d\t%c\t%d\t", ptr->ID, ptr->name, ptr->sex, ptr->age, ptr->city, ptr->remain_day);
        if(ptr->state==0) printf("isolation\n");
        else if(ptr->state==1) printf("quarantine\n");
        else if(ptr->state==2) printf("release\n");
    }
    else if (No == 2){
        ptr=search_people_ID(condition);
        printf("ID\tNAME\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
        printf("%s\t%s\t%c\t%d\t%c\t%d\t", ptr->ID, ptr->name, ptr->sex, ptr->age, ptr->city, ptr->remain_day);
        if(ptr->state==0) printf("isolation\n");
        else if(ptr->state==1) printf("quarantine\n");
        else if(ptr->state==2) printf("release\n");
    }
    else if(No == 3){
        point=search_city(condition);
        printf("Total\tinflect\tinflect rate\n");
        printf("%d\t%d\t%f\n", cities[i].total_people, cities[i].inflected_people, cities[i].inflected_rate);
    }
}

struct people *search_people_name(const char ppl_name[])
{
    struct people *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->name, ppl_name)) // wrong ppl
        {
            cur = cur->next;
        }
        else //已經找到people的地址了。
        {
            char name[1000][50];
            int k = 0;
            ////////////先印傳染源，再印自己///////////////////////////////////////////
            while (cur->pre_inflect_people != NULL)
            {
                name[k] = cur->pre_inflect_people->ID;
            }
            for (int i = 0; i < k; i++)
            {
                printf("%s", name[i]);
            }
            printf("%s", cur->ID);
            //////////////////////////////////////////////////////////////////////////
            return cur;
            //             print("%s", cur->name);
        }
    }
}

struct people *search_people_ID(const char ppl_ID[])
{
    struct people *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->name, ppl_ID)) // wrong ppl
        {
            cur = cur->next;
        }
        else //已經找到people的地址了。
        {
            ////////////先印傳染源，再印自己///////////////////////////////////////////
            while (cur->pre_inflect_people != NULL)
            {
                name[k] = cur->pre_inflect_people->ID;
            }
            for (int i = 0; i < k; i++)
            {
                printf("%s", name[i]);
            }
            printf("%s", cur->ID);
            //////////////////////////////////////////////////////////////////////////
            return cur;
            //             print("%s", cur->name);
        }
    }
}

int search_city(const char ppl_city[])
{
    // assume city is char array
    for (int i = 0; i < num_of_cities; i++)
    {
        if (cities[i] != (ppl_city - 65))
        {
            continue;
        }
        else
        {
            return i; //回傳該城市所屬數字
        }
    }
}
