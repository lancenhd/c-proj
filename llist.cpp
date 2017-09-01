#include<iostream>
using namespace std;
#include <iomanip>
#include "llist.h"
#include <fstream>  


/*******************************************************
//
// function name: addRecord 
//
// DESCRIPTION: Adds a record to the database. The information it adds, includes the "id number, name, address, and year of birth". 
//
//  
// Parameters: 
//              accoutnNum(int) contains the account number of a person.
//              name(char[]) contains the name of a person
//              address(char[]) contains the address of a person.
//              yob(int) contains the year of birth of a person.  
// 
// Return values:  0:it works  
//                 -1: value was not found.  
//
//
//****************************************************/

int llist::addRecord(int accountNum, char name[],char address[], int yob)
{

    struct record * temp;
    struct record * newRecord;
    temp = start;
    
    newRecord = new record; 
    newRecord->accountno = accountNum;
    strncpy(newRecord->name, name, 25);
    strncpy(newRecord->address,address,80);
    newRecord->yearofbirth = yob;
    newRecord->next = NULL;   

    if(start == NULL)
    {  
     start = newRecord;
     temp = newRecord;
    } 
   
       else
       {
         temp = start; 
         
           while(temp->next != NULL)
           {
              temp = temp->next;
           }
            
             temp->next = newRecord;
       }
      newPage();
#ifdef DEBUG 
       cout<< "\n\n\n";
       cout << "Debug mode= ON\n\n";
       cout << "This is what you sent.\n";   
       cout << "Account Number = "<< accountNum << "\n";
       cout << "Name =  "<< name << "\n";  
       cout <<"Address = " << address << "\n"; 
       cout << "Year Of Birth = " << yob << "\n";
       cout << "\n\n\n";
#endif
}  



/*******************************************************
//
// function name:printRecord 
//
// DESCRIPTION:  Prints out the record of an person using their accountNumber. 
//
// Parameters: accoutNum(int) contains the account number of a perosn. 
// 
// Return values:  0:it works  
//                 -1: value was not found.  
//
//***************************************/
int llist::printRecord(int accountNum )  
{ 
  struct record * temp = start; 
  int found = 0;
  
    if(temp == NULL) 
    {
       cout<<"Sorry, this database is empty right now.\n";
    }

        else
        {
           while(temp != NULL)
           { 
                if(temp->accountno == accountNum)
                {
                   cout<< "ID = " << temp->accountno << "\n";
                   cout<< "Name = " << temp->name << "\n";
                   cout<< "Address = " << temp->address << "\n";
                   cout<< "Year of Birth = " << temp->yearofbirth << "\n";
                   found = 1;
                }  
                     
                     if(temp->accountno != accountNum)
                     {
                       cout << "That account does not exist in this database.\n";                   }
                       temp = temp->next;
              
           }
            
                if(found == 0) 
                {
                  cout<< "That account does not exist in this database.\n"; 
                }

        } 
#ifdef DEBUG    
     cout << "\n\n\n"; 
     cout << "Debug mode = ON\n\n";
     cout << "This is what you sent.\n"; 
     cout << "Account Number: " << accountNum << "\n";
     cout << "\n\n\n";    
#endif   
}  







/*******************************************************
//
// function name: modifyRecord   
//
// DESCRIPTION:  Modifys the record of a person's address. 
//
// Parameters:  accoutnNum(int) contains the account number of a person.
//              name(char[]) contains the name of a person
// 
// Return values:  0:it works  
//                 -1: value was not found.  
//
//***************************************/
int llist::modifyRecord(int accountNum, char address[])
{

  struct record * temp;
  temp = start;
  int found = 0;
 
    if(temp == NULL)
    { 
      cout << "No changes becasuse the database is empty.\n"; 
    }

       else 
       {
            while(temp != NULL) 
            {
            
                if(temp->accountno == accountNum)
                {  
                  strncpy(temp->address, address,25); 
                }
                
                temp = temp->next;
            } 
               
                if(found == 0)
                {
                  cout << "Sory that account does not exist in this database.\n";
                } 
        } 
       
#ifdef DEBUG      
     cout << "\n\n\n"; 
     cout << "Debug mode = ON\n\n";
     cout << "This is what you sent.\n"; 
     cout << "Account Number: " << accountNum << "\n";  
     cout << "Address: " << address << "\n";  
     cout << "\n\n\n";   
#endif 
}  





