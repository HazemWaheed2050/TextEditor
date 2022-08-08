#include "TextEditorHeader.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string DisplayChoices(){
    set <string> choices = {"1","2","3","4","5","6","7","8","9",
                            "10","11","12","13","14","15","16"};
    string choice;
    do{
        cout << "\t\n *** Ahlan ya User Choose What You Want ! *** \n";
        cout << "1. Add new text to the end of the file \n"
                "2. Display the content of the file\n"
                "3. Empty the file\n"
                "4. Encrypt the file content \n"
                "5. Decrypt the file content\n"
                "6. Merge another file\n"
                "7. Count the number of words in the file.\n"
                "8. Count the number of characters in the file\n"
                "9. Count the number of lines in the file\n"
                "10. Search for a word in the file\n"
                "11. Count the number of times a word exists in the file\n"
                "12. Turn the file content to upper case.\n"
                "13. Turn the file content to lower case.\n"
                "14. Turn file content to 1st caps (1st char of each word is capital) \n"
                "15. Save\n"
                "16. Exit\n";
        cout << "Please Enter Your Choice ==> ";
        cin >> choice;
        if(!choices.count(choice))
            cout<<"\t\n ** Invalid Choice Please Enter a Valid One ** \n";

    }while(!choices.count(choice));

    return choice;
}

void FileName() {
    fstream myFile;
    cout << "Enter file name: ";
    cin >> filename;
    strcat(filename, ".txt");
    myFile.open(filename);
    if (myFile) {
        cout << "File already exists" << endl;
    } else
        cout << "File " << filename << " does not exist. I created it for you :).\n\n";

}

void addText() {
    ofstream myFile;
    string userText;
    myFile.open(filename, ios::app);
    cout << "Enter the text you want to add at the end of the file finish it with an enter followed by CTRL + Z : "
         << endl;
    while (!cin.eof()) {
        getline(cin, userText);
        myFile << userText << endl;
    }
    myFile.close();
}

void display() {
    fstream myFile;
    string userText;
    myFile.open(filename, ios::in);
    while (myFile.peek() != EOF) {
        userText += myFile.get();
    }
    cout << userText;
}

void empty() {
    ofstream myFile;
    myFile.open(filename, ios::trunc);
    myFile.close();
    cout << "File cleared :) ." << endl;
}

void encrypt() {
    string lowerPlainAlphabet = "abcdefghijklmnopqrstuvwxyz", capitalPlainAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", cipherText, plainText;

    fstream myFile;
    myFile.open(filename, ios::in);
    while (myFile.peek() != EOF) {
        plainText += myFile.get();
    }

    for (int i = 0; i < plainText.length(); i++) {
        if (isalpha(plainText[i]) && islower(plainText[i])) {
            cipherText += lowerPlainAlphabet[25 - (plainText[i] - 'a')];
        } else if (isalpha(plainText[i]) && isupper(plainText[i])) {
            cipherText += capitalPlainAlphabet[25 - (plainText[i] - 'A')];
        } else {
            cipherText += plainText[i];
        }
    }
    myFile.close();

    myFile.open(filename, ios::out);
    myFile << cipherText << endl;
}

void decrypt() {
    // decryption is using the same algorithm as decryption
    encrypt();
}


void merge(string name) {
    string filename2;
    fstream myFile, myFile2;
    cout << "Enter second file's name: ";
    cin >> filename2;
    myFile2.open(filename2, ios::in);
    if (myFile2.is_open()) {
        myFile.open(name, ios::app);
        string line;
        while (getline(myFile2, line)) {
            myFile << line << endl;
        }
        myFile.close();
        myFile2.close();
        cout << "Files merged\n\n";
    } else {
        cout << "Invalid file name\n";
    }
}

void wordNo() {
    fstream myFile;
    string word;
    int count = 0;
    char ch;
    myFile.open(filename, ios::in);
    if (myFile.is_open()) {
        while (!myFile.eof()) {
            ch = myFile.get();
            if (myFile.peek() != EOF && ch != ' ') {
                myFile >> word;
                count++;
            }
        }

        cout << "There are (" << count << ") words in the file\n\n";
    }

}

