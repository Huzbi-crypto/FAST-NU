// Title: Text Editor by using Stack Data Structure in C++
// Authors: Huzefa Saifuddin (22K-5125), Ijlal Iqbal (22K-5034), Ruhaan Ahmed (22K-6014)
// Last Modified: 4th December 2023

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Stack.h"
// #include <stack>

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
	if (undoStack.isEmpty())
	{
		cout << "Nothing to Undo" << endl;
	}
	else
	{
		string temp = undoStack.topElement();
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
	if (redoStack.isEmpty())
	{
		cout << "Nothing to Redo" << endl;
	}
	else
	{
		string temp = redoStack.topElement();
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
	while (!copyStack.isEmpty())
	{
		myfile << copyStack.topElement() << "\n";
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
	// This `if statement` is used to create a new file.
	{
		cout << endl
			 << "Enter name of file: ";
		cin.ignore();
		getline(cin, filename);
		ofstream myfile((filename + ".txt").c_str()); // Create file with given name. The .c_str() function converts the string to a character array.
		myfile.close();
		menu(1);
		cin >> choice;
	}
	if (choice == 2)
	// This `if statement` is used to add text to an existing file.
	{
		text = ""; // This variable is used to store the text to be written to the file.
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		cout << endl
			 << "Enter text to write to file: (Enter END to complete)" << endl;
		ofstream myfile; // This variable is used to write to the file.
		myfile.open((filename + ".txt").c_str(), ios::app); // Open the file in append mode.
		string line; // This variable is used to store the text entered by the user.
		cin.ignore(); // This is used to ignore the newline character.
		while (getline(cin, line))
		// This loop is used to read the text entered by the user.
		{
			if (line.size() >= 3)
			// This `if statement` is used to check if the user has entered the word "END" to indicate the end of the text.
			{
				if (line.substr(line.size() - 3) == "END")
				{
					text += line.substr(0, line.size() - 3);
					break;
				}
				else
				// If the user has not entered the word "END", the text is appended to the variable `text`.
				{
					text += line + "\n";
				}
			}
			else
			// If the user has not entered the word "END", the text is appended to the variable `text`.
			{
				text += line + "\n";
			}
		}
		myfile << text; // Write the text to the file.
		undoStack.push(text); // Push the text to the undo stack.
		myfile.close();
		menu(2);
		cin >> choice;
	}
	if (choice == 3)
	// This `if statement` is used to read the contents of a file.
	{
		text = ""; // This variable is used to store the text read from the file.
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		fstream myfile;
		myfile.open((filename + ".txt").c_str()); // Open the file in read mode. The .c_str() function converts the string to a character array.
		while (getline(myfile, text))
		// This loop is used to read the contents of the file line by line.
		{
			cout << text << "\n";
		}
		myfile.close();
		char now; // This variable is used to store the character entered by the user.
		cout << endl
			 << "End of File. Press any key for main menu: "; 
		cin >> now; // Read the character entered by the user.
		menu(2);
		cin >> choice;
	}
	if (choice == 4)
	// This `if statement` is used to empty the contents of a file.
	{
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		ofstream myfile; // This variable is used to write to the file.
		myfile.open((filename + ".txt").c_str()); // Open the file in write mode. The .c_str() function converts the string to a character array.
		myfile << ""; // Write an empty string to the file.
		myfile.close();
		menu(4);
		cin >> choice;
	}
	if (choice == 5)
	// This `if statement` is used to delete a file.
	{
		cout << endl
			 << "Enter name of file: ";
		cin >> filename;
		if (remove((filename + ".txt").c_str()) == 0) // The .c_str() function converts the string to a character array.
		// This `if statement` is used to check if the file was deleted successfully.
		{
			menu(5);
		}
		else
		// This `else statement` is used to display an error message if the file was not deleted successfully.
		{
			menu(55);
		}
	}
	if (choice == 6)
	// This `if statement` is used to copy the contents of a file.
	{
		text = "";
		cout << endl
			 << "Enter name of file to copy from: ";
		cin.ignore(); // to ignore the newline character
		getline(cin, filename); // read the filename
		fstream myfile((filename + ".txt").c_str()); // open the file in read mode
		string line; // to store the line read from the file
		while (getline(myfile, line))
		// This loop is used to read the contents of the file line by line.
		{
			copyStack.push(line); // push the line to the copy stack
		}
		myfile.close();
		menu(6);
		cin >> choice;
	}
	if (choice == 7)
	// This `if statement` is used to undo the last operation performed on the text file.
	{
		undo(filename); // call the undo function
		menu(7);
	}
	if (choice == 8)
	// This `if statement` is used to redo the last operation performed on the text file.
	{
		redo(filename); // call the redo function
		menu(8);
	}
	if (choice == 9)
	// This `if statement` is used to exit the program.
	{
		exit(0);
	}
	if (choice == 10)
	// This `if statement` is used to copy the contents of a file.
	{
		cout << endl
			 << "Enter name of file to copy from: ";
		cin.ignore(); // to ignore the newline character
		getline(cin, filename); // read the filename
		copyFile(filename); // call the copyFile function
		menu(6);
		cin >> choice;
	}
	if (choice == 11)
	// This `if statement` is used to paste the contents of a file.
	{
		// ask for filename to paste to, if not given, paste to the same file
		string temp;
		temp = filename;
		cout << endl
			 << "Enter name of file to paste to: ";
		cin.ignore(); // to ignore the newline character
		getline(cin, filename); // read the filename
		if (filename == "")
		// if the filename is not given, paste to the same file
		{
			filename = temp; // set the filename to the original filename
		}
		pasteFile(filename); // call the pasteFile function
		menu(6);
		cin >> choice;
	}
	if (choice == 12)
	// This `if statement` is used to cut the contents of a file.
	{
		cutFile(filename);
		menu(4);
		cin >> choice;
	}
}


/**
 * @brief The main function of the program.
 * 
 * @return int Returns 0 to indicate successful execution.
 */
int main()
{
	menu(0);
	return 0;
}
