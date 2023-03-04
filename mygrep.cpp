

#include <iostream>
#include <string>
#include<string.h>

#include<fstream>   //Library to collect data from another file


using namespace std;



int main(int argc, char* argv[])
{
    fstream f1;     // Variable to collect data from a file
    string str, str1;

    string line;

    if (argc == 1) {        // 1. increment - Search if string is in another string

    cout << "Give a string from which to search for: "; // User input for string where to search from
    getline(cin >> ws, str);

    cout << "Give search string: "; // User input for search
    getline(cin >> ws, str1);

    size_t found = str.find(str1);
    
    if (found != string::npos) {        // Find search string position
    cout << endl << "\"" << str1 << "\" found in \"" << str << "\" in position " << found << endl;
    }

    else {                      //Error message if string is not found
        cout << endl << "\"" << str1 << "\" NOT found in \"" << str << "\""<< endl; 
    }
    }

    if (argc == 3){ // 2. Increment - Open file and search for a string from file and print line if found
    ifstream file;

    file.open(argv[2]);

    if (file.fail())            // Error message if file doesn't exist or is written wrong
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    while (getline(file, line)) {           // Read all the lines from the file and find matches
        if (line.find(argv[1]) != string::npos) {
            cout << line << endl;           //Print line
        }
    }
    }

    if (argc == 4){ // 3. Increment - Add commands to reveal line number, occurrences or both of strings that are searched.
    ifstream file;         
    int line_counter;
    if(strcmp(argv[1], "-olo") == 0)    // Add -olo command to reveal line number and occurrences of strings that are searched.
    {
        file.open(argv[3]);

        int n_count = 0;

        if (file.fail())                // Error message if file doesn't exist
        {
            cout << "File failed to open." << endl;
            return 1;
        }

        while (getline(file, line)) {
            line_counter++;             // Count line numbers
            if (line.find(argv[2]) != string::npos) {
                cout << line_counter << ":\t" << line << endl;
                n_count++;

            }

        }   // Show how many occurrences there are in the file with specific string
            cout << endl << "Occurrences of line containing \"" << argv[2] << "\": " << n_count;

        }
        
        
        else if (strcmp(argv[1], "-ol") == 0)   // Add -ol command to reveal line number of strings that are searched.
        {
        file.open(argv[3]);

        int n_count = 0;

        if (file.fail())                // Error message if file doesn't exist
        {
            cout << "File failed to open." << endl;
            return 1;
        }

        while (getline(file, line)) {
            line_counter++;             // Count line numbers
            if (line.find(argv[2]) != string::npos) {
                cout << line_counter << ":\t" << line << endl;
                n_count++;

            }

        } 
        

        

        }
        else if(strcmp(argv[1], "-oo") == 0)    // Add -oo command to reveal occurrences of strings that are searched.
        {
            file.open(argv[3]);

            int n_count = 0;

            if (file.fail())                // Error message if file doesn't exist
            {
                cout << "File failed to open." << endl;
                return 1;
            }

            while (getline(file, line)) {
                line_counter++;             // Count line numbers
                if (line.find(argv[2]) != string::npos) {
                    cout << line << endl;
                    n_count++;

                }

            }   // Show how many occurrences there are in the file with specific string
                cout << endl << "Occurrences of line containing \"" << argv[2] << "\": " << n_count;

        }
        else {          // Error message if the command is written wrong or isn't any of the options
            cout << "Error. Command not found!";
        }
    }



    return 0;
}