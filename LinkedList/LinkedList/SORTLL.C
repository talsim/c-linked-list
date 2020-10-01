#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node * head = NULL;
void sort();
void print();
void main(){
int choice;
struct node *newnode,*temp;
clrscr();
while(choice){
newnode = (struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head == NULL){
head=newnode;
temp=newnode;
}
else{
temp->next=newnode;
temp=newnode;
}
printf("do u want to continue?(0,1)");
scanf("%d",&choice);
}
temp=head;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}
printf("\nsorted list is:\n");
sort();
print();
getch();
}
void sort(){
struct node *curr,*prev;
int temp;
prev=NULL;
for(curr=head;curr!=NULL;curr=curr->next){
  for(prev=curr->next;prev!=NULL;prev=prev->next){
    if(curr->data > prev->data){
    temp=curr->data;
    curr->data=prev->data;
    prev->data=temp;
    }
  }
}
}
void print(){
struct node *temp;
temp=head;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}
}
