
### Background:
    In response to new disease breakout, throughtout the country everyone is in a hard time, 
    so we want to build a database to store the disease case.
    (!!This is not the real situation, it is purely for research!!)
    
### What can it do?
    1. basic operation: User can modify the data in this data, or check the information about the city and cases.
    2. simulate the real situation: In each day, we pretend to be the mayor on a mission.
    So that we can study the situation of this epidemic.

### What information we use:
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

### Database operation: (how to use it?)
    1. ADD: You can add CASE to the list.
        `ADD CASE_ID CASE_NANE CASE_SEX CASE_AGE CASE_CITY CASE_SOURSE`
    2. DELETE: You can delete CASE from the list.
        `DELETE CASE_NANE`
    3. TRAVERSE: You can see all the case in the list and informations of each city.
        `TRAVERSE`
    4. SORT: User can choose to Sort the data according to NAME or ID, then see the result.
        Hint: which data do you want to sort: (1) name (2) ID
        `SORT method(1or2)`
    5. SEARCH: User can search the certain data of people or city.
        Hint: Which data do you want to search: (1) name (2) ID (3) city
        `SEARCH method(1or2or3)`
    6. END: If user has no more action, end the day.
        `END`
