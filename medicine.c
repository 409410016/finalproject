#include "main.c"

void medecine(struct people **start, const char *ppl_name)
{
    struct people *cur = *start;
    if (strcmp(cur->city, ppl_name))
    {
        cur = cur->next;
    }
    else
    {
        cur->remain_day = 0;
    }
}

struct people *search_people(struct people *start, const char ppl_name[])
{
    struct people *cur = *start;
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

struct people * search_city(struct people **start, const char ppl_city[])
{
    // assume city is char array
    struct people *cur = *start;
    while (cur != NULL){
        if (strcmp(cur->city, ppl_city))
        {
            cur = cur->next;
        }
        else
        {   
            return cur;
    //         printf("%s", cur->city);
        }
   }
}
