// File: A1_T1_S14_20231106.cpp
// Purpose: A program that offers multiple functionalities and allows the user to select which one to run
// Author: Abdulwhab Essam Mohamed
// ID: 20231106
// Date: 12 Oct 2024
// The program contains several independent functions like splitting a string, printing numbers in binary, etc.
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Function 1: Split a string by a delimiter
vector<string> split(string target, string delimiter)
{
    vector<string> result;
    size_t pos = 0;
    string token;
    while ((pos = target.find(delimiter)) != string::npos)
    {
        token = target.substr(0, pos);
        result.push_back(token);
        target.erase(0, pos + delimiter.length());
    }
    result.push_back(target);
    return result;
}

// Function 2: Print a number in binary
void binaryPrint(int n)
{
    if (n == 0)
    {
        cout << "0";
        return;
    }

    if (n > 1)
    {
        binaryPrint(n / 2);
    }

    cout << (n % 2);
}

// Function 3: Generate binary numbers of length k with a given prefix
void numbers(string prefix, int k)
{
    if (k == 0)
    {
        cout << prefix << endl;
        return;
    }

    numbers(prefix + "0", k - 1);
    numbers(prefix + "1", k - 1);
}

// Function 4: Bear game logic
bool bearGame(int n)
{
    if (n == 42)
        return true;

    if (n < 42)
        return false;

    if (n % 2 == 0 && bearGame(n / 2))
        return true;

    if (n % 3 == 0 || n % 4 == 0)
    {
        int lastTwoDigits = (n % 10) * ((n / 10) % 10);
        if (lastTwoDigits > 0 && bearGame(n - lastTwoDigits))
            return true;
    }

    if (n % 5 == 0 && bearGame(n - 42))
        return true;

    return false;
}

// Function 5: Phishing scanner
bool phishingScanner(const string &emailContent)
{
    vector<string> phishingKeywords = {"password", "credit card", "social security", "bank",
                                       "phishing", "account", "login", "urgent", "verify", 
                                       "click here", "secure", "update", "financial", 
                                       "fraud", "limited time", "immediately", "claim", 
                                       "confirm", "id number", "transaction", "free", 
                                       "offer", "gift", "win", "prize"};

    for (const string &keyword : phishingKeywords)
    {
        if (emailContent.find(keyword) != string::npos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int choice;
    do {
        cout << "Select a program to run:" << endl;
        cout << "1. Split string by delimiter" << endl;
        cout << "2. Print number in binary" << endl;
        cout << "3. Generate binary numbers with prefix" << endl;
        cout << "4. Bear game" << endl;
        cout << "5. Phishing scanner" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string str, delimiter;
            cout << "Enter the string to split: ";
            cin.ignore();
            getline(cin, str);
            cout << "Enter the delimiter: ";
            getline(cin, delimiter);
            vector<string> result = split(str, delimiter);
            cout << "Result: [";
            for (size_t i = 0; i < result.size(); i++)
            {
                cout << "'" << result[i] << "'";
                if (i != result.size() - 1) 
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
            break;
        }

        case 2:
        {
            int num;
            cout << "Enter a number to convert to binary: ";
            cin >> num;
            binaryPrint(num);
            cout << endl;
            break;
        }

        case 3:
        {
            string prefix;
            int k;
            cout << "Enter a prefix: ";
            cin >> prefix;
            cout << "Enter the length of binary numbers: ";
            cin >> k;
            numbers(prefix, k);
            break;
        }

        case 4:
        {
            int n;
            do
            {
                cout << "Enter the number of bears: ";
                cin >> n;

                if (bearGame(n))
                {
                    cout << "bear(" << n << ") is true" << endl;
                }
                else
                {
                    cout << "bear(" << n << ") is false. Try again." << endl;
                }
            } while (!bearGame(n));  // The loop will continue until a valid number is entered
            break;
        }

        case 5:
        {
            string emailContent;
            cout << "Enter the email content: ";
            cin.ignore(); 
            getline(cin, emailContent);

            if (phishingScanner(emailContent))
            {
                cout << "Warning: This email may be a phishing attempt." << endl;
            }
            else
            {
                cout << "This email appears to be safe." << endl;
            }
            break;
        }

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please select between 1 and 6." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}