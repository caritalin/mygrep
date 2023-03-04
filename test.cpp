#include<iostream>
#include<fstream>
#include<string>
#include<string.h>


ifstream inputFile("Students.txt");
string line;

string Surname;
string Initial;
int number1, number2;

using namespace std;
 
int main()
{
   string strNumber1;
string strNumber2;
getline(linestream, strNumber1, ',');
getline(linestream, strNumber2, ',');
int number1 = stoi(strNumber1);
int number2 = atoi(strNumber2.c_str());

return 0;
}