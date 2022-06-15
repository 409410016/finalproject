確診隔離人員資料庫(new virus)

command:

operation(工作內容):
// 要怎麼輸入指令
    ADD: add people
    
    DELETE:若被解隔及delete
    
    TRAVERSE: 印出全部，依據各city列印people
    
    SORT:(ascending)
        according 姓名、ID
        (方法)用struct pointer array去做sort
    SEARCH:
        search_people : according 姓名 or ID : 輸出個人以及他的pre感染鏈
        search_city : city資料
    END: next day
    file in:(按n會新增下一天資料)
        1(天)    +450000
        danny wong  female  ...
    Report(out):(公告)
        記錄每天的變化跟結果。
    funny func():(maybe divided in to 2 pieces?)
        change the data in the system

//data structure

struct people{
    char ID[50];                                        //案例編號
    int age;
    char sex;                                           //性別
    char city;
    char name[50];
    /*<----------->*/
    int remain_day;                             //累積隔離天數       
    enum{isolation,quarantine,release} state;
    /*<----------->*/    
    struct people *pre_inflect_people;                  //誰是傳染源
    struct people *next;                                //下一個輸入人員
    struct people *prev;
};

struct city{                                            //城市
    int total_people;
    int inflected_people;
    float inflected_rate;
}cities[num_of_cities];                                 //各城市

王 : add(){順便計算總人數} delete() city_update()  release()

丁丁 : sort_ID() sort_name() move_paitient()

吳 : search_people() search_city() medicine()

佑佑 : FILE_I()  FILE_O()  main  todays_news()
