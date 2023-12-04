#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<string> undoStack;
stack<string> redoStack;
string filename;

/**
 * @brief      Undo the last operation
 * @detail    This function will undo the last operation performed on the file
 * @param[in]  filename  The filename
 */
void undo(string filename)
{
	if(undoStack.empty())
	{
		cout<<"Nothing to Undo"<<endl;
	}
	else
	{
		string temp = undoStack.top();
		undoStack.pop();
		redoStack.push(temp);

		ofstream myfile((filename+".txt").c_str());
		myfile.close();
	}
}

/**
 * @brief      Redo the last operation
 * @detail    This function will redo the last operation performed on the file
 * @param[in]  filename  The filename
 */
void redo(string filename)
{
	if(redoStack.empty())
	{
		cout<<"Nothing to Redo"<<endl;
	}
	else
	{
		string temp = redoStack.top();
		redoStack.pop();
		undoStack.push(temp);

		ofstream myfile((filename+".txt").c_str());
		myfile<<temp;
		myfile.close();
	}
}

/**
 * @brief      Menu
 * @detail    This function will display the menu and perform the operations
 * @param[in]  msg  The message
 */
void menu(int msg)
{	
	system("CLS");
	if(msg==0)
	{
		cout<<"Welcome to Text Editor"<<endl<<endl;
	}
	if(msg==1)
	{
		cout<<"File Created Successfully"<<endl<<endl;
	}	
	if(msg==2)
	{
		cout<<"File Updated Successfully"<<endl<<endl;
	}	
	if(msg==4)
	{
		cout<<"File Emptied Successfully"<<endl<<endl;
	}
	if(msg==5)
	{
		cout<<"File Deleted Successfully"<<endl<<endl;
	}	
	if(msg==55)
	{
		cout<<"File Not Found"<<endl<<endl;
	}
	if(msg==6)
	{
		cout<<"File Copied Successfully"<<endl<<endl;
	}	
	
	cout<<"Main Menu"<<endl;
	cout<<"-------------"<<endl;
	cout<<"1. Create File"<<endl;
	cout<<"2. Add to File"<<endl;
	cout<<"3. Read from File"<<endl;
	cout<<"4. Empty File"<<endl;
	cout<<"5. Delete File"<<endl;
	cout<<"6. Copy File"<<endl;
	cout<<"7. Undo"<<endl;
	cout<<"8. Redo"<<endl;
	cout<<"9. Exit"<<endl<<endl;	
	cout<<"Enter Choice: ";
	
	int choice = 0;
	// string filename;	
	string text;	
			
	cin>>choice;
	if(choice==1)
	{	/* LOGIC
		*	1. Ask for filename
		*	2. Create file with filename
		*	3. Close file
		*/
		cout<<endl<<"Enter name of file: ";		
		cin.ignore();
		getline(cin, filename);
		ofstream myfile( (filename+".txt").c_str() ); //.c_str() is used when you want to pass the contents of string to function//
		myfile.close();		
		menu(1);		
		cin>>choice;
	}
	if(choice==2)
	{
		/*LOGIC
		*	1. Ask for filename
		*	2. Ask for text to write to file
		*	3. Open file with filename
		*	4. Write text to file
		*	5. Close file
		*/
		text="";
		cout<<endl<<"Enter name of file: ";
		cin>>filename;		
		cout<<endl<<"Enter text to write to file: (Enter END to complete)"<<endl;
		ofstream myfile;
		myfile.open((filename+".txt").c_str(),ios::app); // ios::app is used to append the text to the file//	
		string line; // string is a class and line is an object of that class//
		cin.ignore();	 // (Ignore the Buffer(Temperory contents)	
		while (getline(cin, line))
		{
			if(line.size()>=3)
			{ // if the size of line is greater than or equal to 3 then only check for END//
			    if (line.substr(line.size() - 3) == "END") //Specifying that whenever END is typed stop reading data eof//
			    {
			    	text += line.substr(0, line.size()-3); // o is position of 1st chracter ,line.size is the total length, t is size of END//
			    	break;	
				}	
				else { // if END is not typed then keep on adding the text to the file//
					text += line+"\n";
				}
			}
			else { // if the size of line is less than 3 then keep on adding the text to the file//
				text += line+"\n";
			}      			    
		}
		myfile<<text; // writing the text to the file//
		undoStack.push(text); // pushing the text to the stack//
  		myfile.close(); // closing the file//
  		menu(2); // calling the menu function//
		cin>>choice; // taking the choice from the user//
	}
	if(choice==3)
	{	/*LOGIC
		*	1. Ask for filename
		*	2. Open file with filename
		*	3. Read file
		*	4. Close file
		*/
		text="";
		cout<<endl<<"Enter name of file: ";
		cin>>filename;		
		fstream myfile;
		myfile.open((filename+".txt").c_str());			
		while(getline(myfile, text)) { // getline is used to read the file line by line//
         cout << text << "\n"; // printing the text//
      	}
      	myfile.close();
      	char now; // declaring a variable whose purpose is to pause the screen//
		cout<<endl<<"End of File. Press any key for main menu: ";
		cin>>now;		
		menu(2);		
		cin>>choice;
	}
	if(choice==4)
	{	/*LOGIC
		*	1. Ask for filename
		*	2. Open file with filename
		*	3. Empty file
		*	4. Close file
		*/
		cout<<endl<<"Enter name of file: ";
		cin>>filename;		
		ofstream myfile;
		myfile.open((filename+".txt").c_str());	
		myfile<<"";
  		myfile.close();
		menu(4);		
		cin>>choice;
	}
	if(choice==5)
	{	/*LOGIC
		*	1. Ask for filename
		*	2. Delete file with filename
		*/
		cout<<endl<<"Enter name of file: ";
		cin>>filename;		
		if (remove((filename+".txt").c_str())==0)
		{
			menu(5);		    	
		}		
		else
		{
			menu(55);	
		}		    
	}
	if(choice==6)
	{	/*LOGIC
		*	1. Ask for filename to copy from
		*	2. Open file with filename to copy from
		*	3. Read file
		*	4. Close file
		*	5. Ask for filename to copy to
		*	6. Open file with filename to copy to
		*	7. Write to file
		*	8. Close file
		*/
		text="";
		cout<<endl<<"Enter name of file to copy from: ";		
		cin.ignore();
		getline(cin, filename);		
		fstream myfile( (filename+".txt").c_str() );
		string line;
		while(getline(myfile, line)){
         text += line+"\n";
      	}
		myfile.close();
		cout<<endl<<"Enter name of file to copy to: ";		
		string second;
		getline(cin, second);
		ofstream myfile2;
		myfile2.open((second+".txt").c_str(),ios::app);					
		myfile2<<text;
  		myfile2.close();
		menu(6);		
		cin>>choice;
	}
	if(choice==7)
	{	undo(filename); // calling the undo function//
		cin>>choice;
		menu(7);		
	}
	if(choice==8)
	{	redo(filename); // calling the redo function//
		cin>>choice;
		menu(8);		
	}
	if(choice==9)
	{
		exit(0);
	}
	
}

int main()
{
	menu(0);		
	return 0;
}

