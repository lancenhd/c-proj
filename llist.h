#include "record.h"
#include <string>

#ifndef LLIST_H
#define LLIST_H 

class llist{

 private:
        record * start;
        char filename[16];
        int readFile();
        int writeFile();
        record * reverse (record *);
        void cleanup();

   public:

       llist();/*constructor*/
       llist(char[]);
       ~llist(); /*deconstructor*/
       int addRecord(int, char[], char[], int);
       int printRecord(int);
       int modifyRecord(int, char[]);
       void printAll();
       int deleteRecord(int);
       void reverse();
       friend ostream& operator <<(ostream&, const llist& list);
       void newPage();
};

#endif 