/*******************************************************
//
// function name:printAll
//
// DESCRIPTION:  Prints all the records in database. 
//
// Parameters:none
// 
// Return values: none 
//
/***********************************************************/
void llist::printAll()

{ 

   struct record * temp;
   temp = start; 
   int counter = 1; 

      if(temp == NULL)
      {
         cout << "There seems to be nothing in the database.\n"; 
      }
     
          while(temp != NULL)
          {
           
             cout << "ID Number = " << temp->accountno << "\n"; 
             cout <<"Name = " << temp->name << "\n"; 
             cout << "Address = " << temp->address << "\n";
             cout << "Year of Birth = " << temp->yearofbirth << "\n\n\n";
             counter++;
             temp = temp->next;
              
          }
            
 #ifdef DEBUG 
     cout<<"\n\n\n"; 
     cout<<"Debug mode = ON\n\n";
     cout<<"Because you chose choice 4, it prints everything\n"; 
#endif 
}  















/*******************************************************
//
// function name: deleteRecord  
//
// DESCRIPTION: Deletes the record of an person using their accountNumber. 
//
// Parameters:  accoutnNum(int) contains the account number of a person.
// 
// Return values:  0:it works  
//                 -1: value was not found.  
//
//***************************************/
int llist::deleteRecord(int accountNum)  
{
  struct record * temp = NULL;
  struct record * current; 
  int found = 0;
  current = NULL;
  temp = start; 
 
if(temp!= NULL)
{
   current = NULL; 
   
   while(temp->accountno != accountNum)
   {
      current = temp; 
      temp = temp->next;
   }
       

       if(current != NULL && temp->next != NULL)
       {
           current->next = temp->next; 
           delete(temp);
           found = 1;
       }

       if(current != NULL && temp->next == NULL)
       {
         temp->accountno = 0; 
         current->next = NULL; 
         delete(temp);
         found = 1; 
       } 
       
       if(current == NULL)
       {
          current = temp; 
          temp = temp->next; 
          delete(current);
          found = 1;
          start = temp; 

       }

}
 
  else
  {
      cout << "That number is not in the database.\n";
  }

  if(found == 1)
  {
    cout << "The account number you sent was deleted!\n";
  }

#ifdef DEBUG   
     cout<<"\n\n\n"; 
     cout<<"Debug mode = ON\n\n";
     cout<<"This is what you sent.\n";  
     cout<<" Account Number = " <<  accountNum << "\n";
     cout<<"\n\n\n";   
#endif 
}  





/*******************************************************
//
// function name:readFile
//
// DESCRIPTION: Reads the "saveFile.txt" which is all the data in the database.  
//
// Parameters: none
// 
// Return values: none 
//
/*******************************************************/
int llist::readFile()

{


   ifstream saveFile;
   char space[80];
   char eatSpace[10];
   int step = 0;
   int accountNum;
   char name[25];
   char address[80];
   int yob;
   saveFile.open("saveFile.txt"); 


        
    /* while(saveFile.getline(line,80)!= NULL)
     {
            if(step == 0)
            {
              saveFile >> accountNum;
              step++;
              cout << accountNum; 
            }
             
            if(step == 1)
            { 
            saveFile >> accountNum;
            step++;
            
            }

            if(step == 2)
            {
            saveFile.getline(address,80);
            step++; 
            }

            if(step == 3)
            {
             saveFile >> yob;
             step = 0;
             addRecord(accountNum, name, address, yob);
             }
           
            saveFile.getline(line, 80);
 
        }
   }
  saveFile.close();*/
}   


/*******************************************************
//
// function name:writeFile
//
// DESCRIPTION: copies all the records in database to a file called "saveFile.txt". 
//
// Parameters: none 
// 
// Return values: none
//
/*******************************************************/
int llist::writeFile()
{
  ofstream saveFile; 
  struct record * temp;
  int counter = 0;

  saveFile.open(filename);

  temp = start;
   
  /*cout<<"write file Activated!\n";*/ 
    while(temp != NULL)
    {  
      saveFile << temp->accountno << "\n" << temp->name << "\n" << temp->address << "\n" << temp->yearofbirth << "\n\n"; 
      temp = temp->next; 
   }   
       saveFile.close();
       cout << "Saving files...\n";

}

