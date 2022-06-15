#include"people.h"
//#include"add.c"
//#include"sort.c"
//#include"search_ppl_or_city.c"
//#include"dice.c"

void init(){
    // build city and initialized
    cities[0].total_people = num_in_A;
    cities[1].total_people = num_in_B;
    cities[2].total_people = num_in_C;
    cities[3].total_people = num_in_D;
    cities[4].total_people = num_in_E;
    for(int i=0;i<num_of_cities;i++){
        cities[i].inflected_people = 0;
        cities[i].inflected_rate = 0;
    }
    // struct head
    head = (struct people*)malloc(sizeof(struct people));
    head->next = NULL;
    rootName = NULL;
    rootID = NULL;
    return;
}

void print_all(){
    // 人員基本資料
    struct people *cur;
    cur = head->next;
    printf("ID\tNAME\t\tSEX\tAGE\tCITY\tREMAIN_DAY\tSTATE\n");
    while (cur != NULL) {
        printf("%s\t%s\t\t%c\t%d\t%c\t%d\t\t", cur->ID, cur->name, cur->sex, cur->age, cur->city, cur->remain_day);
        if(cur->state==0) printf("isolation\n");
        else if(cur->state==1) printf("quarantine\n");
        else if(cur->state==2) printf("release\n");
        cur = cur->next;
    }
    printf("\n");
    
    // 城市資料
    printf("City\tTotal\tinflect\tinflect rate\n");
    printf("A\t%d\t%d\t%f\n", cities[0].total_people, cities[0].inflected_people, cities[0].inflected_rate);
    printf("B\t%d\t%d\t%f\n", cities[1].total_people, cities[1].inflected_people, cities[1].inflected_rate);
    printf("C\t%d\t%d\t%f\n", cities[2].total_people, cities[2].inflected_people, cities[2].inflected_rate);
    printf("D\t%d\t%d\t%f\n", cities[3].total_people, cities[3].inflected_people, cities[3].inflected_rate);
    printf("E\t%d\t%d\t%f\n", cities[4].total_people, cities[4].inflected_people, cities[4].inflected_rate);
}

int main(){
    
    init(); // initialized and city info
    fp = fopen("data.txt","r");
    today = 1;
    
    //每天
    while(1){
        // read data
        int new;
        fscanf(fp,"%d\n",&new);
        while(new--) add();

        // basic operation
        char instruct[10];
        printf("Please input these command to use the database!!\n\"ADD\"(add a person to database)\n\"DELETE\"(delete a person in the database)\n\"TRAVERSE\"(print all the data in the data base)\n\"SEARCH\"(can search the database and print out)\n\"SORT\"(can sort the database and print out)\n\"END\"(today will be end and going to the next day) to use the database.\n");
        while(scanf("%s",&instruct)){
            if(!strcmp(instruct,"ADD")) add_user();
            else if(!strcmp(instruct,"DELETE")) delete();
            else if(!strcmp(instruct,"TRAVERSE")) print_all();
            else if(!strcmp(instruct,"SEARCH")) search();
            else if(!strcmp(instruct,"SORT")) sort();
            else if(!strcmp(instruct,"END")) break;
        }
        printf("success!!\n");
        // dice
        //for(int i=0;i<num_of_cities;i++)
        //    dice_city(i);
        
        // daily report
        printf("Today is: DAY %d\n",today);
        printf("Total inflect: %d\n",cities[0].inflected_people+cities[1].inflected_people+cities[2].inflected_people+cities[3].inflected_people+cities[4].inflected_people);
        printf("A\t\tB\t\tC\t\tD\t\tE\n");
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",cities[0].inflected_people,cities[1].inflected_people,cities[2].inflected_people,cities[3].inflected_people,cities[4].inflected_people);
        printf("%f\t%f\t%f\t%f\t%f\n",cities[0].inflected_rate,cities[1].inflected_rate,cities[2].inflected_rate,cities[3].inflected_rate,cities[4].inflected_rate);

        release(1);
    }

    return 0;
}
