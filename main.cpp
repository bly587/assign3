#include <iostream>
#include <fstream>
#include "GenStack.h"

/*
  include in readme
  http://www.cplusplus.com/doc/tutorial/files/
// */
// template <class T>
// void checkParenthesis(GenStack<T> s, string line, int lineNumber);

int main(int argc, char *argv[])
{
  int numOfErrors = 0;
  //create variable to hold filename
  string filename = "";
  //if they forgot to add a file at the end in the command line
  if(argc < 2)
  {
    cout << "Please enter a file!" << endl;
    cin >> filename;
  }
  //if the user put too many arguements
  else if(argc > 2)
  {
    cout << "Too many arguements! Try again!" << endl;
  }
  //take the file they entered and make it the variable filename
  else
  {
    filename = argv[1];
  }
  //allow for multiple submissions
  while(numOfErrors == 0)
  {
    int quotationCheck = 0;
    int charCheck = 0;
    GenStack<char> s(2);
    int lineNumber = 1;
    string line = "";
    ifstream myfile (filename);
    if (myfile.is_open())
    {
      while(getline(myfile,line))
      {
        //for brackets
        for(int i = 0; i < line.size(); ++i)
        {
          //check if commented out
          if(line[i] == '/' && line[i+1] == '/')
          {
            //set i to max length so you skip this line
            i = line.size();
          }
          //check if within a string
          else if(line[i] == '"')
          {
            if(quotationCheck == 0)
            {
              cout << "Quotation found!" << endl;
              s.push('q');
              quotationCheck++;
            }
            else
            {
              if(s.isEmpty() == false)
              {
                char check = s.pop();
                while(check != 'q')
                {
                  check = s.pop();
                }
                cout << "Quoation ended!" << endl;
                quotationCheck = 0;
              }
              else
              {
                cout << "I don't see how you managed this..." << endl;
              }
            }
          }
          else
          {
            //check if there is an open delimeter
            if(line[i] == '{' || line[i] == '[' || line[i] == '(')
            {
              //then push those open delimeters to the stack
              s.push(line[i]);
              cout << "Pushed open delimeter" << endl;
            }
            //check for closed delimeters
            else if(line[i] == '}' || line[i] == ']' || line[i] == ')')
            {
              //check if stack is empty
              if(s.isEmpty() == false)
              {
                //pop off the most recent thing on the stack and see if the delimeters match and if they open and close correctly
                //char check = line[i];
                char tOfStack = s.pop();
                //check if it is brackets and throw error if it's not right
                if(tOfStack == '{' && line[i] != '}')
                {
                  //cout << tOfStack << " & " << line[i] << endl;
                  cout << "Error: Expected } and found " << line[i] << " " << lineNumber << ":" << i << endl;
                  numOfErrors++;
                }
                //same for [
                else if(tOfStack == '[' && line[i] != ']')
                {
                  //cout << tOfStack << " & " << line[i] << endl;
                  cout << "Error: Expected ] and found " << line[i] << " " << lineNumber << ":" << i << endl;
                  numOfErrors++;
                }
                else if(tOfStack == '(' && line[i] != ')')
                {
                  //cout << tOfStack << " & " << line[i] << endl;
                  cout << "Error: Expected ) and found " << line[i] << " " << lineNumber << ":" << i << endl;
                  numOfErrors++;
                }
              }
              else
              {
                //stack is empty so delimeter cannot be closing already
                cout << "Error: " << line[i] << " " << lineNumber << ":" << i << endl;
                numOfErrors++;
              }
            }
          }
        }
        lineNumber++;
      }
      myfile.close();
    }
    if(numOfErrors == 0)
    {
      char user = 'n';
      cout << "Would you like to check another file?(y/n)" << endl;
      cin >> user;
      if(user == 'y')
      {
        cout << "Enter filename!" << endl;
        cin >> filename;
      }
      else
      {
        exit(1);
      }
    }
  }
}