/*******************************************************
//
// function name:llist constructor
//
// DESCRIPTION: llist constructor 
//
// PARAMETERS: none
//
// Return values:  0:it works
//                 -1: value was not found.
//
/***********************************************************/


llist::llist()
{
  this->start = NULL; 
  strcpy(filename,"saveFile.txt");
  /*readFile();*/
}




/*******************************************************
//
// function name:llist constructor
//
// DESCRIPTION: llist constructor 
//
// PARAMETERS: saveFile(char[]): The filename that it will copy and read. 
//
// Return values:  0:it works
//                 -1: value was not found.
//
/***********************************************************/


llist::llist(char saveFile[])
{
   start = NULL; 
   strcpy(filename, saveFile);
   /*readFile()*/
}






/*******************************************************
//
// function name:~llist constructor
//
// DESCRIPTION: llist deconstructor 
//
// PARAMETERS: none
//
// Return values:  0:it works
//                 -1: value was not found.
//
/******************************************************/
llist::~llist()
{
  writeFile();
  cleanup();
}






/*******************************************************
//
// function name: reverse  
//
// DESCRIPTION: reverses the order of the list. 
//
// PARAMETERS: none
//
// Return values:  0:it works
//                 -1: value was not found.
//
/***********************************************/

void llist::reverse()
{
   reverse(start);
}



/*******************************************************
//
// function name: reverse  
//
// DESCRIPTION: reverses the order of the list. 
//
// PARAMETERS: none
//
// Return values:  0:it works
//                 -1: value was not found.
//
/***********************************************/

record * llist::reverse(record *current)
{
  if(current->next == NULL)
  {
    start = current; 
  }

     else 
     {
        reverse(current->next);
        current->next->next = current; 
        current->next = NULL; 
     }
}



/*******************************************************
//
// function name:cleanup 
//
// DESCRIPTION: Deletes every record in the list. 
//
// PARAMETERS: none
//
// Return values:none  
//                
//
/***********************************************/
void llist::cleanup()
{
   struct record *temp;
   struct record *trashTarget;
   temp = start; 

     while(temp!= NULL)
     {
        if(temp == start)
        {
           temp = temp->next;
           delete(start);
           start = temp; 
        }

        else 
        {
           trashTarget->next = temp->next; 
           delete(temp);
           trashTarget->next = temp;
        }
     }
  cout << "Finished cleaning!\n";
}


/*******************************************************
//
// function name: ostream
//
// DESCRIPTION:Overloads the printall operator. 
//
// PARAMETERS: stream(ostream): the output stream 
               list(llist):list that will be printed.
//
// Return values:none  
//                
//
/***********************************************/

ostream& operator <<(ostream &stream, const llist &list)
{
   struct record *temp; 
   temp = list.start;
   int counter = 1; 

      if(temp == NULL)
      {
         stream << "There seems to be nothing in the database.\n"; 
      }
      
      else
      { 
          while(temp != NULL)
          {
           
             stream << "ID Number = " << temp->accountno << "\n"; 
             stream <<"Name = " << temp->name << "\n"; 
             stream << "Address = " << temp->address << "\n";
             stream << "Year of Birth = " << temp->yearofbirth << "\n\n\n";
             counter++;
             temp = temp->next;
           }

       } 
}


/*******************************************************
//
// function name: newPage 
//
// DESCRIPTION: Creates a bunch of new lines, making it nicer for the user to see the menu. 
//
// PARAMETERS: none. 
//
// Return values:none  
//                
/***********************************************/
void llist::newPage()
{
cout << "\n\n\n\n\n\n\n";
cout << "\n\n\n\n\n\n\n";
cout << "\n\n\n\n\n\n\n";
cout << "\n\n\n\n\n\n\n";
cout << "\n\n\n\n\n\n\n";
cout << "\n\n\n\n\n\n\n";
}
