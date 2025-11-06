/*
Name: Wangui James Kahwai 
Reg no:CT101/G/26490/25
Date:6/11/25
Description:C program for calculation of gross pay,taxes and net pay from hourly work and wages per week 
*/

#include <stdio.h>

int main() {
    float hours, wage, gross_pay, taxes, net_pay;
    
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: kes");
    scanf("%f", &wage);
    
    if (hours > 40) {
        gross_pay = (40 * wage) + ((hours - 40) * wage * 1.5);
    } else {
        gross_pay = hours * wage;
    }
    
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;
    } else {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    }
    
    net_pay = gross_pay - taxes;
    
    printf("\nGross Pay: kes%.2f\n", gross_pay);
    printf("Taxes: kes%.2f\n", taxes);
    printf("Net Pay: kes%.2f\n", net_pay);
    
    return 0;
}