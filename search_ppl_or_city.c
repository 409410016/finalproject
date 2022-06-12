#include ""

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

struct people *search_city(const char ppl_city[])
{
    // assume city is char array
    struct city *cur = head;
    while (cur != NULL)
    {
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
