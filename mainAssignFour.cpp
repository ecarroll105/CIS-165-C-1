//Name: Evan Carroll
//Class: CIS-165
//Professor: Prof. Luy
//last Updated: 4/30/2019
//preprocessor directives
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>
using namespace std;
//initializing/declaring constants
const int MAX_SIZE = 10, MAX_NAME = 30, COLUMN_ROW = 4; //declaring constant array sizes
//declaring types and arrays
typedef char STRING30[MAX_NAME]; //declaring the string30 type
typedef STRING30 NAME_LIST[MAX_SIZE]; //declaring name array of type string30
typedef STRING30 LIST_COL[MAX_SIZE]; //declaring column of array of type string30
typedef int LIST_I[MAX_SIZE]; //declaring an int array of all the days rented
typedef double LIST_D[MAX_SIZE]; //decarling a float array of the balance due
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//main function
int main(int argc, char** argv)
{
	//array, file, and variable declaration
	int mostDaysRented, mostDaysRented2; //declaring the most days rented variables (for both text files 1 and 2)
	double maxBalance, totalBalanceDue, maxBalance2, totalBalanceDue2; //declaring the largest balance due and total balance due variables (for both text files 1 and 2)
	char fName[MAX_NAME], lName[MAX_NAME], fName2[MAX_NAME], lName2[MAX_NAME]; //declaring the first name and last name (for both text files 1 and 2) variables
	bool boolFile2; //declaring a bool variable to determine whether or not the user wants to process the second file
	NAME_LIST first, last, first2, last2; //declaring variables for first and last names (for both text files 1 and 2) of type NAME_LIST
	LIST_I daysRented, daysRented2; //declaring daysRented variables (for both text files 1 and 2) of type LIST_I
	LIST_D balanceDue, balanceDue2; //declaring balanceDue variables (for both text files 1 and 2) of type LIST_D
	LIST_COL headers, headers2; //declaring headers variable (for both text files 1 and 2) of type LIST_COL
	ifstream inFile, inFile2; //declaring the infile (for both text files 1 and 2) to write into
	ofstream outFile, outFile2; //declaring the outfile (for both text files 1 and 2) write out to
	//initializing variables
	totalBalanceDue = 0.0, maxBalance = 0.0, totalBalanceDue2 = 0.0, maxBalance2 = 0.0; //balance begins at 0
	//textfile fun
	inFile.open("invoice1_test1.txt", ios :: out | ios :: app); //opens the invoice1_test1.txt textfile on computer
	if(inFile.is_open()) //checks if recordFile is there
	{
		//reading in the text file to an array
		for(int i = 0; i <= MAX_SIZE;i++) //for loop to go through file
		{
			if(i == 0) //if this is the first iteration make a header array
				inFile >> headers[i] >> headers[i] >> headers[i] >> headers[i]; //header array input
			else //if their is already a header array continue to make the other arrays
				inFile >> last[i-1] >> first[i-1] >> daysRented[i-1] >> balanceDue[i-1];
		}
		//sorting the array in alaphabetical order of last name using a bubble sort
		for(int j = 0; j < (MAX_SIZE - 1); j++) //outer loop for bubble sort
		{
			int daysRentedTemp; //declaring daysRented temp variable
			double balanceDueTemp; //declaring balanceDue temp variable
			char lNameTemp[MAX_NAME], fNameTemp[MAX_NAME]; //making temporary name variables to make sorting easier (I think)
			for(int k = (j + 1); k < MAX_SIZE; k++) //outer for loop to iterate through the array
			{
				int match = strcmp(last[j], last[k]); //match determines if the next value is bigger than the previous one and saves the results in the int variable match
				if(match > 0) //is executed if last[k] is bigger than last[j]
				{
					strcpy(lNameTemp, last[j]); //the value of the char array in last[j] is copied into lNameTemp
					strcpy(last[j], last[k]); //the value of the char array in last[k] is copied into last[j]
					strcpy(last[k], lNameTemp); //the value of the char array in lNameTemp is copied into last[k]
					
					strcpy(fNameTemp, first[j]); //the value of the char array in first[j] is copied into fNameTemp
					strcpy(first[j], first[k]); //the value of the char array in first[k] is copied into first[j]
					strcpy(first[k], fNameTemp); //the value of the char array in fNameTemp is copied into first[k]
					
					daysRentedTemp = daysRented[j]; //the value of the int array in daysRented[j] is copied into the daysRentedTemp variable
					daysRented[j] = daysRented[k]; //the value of the int array in daysRented[k] is copied into daysRented[j]
					daysRented[k] = daysRentedTemp; //the value of the daysRentedTemp variable is copied into the int array in daysRented[k]
				
					balanceDueTemp = balanceDue[j]; //the value of the double array in balanceDue[j] is copied into the balanceDueTemp variable
					balanceDue[j] = balanceDue[k]; //the value of the double array in balanceDue[k] is copied into balanceDue[j]
					balanceDue[k] = balanceDueTemp; //the value of the balanceDueTemp variable is copied into the double array in balanceDue[k]
				}
			}
		}
		//process section
		mostDaysRented = daysRented[0]; //setting the mostDaysRented variable equal to the first value in the daysRented array
		for(int a = 0; a < MAX_SIZE; a++) //for loop to iterate through the array
		{
			if(mostDaysRented < daysRented[a]) //if statement to check for a value larger than mostDaysRented
				mostDaysRented = daysRented[a]; //mostDaysRented is now equal to the value that was previously bigger
		}
		//calculating the largest balance due
		maxBalance = balanceDue[0]; //setting the maxBalance variable equal to the first value in the balanceDue array
		for(int b = 0; b < MAX_SIZE; b++) //for loop to iterate through the array
		{
			if(maxBalance < balanceDue[b]) //if statement to check for a balance larger than initial largest balance
				maxBalance = balanceDue[b]; //maxBalance is now equal to the balance that was preciously bigger
		}
		//calculating the total balance due
		for(int c = 0; c < MAX_SIZE; c++) //for loop to iterate through the balanceDue array
			totalBalanceDue += balanceDue[c]; //the total is equal to each value in the balanceDue array
		inFile.close(); //closing inFile because we no longer need it to read it into the arrays
	}
	else //if invoice1_test1.txt isn't found entire process is skipped
		cout << "invoice1_test1.txt cannot be found, try again." << endl; //what is printed out to console
	//sorted file/output section
	outFile.open("sorted.txt", ios :: out | ios :: app); //opening and created the sorted text file
	outFile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2); //2.00 decimal points
	if(outFile.is_open()) //checking if the sorted file is open
	{
		outFile << setw(15) << "LastName" << setw(15) << "FirstName" << setw(15) << "DaysOfRental" << setw(15) << "BalanceDue" << endl; //what you wanted on the top of the file
		for(int j = 0; j < MAX_SIZE; j++) //for loop to go through all the arrays and print them into the sorted file
			outFile << setw(15) << last[j] << setw(15) << first[j] << setw(15) << daysRented[j] << setw(15) << balanceDue[j] << endl; //the actual data that is going into the file
		outFile << "Total balance due for the file: $" << totalBalanceDue << endl; //total balance due is put into the textfile
		outFile << " " << endl; //readability
		outFile << "The customer with the most days rented: "; //printing to the outfile the customer who has the most days rented
		for(int m = 0; m < MAX_SIZE; m++) //for loop to find every person who may have the most days rented in text file 1
		{
			if(daysRented[m] == mostDaysRented) //if the value in this array is equal to the mostDaysRented
				outFile << first[m] << " " << last[m] << ", "; //we print their name into the sorted file
		}
		outFile << "renting for a total of: " << mostDaysRented << " days." << endl;  //the customer has rented it for mostDaysRented days
		outFile << " " << endl; //readability
		outFile << "The customer who has the highest balance due is: "; //printing to outfile the customer who has the highest balance due is
		for(int n = 0; n < MAX_SIZE; n++) //for loop to find every person who may have the highest balance due in text file 1
		{
			if(balanceDue[n] == maxBalance) //if the value in this array is equal to the maxBalance...
				outFile << first[n] << " " << last[n] << ", "; //we print their name into the sorted file
		}
		outFile << "in total this customer owes us: $" << maxBalance << "." << endl; //the customer in total owes us this balance of money 
	}
	outFile.close(); //closing outFile
	//time to see if you want to sort the second file
	cout << "Would you like to sort the second file? (1 for true, 0 for false)" << endl; //output to the console asking the user if they want to continue
	cin >> boolFile2; //inputting the user's choice into boolFile2
	if(boolFile2 == true) //checking to see if the user wants to sort another file
	{
		inFile2.open("invoice2_test2.txt", ios :: out | ios :: app); //opens textfile on computer
		if(inFile2.is_open()) //checks if inFile2 is there
		{
			//reading in the text file to an array
			for(int z = 0; z <= MAX_SIZE;z++) //for loop to go through file
			{
				if(z == 0) //if this is the first iteration make a headers2 array
					inFile2 >> headers2[z] >> headers2[z] >> headers2[z] >> headers2[z]; //headers2 array input
				else //if their is already a header array continue to make the other arrays
					inFile2 >> last2[z-1] >> first2[z-1] >> daysRented2[z-1] >> balanceDue2[z-1];
			}
			//sorting the array in alaphabetical order of last name using a bubble sort
			for(int y = 0; y < (MAX_SIZE - 1); y++) //outer loop for bubble sort
			{
				int daysRentedTemp2; //declaring daysRented2 temp variable
				double  balanceDueTemp2; //declaring balanceDueTemp2 variable 
				char lNameTemp2[MAX_NAME], fNameTemp2[MAX_NAME]; //making temporary name variables to make sorting easier (I think)
				for(int x = (y + 1); x < MAX_SIZE; x++) //outer for loop to iterate through the array
				{
					int match2 = strcmp(last2[y], last2[x]); //match2 saves whether or not the second value is smaller than the previous one
					if(match2 > 0) //to check if the next value is larger than the previous one
					{
						strcpy(lNameTemp2, last2[y]); //the value of the char array in last2[y] is copied into lNameTemp2
						strcpy(last2[y], last2[x]); //the value of the char array in last2[x] is copied into last2[y]
						strcpy(last2[x], lNameTemp2); //the value of the char array in lNameTemp2 is copied into last2[x]
						
						strcpy(fNameTemp2, first2[y]); //the value of the char array in first2[y] is copied into fNameTemp2
						strcpy(first2[y], first2[x]); //the value of the char array in first2[x] is copied into first2[y]
						strcpy(first2[x], fNameTemp2); //the value of the char array in fNameTemp2 is copied into first2[x]
						
						daysRentedTemp2 = daysRented2[y]; //the value of the int array in daysRented2[y] is copied into the daysRentedTemp2 variable
						daysRented2[y] = daysRented2[x]; //the value of the int array in daysRented2[x] is copied into daysRented2[y]
						daysRented2[x] = daysRentedTemp2; //the value of the daysRentedTemp2 variable is copied into the int array in daysRented2[x]
					
						balanceDueTemp2 = balanceDue2[y]; //the value of the double array in balanceDue2[y] is copied into the balanceDueTemp2 variable
						balanceDue2[y] = balanceDue2[x]; //the value of the double array in balanceDue2[x] is copied into balanceDue2[y]
						balanceDue2[x] = balanceDueTemp2; //the value of the balanceDueTemp2 variable is copied into the double array in balanceDue2[x]
					}
				}
			}
			//process section
			//finding who rented the most days in file 2
			mostDaysRented2 = daysRented2[0]; //setting the mostDaysRented2 variable equal to the first value in the daysRented2 array
			for(int a = 0; a < MAX_SIZE; a++) //for loop to iterate through the array
			{
				if(mostDaysRented2 < daysRented2[a]) //if statement to check for a value larger than mostDaysRented2
					mostDaysRented2 = daysRented2[a]; //mostDaysRented2 is now equal to the value that was previously bigger
			}
			//calculating the largest balance due of file 2
			maxBalance2 = balanceDue2[0]; //setting the maxBalance variable equal to the first value in the balanceDue array
			for(int b = 0; b < MAX_SIZE; b++) //for loop to iterate through the array
			{
				if(maxBalance2 < balanceDue2[b]) //if statement to check for a value larger than initial value
					maxBalance2 = balanceDue2[b]; //maxBalance2 is now equal to the value that was preciously bigger
			}
			//calculating the total balance due of file 2
			for(int c = 0; c < MAX_SIZE; c++) //for loop to iterate through the balanceDue2 array
				totalBalanceDue2 += balanceDue2[c]; //the total is equal to each value in the balanceDue2 array
			inFile2.close(); //closing inFile2 because we no longer need it to read it into the arrays
		}	
		else //if invoice2_test2.txt isn't found entire process is skipped
			cout << "invoice2_test2.txt cannot be found, try again." << endl; //what is printed out to console
		//sorted file/output section
		outFile2.open("sorted2.txt", ios :: out | ios :: app); //opening and created the sorted2 textfile
		outFile2 << setiosflags(ios::showpoint | ios::fixed) << setprecision(2); //2 decimal points
		if(outFile2.is_open()) //checking if the sorted file is open
		{
			outFile2 << setw(15) << "LastName" << setw(15) << "FirstName" << setw(15) << "DaysOfRental" << setw(15) << "BalanceDue" << endl; //what you wanted on the top of the file
			for(int j = 0; j < MAX_SIZE; j++) //for loop to go through all the arrays and print them into the sorted2 textfile
				outFile2 << setw(15) << last2[j] << setw(15) << first2[j] << setw(15) << daysRented2[j] << setw(15) << balanceDue2[j] << endl; //the actual data that is going into the file
			outFile2 << "Total balance due for the file: $" << totalBalanceDue2 << endl; //totalBalanceDue2 is put into the textfile sorted2
			outFile2 << " " << endl; //readability
			outFile2 << "The customer with the most days rented: "; //printing to outfile2 the customer who has the most days rented in text file 2
			for(int i = 0; i < MAX_SIZE; i++) //for loop to iterate through the daysRented2 array
			{
				if(daysRented2[i] == mostDaysRented2)  //if the value in this array is equal to the mostDaysRented2...
					outFile2 << first2[i] << " " << last2[i] << ", "; //then we print out the name to sorted2.txt
			}
			outFile2 << "renting for a total of: " << mostDaysRented2 << " days." << endl; //the customer has rented it for mostDaysRenteds days
			outFile2 << " " << endl; //readability
			outFile2 << "Customer who has the highest balance due are : ";  //printing to outfile2 the customer who has the highest balance due is in textfile 2
			for(int h = 0; h < MAX_SIZE; h++) //for loop to iterate through the balanceDue2 array
			{
				if(balanceDue2[h] == maxBalance2) //if the value in this array is equal to the maxBalance2...
					outFile2 << first2[h] << " " << last2[h] << ", "; //then we print out the name to sorted2.txt
			}
			outFile2 << "in total this customer owes us: $" << maxBalance2 << "." << endl; //the customer in total owes us this balance of money
		}
		outFile2.close(); //closing outFile2
	}
	else //else statement for when the us
		cout << "Thank you for sorting those files!" << endl; //thanking you for sorting those files
	system("pause"); //pauses the screen so you can see the thanking
	system("cls"); //clears computer console screen from any random text
	return 0; //return of the return of 0
}
