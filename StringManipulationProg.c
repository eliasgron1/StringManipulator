/***************************************************************************
 *   Copyright (C) $Year$ by $Author$   *
 *   $Email$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
        String Manipulation Program

 2.  DESCRIPTION


 3.  VERSIONS
       Original:
         5.3.2020 / Elias Grönholm

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define STDLEN 100
#define MAX_LINE 80000

/* Global variables */

/* Global structures */


/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int count_vowel(char *str);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void){
char cmd;
char str[STDLEN]={"Hello world!"} ;
printf("--------------------------------------------------------------------------------------------------------\n");
printf("                                  String Editor by: Elias Gronholm\n");
printf("--------------------------------------------------------------------------------------------------------\n\n\n");
print_menu();


while (1){
cmd=getchar();



    switch(toupper(cmd)){

        case 'A':
            printf("Counting vowels\n");
            printf("%d vowels!\n",count_vowel(str));
        break;

        case 'B':
            printf("Counting consonants\n");
            printf("%d consonants!\n",count_consonants(str));
        break;

        case 'C':
            printf("Converting to uppercase\n");
            strupr(str);
            printf("Converted to uppercase\n");
        break;
        case 'D':
            printf("Converting to lowercase\n");
            strlwr(str);
            printf("Converted to lowercase\n");
        break;

        case 'E':
            fputs(str, stdout);
            printf("\n");
        break;

        case 'F':
            change_string(str);
        break;

        case 'G':
            read_from_file(str);
        break;

        case 'H':
            write_to_file(str);
        break;

        case 'M':
            print_menu();
        break;

        case 'X':
            printf("\nProgram Finished\n");
            exit(0);
        break;
    }
}
}


/*********************************************************************
*   FUNCTIONS                    
    int count_vowel(char *str)
    int count_consonants(char *str)                               *
**********************************************************************/


/*********************************************************************
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/


#define STDLEN 100
#define MAX_LINE 80000

int count_vowel(char *str){
    char vowel[12] = {"AEIOUYaeiouy"};
    int i,j=0;
    int count=0;

    while(str[j] != '\0'){
        for(i=0;i<12;i++){
            if(str[j] == vowel[i]){
                count++;
            }
        }
        j++;
    }
return count;
}

int count_consonants(char *str){
    char consonants[] = {"BCDFGHJKLMNPQRSTVWXYZbcdghjklmnpqrstvwxyz"};
    int i,j=0;
    int count=0;
    
    while(str[j] != '\0'){
        for(i=0;i<42;i++){
            if(str[j] == consonants[i]){
                count++;
            }
        }
        j++;
    }
return count;
}


int change_string(char *str){
    puts("Enter new string");
    scanf("%1[\n]");
    fgets(str,STDLEN,stdin);
}



int read_from_file(char *str){
FILE *file; 

char buffer[MAX_LINE];
int read_line = 0;
int current_line = 1;
bool keep_reading = true;

printf("Read from line: ");
scanf("%d",&read_line);

file = fopen("words.txt", "r");

if (file == NULL){
    printf("Error opening file.\n");
    return 1;
}

while(keep_reading){
    fgets(buffer, MAX_LINE, file);

    if(feof(file)){
        keep_reading = false;
        printf("couldnt find line %d\n", read_line);
    }

    else if(current_line == read_line){
        keep_reading = false;
        printf("line %d contained string: %s", read_line, buffer);
    }

    current_line++;

}

strcpy(str, buffer);
fclose(file);
return 0;

}




int write_to_file(char *str){
int line=0;
char c=0;
FILE *file;

    file = fopen("words.txt", "r");
    for (c = getc(file); c != EOF; c = getc(file)){
            if (c == '\n'){
                line++;
            }   
    }    
fclose(file);

file = fopen("words.txt", "a");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    else{
        fputs(str,file);
        printf("String written to line %d\n", line+1);
    }
fclose(file);
return 0;
}





int print_menu(void){
printf("\n\n");
printf("A)  Count the number of vowels in the string\n");
printf("B)  Count the number of consonants in the string\n");
printf("C)  Convert the string to uppercase\n");
printf("D)  Convert the string to lowercase\nE)  Display the current string\nF)  Enter another string\n");
printf("G)  Read string from file\n");
printf("H)  Write string to file\n\n");
printf("M)  Display this menu \nX)  Exit the program\n\n");
return 0;
}

