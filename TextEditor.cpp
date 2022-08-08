// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: TextEditor.cpp
// Last Modification Date: 30/4/2022
// Author1 and ID and Group: Karim Mohamed Hassib 20210298
// Author2 and ID and Group: Hazem Mohamed Waheed 20210115
// Author3 and ID and Group: Mohamed Essam Mahmoud 20210346


#include "TextEditorlib.cpp"


int main() {
    FileName();
    int choice;
    bool cont = true;
    while(cont){
        cin.clear();
        cin.sync();
        choice = stoi(DisplayChoices());
        switch (choice) {
            case 1:
                addText();
                break;
            case 2:
                display();
                break;
            case 3:
                empty();
                break;
            case 4:
                encrypt();
                break;
            case 5:
                decrypt();
                break;
            case 6:
                merge(filename);
                break;
            case 7:
                wordNo();
                break;
            case 8:
                charNo();
                break;
            case 9:
                cout << "There are (" << lineNo() << ") lines in the file\n\n";
                break;
            case 10:
                search();
                break;
            case 11:
                CountWordFile();
                break;
            case 12:
                upperFile();
                break;
            case 13:
                lowerFile();
                break;
            case 14:
                firstCapsFile();
                CopyFile();
                break;
            case 15:
                saveFile();
                break;
            case 16:
                cont = false;
                cout << "Goodbye :)";
                break;
        }
    }
    cout<<"\t\n *** Thanks for Using FCAI Text Editor Application *** \n";
}
