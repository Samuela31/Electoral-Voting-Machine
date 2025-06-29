/*************************************************************************
 * Welcome to votecandidate.c programed by Samuela Abigail- 71762108039  *
 *                                                                       *
 *                                                                       *
 *                                                                       *
 *                           AI & DS Department                          *
 *                    Coimbatore Institute of Technology                 *
 *************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "votecandidate.h"


 /*****global variables*******/
//for voters
struct voters
 {
    char voter_id[45];//voter ID
    char voter_name[45];//voter first name
    char status;//Y means already voted, N means not voted
    int voter_div;//voter division number (division 1 to division 4)
    int age;//age of voter should be >=18
 }voter;



 /*****End of global variables*******/



/***********Accessory functions************/
//red color
void red(){
    printf("\033[1;31m");
}
void reset();



//green color
void green(){
    printf("\033[1;32m");
}
void reset();



//yellow color
void yellow(){
    printf("\033[1;33m");
}
void reset();



//blue color
void blue(){
    printf("\033[1;34m");
}
void reset();



//purple color
void purple(){
    printf("\033[1;35m");
}
void reset();



//cyan color
void cyan(){
    printf("\033[1;36m");
}
void reset();




/*********************************
 * End of colored text functions *
 *********************************/




//function to clear screen. Use cls for TurboC and clear for GCC/G++ compilers
void screen_clear()
{
     system("cls");
}



/**********************************
 * End of screen_clear() function *
 **********************************/



 //function which displays real/actual time
void real_clock()
{
    time_t t;//for showing actual time
    time(&t);//I used time to make this machine look pretty, although not sure if real EVMs display time

        //made this much space characters so that clock will be placed in right most corner
        green();
        printf("   ***************************\n");
        printf("                                                                                 %s",ctime(&t));//displays time
        printf("                                                                               ***************************\n\n");
}



/********************************
 * End of real_clock() function *
 ********************************/

 /*************End of accessory functions***************/





 /**********Menu option 1 functions***********/
//displays list of all candidates
void full_candidate_list()
{
    int i=0;
    char buf[500], line[500];
    char* token;

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
         }Cand[100];

    FILE *fptr;
//inside candidate list file, if I store details having space characters inbetween, strtok is considering that also as part of string
//so strcmp will give non zero value when comparing in if loop
//so don't leave space between each detail like name and party name

    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }

    purple();
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY NAME\t\t\tDIVISION\tVOTES\n");

    yellow();
    // Keep printing tokens while one of the
    // delimiters present in str[].
    //https://fresh2refresh.com/c-programming/c-strings/c-strtok-function/
    //https://stackoverflow.com/questions/3889992/how-does-strtok-split-the-string-into-tokens-in-c
    //I tried using fscanf() with %[^|]s and all, but it didn't work
  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

       if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

        token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        printf("\n%s\t\t\t%s\t\t%s\t\t\t%s\t\t%s\n",Cand[i].Cand_id,Cand[i].Cand_name,Cand[i].Cand_par,Cand[i].Cand_div,Cand[i].Cand_count);
        }

        i++;
  }

  printf("\n\n");

    fclose(fptr);

}




/*****************************************
 * End of full_candidate_list() function *
 *****************************************/



//for displaying candidate list division-wise
void div_list()
{
    int i=0, div_flag=1;
    char division[2]="2";//I'm declaring and initializing it as string since it is part of line in file which is a string
    char buf[500], line[500];
    char* token;

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
         }Cand[100];

    FILE *fptr;


    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }


    green();
    printf("Enter division number: ");
    scanf("%s",division );

    purple();
    printf("\nCandidates from division %s are: \n",division);
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY NAME\tVOTES\n");

    yellow();
    // Keep printing tokens while one of the
    // delimiters present in str[].
  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

        if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

         token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        if(strcmp(Cand[i].Cand_div,division)==0)
        {
            printf("\n%s\t\t\t%s\t\t%s\t\t%s\n",Cand[i].Cand_id,Cand[i].Cand_name,Cand[i].Cand_par,Cand[i].Cand_count);
            div_flag=0;
        }


    }

        i++;
  }

        if(div_flag)
         {
             red();
             printf("\nEnter correct division number!");
         }

    fclose(fptr);

      printf("\n\n");


}



/******************************
 * End of div_list() function *
 ******************************/




