
Background:

What information we use:
    A. Information of people:
        1. ID
        2. Age
        3. Sex
        4. City
        5. Name
        6. remain day(isolation)
        7. State(isolation/release)

    B. Information of city:
        1. How many people are in this city?
        2. How many people are infected?
        3. What is the infection rate?

command:

Basic dataperation(工作內容):
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
