/*********************************************************
//
// NAME: Lancen Daclison
//
// HOMEWORK: Project2
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: 4/24/16
//
// FILE: p2Main.cpp
//
// DESCRIPTION: This file contains the driver and the menu which allows the user to interact with the program.
//
//*****************************************************/
#include <iostream>
using namespace std;
#include <iomanip>
#include "llist.h"
/*********************************************************
//
// Function name: main
//
// DESCRIPTION: Checks if user typed in debug or not when using command line. However, debug option is always turned on for my program.
// This function also has a menu, but in the future I should make menu into it's own function. So I can just call it instead.
//This method also calls functions of menu after user chooses choices from menu.
//
// Parameters: argc(char): Is the arguments used to start this program. For example, "homework3" would be a correct parameter.
argv(int): This is the argument that counts how much space it takes. So for example "homework3 debug" would be 2 spaces. arg[0] and arg[1].
//
//**************************************************************/
main(int argc, char *argv[])
{
/*variables*/
struct record *start = NULL;
int choice = 0; 
int getOutLoop = 0;
char eatSpace[3];
char debugScanner[] = "debug";

   int accountno = 0;
   char name[25];
   char address[80];
   int yearofbirth = 0;
   llist database;
   string nextPage;

   while(getOutLoop < 1 )
   {
      cout << "\n";
#ifdef DEBUG 
  cout << "DEBUG = ON\n";
#endif
      cout << "***************************************************************\n";
      cout << "Enter 1: To add new information.\n";
      cout << "Enter 2: To print out a student's record.\n";
      cout << "Enter 3: to modify record.\n";
      cout << "Enter 4: To Print out all student records.\n";
      cout << "Enter 5: To delete a student's record.\n";
      cout << "Enter 6: To reverse order.\n";
      cout << "Enter 7: To quit program.\n\n";
      cout << "*************************************************************\n";
      cout << "choice: ";
      cin >> choice ;



      if(choice == 1)
      {
         database.newPage(); 
         cout << "Enter in an account number: ";
         cin >>  accountno;
         cout << "Enter in a name:";
         cin.getline(eatSpace,3);
         cin.getline(name,25);
         cout << "Enter in an address (END WITH $):";
         cin.getline(address,80,'$'); 
         cout << "Enter in the year of birth of someone: ";
         cin >> yearofbirth;
         getOutLoop = 0;
         database.addRecord(accountno, name,address, yearofbirth);

        cout << "When you are done looking press '1' or 'done'\n";
        cin >> nextPage; 
        database.newPage(); 

      }

      if(choice == 2)
      {
         database.newPage(); 
         cout << "What account number would you like to see?:";
         cin >> accountno;
         database.printRecord(accountno);
        
         cout << "When you are done looking press '1' or 'done'\n";
         cin >> nextPage; 
         database.newPage(); 

         getOutLoop = 0;

      }

      if(choice == 3)
      {
         database.newPage(); 
         cout << "What account number would you like to modify?:";
         cin >> accountno;
         cout << "\n";
         cout << "Enter in a new address (END WITH $):";
         cin.getline(eatSpace,3);
         cin.getline(address,80,'$');
         database.modifyRecord(accountno, address);
        
         cout << "When you are done looking press '1' or 'done'\n";
         cin >> nextPage; 
         database.newPage(); 

         getOutLoop = 0;
      }

      if( choice == 4)
      {
         database.newPage(); 
        /*cout <<  database;*/
        database.printAll();
         
         cout << "When you are done looking press '1' or 'done'\n";
         cin >> nextPage; 
         database.newPage(); 

         getOutLoop = 0;

      }

      if (choice == 5)
      {
         database.newPage(); 
         cout << "Type in a account number to delete:";
         cin >>  accountno;
         database.deleteRecord(accountno);
         
         cout << "When you are done looking press '1' or 'done'\n";
         cin >> nextPage; 
         database.newPage(); 

         getOutLoop = 0;

      }

    
      if(choice == 6)
      {
        database.reverse(); 
        cout << "Reverse activated!";
      }

      
      if (choice == 7)
      {
         cout << "\n";
         cout << "Shutting down\n";
         getOutLoop++;
      }

      
      if((choice >7)||(choice < 0))
      {
         cout << "\n";
         cout << "You have preseed something that was not options 1 - 7\n";
         cout << "Shutting down\n";
         getOutLoop++;
      }

   }/*close while*/

}/*close function*/