//for displaying candidate list party-wise
void par_list()
{
    int i=0, par_flag=1;
    char party[100];
    char buf[500], line[500];
    char* token;

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
         }Cand[100];

    FILE *fptr;


    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }


    green();
    printf("Enter party name: ");
    getchar();
    scanf("%[^\n]s",party);

    purple();
    printf("\nCandidates from party %s are: \n",party);
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tDIVISION\tVOTES\n");

    yellow();
    // Keep printing tokens while one of the
    // delimiters present in str[].
  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

       if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

        token = strtok(NULL, "|");
        Cand[i].Cand_count= token;

        token = strtok(NULL, "|");

        if(strcmp(Cand[i].Cand_par,party)==0)
        {
            printf("\n%s\t\t\t%s\t\t\t\t%s\t\t%s\n",Cand[i].Cand_id,Cand[i].Cand_name,Cand[i].Cand_div, Cand[i].Cand_count);
            par_flag=0;
        }

    }

        i++;
  }

         if(par_flag)
         {
             red();
             printf("\nParty not found!");
         }

    fclose(fptr);

          printf("\n\n");


}



/******************************
 * End of par_list() function *
 ******************************/



//for viewing candidates in option 1 in menu
void view_candidates()
{
    int option;

    screen_clear();

    blue();
    printf("\n******************WELCOME to List of Election Candidates********************");
    real_clock();

        cyan();
        printf("\t1. View all candidates\n");
        printf("\t2. View candidates by division\n");
        printf("\t3. View candidates by party\n");
        printf("\n**********************PLEASE select a choice**********************\n\n");

        yellow();
        printf("Enter your choice: ");
        scanf("%d",&option);

        green();
        switch (option) {
        case 1:
            screen_clear();
            full_candidate_list();

            break;

        case 2:
             screen_clear();
             div_list();

            break;

        case 3:
             screen_clear();
             par_list();

            break;

        default:
            red();
            printf("\nInvalid selection! Please try again.\n\n");

        }

}



/*************************************
 * End of view_candidates() function *
 *************************************/


/*********End of Menu option 1 functions************/




/**********Menu option 2 functions***********/
//to register as voter
void register_voter()
{
    char temp[100], line[100], str[]="@EVM#";
    int i=0,j=0,len,k, dup_flag=0, no_space_flag=1;

    screen_clear();

    blue();
    printf("\n******************WELCOME to Voter Registration Portal**********************");
    real_clock();


   for(k=1;k<2;k++ )//for the sake of having a loop to apply break statement.
        //We have specified conditions so that for loop will be executed only once,
        //otherwise it'll be infinite loop if left as for ( ; ; )
   {
       cyan();
       printf("*You should be at least 18 years old to register as voter.\n");
       printf("*Your division number should be from 1 to 4.\n");
       printf("*While entering name, please leave space in case of initials. Example- L Sasha\n\n\n");

           yellow();
           printf("\nEnter your full name: ");
           getchar();//if not used means scanf won't work for strings involving space characters
           scanf("%[^\n]s", voter.voter_name);

           FILE *file=fopen("voter_list.txt","r");//opening file in reading mode

            if(file==NULL){
                file=fopen("voter_list.txt","w");//since we are supposed to create a voter file if it doesn't exist
                //at least that's what is written in that assignment PDF
                //so I'm not printing error message nor implementing exit(1)
            }

           while ( fgets ( line, sizeof(line), file )!=NULL)//checking each line for duplicate voter name
                {
                   char *ptr = strstr(line, voter.voter_name);
                    if (ptr != NULL)
                    {
                        dup_flag=1;//voter name is already registered
                        break;//so no need to check voter list further

                    }
                }

           fclose(file);

           if(dup_flag)//breaks out of loop if flag is set to 1
           {
               red();
               printf("Already registered as voter!\n\n");
               break;
           }

           printf("\nEnter your age: ");
           scanf("%d", &voter.age);


           if(voter.age <18)
                {
                  red();
                  printf("\nYou are not eligible to be vote!\n\n");
                  break;
              }

           printf("\nEnter your division number: ");
           scanf("%d", &voter.voter_div);

           if(voter.voter_div <1 || voter.voter_div >4)
                {
                  red();
                  printf("\nInvalid division number!\n\n");
                  break;
                }

           green();
           printf("\n\nYou have successfully registered as a voter!");
           printf("\nHere is your voter ID, PLEASE keep it carefully: ");


            len=strlen(voter.voter_name);
            strcpy(temp, voter.voter_name);//storing voter name in temp.
            //If voter.voter_name itself used means concatenated name will be saved in file in place of actual name

                for(i=0,j=0 ; i<len ; i++)//for removing space characters, but won't work for names without space characters,
                                         //and hence their voter ID's will be blank
                    {
                        if(temp[i] == ' ' && temp[i]!=NULL)
                        {
                            for(j=i ; j<len ; j++)
                            {
                                temp[j] = temp[j+1];
                            }
                            len--;
                            no_space_flag=0;//flag is set to 0 since voter name has space character
                            //if voter name doesn't have space character (example- Sasha),it won't go inside above loop and voter ID won't be generated
                        }
                    }

                temp[j]='\0';//assigning NULL at end of string

            if(no_space_flag)//generating voter ID for names without space character
            {
                strcpy(temp,voter.voter_name);//if I remove this here despite already applying it above for loop, it's not working
                strcat(temp, str);//concatenating
                strcpy(voter.voter_id,temp);//voter ID is voter name only with @EVM# in end
            }

            else//for voters having space character in their name
            {
               strcpy(voter.voter_id,temp);//assigning voter ID
            }

            purple();
            printf("%s\n\n", voter.voter_id);

            voter.status='N';

            FILE *fptr=(fopen("voter_list.txt","a"));//opening file in appending mode

            if(fptr==NULL){
                red();
                printf("\nNo voters yet. Please try again later\n\n");
                exit(1);
            }


            //storing full name, voter ID, age, division, and status of voter in file
            fprintf(fptr,"\n%s|%s|%d|%d|%c;", voter.voter_name, voter.voter_id, voter.age, voter.voter_div, voter.status);
            //if I don't use \n, it's not getting stored as separate line, but is getting attached to previous line
            fclose(fptr);

   }
}


