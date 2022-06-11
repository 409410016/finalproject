#include "main.c"


struct people *search_people_name(struct people *start, const char ppl_name[])
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


struct people *search_people_ID(struct people *start, const int ppl_id)
{
    struct people *cur = *start;
    
	char num[5]; 
	sprintf(num, "%d", ppl_id);   
    
    while (cur != NULL)
    {
        if (strcmp(cur->name, num)) // wrong ppl
        {
            cur = cur->next;
        }
        else //已經找到people的地址了。
        {
            return cur;
        }
    }
}

struct people * search_city(struct city **start, const char ppl_city[])
{
    // assume city is char array
    struct city *cur = *start;
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