void charNo() {
    fstream myFile;
    char ch;
    int count = 0;
    myFile.open(filename, ios::in);
    if (myFile.is_open()) {
        while (myFile >> skipws >> ch) {
            count++;
        }
        myFile.close();
        cout << "There are (" << count << ") characters in the file\n\n";
    }

}

int lineNo() {
    fstream myFile;
    string line;
    int count = 0;
    myFile.open(filename, ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            count++;
        }
        myFile.close();
    }
    return count;
}

void search() {
    fstream myFile;
    string word, fword;
    bool flag = false;
    cout << "Enter a word to find: ";
    cin >> word;                    // word to search for
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    lowerFile();                    // Make all the file in lower case
    myFile.open(filename, ios::in);
    while (!myFile.eof()){
        myFile>>fword;
        if(fword == word)
            flag = true;
    }
    myFile.close();
    if(!flag)
        cout<<"Word was not found \n";
    else
        cout<<"Word was found \n";

}

void CountWordFile() {
    ifstream inFile(filename);
    string certainWord, certainWordSmall, oneWord;
    int countWord = 0;
    multiset<string> words = {};
    cout << "Enter a word to search: ";
    cin >> certainWord;
    cout << "Word " << certainWord << " was found ";
    for (int i = 0; i < certainWord.size(); i++) {
        certainWordSmall += tolower(certainWord[i]);
    }
    while (!inFile.eof()) {
        inFile >> oneWord;
        certainWord = "";
        for (int i = 0; i < oneWord.size(); i++) {
            certainWord += tolower(oneWord[i]);
        }
        if (inFile.peek() != EOF) {
            if (certainWord == certainWordSmall) {
                words.emplace(certainWord);
            }
        }
    }
    countWord = words.count(certainWord);
    cout << countWord << " times" << endl;
}

void upperFile() {
    fstream inFile(filename, ios::in | ios::out);
    string text;
    while (inFile.peek() != EOF) {
        text += toupper(inFile.get());
    }
    inFile.clear();
    inFile.seekg(0);
    for (int i = 0; i < text.length(); i++) {
        inFile.put(text[i]);
    }
}


void lowerFile() {
    fstream inFile(filename, ios::in | ios::out);
    string text;
    while (inFile.peek() != EOF) {
        text += tolower(inFile.get());
    }
    inFile.clear();
    inFile.seekg(0);
    for (int i = 0; i < text.length(); i++) {
        inFile.put(text[i]);
    }
}

void firstCapsFile() {
    int counter = lineNo();
    fstream inFile(filename, ios::in);
    fstream outFile("testfile.txt", ios::out);
    string sentence, word;

    while (inFile.peek() != EOF) {
        for (int j = 0; j < counter; j++) {
            if (word != "")
                Title(word);
            outFile << word;
            word = "";
            if (j > 0)
                outFile << endl;
            getline(inFile, sentence, '\n');
            for (int i = 0; i < sentence.length(); i++) {
                if (sentence[i] == ' ') {
                    Title(word);
                    cout << word << endl;
                    outFile << word << " ";
                    word = "";
                } else
                    word += sentence[i];
            }
        }
    }
    if (word != "") {
        Title(word);
        cout << word << endl;
        outFile << word << " ";
    }
}

void saveFile() {
    cin.clear();
    cin.sync();
    string NameFile;
    cout << "Enter File Name To Save: ";
    getline(cin,NameFile);
    NameFile += ".txt";
    char name[100];
    strcpy(name,NameFile.c_str());
    rename(filename,name);
}

//__________________________________________________________

void CopyFile() {
    char ch;
    fstream outFile(filename, ios::out);
    fstream inFile("testfile.txt", ios::in);
    while (inFile.peek() != EOF) {
        inFile.get(ch);
        outFile.put(ch);
    }

}


void Title(string &word) {
    string titleWord;
    titleWord += toupper(word[0]);
    for (int i = 1; i < word.size(); i++) {
        titleWord += tolower(word[i]);
    }
    word = titleWord;

}
//_________________________________________________________________