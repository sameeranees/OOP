#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ColdDrink.h"// includes cold drink object header file

using namespace std;

ColdDrink::ColdDrink()//constructor
{
    Company = NULL; //initializes company
    Capacity = NULL;//initializes capacity
    this -> Company = new string[3]{"Pepsi", "Fanta", "Sprite"};//company points to a string array containing companies of drinks
    this -> Capacity = new int[3]{200, 250, 300};// capacity points to a int array containing capacities of drinks
    count = 10;//initializes count(no of coldrinks)
}

void ColdDrink::Use(int colddrinkIndex)
{
    int companyIndex;//initializes local variable companyIndex
    int capacityIndex;//initializes local variable capacityIndex
    cout << endl << "ColdDrinks Used: " << colddrinkIndex << endl;//prints coldrinks used per day
    for (int i = 0; i < colddrinkIndex; i++)// loop works till the random number of colddrinks used per day.
    {
        companyIndex = rand() % 3;// can be in range from 0 to 3
        capacityIndex = rand() % 3;// can be in range from 0 to 3
        cout << Company[companyIndex] << ": " << Capacity[capacityIndex] << endl;//prints companies and capacities according to random cold drinks used per day
        count--;// decrements count
    }
    if (count < 3)//works if count is less than 3
    {
        cout << "Fridge refilled today!" << endl;// prints this statement
        count = 10;//refills fridge and return value of colddrinks back to 10
    }
}
