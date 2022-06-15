#include "people.h"

void search(){
    int No;
    char condition[50];
    printf("which data do you want to search: ");
    printf("(1) name (2) ID (3) city\n");
    printf("data type number: ");
    scanf("%d", &No);
    scanf("%s",condition);
    
    struct people *ptr;
    int point;
    if (No == 1){
        ptr=search_people_name(condition);
        printf("ID\tNAME\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
        printf("%s\t%s\t%c\t%d\t%c\t%d\t\t", ptr->ID, ptr->name, ptr->sex, ptr->age, ptr->city, ptr->remain_day);
        if(ptr->state==0) printf("isolation\n");
        else if(ptr->state==1) printf("quarantine\n");
        else if(ptr->state==2) printf("release\n");
    }
    else if (No == 2){
        ptr=search_people_ID(condition);
        printf("ID\tNAME\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
        printf("%s\t%s\t%c\t%d\t%c\t%d\t\t", ptr->ID, ptr->name, ptr->sex, ptr->age, ptr->city, ptr->remain_day);
        if(ptr->state==0) printf("isolation\n");
        else if(ptr->state==1) printf("quarantine\n");
        else if(ptr->state==2) printf("release\n");
    }
    else if(No == 3){
        point=search_city(condition);
        printf("Total\tinflect\tinflect rate\n");
        printf("%d\t%d\t%f\n", cities[point].total_people, cities[point].inflected_people, cities[point].inflected_rate);
    }
}

struct people *search_people_name(const char ppl_name[])
{
    struct people *cur = head->next;
    people_node ptr;
    while (cur != NULL)
    {
        if (strcmp(cur->name, ppl_name) != 0) // wrong ppl
        {
            cur = cur->next;
        }
        else //already_find_*people。
        {
            char name[1000][50];
            int k = 0;
            ptr = cur;
            ////////////print Source of infection///////////////////////////////////////////
            while (ptr->pre_inflect_people != NULL)
            {
                strcpy(name[k++],ptr->pre_inflect_people->ID);
                ptr = ptr->pre_inflect_people;
            }
            printf("Source of Inflected Chain is : ");
            for (int i = k-1; i >= 0; i--)
            {
                printf("%s->", name[i]);
            }
            printf("%s\n", cur->ID);
            //////////////////////////////////////////////////////////////////////////
            return cur;
            //             print("%s", cur->name);
        }
    }
}

struct people *search_people_ID(const char ppl_ID[])
{
    struct people *cur = head->next;
    people_node ptr;
    while (cur != NULL)
    {
        if (strcmp(cur->ID, ppl_ID) != 0) // wrong ppl
        {
            cur = cur->next;
        }
        else //already_find_*people。
        {
            char name[1000][50];
            int k = 0;
            ptr = cur;
            ////////////print Source of infection///////////////////////////////////////////
            while (ptr->pre_inflect_people != NULL)
            {
                strcpy(name[k++],ptr->pre_inflect_people->ID);
                ptr = ptr->pre_inflect_people;
            }
            printf("Source of Inflected Chain is : ");
            for (int i = k-1; i >= 0; i--)
            {
                printf("%s->", name[i]);
            }
            printf("%s\n", cur->ID);
            //////////////////////////////////////////////////////////////////////////
            return cur;
            //             print("%s", cur->ID);
        }
    }
}

int search_city(const char ppl_city[])
{
    // assume city is char array
//     for (int i = 0; i < num_of_cities; i++)
//     {
//         if ( != (ppl_city - 65))
//         {
//             continue;
//         }
//         else
//         {
//             return i; 
//         }
//     }
    return (*ppl_city-65);//return city's num
}
