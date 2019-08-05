
#include "linked_list.h"
#define STATIC_PASS 1234

/**** Global Variables ****/
int type ;
int admin_pass; // to take the pass of the admin
int number_users ;
User user ;
struct Book {
    char name[100] ;
    int id ;
    short state  ;
    short student_id ;
    };
// ARRAY OF THE BOOKS
struct Book books[11] = {{"one  "  , 1 , 1 , 1 } ,
                         {"two  "  , 2 , 1 , 1 } ,
                         {"three" , 3 , 0 } ,
                         {"four "  , 4 , 0 } ,
                         {"five "  , 5 , 1 , 2 } ,
                         {"six  "  , 6 , 0 } ,
                         {"seven" , 7 , 0 },
                         {"eight" , 8 , 1 , 3 },
                         {"nine "  , 9 , 0 } ,
                         {"ten  "  , 10, 1 , 4}};

/******       admin functions :-     ******/

/** to get back to the admin page**/
void get_back_to_admin(){
    puts("\t\t\t enter any key to get back ");
    getch();
    admin ();
}

void show_users(){
    system("cls");
    printNodes();
    get_back_to_admin();
    }

/** to add a user to the system **/
void add_user(){

    printf("\n\n\n\t\t\t add the username plz : ");
    scanf("%s" ,& user.username);
    if(check_username(user.username)){
            printf("\t\t\t This username is taken please choose another one ."); add_user();}
    printf("\n\t\t\t add the password plz : ");
    scanf("%i" ,& user.pass);
    printf("\n      \t\t\t add the id plz : ");
    scanf("%i" ,& user.id);
    appendNode( user.username,user.pass ,user.id );
    get_back_to_admin();
}

/**  to edit an user by entering his name  **/
void edit_user(){
    printf("\n\n\n \t\t\t enter username : ");
    char username[100];
    scanf("%s" ,& username);
    // to make the user choose what he want to edit
    if(check_username(username)){
        printf("\n\n\t\t\t the user's file :- \n\n");
        printf("\t\t\t 1 - user name :-   %s \n" , username);
        printf("\t\t\t 2 - password  :-   %i \n" , pss);
        printf("\t\t\t 3 - id        :-   %i \n\n" , x);
    }
    else {printf("\t\t\t wrong username ."); edit_user();} // in case he entered a wrong username
    int choise = 0 ;
    int flag = 0 ;
    // to make sure the user enter the right choise
    while(flag == 0){
        printf("\n\t\t\t choose what you want to edit . ");
        scanf("%i" , & choise);
        if (choise > 3 ){printf("\n\t\t\t wrong entry");}
        else{flag = 1 ;}
    }
    switch(choise)
    {
        case 1 : printf("\n\t\t\t Enter tne new username pleaze .");
                 scanf("%s" ,& user.username) ;
                 if(check_username(user.username)){printf("\t\t\tThe Username is taken .\n"); get_back_to_admin(); }
                 else {break ;}
        case 2 : printf("\n\t\t\t Enter tne new password pleaze .");
                 scanf("%i" ,& pss) ;
                 strcpy(user.username , username);
                 break ;
        case 3 : printf("\n\t\t\t Enter tne new id pleaze .");
                 scanf("%i" ,& x) ;
                 strcpy(user.username , username);
                 if ( !(check_id(x)) ){break ;}
                 else {printf("\n\t\t\t This id is already taken .\n") ; get_back_to_admin();}

    }
    edit_node(username,user.username , pss , x);
    get_back_to_admin();
}

/*** to reserve a book to a particular user ***/
void reserve_book(){
    system("cls");
    int i = 0 ;
    printf("\n\n\n\t\t\t number  |   name \n"  );
    printf("\t\t\t ________________\n\n");
    while(i < 10 ){
        if(books[i].state == 0 ){
            printf("\t\t\t %i       |   %s \n" , i+1 ,books[i].name );
        }
        i++;
    }
    int flag = 0 ;
    while(flag == 0){
        printf("\n \n\t\t\t choose the book u want to reserve ");
        short choise = 0 ;
        scanf("%i", & choise);
        if ( (books[choise-1].state == 1) || (choise > 10) ){puts("\t\t\t wrong entry");}
        else {
            books[choise-1].state = 1 ;
            printf("\n\t\t\t enter the student id you want to reserv this book to ");
            scanf("%i" , & books[choise-1].student_id );
            if(!(check_id(books[choise-1].student_id))){printf("\n\t\t\t wrong id"); get_back_to_admin();}
            flag = 1 ;
        }
    }
    get_back_to_admin();
}

/**** to change  a borrowed book to available , will show the borrowed books to choose from them  ****/
void make_available(){
    system("cls");
    int i = 0 ;
    printf("\t\t\t number | name   | student ID \n "  );
    printf("\t\t\t _____________________________ \n \n");
    while(i < 10 ){
        if(books[i].state == 1 ){
            printf("\t\t\t  %i \t|%s \t | %i \t \n" , i+1 ,books[i].name,books[i].student_id );
        }
        i++;
    }
    int flag = 0 ;
    while(flag == 0){
        printf("\n \n\t\t\t choose the book u want to make available ");
        short choise = 0 ;
        scanf("%i", & choise);
        if ( (books[choise-1].state == 0 ) || (choise > 10) ){puts("\t\t\t wrong entry");}
        else {books[choise-1].state = 0 ;
              books[choise-1].student_id  = '\0' ;
              flag = 1 ;}
    }
    get_back_to_admin();
}
/*****************************/

