//CODE BY B1901264
#include <stdio.h>
#include <stdlib.h>
#define MENUSIZE 12
#define MEALSIZE 3
#define CALSIZE 3
int calculateBMI(float weight, float height,char inGender,int inAge);//Function for calculate BMI result,and show the IBW
int calculateBMR(float weight, float height,char inGender,int inAge);//Function for calculate BMR result
int printMenu();//display a food menu and calculate the day calories
void calculateWeek(int inTotal, float weight,float height, char inGender,float inBMIresult,float inBMRchoice);//determine the week to gain the ideal body weight
int main()//the main menu display.
{
    float w, h,BMIresult,BMRchoice;//declare the variable. w=weight,h=height.
    int age,total,choice;//declare the variable
    char gender,cont;//declare the variable
    cont='Y','y';

    while(cont !='N' && cont !='n')//looping the program
    {
    printf("\t\t****<<< Calories Tracker >>>****\t\t\n");
    printf("====================================================================");
    printf("\n");
    printf("1.Calculate BMI\n");
    printf("2.Calculate BMR\n");
    printf("3.Actual Calories Per Day\n");
    printf("4.Number Of Week To Gain Ideal Weight\n");
    printf("====================================================================\n");
    printf("Enter You Choice(1/2/3/4):");//enter the number to choice the function
    scanf("%d",&choice);
    printf("====================================================================\n");
    switch (choice)
    {
    case 1:
        printf("\t\t****<<< Calculate your BMI >>>****\t\t\n");
        printf("====================================================================\n");
        printf("Enter your weight(kg):" ); //input the weight
        scanf("%f", &w);
        printf("Enter your height(m):");//input the height with m
        scanf("%f", &h);
        printf("Enter your gender(M/m or F/f):");//input the gender with M/m and F/f
        scanf(" %c", &gender);
        printf("Enter your age :");//input the age
        scanf("%d", &age);
        BMIresult=calculateBMI(w,h,gender,age);
        break;

    case 2:
        BMRchoice=calculateBMR(w,h,gender,age);
        break;

    case 3 :
        printMenu();
        break;

    case 4 :
        calculateWeek(total,w,h,gender,BMIresult,BMRchoice);
        break;
    default: printf("Please enter the valid number!");
    break;
    }
    printf("Enter ""Y"" is continue or ""N"" is exit>>");//input the Y to continue the program,input the N to exit the program.
    scanf(" %c", &cont);
    printf("\n====================================================================\n");
    }
    return 0;
}

