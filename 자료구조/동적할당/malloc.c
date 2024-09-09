#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

int main() {
    int *p = (int *) malloc(sizeof(int));
    *p = 1000;
    printf("%d\n", *p);

    float *q = malloc(sizeof(float));
    *q = 12.345;
    printf("%f\n", *q);

    student *s;
    s = (student *)malloc(2*sizeof(student)); //메모리 공간이 2공간이 아니라 1공간이면 s->name으로 해도 된다.((*s).name과 같다.)
    if (s==NULL) {
        fprintf(stderr,"메모리부족\n");
        exit(1);
    }

    strcpy(s[0].name,"Park");
    s[0].age = 20;
    s[0].gpa = 1.1;
    strcpy(s[1].name,"Kim");
    s[1].age = 22;
    s[1].gpa = 3.0;
    for (int i=0;i<2;++i) {
        printf("이름:%s\n",s[i].name);
        printf("나이:%d\n",s[i].age);
        printf("평점:%f\n",s[i].gpa);
    }
    free(s);
}