/*
Name:Wangui James Kahwai 
Reg no:CT101/G/26490/25
Date:6/11/25
Description:C program that reads integers stores them in input.txt, calculates average and sum and writes them in output.txt
*/
#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening input.txt for writing!\n");
        return;
    }
    
    int num;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    
    fclose(file);
    printf("Numbers written to input.txt\n\n");
}

void processFile() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt for reading!\n");
        return;
    }
    
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt for writing!\n");
        fclose(inputFile);
        return;
    }
    
    int numbers[10];
    int sum = 0;
    float average;
    
    for (int i = 0; i < 10; i++) {
        if (fscanf(inputFile, "%d", &numbers[i]) != 1) {
            printf("Error reading from input file!\n");
            fclose(inputFile);
            fclose(outputFile);
            return;
        }
        sum += numbers[i];
    }
    
    average = (float)sum / 10;
    fprintf(outputFile, "Sum: %d\nAverage: %.2f\n", sum, average);
    
    fclose(inputFile);
    fclose(outputFile);
    printf("Results written to output.txt\n\n");
}

void displayFiles() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt for reading!\n");
        return;
    }
    
    FILE *outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        printf("Error opening output.txt for reading!\n");
        fclose(inputFile);
        return;
    }
    
    printf("Contents of input.txt:\n");
    int num;
    for (int i = 0; i < 10; i++) {
        fscanf(inputFile, "%d", &num);
        printf("%d ", num);
    }
    printf("\n\n");
    
    printf("Contents of output.txt:\n");
    char line[100];
    while (fgets(line, sizeof(line), outputFile)) {
        printf("%s", line);
    }
    
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    writeToFile();
    processFile();
    displayFiles();
    return 0;
}