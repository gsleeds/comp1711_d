#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
char filename [] = "FitnessData_2023.csv";

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
    FILE *file = fopen(filename, "r");

    int buffer_size = 30;
    char line_buffer[buffer_size];
    int v = 0;
    
    FITNESS_DATA fitnessDataArray[1000];

    while (fgets(line_buffer, buffer_size, file) != NULL){
        char date[11], time[6], steps[5];
        tokeniseRecord(line_buffer, "/", date,time,steps);
        
        strcpy(fitnessDataArray[v].date, date);
        strcpy(fitnessDataArray[v].time, time);
        fitnessDataArray[v].steps = atoi(steps);
        
        v++;
    }

    fclose(file);
    return 0;
}
