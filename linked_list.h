#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct user User;

struct user{
    char username[100] ;
    int pass;
    int id ;
    struct user *next ;
    };
int x ;
int pss;

 void appendNode(char usern[100] , int Pass, int ID  );
 void printNodes();
 int check_username(char name[100] );
 int check_pass(int pass);
 int check_id(int id);
 void edit_node (char old_user[100],char usern[100] , int Pass, int ID );

#endif
