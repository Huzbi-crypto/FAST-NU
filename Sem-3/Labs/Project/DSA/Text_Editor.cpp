// Title: Text Editor by using Stack Data Structure in C++
// Authors: Huzefa Saifuddin (22K-5125), Ijlal Iqbal (22K-5034), Ruhaan Ahmed (22K-6014)
// Last Modified: 4th December 2023

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<string> undoStack;
stack<string> redoStack;
stack<string> copyStack;
stack<string> pasteStack;
string filename;


/**
 * Undoes the last operation performed on the text file.
 * If the undo stack is empty, it displays a message "Nothing to Undo".
 * Otherwise, it pops the top element from the undo stack, pushes it onto the redo stack,
 * and clears the contents of the text file.
 *
 * @param filename The name of the text file to perform the undo operation on.
 */
void undo(string filename)
{
	if (undoStack.empty())
	{
		cout << "Nothing to Undo" << endl;
	}
	else
	{
		string temp = undoStack.top();
		undoStack.pop();
		redoStack.push(temp);

		ofstream myfile((filename + ".txt").c_str());
		myfile.close();
	}
}


/**
 * Performs the redo operation in the text editor.
 * If the redo stack is empty, it displays a message "Nothing to Redo".
 * Otherwise, it pops the top element from the redo stack, pushes it onto the undo stack,
 * and writes the content to the file with the given filename.
 *
 * @param filename The name of the file to write the content after redo operation.
 */
void redo(string filename)
{
	if (redoStack.empty())
	{
		cout << "Nothing to Redo" << endl;
	}
	else
	{
		string temp = redoStack.top();
		redoStack.pop();
		undoStack.push(temp);

		ofstream myfile((filename + ".txt").c_str());
		myfile << temp;
		myfile.close();
	}
}


/**
 * Copies the contents of a file into a stack.
 * 
 * @param filename The name of the file to be copied.
 */
void copyFile(string filename)
{
	fstream myfile((filename + ".txt").c_str());
	string line;
	while (getline(myfile, line))
	{
		copyStack.push(line);
	}
	myfile.close();
}


/**
 * Appends the contents of the copyStack to a file with the given filename.
 * 
 * @param filename The name of the file to paste the contents into.
 */
void pasteFile(string filename)
{
	ofstream myfile;
	myfile.open((filename + ".txt").c_str(), ios::app);
	while (!copyStack.empty())
	{
		myfile << copyStack.top() << "\n";
		copyStack.pop();
	}
	myfile.close();
}

/**
 * @brief Cuts the contents of a file and empties the file.
 * 
 * This function reads the contents of the specified file and stores them in a stack.
 * Then, it empties the file by opening it in write mode and writing an empty string.
 * 
 * @param filename The name of the file to be cut.
 */
void cutFile(string filename)
{
	ofstream myfile;
	// store the contents of the file in a stack
	fstream myfile2((filename + ".txt").c_str());
	string line;
	while (getline(myfile2, line))
	{
		copyStack.push(line);
	}
	myfile2.close();

	// empty the file
	myfile.open((filename + ".txt").c_str()); // Empty file
	myfile << "";
	myfile.close();
}

/**
 * Displays the menu options for the text editor and performs corresponding actions based on user input.
 * 
 * @param msg An integer representing the message code to display a specific message.
 *            0 - Welcome message
 *            1 - File created successfully message
 *            2 - File updated successfully message
 *            4 - File emptied successfully message
 *            5 - File deleted successfully message
 *            55 - File not found message
 *            6 - File copied successfully message
 */
