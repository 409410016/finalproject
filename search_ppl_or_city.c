#include "people.h"

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
                print("%s", name[i]);
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
                print("%s", name[i]);
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
