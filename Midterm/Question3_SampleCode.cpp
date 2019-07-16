#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

float* DataAnalyzer(float* allData, int totalValues);

int main()
{
    srand (time(NULL));

    int totalValues = 5 + rand() % 6;
    float* allData = new float[totalValues];

    for (int i = 0; i<totalValues; i++)
    {
        allData[i] = (10 + rand()% 10) + ((float)(rand()%10)/10);
    }

    allData = DataAnalyzer(allData, totalValues);

    cout<<"The sum of all the values is: "<</* Add code here */<<endl;
    cout<<"The square of the sum of all the values is: "<</* Add code here */<<endl;

    return 0;
}

float* DataAnalyzer(float* allData, int totalValues)
{

}
