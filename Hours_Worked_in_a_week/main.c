/*
Authore : Sagnik Sarkar

Date : 16.08.2018

Purpose : Income In A Week Of a man Working In XYZ Company

*/
#include <stdio.h>
#include <math.h>

int main()
{
    //Declearing Variable
    int Working_hours_In_a_week;
    int Basic_Pay_Rate_per_hour = 840;
    int Gross_Pay;
    int Overtime;
    int Overtime_Rate_per_hour = 1205;
    int Overtime_pay;
    double Tax , Net_pay;

    printf("Enter The Working Hours in a week :");
    //Input From User
    scanf ("%i" , &Working_hours_In_a_week);

    //Starting loop
    if ( Working_hours_In_a_week > 40 ) //Calculating Gross Play With Overtime
      {                                   //OVER TIME PAYMENT AVALABLE AFTER 40HOURS OF MAN WORK IN A WEEK
        Overtime = (Working_hours_In_a_week - 40);
        Overtime_pay = (Overtime * Overtime_Rate_per_hour);
        Gross_Pay= (Basic_Pay_Rate_per_hour * 40);
        Gross_Pay += Overtime_pay;
        printf("The Gross pay in a week = %d\n",Gross_Pay);
      }
    else
      {
         Gross_Pay = (Basic_Pay_Rate_per_hour * Working_hours_In_a_week);
         printf("The Gross pay in a week = %d\n",Gross_Pay);
      }
    //Tax loop starts
    if (Gross_Pay < 20100)
       {
          printf("You don't Need to pay Tax\n");
       }
    else if (Gross_Pay >= 20100 && Gross_Pay < 30150)
       {
           Tax = (20100 * 0.15);
           Tax += (10050 * 0.20);
           printf("The Total Amount of Tax You have to pay = %f\n ",Tax);
        }
    else if (Gross_Pay >= 30150)
       {
           Tax = (20100 * 0.15);
           Tax += (10050 * 0.20);
           Tax +=((Gross_Pay - 30150) * 0.25);
           printf("The Total Amount of Tax You have to pay = %f\n ",Tax);
        }

        Net_pay = (Gross_Pay - Tax);
        printf("Your Net Pay of this Week  is %2f Rs",Net_pay);

        return 0;

    }
