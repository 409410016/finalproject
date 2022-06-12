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
            return cur;
            //             print("%s", cur->name);
        }
    }
}

int search_city(const char ppl_city[])
{
    // assume city is char array
    for (int i = 0; i < num_of_cities++)
    {
        if (strcmp(cities[i].name, ppl_city))
        {
            continue;
        }
        else
        {
            return cities[i];
        }
    }
}
