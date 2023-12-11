#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Error: invalid file");
        return 1;
    }
    
    FitnessData data[100];
    char line[100];
    int count = 0;
    int invalidFile = 0;

    while(fgets(line, sizeof(line), file)){

        line[strcspn(line,"\n")]=0;

        FitnessData temp;
        tokeniseRecord(line, ',', temp.date, temp.time, &temp.steps);

        if (strlen(temp.date) != 10 || strlen(temp.time) != 5 || temp.steps <= 0) {
            invalidFile = 1; // Invalid line
        }
        else{
            data[count++] = temp;
        }
    }
    fclose(file);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) {
                // swapping
                FitnessData temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    if(invalidFile){
        printf("Error: invalid file format");
        return 1;
    }

    char outputFilename[200];
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    file = fopen(outputFilename, "w");
    for(int i=0; i < count; i++){
        if (i<count-1){
            fprintf(file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
        }
        else {
            fprintf(file, "%s\t%s\t%d", data[i].date, data[i].time, data[i].steps);
        }
    }
    fclose(file);
    return 0;
}