/** in case you chose admin (admin's menu) **/
void admin (){
    system("cls");
    puts("\n\n\n\t\t\t Welcome to the admin page");
    puts("\t\t\t ___________________________\n");
    puts("\n\t\t\t 1 - Show users .");
    puts("\n\t\t\t 2 - Add user .");
    puts("\n\t\t\t 3 - Edit an user .");
    puts("\n\t\t\t 4 - Reserve a book .");
    puts("\n\t\t\t 5 - Make a book available .");
    puts("\n\t\t\t 6 - get back .");
    puts("\n\t\t\t plz choose :\n");
    short choise = 0 ;
    scanf("%i" , & choise); // variable to take the entered choise from the user
    switch (choise)
    {
        case 1: show_users();
            break;
        case 2: system("cls"); add_user();
            break;
        case 3 : system("cls"); edit_user();
            break;
        case 4: reserve_book();
            break;
        case 5: make_available();
            break;
        case 6: system("cls"); log_in();
            break;

        default: puts("\t\t\t wrong entry\n"); admin();
     }
}
/********               users functions                   ***********/

/**  to get back to user's menu **/
void get_back_to_users(){
    puts("\n\n\t\t\t enter any key to get back ");
    getch();
    users();
}

void show_statues(){
    system("cls");
    printf("\n\n\n \t\t\t user's data : \n");
    printf("\t\t\t ____________________\n\n ");
    printf("\t\t\t username: %s\n" , user.username);
    printf("\t\t\t pass    : %i\n",user.pass);
    printf("\t\t\t id      : %i\n\n",x);
    get_back_to_users();
}

/**** to show the books the user can borrow ****/

void show_available_books(){
    system("cls");
    int i = 0 ;
    printf("\n\n\n\t\t\t number \t | name \t |   \t ID \n "  );
    printf("\t\t\t ____________________________________________ \n \n");
    int j = 1 ;
    while(i < 10 ){
        if(books[i].state == 0 ){
            printf("\t\t\t %i \t         |  %s  \t | \t %i \n" , j ,books[i].name ,books[i].id  );
            j++;
        }
        i++;
    }
    get_back_to_users();
}

/** to show the books the users has borrowed**/
void show_borrowed_books(){
    system("cls");
    printf("\n\n\n\t\t\t borrowed books :- \n\n\n"  );
    printf("\t\t\t number  | name \t | \t ID \n "  );
    printf("\t\t\t _________________________________________ \n \n");
    int i = 0 ;
    int j = 0;
    while(i < 10 ){
        if(books[i].state == 1 && books[i].student_id == x  ){
            printf("\t\t\t %i \t | %s \t | \t %i \n" , j ,books[i].name ,books[i].id  );
            j++;
        }
        i++;
    }
    get_back_to_users();
}

/*** gets excuted in case you chose to enter as user and entered the username and pass right   ***/
void users(){
    system("cls"); // to clear the console
    puts("\n\n\n\t\t\t Welcome to the admin page\n");
    puts("\n\t\t\t 1 - Show my statues .");
    puts("\n\t\t\t 2 - show available books .");
    puts("\n\t\t\t 3 - show borrowed books .");
    puts("\n\t\t\t 4 - get back .");
    puts("\n\t\t\t plz choose :\n");
    short choise = 0 ; // variable to take the entered choise from the user
    printf("\t\t\t");
    scanf("%i" , & choise);
    switch (choise)
    {
        case 1: show_statues(); // if user entered 1
            break;
        case 2: show_available_books(); // if user entered 2
            break;
        case 3: show_borrowed_books(); // if user entered 3
            break;
        case 4: system("cls"); log_in(); // if user entered 4
            break;
        default: puts("wrong entry"); admin(); // if user entered anything but the above
     }
}

/***********************************************************************/

/** function to log in the system and choose admin or user if admin you enter the pass 1234   **/
void log_in (){
    puts("\n\n\n\t\t Select if u are an admin or an user");
    puts("\t\t\t 1- admin     2 - user");
    puts("\t\t _________________________________________");
    printf("\t\t ");
    scanf("%i" ,& type);
    if (type == 1 ){
        printf("\n\t\t enter the password please : ");
        scanf("%i" ,& admin_pass);
        if (admin_pass == STATIC_PASS ) {admin();}
        else{puts("\t\t wrong password"); log_in();}
    }
    else if (type == 2){
        printf("\n \t\t enter username plez : ");
        scanf("%s" ,& user.username);
        printf("\n \t\t enter password plez : ");
        scanf("%i" ,& user.pass);
        if ( (check_username(user.username)) &&(check_pass(user.pass)) ){users();}
        else{puts("\n\t\t username or password isn't right"); log_in(); }
    }
    else {puts ("\t\t wrong entry") ;  log_in();}
}

/************************************************************************/

int main()
{
    appendNode("ahmed" ,1234 ,1 ); //user1
    appendNode("mohamed" ,1234 ,2  ); //user2
    appendNode("mosad" ,1234 ,3 ); //user3
    appendNode("body" ,1234 ,4 ); //user4

    log_in();
}
