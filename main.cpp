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

  GenStack<char> s(2);
  GenStack<char> paren(10);
  int lineNumber = 1;
  string line = "";
  char c = 'c';
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while(getline(myfile,line))
    {
      //for brackets
      for(int i = 0; i < line.size(); ++i)
      {
        if(line[i] == '{')
        {
          cout << "Added" << endl;
          s.push(line[i]);
          if(lineNumber != 1)
          {
            if(s.isEmpty() == true)
            {
              cout << "You are missing a closing bracket '}' before line " << lineNumber << endl;
            }
          }
        }
        else if(line[i] == '}')
        {
          // cout << "Attempting to pop" << endl;
          if(s.peek() != '{')
          {
            //bad sign
            //extra bracket or why is it there?
            cout << "Why do you have an extra '}' on line " << lineNumber << ": " << i << endl;
          }
          else
          {
            s.pop();
          }
        }
        //for parenthesis
        //
        //
        if(line[i] == '(')
        {
          cout << "Added paren" << endl;
          paren.push(line[i]);
          if(lineNumber != 1)
          {
            if(paren.isEmpty() == true)
            {
              cout << "You are missing a closing bracket ')' before line " << lineNumber << endl;
            }
          }
        }
        else if(line[i] == ')')
        {
          // cout << "Attempting to pop" << endl;
          if(paren.peek() != '(')
          {
            //bad sign
            //extra bracket or why is it there?
            cout << "Why do you have an extra ')' on line " << lineNumber << ": " << i << endl;
          }
          else
          {
            paren.pop();
          }
        }
      }
      //for parenthesis

      //for brackets
      lineNumber++;
      //cout << line << '\n';
    }
    myfile.close();
  }
}
