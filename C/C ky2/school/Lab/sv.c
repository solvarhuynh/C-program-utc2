#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SV{
    char id[10];
    char name[50];
    float score;
    struct SV* next;
}SV;

SV* createSV(char* id, char* name, float score){
    SV* sv=(SV*)malloc(sizeof(SV));
    strcpy(sv->id,id);
    strcpy(sv->name,name);
    sv->score=score;
    sv->next=NULL;
    return sv;
}

void insertSorted(SV** head, SV* sv){
    if(*head==NULL||strcmp(sv->id,(*head)->id)<0){
        sv->next=*head;
        *head=sv;
        return;
    }
    SV* temp=*head;
    while(temp->next!=NULL&&strcmp(sv->id,temp->next->id)>0){
        temp=temp->next;
    }
    sv->next=temp->next;
    temp->next=sv;
}

void displayList(SV* head){
    while(head!=NULL){
        printf("%s %s %.2f\n",head->id,head->name,head->score);
        head=head->next;
    }
}

SV* findByID(SV* head, char* id){
    while(head!=NULL){
        if(strcmp(head->id,id)==0)return head;
        head=head->next;
    }
    return NULL;
}

void delByID(SV** head, char* id){
    SV* temp=*head,*prev=NULL;
    while(temp!=NULL&&strcmp(temp->id,id)!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    if(prev==NULL)*head=temp->next;
    else prev->next=temp->next;
    free(temp);
}

SV* findMaxScore(SV* head){
    if(head==NULL)return NULL;
    SV* max=head;
    while(head!=NULL){
        if(head->score>max->score)max=head;
        head=head->next;
    }
    return max;
}

void updateSV(SV* head, char* id, char* name, float score){
    SV* sv=findByID(head,id);
    if(sv){
        if(name)strcpy(sv->name,name);
        if(score>=0)sv->score=score;
    }
}

void findByScoreRange(SV* head, float min, float max){
    while(head!=NULL){
        if(head->score>=min&&head->score<=max)
            printf("%s %s %.2f\n",head->id,head->name,head->score);
        head=head->next;
    }
}

void saveToFile(SV* head, const char* fn){
    FILE* f=fopen(fn,"wb");
    while(head!=NULL){
        fwrite(head,sizeof(SV)-sizeof(SV*),1,f);
        head=head->next;
    }
    fclose(f);
}

void loadFromFile(SV** head, const char* fn){
    FILE* f=fopen(fn,"rb");
    if(!f)return;
    SV sv;
    while(fread(&sv,sizeof(SV)-sizeof(SV*),1,f)){
        SV* newSV=createSV(sv.id,sv.name,sv.score);
        insertSorted(head,newSV);
    }
    fclose(f);
}

int main(){
    SV* list=NULL;
    int opt;
    char id[10],name[50];
    float score,min,max;
    do{
        printf("\n===== SELECT =====\n");
        printf("1. Them thong tin sv\n2. Hien thi\n3. Tim MSSV\n4. Xoa MSSV\n5. Diem cao nhat\n6. Cap nhat\n7. Tim theo diem\n8. Luu\n9. Doc\n0. Thoat\nChon: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("ID: ");scanf("%s",id);
                printf("Ten: ");scanf(" %[^\n]",name);
                printf("Diem: ");scanf("%f",&score);
                insertSorted(&list,createSV(id,name,score));
                break;
            case 2:
                displayList(list);
                break;
            case 3:
                printf("Nhap MSSV: ");scanf("%s",id);
                SV* sv=findByID(list,id);
                if(sv)printf("%s %s %.2f\n",sv->id,sv->name,sv->score);
                else printf("Khong tim thay\n");
                break;
            case 4:
                printf("Nhap MSSV: ");scanf("%s",id);
                delByID(&list,id);
                break;
            case 5:
                sv=findMaxScore(list);
                if(sv)printf("%s %s %.2f\n",sv->id,sv->name,sv->score);
                break;
            case 6:
                printf("Nhap MSSV: ");scanf("%s",id);
                printf("Ten moi: ");scanf(" %[^\n]s",name);
                printf("Diem moi: ");scanf("%f",&score);
                updateSV(list,id,name,score);
                break;
            case 7:
                printf("Min: ");scanf("%f",&min);
                printf("Max: ");scanf("%f",&max);
                findByScoreRange(list,min,max);
                break;
            case 8:
                saveToFile(list,"sv.dat");
                break;
            case 9:
                loadFromFile(&list,"sv.dat");
                break;
        }
    }while(opt!=0);
    return 0;
}