/************************************
 * End of register_voter() function *
 ************************************/


/*********End of Menu option 2 functions************/





/**********Menu option 3 functions***********/
//registered voters will vote
void voting()
{
    char buf[100], line[100], id[100], name[100];
    char division[2]="2";//if I don't make division into character array (i.e) string, it won't work
    int i=0,j=0, k, vote_flag=1, voter_is, val, voted=0;
    char* token;

    struct Voter
         {
            char V_id[45];//voter ID
            char V_name[45];//voter name
            int V_div;//voter division number (division 1 to division 4)
            int V_age;//voter age
            int V_status;//Y/N
         }V[100];

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
         }Cand[100];

    screen_clear();

    blue();
    printf("\n*******************WELCOME to Election Voting Portal************************");
    real_clock();

    cyan();
    printf("\n*You can vote only once");
    printf("\n*You can vote for any candidate standing in your division\n\n");

           green();
           printf("\nEnter your voter ID: ");
           scanf("%s", id);

           FILE *file=(fopen("voter_list.txt","r"));//opening file in reading mode

            if(file==NULL){
                red();
                printf("\nNo voters yet. Please try again later\n\n");
                exit(1);
            }

for(k=1;k<2;k++ )//for the sake of having a loop to apply break statement.
        //We have specified conditions so that for loop will be executed only once
   {

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while(fgets(line, sizeof(line), file)){

        if(fscanf(file, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");//content of line till 1st '|' is encountered gets stored in token now

        if(feof(file))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(V[i].V_name,token);

          token = strtok(NULL, "|");
          strcpy(V[i].V_id ,token);

          token = strtok(NULL, "|");
          V[i].V_age=token;

         token = strtok(NULL, "|");
        V[i].V_div = token;

        token = strtok(NULL, "|");
        V[i].V_status=token;

        token = strtok(NULL, "|");
        }

        if(strcmp(V[i].V_id, id)==0 && strcmp(V[i].V_status,"N")==0)
        //though status is a single character N or Y, it's considered as a string
        {
                vote_flag=0;
                voter_is=i;//determining which position this person(voter) is in full voter list
                strcpy(division,V[i].V_div);
                yellow();
                printf("\nYou are from division %s",V[i].V_div);
        }


        i++;
  }

           if(vote_flag)
           {
               red();
               printf("\nSorry! You can\'t vote due to any of the following reasons-");
               printf("\n*You are not a registered voter");
               printf("\n*You have already voted\n\n");
               break;

           }

         FILE *fptr;


    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }

     FILE *fp;
     FILE *FP;


    if ((fp = fopen("temp_cand.txt", "w")) == NULL)
                {
                    red();
                    printf("Error in opening temp_cand.txt\n");

                }

    if ((FP = fopen("temp_voter.txt", "w")) == NULL)
                {
                    red();
                    printf("Error in opening temp_voter.txt\n");

                }


    printf("\nCandidates from your division are: \n");
    purple();
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY\t\t\tVOTES\n");

    yellow();
    // Keep printing tokens while one of the
    // delimiters present in str[].
  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

       if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[j].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[j].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[j].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[j].Cand_div = token;

        token = strtok(NULL, "|");
        Cand[j].Cand_count= token;

        token = strtok(NULL, "|");

        if(strcmp(division,Cand[j].Cand_div)==0)
        {
            printf("\n%s\t\t\t%s\t\t\t%s\t\t%s\n",Cand[j].Cand_id,Cand[j].Cand_name,Cand[j].Cand_par, Cand[j].Cand_count);
        }

    }

        j++;
  }

      green();
      printf("\n\nEnter name of candidate you want to vote: ");
      getchar();
      scanf("%[^\n]s",name);

      rewind(file);
      rewind(fptr);
      i=0;
      j=0;

   while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

       if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[j].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[j].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[j].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[j].Cand_div = token;

        token = strtok(NULL, "|");
        Cand[j].Cand_count= token;

        token = strtok(NULL, "|");

        if(j==0)
        {
           fprintf(fp,"\n");//if first line is not empty in file, first person's details aren't being recognized
        }

        if(strcmp(name,Cand[j].Cand_name)==0 && strcmp(division,Cand[j].Cand_div )==0)
        //if voting is done without checking if voter and candidate are from same division, it won't be foolproof
          {
              val=atoi(Cand[j].Cand_count);
              val++;
              voted=1;
              fprintf(fp,"%s|%s|%s|%s|%d;\n",Cand[j].Cand_name,Cand[j].Cand_par,Cand[j].Cand_id,Cand[j].Cand_div,val);
          }

          else
              {
                  fprintf(fp,"%s|%s|%s|%s|%s;\n",Cand[j].Cand_name,Cand[j].Cand_par,Cand[j].Cand_id,Cand[j].Cand_div,Cand[j].Cand_count);
              }

    }

        j++;
  }



  while(fgets(line, sizeof(line), file)){

        if(fscanf(file, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");//content of line till 1st '|' is encountered gets stored in token now

        if(feof(file))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(V[i].V_name,token);

          token = strtok(NULL, "|");
          strcpy(V[i].V_id ,token);

          token = strtok(NULL, "|");
          V[i].V_age=token;

         token = strtok(NULL, "|");
        V[i].V_div = token;

        token = strtok(NULL, "|");
        V[i].V_status=token;

        token = strtok(NULL, "|");
        }

        if(i==0)
        {
           fprintf(FP,"\n");//if first line is not empty in file, first person's details aren't being recognized
        }

         if(i==voter_is && voted==1)//if voted=1 condition not there, then it'll change status into Y even if voter enters wrong name
          {
              strcpy(V[i].V_status,"Y");
              fprintf(FP,"%s|%s|%s|%s|%s;\n",V[i].V_name,V[i].V_id,V[i].V_age,V[i].V_div,V[i].V_status);

          }

          else
            {
              fprintf(FP,"%s|%s|%s|%s|%s;\n",V[i].V_name,V[i].V_id,V[i].V_age,V[i].V_div,V[i].V_status);
            }


        i++;
  }

    fclose(fptr);
    fclose(fp);
    fclose(FP);
    fclose(file);

      if(voted)//if voted=1 condition not there, then it'll change status into Y even if voter enters wrong name
      {
          cyan();
          printf("\nYou have voted successfully!");
          remove("candidate_list.txt");
          remove("voter_list.txt");

          rename("temp_cand.txt","candidate_list.txt");
          rename("temp_voter.txt","voter_list.txt");
      }

      else
      {
        red();
        printf("\nPlease enter correct name of candidate you want to vote!");
      }


    printf("\n\n");
   }

}