void menu(int msg)
{
	system("CLS");
	if (msg == 0)
	{
		cout << "Welcome to Text Editor" << endl
			 << endl;
	}
	if (msg == 1)
	{
		cout << "File Created Successfully" << endl
			 << endl;
	}
	if (msg == 2)
	{
		cout << "File Updated Successfully" << endl
			 << endl;
	}
	if (msg == 4)
	{
		cout << "File Emptied Successfully" << endl
			 << endl;
	}
	if (msg == 5)
	{
		cout << "File Deleted Successfully" << endl
			 << endl;
	}
	if (msg == 55)
	{
		cout << "File Not Found" << endl
			 << endl;
	}
	if (msg == 6)
	{
		cout << "File Copied Successfully" << endl
			 << endl;
	}

	cout << "Main Menu" << endl;
	cout << "-------------" << endl;
	cout << "1. Create File" << endl;
	cout << "2. Add to File" << endl;
	cout << "3. Read from File" << endl;
	cout << "4. Empty File" << endl;
	cout << "5. Delete File" << endl;
	cout << "6. Copy File" << endl;
	cout << "7. Undo" << endl;
	cout << "8. Redo" << endl;
	cout << "9. Exit" << endl;
	cout << "10. Copy File" << endl;
	cout << "11. Paste File" << endl;
	cout << "12. Cut File" << endl
		 << endl;
	cout << "Enter Choice: ";

	int choice = 0;
	string text;

	cin >> choice;
	if (choice == 1)
	{
		cout << endl
			 << "Enter name of file: ";
		cin.ignore();
		getline(cin, filename);
		ofstream myfile((filename + ".txt").c_str());
		myfile.close();
		menu(1);
		cin >> choice;
	}
	if (choice == 2)
	{
		text = "";
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		cout << endl
			 << "Enter text to write to file: (Enter END to complete)" << endl;
		ofstream myfile;
		myfile.open((filename + ".txt").c_str(), ios::app);
		string line;
		cin.ignore();
		while (getline(cin, line))
		{
			if (line.size() >= 3)
			{
				if (line.substr(line.size() - 3) == "END")
				{
					text += line.substr(0, line.size() - 3);
					break;
				}
				else
				{
					text += line + "\n";
				}
			}
			else
			{
				text += line + "\n";
			}
		}
		myfile << text;
		undoStack.push(text);
		myfile.close();
		menu(2);
		cin >> choice;
	}
	if (choice == 3)
	{
		text = "";
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		fstream myfile;
		myfile.open((filename + ".txt").c_str());
		while (getline(myfile, text))
		{
			cout << text << "\n";
		}
		myfile.close();
		char now;
		cout << endl
			 << "End of File. Press any key for main menu: ";
		cin >> now;
		menu(2);
		cin >> choice;
	}
	if (choice == 4)
	{
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		ofstream myfile;
		myfile.open((filename + ".txt").c_str());
		myfile << "";
		myfile.close();
		menu(4);
		cin >> choice;
	}
	if (choice == 5)
	{
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		if (remove((filename + ".txt").c_str()) == 0)
		{
			menu(5);
		}
		else
		{
			menu(55);
		}
	}
	if (choice == 6)
	{
		text = "";
		cout << endl
			 << "Enter name of file to copy from: ";
		cin.ignore();
		getline(cin, filename);
		fstream myfile((filename + ".txt").c_str());
		string line;
		while (getline(myfile, line))
		{
			copyStack.push(line);
		}
		myfile.close();
		menu(6);
		cin >> choice;
	}
	if (choice == 7)
	{
		undo(filename);
		cin >> choice;
		menu(7);
	}
	if (choice == 8)
	{
		redo(filename);
		cin >> choice;
		menu(8);
	}
	if (choice == 9)
	{
		exit(0);
	}
	if (choice == 10)
	{
		cout << endl
			 << "Enter name of file to copy from: ";
		cin.ignore();
		getline(cin, filename);
		copyFile(filename);
		menu(6);
		cin >> choice;
	}
	if (choice == 11)
	{
		// ask for filename to paste to, if not given, paste to the same file
		string temp;
		temp = filename;
		cout << endl
			 << "Enter name of file to paste to: ";
		cin.ignore(); // to ignore the newline character
		getline(cin, filename);
		if (filename == "")
		{
			filename = temp;
		}
		pasteFile(filename);
		menu(6);
		cin >> choice;
	}
	if (choice == 12)
	{
		cutFile(filename);
		menu(4);
		cin >> choice;
	}
}

int main()
{
	menu(0);
	return 0;
}
