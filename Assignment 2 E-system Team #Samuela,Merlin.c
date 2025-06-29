/*****************************************************************************
 * Welcome to TN E-System programed by Samuela Abigail- 71762108039,         *
 *                                 and Merlin Might V S- 71762108027,        *
 *                                                                           *
 *                                                                           *
 *                               AI & DS Department                          *
 *                        Coimbatore Institute of Technology                 *
 *                                                                           *
 * C File name- ASSIGNMENT 2 E-system Team #Samuela,Merlin.c                 *
 * Notepad (text file) name- ASSIGNMENT 2 E-system Team #Samuela,Merlin.txt ,*
 * addcandidate_source.txt , votecandidate_source.txt                        *
 * Source files- addcandidate.c , votecandidate.c                            *
 * Header files- addcandidate.h , votecandidate.h                            *
 * Text files- candidate_list.txt , voter_list.txt                           *
 *****************************************************************************/

/******This program is created based on our assumptions of EVMs and our understanding of the instructions in GCR*******/
//I(Samuela) have never seen voting machines and don't know it's features :(

#include <stdio.h>
#include <stdlib.h>
#include "votecandidate.h"//including header created by me so that I can call it's library functions here
#include "addcandidate.h"//including header created by Merlin so that I can call it's library functions here

int main()
{
    int option;

    printf("\n**************Press ENTER key to start Machine****************\n");
    getchar();
    screen_clear();//clears screen

do {

    blue();
    printf("\n*********WELCOME to Tamil Nadu State Electoral Commission E-system**********");
    real_clock();//calling to display time

    cyan();
        printf("******************WHO ARE YOU?*************************\n");
        printf("\t1. I'm a Candidate\n");
        printf("\t2. I'm a Voter\n");
        printf("\n**********************PLEASE select a choice**********************\n\n");

        yellow();
        printf("Enter your choice: ");
        scanf("%d",&option);

        switch (option) {
        case 1:
            screen_clear();
            candidate_menu();//calling function from addcandidate.h header file
            break;

        case 2:
             screen_clear();
             voter_menu();//calling function from votecandidate.h header file
            break;

        default:
            red();
            printf("\nInvalid selection! Please try again.\n\n");

        }
     } while (1);


    return 0;
}
