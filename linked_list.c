#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

 User* head = NULL ;
 User* tail = NULL ;

// to add a node
void appendNode(char usern[100] , int Pass, int ID   ){
    struct user *node = (struct user*) malloc(sizeof(struct user));
    node->next = NULL ;
    strcpy(node->username , usern);
    node->pass = Pass ;
    node->id = ID ;
    //strcmp(node->books , books) ;
    if (head == NULL){
        head = node ;
        tail = node ;
    }
    else {
        tail->next=node;
        tail=node;
    }

	}


//To print nodes (printing the users when you get in as an admin)
void printNodes(){
    User *node = '\0' ;
    printf("\n\n\n\t\t\t username \t | passward \t | id \t  \n");
    printf("\t\t\t _________________________________________\n\n");
     for(node=head; node!= NULL; node=node->next)
    {
        printf("\t\t\t %s    \t | %i \t | %i \n " ,node->username , node->pass ,node->id  );
    }
	}


// to compare the username with all the usernames in the linked list
int check_username(char name[100] ) {
    User *node = '\0' ;
     for(node=head; node!= NULL; node=node->next){
            if(!(strcmp(node->username , name) ) ){
                x = node->id;
                pss = node->pass;
                return 1 ;
            }
      }
      return 0 ;
}
// to compare the password with all the password in the linked list
int check_pass(int pass){
    User *node = '\0' ;
     for(node=head; node!= NULL; node=node->next){
            if(pass == node->pass ){
                return 1 ;
            }
      }
      return 0 ;
}
// to check id
int check_id(int id){
    User *node = '\0' ;
     for(node=head; node!= NULL; node=node->next){
            if(id == node->id ){
                return 1 ;
            }
      }
      return 0 ;
}

// to edit an user
void edit_node (char old_user[100],char usern[100] , int Pass, int Id ){
    User *node = head ;
    while (node!= NULL && (strcmp(node->username , old_user)) )
		{
			node=node->next;
		}
	strcpy(node->username ,usern );
	node->pass = Pass ;
	node->id = Id ;

}





