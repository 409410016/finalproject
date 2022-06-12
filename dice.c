#include"people.h" 


void medecine(struct people **start, const char *ppl_name)
{
    
    struct people *cur = *start;
    if (strcmp(cur->city, ppl_name))
    {
        cur = cur->next;
    }
    else
    {
        srand( time(NULL) );
        int min = 1;
        int max = 3;
        int x = rand() % (max - min + 1) + min;
        if(x==3)
            cur->remain_day = 0;
    }
}