int calculateBMI(float weight, float height,char inGender,int inAge)//function of calculate BMI
{
    printf("====================================================================\n");
    float BMIresult;
    BMIresult = weight/((height)*(height));
    float IBWmale,IBWfemale;
    IBWmale=50+(2.3*((height*100)-152.4)*0.3937);
    IBWfemale=45.5+(2.3*((height*100)-152.4)*0.3937);
    if (BMIresult <18.5)
    {
        printf("Your BMI is %.2f.You are currently underweight.\n",BMIresult);//print the result oF BMI
        if (inGender=='M' || inGender =='m')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWmale);//print the result of male ideal body weight
        }
        else if (inGender=='F' || inGender =='f')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWfemale);//print the result of female ideal body weight
        }
    }
    else if((BMIresult>18.6) && (BMIresult<24.9))
    {
        printf("Your BMI is %.2f.You are normal weight.\n",BMIresult);//print the result oF BMI
        printf("Well Done! No Need To Gain The Ideal Weight!\n");
    }
    else if((BMIresult>24.9) && (BMIresult<29.9))
    {
        printf("Your BMI is %.2f.You are currently overweight.\n",BMIresult);//print the result oF BMI
        if (inGender=='M' || inGender =='m')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWmale);//print the result of male ideal body weight
        }
        else if (inGender=='F' || inGender =='f')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWfemale);//print the result of female ideal body weight
        }
    }
    else if (BMIresult>30)
    {
        printf("\nYour BMI is %.2f.You are obesity.\n",BMIresult);//print the result oF BMI

        if (inGender=='M' || inGender =='m')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWmale);//print the result of male ideal body weight
        }
        else if (inGender=='F' || inGender =='f')
        {
            printf("Your ideal body weight is %.2f kg\n",IBWfemale);//print the result of female ideal body weight
        }
    }
    printf("====================================================================\n");

    return BMIresult;

}
int calculateBMR(float weight, float height,char inGender,int inAge)//function of calculate BMR
{
    int BMRchoice;
    float BMRmale,BMRfemale,calories;
    printf("\t\t****<< ACTIVITY >>****\t\t");
    printf("\n====================================================================\n");
    printf(" 1.Sedentary (little or no exercise)\n");
    printf(" 2.lightly active (light exercise/sports 1-3 days/week)\n");
    printf(" 3.moderately active (moderate exercise/sports 3-5 days/week)\n");
    printf(" 4.very active (hard exercise/sports 6-7 days a week)\n");
    printf("====================================================================\n");
    printf("Enter you choice(1/2/3/4):");
    scanf("%d",&BMRchoice);
    printf("====================================================================\n");

     if (inGender=='M' || inGender =='m')
     {
        BMRmale=66+(13.7*weight)+(5*(height*100))-(6.8*inAge);
        printf("Your BMR is %.2f\n",BMRmale);
        switch(BMRchoice)
        {
            case 1:
                calories=BMRmale*1.2;
                printf(" \nYou total daily calorie needs assume per day is %.2f\n",calories);
                break;
            case 2:
                calories=BMRmale*1.375;
                printf(" \nYou total daily calorie needs assume per day is %.2f\n",calories);
                break;
            case 3:
                calories=BMRmale*1.55;
                printf(" \nYou total daily calorie needs assume per day is %.2f\n",calories);
                break;
             case 4:
                calories=BMRmale*1.725;
                printf(" \nYou total daily calorie needs assume per day is %.2f\n",calories);
                break;
        }

     }
     else if(inGender=='F' || inGender =='f')
     {
        BMRfemale=655+(9.6*weight)+(1.8*(height*100))-(4.7*inAge);
        printf("Your BMR is %.2f\n",BMRfemale);
        switch(BMRchoice)
        {
            case 1:
                calories=BMRfemale*1.2;
                printf("You total daily calorie needs assume per day is %.2f\n",calories);
                break;
            case 2:
                calories=BMRfemale*1.375;
                printf("You total daily calorie needs assume per day is %.2f\n",calories);
                break;
            case 3:
                calories=BMRfemale*1.55;
                printf("You total daily calorie needs assume per day is %.2f\n",calories);
                break;
             case 4:
                calories=BMRfemale*1.725;
                printf("You total daily calorie needs assume per day is %.2f\n",calories);
                break;
        }
        printf("====================================================================\n");
     }
      return BMRchoice;
}
int printMenu()//function of display food menu
{
    char* food[MENUSIZE]={"Nasi Lemak + Teh Tarik","Roti Canai/Dhall + Teh Tarik","Roti Telur + Teh Tarik","Chappati + Teh Tarik\t","2 half boiled egg\n   plain bread + Teh Tarik","Mamak Noodles Goreng\n   +Teh Tarik\t\t","Prawn Mee\t\t","Lor Mee\t\t","Mee Hailam\t\t","Penang Laksa\t","McDonald/KFC/Pizza Hut Meal","Rice+ Meat/Poultry/SeaFood\n    +Vege+Soft Drink\t"};
    int foodcalories[MENUSIZE]={727,442,497,249,360,743,239,383,277,436,850,740};
    int index=0,number;
    int meal[3];
    int calory[CALSIZE];
    int total;

    for(number=0;number<MEALSIZE;number++)
    {
        printf("\t\t****<<< FOOD MENU >>>****\t\t\n");
        printf("====================================================================\n");
        printf("Malaysian food \t\t\t\tCalories\t\t\n");
        printf("====================================================================\n");
        for (index=0; index<MENUSIZE;index++)
        {
            printf("[%d]%s\t\t%d\n",index+1,food[index],foodcalories[index]);
        }
        printf("====================================================================\n");
        printf("Enter Your meal(1.breakfast/2.lunch/3.dinner) base on the menu :");
        scanf("%d",&meal[number]);
        printf("====================================================================\n");
    }
    for (index=0; index<MENUSIZE;index++)
    {
          if(meal[0]==index+1)
          printf("The calories of breakfast is %d\n",foodcalories[index]);
    }
    for (index=0; index<MENUSIZE;index++)
    {
          if(meal[1]==index+1)
          printf("The calories of lunch is %d\n",foodcalories[index]);
    }
    for (index=0; index<MENUSIZE;index++)
    {
          if(meal[2]==index+1)
          printf("The calories of dinner is %d\n",foodcalories[index]);
    }
    printf("====================================================================");

    switch(meal[0])
    {
        case 1: calory[0]=foodcalories[0];
        break;
        case 2: calory[0]=foodcalories[1];
        break;
        case 3: calory[0]=foodcalories[2];
        break;
        case 4: calory[0]=foodcalories[3];
        break;
        case 5: calory[0]=foodcalories[4];
        break;
        case 6: calory[0]=foodcalories[5];
        break;
        case 7: calory[0]=foodcalories[6];
        break;
        case 8: calory[0]=foodcalories[7];
        break;
        case 9: calory[0]=foodcalories[8];
        break;
        case 10: calory[0]=foodcalories[9];
        break;
        case 11: calory[0]=foodcalories[10];
        break;
        case 12: calory[0]=foodcalories[11];
        break;
    }
    switch(meal[1])
    {
        case 1: calory[1]=foodcalories[0];
        break;
        case 2: calory[1]=foodcalories[1];
        break;
        case 3: calory[1]=foodcalories[2];
        break;
        case 4: calory[1]=foodcalories[3];
        break;
        case 5: calory[1]=foodcalories[4];
        break;
        case 6: calory[1]=foodcalories[5];
        break;
        case 7: calory[1]=foodcalories[6];
        break;
        case 8: calory[1]=foodcalories[7];
        break;
        case 9: calory[1]=foodcalories[8];
        break;
        case 10: calory[1]=foodcalories[9];
        break;
        case 11: calory[1]=foodcalories[10];
        break;
        case 12: calory[1]=foodcalories[11];
        break;
    }
    switch(meal[2])
    {
        case 1: calory[2]=foodcalories[0];
        break;
        case 2: calory[2]=foodcalories[1];
        break;
        case 3: calory[2]=foodcalories[2];
        break;
        case 4: calory[2]=foodcalories[3];
        break;
        case 5: calory[2]=foodcalories[4];
        break;
        case 6: calory[2]=foodcalories[5];
        break;
        case 7: calory[2]=foodcalories[6];
        break;
        case 8: calory[2]=foodcalories[7];
        break;
        case 9: calory[2]=foodcalories[8];
        break;
        case 10: calory[2]=foodcalories[9];
        break;
        case 11: calory[2]=foodcalories[10];
        break;
        case 12: calory[2]=foodcalories[11];
        break;
    }
    total=calory[0]+calory[1]+calory[2];
    printf("\nTotal calories is %d",total);
    printf("\n====================================================================\n");
    return total;


}
void calculateWeek(int inTotal, float weight,float height, char inGender,float inBMIresult, float inBMRchoice)//function of calculate week to gain weight of lose weight
{
    float IBWmale,IBWfemale,extracalories,daycalories,actualtweight;
    int week;
    if (inGender=='M' || inGender =='m')
    {
        IBWmale=50+(2.3*((height*100)-152.4)*0.3937);
        if (inBMIresult<18.5)
        {
            actualtweight=IBWmale-weight;
            week=actualtweight*2;
            printf("You need to increase %.2f kg to gain the ideal weight\n",actualtweight);
            printf("You need to eating an extra 500 calories per day,\nthe number of week is %.2d to gain the ideal weight.",week);
        }
        else if (inBMIresult>=18.5 && inBMIresult<=24.9)
        {
            printf("WELL DONE! KEEP IT UP\n");
        }
        else if (inBMIresult>=25)
        {
            actualtweight=-(IBWmale-weight);
            daycalories=actualtweight*7000;
            extracalories=inTotal-(inTotal*0.15);
            week=daycalories/extracalories;
            printf("You need to reduce %.2f kg to gain the ideal weight\n",actualtweight);
            printf("You need to reduce the calories per day by 15\nthe number of week is %.2d to gain the ideal weight.",week);
        }
    }
    if (inGender=='F' || inGender =='f')
    {
        IBWfemale=45.5+(2.3*((height*100)-152.4)*0.3937);
        if (inBMIresult<18.5)
        {
            actualtweight=IBWfemale-weight;
            week=actualtweight*2;
            printf("You need to increase %.2f kg to gain the ideal weight\n",actualtweight);
            printf("You need to eating an extra 500 calories per day,\nthe number of week is %.2d to gain the ideal weight.\n",week);
        }
        else if (inBMIresult>=18.5 && inBMIresult<=24.9)
        {
           printf("WELL DONE! KEEP IT UP\n");
        }
        else if (inBMIresult>=25)
        {
            actualtweight=-(IBWfemale-weight);
            daycalories=actualtweight*7000;
            extracalories=inTotal-(inTotal*0.15);
            week=daycalories/extracalories;
            printf("You need to reduce %.2f kg to gain the ideal weight\n",actualtweight);
            printf("You need to reduce the calories per day by 15\nthe number of week is %.2d to gain the ideal weight.\n",week);

        }

    printf("\n====================================================================\n");

    }
}
