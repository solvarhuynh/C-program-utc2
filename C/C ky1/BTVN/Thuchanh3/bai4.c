#include <stdio.h>
#include <string.h>

typedef struct doibong{
    char name[20];
    int member;
    float score;
}team;
//nhap
void inputTeam(team football[], int n){
    for(int i = 0; i<n; i++){
        getchar();
        printf("\n========== ENTER THE SOCCER TEAM %d ==========\n",i+1);
        printf("Enter name: ");
        scanf("%[^\n]s",football[i].name);
        printf("Enter member: ");
        scanf("%d",&football[i].member);
        printf("Enter score: ");
        scanf("%f",&football[i].score);
    }
}
//xuat 1 doi
void outputTeam(team team){
    printf("%-15s | %-6d | %-5.1f\n",team.name,team.member,team.score);
}
//xuat tat ca doi bong
void printTeams(team football[], int n){
    printf("%-15s | %-6s | %-5s\n", "NAME", "MEMBER", "SCORE");
    for(int i =0 ; i<n; i++){
        outputTeam(football[i]);
    }
}
//3 doi co diem cao nhat 
void top3MaxOfScore(team football[], int n){
    for(int i = 0; i<3; i++){
        for(int j = i+1; j<n; j++){
            if(football[i].score < football[j].score){
                team tmp;
                tmp = football[i];
                football[i] = football[j];
                football[j] = tmp;
            }
        }
    }
    printf("\n========== TOP 3 TEAMS WITH THE HIGHEST SCORES ==========\n");
    printTeams(football,3);
}
//3 doi co nhieu thanh vien nhat 
void top3MaxOfMember(team football[], int n){
    for(int i = 0; i<3; i++){
        for(int j = i+1; j<n; j++){
            if(football[i].member < football[j].member){
                team tmp;
                tmp = football[i];
                football[i] = football[j];
                football[j] = tmp;
            }
        }
    }
    printf("\n=========== TOP 3 TEAMS WITH THE MOST MEMBERS ===========\n");
    printTeams(football,3);
}
//sap xep thu tu ten theo ABC
void arrangeName(team football[], int n){
    for(int i = 0; i<n-1; i++){
        char nameCopy1[10];
        strcpy(nameCopy1,football[i].name);
        char *token1 = strtok(nameCopy1, " ");
        char *lastName1 = NULL;
        while(token1 != NULL){
            lastName1 = token1;
            token1 = strtok(NULL, " ");
        }
        for(int j = i+1; j<n; j++){
            char nameCopy2[10];
            strcpy(nameCopy2,football[j].name);
            char *token2 = strtok(nameCopy2, " ");
            char *lastName2 = NULL;
            while(token2 != NULL){
                lastName2 = token2;
                token2 = strtok(NULL, " ");
            }
            

            if(strcmp(lastName1, lastName2) > 0){
                team tmp;
                tmp = football[i];
                football[i] = football[j];
                football[j] = tmp;
            }
        }
    }
    printf("\n============ NAME ARRANGE ============\n");
    printTeams(football,n);
}

int main(){
    int n;
    do{
        printf("Enter n: ");
        scanf("%d",&n);
    }while(n<=0);

    team football[n];

    inputTeam(football,n);
    top3MaxOfScore(football,n);
    top3MaxOfMember(football,n);
    arrangeName(football,n);
}
