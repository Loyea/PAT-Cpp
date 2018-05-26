#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct student {
    string name, id;
    int grade;
};

bool cmp_dsc(student s1, student s2){
    return s1.grade > s2.grade;
}

int main() {
    student male_stu[10000], female_stu[10000];
    int male_count = 0, female_count = 0;
    
    int n;
    scanf("%d", &n);
    while (n--) {
        char name[15], id[15];
        char gender;
        int grade;
        scanf("%s %c %s %d", name, &gender, id, &grade);
        if (gender == 'M') {
            male_stu[male_count].id = id;
            male_stu[male_count].name = name;
            male_stu[male_count].grade = grade;
            male_count++;
        } else {
            female_stu[female_count].id = id;
            female_stu[female_count].name = name;
            female_stu[female_count].grade = grade;
            female_count++;
        }
    }

    bool absent_flag = false;
    
    int highest = 0, lowest = 0;
    
    if (female_count > 0) {
        sort(female_stu, female_stu + female_count, cmp_dsc);
        highest = female_stu[0].grade;
        printf("%s %s\n", female_stu[0].name.c_str(), female_stu[0].id.c_str());
    } else {
        printf("Absent\n");
        absent_flag = true;
    }

    if (male_count > 0) {
        sort(male_stu, male_stu + male_count, cmp_dsc);
        lowest = male_stu[male_count - 1].grade;
        printf("%s %s\n", male_stu[male_count - 1].name.c_str(), male_stu[male_count - 1].id.c_str());
    } else {
        printf("Absent\n");
        absent_flag = true;
    }

    if (!absent_flag) {
        printf("%d", highest - lowest);
    } else {
        printf("NA");
    }
    
    
    return 0;
}