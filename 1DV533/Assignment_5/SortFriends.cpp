//-----------------------------------------------------------------------
// File: SortFriends.cpp
// Summary: A program that reads 5 names and prints them in ascending
// order, also deallocates the memory when it is finished
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-29 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

const int BUFLEN = 100; // Max length of reading buffer

void sort(char *friendList[], int n); // n is the number of elements
void print(char *friendList[], int n); // n is the number of elements
void terminate(char *friendList[], int n); // n is the number of elements

const int AMOUNT = 5;

int main()
{
    char* friends[AMOUNT]; // Dynamic array with AMOUNT pcs of string pointers
    char buff[BUFLEN] = {""}; // Creates a string buffer (null terminated)
    int count = 0;
    while (count < AMOUNT) // enter AMOUNT number of friends
    {
        cout << "Name a friend: ";
        cin.getline(buff, BUFLEN); // Temporary reading into string buffer
        
        // Find the length for each name
        int count2 = 0;
        for (int i = 0; buff[i]; i++)
        {
            count2++;
        }
        
        friends[count] = new char[count2 + 1]; // WRITE CODE allocating memory to the string
        // WRITE CODE that adds loaded name to current location in the dynamic array
        strcpy(friends[count],buff);
        ++ count;
    }
    
    sort(friends, count); // Sorts the ‘count’ strings
    print(friends, count); // Prints the ‘count’ first names
    terminate(friends, count); // Releases all allocated memory space

    return 0;
}

void sort(char *friendList[], int n)
{
    int result;    
	// Iterates through each strings	
	for ( int i = 0; i < n - 1 ; ++i )
	{
		// Iterates through each string for compare		
		for ( int j = 0; j < n - 1 - i; ++j )
		{		
			// Perform string compare and return value store as result                
			result = strcmp (friendList[j], friendList[j+1]);		
			// If value is more than 0 then swap               
			if (result > 0) 
            {		   
                char *temp = friendList[j];
                friendList[j] = friendList[j + 1];
                friendList[j + 1] = temp;
            }		
		}		 	
	}
}

void print(char *friendList[], int n)
{
    // Print each string in friendlist
    for (int i = 0; i < n; i++)
    {
        cout << friendList[i] << " " << endl;
    }    
}

void terminate(char *friendList[], int n)
{
    // deallocate each string in friendlist
    for (int i = 0; i < n; i++)
    {
        delete [] friendList[i];
    }
}