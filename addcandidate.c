/*************************************************************************
 * Welcome to addcandidate.c programed by Merlin Might V S- 71762108027  *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                           AI & DS Department                          *
 *                    Coimbatore Institute of Technology                 *
 *************************************************************************/
#include <stdio.h>
#include "addcandidate.h"
#include "votecandidate.h"//to access color, screen_clear, and real_clock functions and struct candidate
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
//inclusion of struct candidate which is already present in votecandidate.c causes error

/************Global variables************/
char candidateid[5];
char name[50];
char party[50];
int count, division;
char *value;


/**********End of global variables**********/




/*********Menu Option 1 functions************/
//for adding candidates
void add_cand()
{
    char temp[5]="", random[3],line[500];
    char buffer[1024];
    //if temp not initialized as empty string, @ symbol is also coming
    int dup_flag=0, nope=0, i=0, j, k, num, upper=99, lower=10;
    struct Candidate
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int div;//candidate division number (division 1 to division 4)
            int count;//number of votes of candidate
         }C[100];

     FILE* fp = fopen("candidate_list.txt", "r");
        if (fp==NULL) {
        fp = fopen("candidate_list.txt", "w");//if candidate table doesn't exist, we have to create it
        }


     cyan();
     printf("\nNOTE- No two candidates belonging to the same party can stand in the same division\n\n");

     green();
     printf("\nEnter Candidate Name: ");
     getchar();
     scanf("%[^\n]s", name);

     for(k=1;k<2;k++)//to apply break statement
     {
                while (fgets(buffer,1024,fp)) {

                char *ptr = strstr(buffer, name);
                        if (ptr != NULL)
                        {
                            dup_flag=1;//candidate name already there in list
                            break;//so no need to check candidate list further

                        }

                }

                if(dup_flag)//breaks out of loop if flag is set to 1
                   {
                       red();
                       printf("\nAlready registered as candidate!\n\n");
                       break;
                   }

                printf("\nEnter Candidate Party name: ");
                getchar();
                scanf("%[^\n]s",party);

                printf("\nEnter Division number (1-4): ");
                scanf("%d", &division);

                if(division>4 || division<1)
                {
                    red();
                    printf("\nPlease enter correct division number!\n\n");
                    break;
                }


          rewind(fp);//after checking is name is already in list,
          //we have to reset position of cursor to beginning of file

          //2 candidates from same party can't stand in same division
          while(fgets(line, sizeof(line), fp)){

                if(fscanf(fp, "%[^;]s ",buffer))
                   value = strtok(buffer, "|");

               if(feof(fp))
                    break;

                 while (value != NULL) {

                  strcpy(C[i].name,value);

                  value = strtok(NULL, "|");
                  strcpy(C[i].par ,value);

                  value = strtok(NULL, "|");
                  strcpy(C[i].id,value);

                 value = strtok(NULL, "|");
                C[i].div = value;

                value = strtok(NULL, "|");
                C[i].count= value;
                value = strtok(NULL, "|");

                if(atoi(C[i].div)==division && strcmp(party,C[i].par)==0)
                {
                    nope=1;
                    break;
                }

            }

                i++;
          }

          if(nope)
            {
                red();
                printf("\nOnly 1 candidate from a party can stand in a division!\n\n");
                break;
            }



                //for candidate ID generation
                for(j=0;j<3;j++)
                {
                    if(islower(party[j]))
                    {
                        temp[j]=party[j]-32;//to convert to uppercase

                    }
                    else
                        temp[j]=party[j];
                }


                //generating random 2-digit number for candidate ID
                srand(time(0));
                num = (rand() % (upper - lower + 1)) + lower;

                sprintf(random,"%d",num);//copying integer to string

                strcat(temp,random);//concatenating temp with random to get alphanumeric candidate ID
                strcpy(candidateid,temp);

                printf("\nYour Candidate ID is: ");
                purple();
                printf("%s",candidateid);

                fclose(fp);
                fp = fopen("candidate_list.txt", "a");

                // Saving data in file
                count=0;//default value
                fprintf(fp,"\n%s|%s|%s|%d|%d;", name, party, candidateid, division, count);
                yellow();
                printf("\n\nCandidate registered successfully!\n\n");

     }

    fclose(fp);

}

/*****************************
* End of add_cand() function *
*****************************/


/*********End of Menu Option 1 functions************/




/*********Menu Option 2 functions************/
//to display full candidate list
void view_cand()
{
    int i=0;
    char line[500], buffer[1024];

    struct Candidate
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int div;//candidate division number (division 1 to division 4)
            int count;//number of votes of candidate
         }C[100];


   purple();
   printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY NAME\t\t\tDIVISION\n");

   FILE* fp = fopen("candidate_list.txt", "r");
        if (fp==NULL) {
        red();
        printf("\nError in opening file\n");
        }

            yellow();
          while(fgets(line, sizeof(line), fp)){

                if(fscanf(fp, "%[^;]s ",buffer))
                   value = strtok(buffer, "|");

               if(feof(fp))
                    break;

                 while (value != NULL) {

                  strcpy(C[i].name,value);

                  value = strtok(NULL, "|");
                  strcpy(C[i].par ,value);

                  value = strtok(NULL, "|");
                  strcpy(C[i].id,value);

                 value = strtok(NULL, "|");
                C[i].div = value;

                value = strtok(NULL, "|");
                C[i].count= value;
                value = strtok(NULL, "|");

                printf("\n%s\t\t\t%s\t\t%s\t\t\t%s\n",C[i].id,C[i].name,C[i].par,C[i].div);
                }

                i++;
          }

          fclose(fp);
          printf("\n\n");
}

/******************************
* End of view_cand() function *
*******************************/


/*********End of Menu Option 2 functions************/





/************Function to be called inside main() function***************/
void candidate_menu()
{
    int option;


         blue();
         printf("\n*********WELCOME to Tamil Nadu State Electoral Commission E-system**********");
         real_clock();//calling to display time

        cyan();
        printf("\t1. Add Candidate\n");
        printf("\t2. View Candidates\n");
        printf("\t3. Quit\n");
        printf("\n******************PLEASE select a choice******************\n\n");

        yellow();
        printf("\nEnter your choice: ");
        scanf("%d", &option);


        switch (option) {
        case 1:
            screen_clear();
            add_cand();
            break;

        case 2:
            screen_clear();
            view_cand();
            break;

        case 3:
            screen_clear();
            green();
            printf("\nGood luck for the election. Goodbye!\n\n");
            exit(0);
            break;

        default:
            red();
            printf("\nInvalid selection, please try again!\n\n");
        }

}
