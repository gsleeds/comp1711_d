#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char filename[100];
FITNESS_DATA fitnessDataArray[59];


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

// Complete the main function
int main() {
    int buffer_size = 30;
    char line_buffer[buffer_size];
    int v = 0;
    while(1){
        printf("Menu options:\nA: Specify the filename to be imported – you need to check that the file opened correctly.\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit\n");
        char inputChar;
        scanf(" %c", &inputChar);
        int c;
        while ((c = getchar()) != '\n') {}

        switch(inputChar){
        case 'A':
            printf("File name: ");
            char filen[100];
            scanf("%s", &filen);
            strcat(filename, filen);
            
            FILE *file = fopen(filename, "r");
            if (file == NULL){
                printf("Error: could not open file\n");
                return 1;
            }
            break;
        case 'B':
            while (fgets(line_buffer, buffer_size, file) != NULL){
                char *date[11], *time[6], *steps[5];
                tokeniseRecord(line_buffer, ",", fitnessDataArray[v].date,fitnessDataArray[v].time,fitnessDataArray[v].steps);
                v++;
            }
            printf("Total records: %d\n",v);
            break;
        case 'C':
            while (fgets(line_buffer, buffer_size, file) != NULL){
                char *date[11], *time[6], *steps[5];
                tokeniseRecord(line_buffer, ",", fitnessDataArray[v].date,fitnessDataArray[v].time,fitnessDataArray[v].steps);
                v++;
            }
            int t = 500;
            int ti;
            for(int i=0;i<v;i++){
                int num = atoi(strtok(fitnessDataArray[i].steps, "\n"));
                if(num<t){
                    t = num;
                    ti = i;
                }  
            }
            printf("Fewest steps: %s %s\n",
            fitnessDataArray[ti].date,
            fitnessDataArray[ti].time);
            break;
        case 'D':
            while (fgets(line_buffer, buffer_size, file) != NULL){
                char *date[11], *time[6], *steps[5];
                tokeniseRecord(line_buffer, ",", fitnessDataArray[v].date,fitnessDataArray[v].time,fitnessDataArray[v].steps);
                v++;
            }
            int z = 0;
            int zi;
            for(int i=0;i<v;i++){
                int num = atoi(strtok(fitnessDataArray[i].steps, "\n"));
                if(num>z){
                    z = num;
                    zi = i;
                }  
            }
            printf("Largest steps: %s %s\n",
            fitnessDataArray[zi].date,
            fitnessDataArray[zi].time);
            break;
        case 'E':
            while (fgets(line_buffer, buffer_size, file) != NULL){
                char *date[11], *time[6], *steps[5];
                tokeniseRecord(line_buffer, ",", fitnessDataArray[v].date,fitnessDataArray[v].time,fitnessDataArray[v].steps);
                v++;
            }
            int sum;
            for(int i=0;i<v;i++){
                int num = atoi(strtok(fitnessDataArray[i].steps, "\n"));
                sum=sum+num;
            }
            printf("Mean step count: %d\n",sum/v);
            break;
        case 'F':
            while (fgets(line_buffer, buffer_size, file) != NULL){
                char *date[11], *time[6], *steps[5];
                tokeniseRecord(line_buffer, ",", fitnessDataArray[v].date,fitnessDataArray[v].time,fitnessDataArray[v].steps);
                v++;
            }
            int step[100];
            for(int i=0;i<v;i++){
                int num = atoi(strtok(fitnessDataArray[i].steps, "\n"));
                step[i] = num;
            }
            int longestStart = -1, longestEnd = -1;
            int currentStart = -1, longestLength = 0, currentLength = 0;

            for(int i = 0; i < v; i++) {
                if(step[i] > 500) {
                    if(currentStart == -1) {
                        currentStart = i; // Start of a new streak
                    }
                    currentLength++;

                    if(currentLength > longestLength) {
                        longestLength = currentLength;
                        longestStart = currentStart;
                        longestEnd = i;
                    }
                } else {
                    currentLength = 0;
                    currentStart = -1;
                }
            }

            printf("Longest period start: %s %s\n",fitnessDataArray[longestStart].date,fitnessDataArray[longestStart].time);
            printf("Longest period end: %s %s\n",fitnessDataArray[longestEnd].date,fitnessDataArray[longestEnd].time);            
            break;
        case 'Q':
            return 0;
            break;
        default:
            printf("Incorrect input...\n");
            break;
        }
    }

    return 0;
}









