#include"people.h" 
#include <time.h>


void medecine( const char *ppl_name)
{
    
    struct people *cur =*head;
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

void clear(const char *ppl_name){
    struct people* ptr;
    ptr = head->next;
    while(ptr!=NULL){
        if (!strcmp(cur->city, ppl_name)){
            ptr->state = release;
            ptr->remain_day = -1;
        }
        ptr = ptr->next;
    }
}

void protest(){
    srand(time(NULL));
    int dice = rand()%5;
    switch(dice){
        case 0:
            printf("sentense1\n");
            break;
        case 1:
            printf("sentense2\n");
            break;
        case 2:
            printf("sentense3\n");
            break;
        case 3:
            printf("sentense4\n");
            break;
        case 4:
            printf("sentense5\n");
            break;
    }
}