/****************************
 * End of voting() function *
 ****************************/


/*********End of Menu option 3 functions************/




/**********Menu option 4 functions***********/
//voting results and summary
void voting_result()
{
    int option;

    screen_clear();

    blue();
    printf("\n**********************WELCOME to Voting Results Portal**********************");
    real_clock();

        cyan();
        printf("\t1. View results of all candidates\n");
        printf("\t2. View results of candidates in a specific division\n");
        printf("\n**********************PLEASE select a choice**********************\n\n");

        yellow();
        printf("Enter your choice: ");
        scanf("%d",&option);

        green();
        switch (option) {
        case 1:
            screen_clear();
            full_result();
            break;

        case 2:
             screen_clear();
             div_result();
             break;

        default:
            red();
            printf("\nInvalid selection! Please try again.\n\n");

        }

}


/***********************************
 * End of voting_result() function *
 ***********************************/



//for viewing results of all candidates
void full_result()
{
    int i=0, k, total_cand=0, total_voter=0, total_votes=0;
    int highest1=-1,highest2=-1,highest3=-1,highest4=-1, lowest1=1, lowest2=1, lowest3=1, lowest4=1;
    //for finding candidate with max and min votes respectively in each division
    char buf[500], line[500];
    char* token;

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
            float Cand_per;//percentage of votes
         }Cand[100];


   //for candidate with highest votes in each division
    struct winner
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int count;//number of votes of candidate
            float percent;//percentage of votes received
         }win1, win2, win3, win4;


    //for candidate with lowest votes in each division
    struct last
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int count;//number of votes of candidate
            float percent;//percentage of votes received
         }loss1, loss2, loss3, loss4;

    FILE *fptr, *file;


    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }


    if ((file = fopen("voter_list.txt", "r")) == NULL)
                {
                    red();
                    printf("No voters yet. Please try again later.\n");

                }


  for(k=1;k<2;k++ )//for the sake of having a loop to apply break statement.
        //We have specified conditions so that for loop will be executed only once,
   {
    while(fgets(line, sizeof(line), file)){

        if(fscanf(file, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");//content of line till 1st '|' is encountered gets stored in token now

        if(feof(file))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

        total_voter++; //since after while loop ends, it will be equal to total number of voters in voter list
  }
    fclose(file);

  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

        if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

         token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        total_votes+=atoi(Cand[i].Cand_count);//finding total votes in election

            if(atoi(Cand[i].Cand_div)==1 && highest1<atoi(Cand[i].Cand_count))
            {
                highest1=atoi(Cand[i].Cand_count);//updating current highest value,
                //otherwise it'll remain as -1 and will show wrong output
                strcpy(win1.name, Cand[i].Cand_name);
                strcpy(win1.id, Cand[i].Cand_id);
                strcpy(win1.par, Cand[i].Cand_par);
                win1.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==2 && highest2<atoi(Cand[i].Cand_count))
            {
                highest2=atoi(Cand[i].Cand_count);//updating current highest value,
                //otherwise it'll remain as -1 and will show wrong output
                strcpy(win2.name, Cand[i].Cand_name);
                strcpy(win2.id, Cand[i].Cand_id);
                strcpy(win2.par, Cand[i].Cand_par);
                win2.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==3 && highest3<atoi(Cand[i].Cand_count))
            {
                highest3=atoi(Cand[i].Cand_count);//updating current highest value,
                //otherwise it'll remain as -1 and will show wrong output
                strcpy(win3.name, Cand[i].Cand_name);
                strcpy(win3.id, Cand[i].Cand_id);
                strcpy(win3.par, Cand[i].Cand_par);
                win3.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==4 && highest4<atoi(Cand[i].Cand_count))
            {
                highest4=atoi(Cand[i].Cand_count);//updating current highest value,
                //otherwise it'll remain as -1 and will show wrong output
                strcpy(win4.name, Cand[i].Cand_name);
                strcpy(win4.id, Cand[i].Cand_id);
                strcpy(win4.par, Cand[i].Cand_par);
                win4.count=atoi(Cand[i].Cand_count);

            }


            if(atoi(Cand[i].Cand_div)==1 && lowest1>atoi(Cand[i].Cand_count))
            {
                lowest1=atoi(Cand[i].Cand_count);//updating current lowest value,
                //otherwise it'll remain as 1 and will show wrong output
                strcpy(loss1.name, Cand[i].Cand_name);
                strcpy(loss1.id, Cand[i].Cand_id);
                strcpy(loss1.par, Cand[i].Cand_par);
                loss1.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==2 && lowest2>atoi(Cand[i].Cand_count))
            {
                lowest2=atoi(Cand[i].Cand_count);//updating current lowest value,
                //otherwise it'll remain as 1 and will show wrong output
                strcpy(loss2.name, Cand[i].Cand_name);
                strcpy(loss2.id, Cand[i].Cand_id);
                strcpy(loss2.par, Cand[i].Cand_par);
                loss2.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==3 && lowest3>atoi(Cand[i].Cand_count))
            {
                lowest3=atoi(Cand[i].Cand_count);//updating current lowest value,
                //otherwise it'll remain as 1 and will show wrong output
                strcpy(loss3.name, Cand[i].Cand_name);
                strcpy(loss3.id, Cand[i].Cand_id);
                strcpy(loss3.par, Cand[i].Cand_par);
                loss3.count=atoi(Cand[i].Cand_count);

            }

            if(atoi(Cand[i].Cand_div)==4 && lowest4>atoi(Cand[i].Cand_count))
            {
                lowest4=atoi(Cand[i].Cand_count);//updating current lowest value,
                //otherwise it'll remain as 1 and will show wrong output
                strcpy(loss4.name, Cand[i].Cand_name);
                strcpy(loss4.id, Cand[i].Cand_id);
                strcpy(loss4.par, Cand[i].Cand_par);
                loss4.count=atoi(Cand[i].Cand_count);

            }


    }

        i++;
  }

  total_cand=i;//since at end of while loop, i will be total number of candidates in list


    purple();
    printf("\nVoting results and summary from all divisions: \n");

    green();
    printf("\nTotal candidates contesting in this election: %d",total_cand);
    printf("\nTotal number of eligible voters: %d",total_voter);
    printf("\nTotal votes received in this election: %d\n",total_votes);

    cyan();
    printf("\nCandidate who secured highest votes in division 1: ");
    yellow();
    printf("\nCandidate Name: %s",win1.name);
    printf("\nCandidate ID: %s",win1.id);
    printf("\nParty: %s",win1.par);
    printf("\nVotes received: %d",win1.count);
    win1.percent=(win1.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",win1.percent);

    cyan();
    printf("\nCandidate who secured least votes in division 1: ");
    yellow();
    printf("\nCandidate Name: %s",loss1.name);
    printf("\nCandidate ID: %s",loss1.id);
    printf("\nParty: %s",loss1.par);
    printf("\nVotes received: %d",loss1.count);
    loss1.percent=(loss1.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",loss1.percent);

    cyan();
    printf("\nCandidate who secured highest votes in division 2: ");
    yellow();
    printf("\nCandidate Name: %s",win2.name);
    printf("\nCandidate ID: %s",win2.id);
    printf("\nParty: %s",win2.par);
    printf("\nVotes received: %d",win2.count);
    win2.percent=(win2.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",win2.percent);

    cyan();
    printf("\nCandidate who secured least votes in division 2: ");
    yellow();
    printf("\nCandidate Name: %s",loss2.name);
    printf("\nCandidate ID: %s",loss2.id);
    printf("\nParty: %s",loss2.par);
    printf("\nVotes received: %d",loss2.count);
    loss2.percent=(loss2.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",loss2.percent);

    cyan();
    printf("\nCandidate who secured highest votes in division 3: ");
    yellow();
    printf("\nCandidate Name: %s",win3.name);
    printf("\nCandidate ID: %s",win3.id);
    printf("\nParty: %s",win3.par);
    printf("\nVotes received: %d",win3.count);
    win3.percent=(win3.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",win3.percent);

    cyan();
    printf("\nCandidate who secured least votes in division 3: ");
    yellow();
    printf("\nCandidate Name: %s",loss3.name);
    printf("\nCandidate ID: %s",loss3.id);
    printf("\nParty: %s",loss3.par);
    printf("\nVotes received: %d",loss3.count);
    loss3.percent=(loss3.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",loss3.percent);

    cyan();
    printf("\nCandidate who secured highest votes in division 4: ");
    yellow();
    printf("\nCandidate Name: %s",win4.name);
    printf("\nCandidate ID: %s",win4.id);
    printf("\nParty: %s",win4.par);
    printf("\nVotes received: %d",win4.count);
    win4.percent=(win4.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",win4.percent);

    cyan();
    printf("\nCandidate who secured least votes in division 4: ");
    yellow();
    printf("\nCandidate Name: %s",loss4.name);
    printf("\nCandidate ID: %s",loss4.id);
    printf("\nParty: %s",loss4.par);
    printf("\nVotes received: %d",loss4.count);
    loss4.percent=(loss4.count*100)/total_voter;
    printf("\nPercentage of votes: %f\n",loss4.percent);

    purple();
    printf("\nFull voting results of the election: \n");
    blue();
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY NAME\tDIVISION\tVOTES\tPERCENTAGE OF VOTES\n");

    rewind(fptr);
    yellow();
    while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

        if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

         token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        Cand[i].Cand_per=(atoi(Cand[i].Cand_count)*100)/total_voter;
        printf("\n%s\t\t\t%s\t\t%s\t\t%s\t%s\t%f\n",Cand[i].Cand_id,Cand[i].Cand_name,Cand[i].Cand_par,Cand[i].Cand_div,Cand[i].Cand_count,Cand[i].Cand_per);


    }

        i++;
  }


  }

  fclose(fptr);
  printf("\n\n");

}



/*********************************
 * End of full_result() function *
 *********************************/



//for viewing results of candidates in specific division
void div_result()
{
    int i=0, k, total_cand_div=0, total_voter_div=0, div_flag=1, total_votes=0;
    int highest=-1, lowest=1;//for finding candidate with max and min votes respectively
    //if I set lowest=0, then for lowest>C[i].Cand_count condition no one will get stored if actual lowest is 0
    //if I set highest=0, then for highest<C[i].Cand_count condition no one will get stored if actual highest is 0
    char division[2]="2";//I'm declaring and initializing it as string since it is part of line in file which is a string
    char buf[500], line[500];
    char* token;

    struct Voter
         {
            char V_id[45];//voter ID
            char V_name[45];//voter name
            int V_div;//voter division number (division 1 to division 4)
            int V_age;//voter age
            int V_status;//Y/N
         }V[100];

    struct Candidate
         {
            char Cand_id[45];//candidate ID
            char Cand_name[45];//candidate name
            char Cand_par[45];//candidate party name
            int Cand_div;//candidate division number (division 1 to division 4)
            int Cand_count;//number of votes of candidate
            float Cand_per;//percentage of votes
         }Cand[100];


   //for candidate with highest votes
    struct winner
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int count;//number of votes of candidate
            float percent;//percentage of votes received
         }win;


    //for candidate with lowest votes
    struct last
         {
            char id[45];//candidate ID
            char name[45];//candidate name
            char par[45];//candidate party name
            int count;//number of votes of candidate
            float percent;//percentage of votes received
         }loss;

    FILE *fptr, *file;


    if ((fptr = fopen("candidate_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Candidate list is empty.\n");

                }


     if ((file = fopen("voter_list.txt", "r")) == NULL)
                {
                    red();
                    printf("Voter list is empty.\n");

                }


    green();
    printf("Enter division number: ");
    scanf("%s",division );

  for(k=1;k<2;k++){

        while(fgets(line, sizeof(line), file)){

        if(fscanf(file, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");//content of line till 1st '|' is encountered gets stored in token now

        if(feof(file))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(V[i].V_name,token);

          token = strtok(NULL, "|");
          strcpy(V[i].V_id ,token);

          token = strtok(NULL, "|");
          V[i].V_age=token;

         token = strtok(NULL, "|");
        V[i].V_div = token;

        token = strtok(NULL, "|");
        V[i].V_status=token;

        token = strtok(NULL, "|");
        }

        if(strcmp(V[i].V_div ,division)==0)
        {
                total_voter_div++;//counting total number of voters in that division
        }


        i++;
  }

  i=0;//resetting for next while loop

  while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

        if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

         token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        if(strcmp(Cand[i].Cand_div,division)==0)
        {
            total_cand_div++;//finding total number of candidates in that division to calculate % of votes
            total_votes+=atoi(Cand[i].Cand_count);//finding total votes in that division
            div_flag=0;//means entered division number is valid

            if(highest<atoi(Cand[i].Cand_count))
            {
                highest=atoi(Cand[i].Cand_count);//updating current highest value,
                //otherwise it'll remain as -1 and will show wrong output
                strcpy(win.name, Cand[i].Cand_name);
                strcpy(win.id, Cand[i].Cand_id);
                strcpy(win.par, Cand[i].Cand_par);
                win.count=atoi(Cand[i].Cand_count);

            }

            if(lowest>atoi(Cand[i].Cand_count))
            {
                lowest=atoi(Cand[i].Cand_count);//updating current lowest value,
                //otherwise it'll remain as 1 and will show wrong output
                strcpy(loss.name, Cand[i].Cand_name);
                strcpy(loss.id, Cand[i].Cand_id);
                strcpy(loss.par, Cand[i].Cand_par);
                loss.count=atoi(Cand[i].Cand_count);

            }
        }


    }

        i++;
  }

        if(div_flag)
         {
             red();
             printf("\nEnter correct division number!");
             break;
         }


    purple();
    printf("\nVoting results and summary from division %s: \n",division);

    green();
    printf("\nTotal candidates contesting in this division: %d",total_cand_div);
    printf("\nTotal number of eligible voters in this division: %d",total_voter_div);
    printf("\nTotal votes received in this division: %d\n",total_votes);

    cyan();
    printf("\nCandidate who secured highest votes: ");
    yellow();
    printf("\nCandidate Name: %s",win.name);
    printf("\nCandidate ID: %s",win.id);
    printf("\nParty: %s",win.par);
    printf("\nVotes received: %d",win.count);
    win.percent=(win.count*100)/total_voter_div;
    printf("\nPercentage of votes: %f\n",win.percent);

    cyan();
    printf("\nCandidate who secured least votes: ");
    yellow();
    printf("\nCandidate Name: %s",loss.name);
    printf("\nCandidate ID: %s",loss.id);
    printf("\nParty: %s",loss.par);
    printf("\nVotes received: %d",loss.count);
    loss.percent=(loss.count*100)/total_voter_div;
    printf("\nPercentage of votes: %f\n",loss.percent);

    purple();
    printf("\nFull voting results of division %s: \n",division);
    blue();
    printf("\nCANDIDATE ID\t\t\tNAME\t\t\t\tPARTY NAME\tVOTES\tPERCENTAGE OF VOTES\n");

    rewind(fptr);
    yellow();
    while(fgets(line, sizeof(line), fptr)){

        if(fscanf(fptr, "%[^;]s ",buf))//scans till ; is encountered and stores that string in buf
           token = strtok(buf, "|");

        if(feof(fptr))//if I let this while loop terminate on it's own, full program gets terminated abruptly without executing other codes
            break;

         while (token != NULL) {

          strcpy(Cand[i].Cand_name,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_par ,token);

          token = strtok(NULL, "|");
          strcpy(Cand[i].Cand_id,token);

         token = strtok(NULL, "|");
        Cand[i].Cand_div = token;

         token = strtok(NULL, "|");
        Cand[i].Cand_count= token;
        token = strtok(NULL, "|");

        if(strcmp(Cand[i].Cand_div,division)==0)
        {
            Cand[i].Cand_per=(atoi(Cand[i].Cand_count)*100)/total_voter_div;
            printf("\n%s\t\t\t%s\t\t%s\t\t%s\t%f\n",Cand[i].Cand_id,Cand[i].Cand_name,Cand[i].Cand_par,Cand[i].Cand_count,Cand[i].Cand_per);
        }


    }

        i++;
  }

  }

  fclose(fptr);
  fclose(file);
  printf("\n\n");

}



/*********************************
 * End of  div_result() function *
 *********************************/


/*********End of Menu option 4 functions************/





/************Function to be called inside main() function***************/
void voter_menu()
{
    int option;//used for selecting menu option

         blue();
         printf("\n*********WELCOME to Tamil Nadu State Electoral Commission E-system**********");
         real_clock();//calling to display time

        cyan();
        printf("\t1. View Candidates\n");
        printf("\t2. Register Voter\n");
        printf("\t3. Vote\n");
        printf("\t4. View Voting Results and Summary\n");
        printf("\t5. Quit\n");
        printf("\n******************PLEASE select a choice******************\n\n");

        yellow();
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            view_candidates();
            break;

        case 2:
            register_voter();
            break;

        case 3:
            voting();
            break;

        case 4:
            voting_result();
            break;

        case 5:
            screen_clear();
            green();
            printf("\nThank you for visiting. Goodbye!\n\n");
            exit(0);
            break;

        default:
            red();
            printf("\nInvalid selection, please try again!\n\n");
        }


}
