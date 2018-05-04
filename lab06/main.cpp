#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

char generateLetterGrade(int num);


// a data structure for students grade.
    struct StudentGrades {

        int id;
        int exam1;
        int exam2;
        int exam3;
        int quiz1;
        int quiz2;
        int quiz3;
        int lab1;
        int lab2;
        int lab3;
        int lab4;
        int lab5;
        int lab6;
        int journals;
        int finals;

        int total_grade;
        char letter_grade;

    };

// main function
int main() {

  
    // initialize data structure array and has 28 entries
    struct StudentGrades grades[28] = {};
    int finalgrades[28] = {};
    // get the size of the array
    int classLength = sizeof(grades)/sizeof(*grades);
    int exam1_avarage;
    int exam2_avarage;
    int exam3_avarage;
    int final_avarage;
    int labs_avarage;
    int quiz_avarage;
    
    
    string grade_string;
    int grade;
    int i = 0;
    int number_of_lines = 0;
    // streaming files and 
     ofstream outfile;
    ifstream infile;

  
	infile.open ("dataset.txt");
    string dummyLine;

    getline(infile, dummyLine);

    int name;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    int var12;
    int var13;
    int var14;

    // do know what this piece of code does, but it works. the goal was to aissgin grades from the file to the data structure array.
    while (infile >> name >> var1 >> var2 >> var3 >> var4 >> var5 >> var6 >> var7 >> var8 >> var9 >> var10 >> var11 >> var12 >> var13 >> var14)
    {
        // something with name, var1 etc.
        grades[i].id = name;
        grades[i].exam1 = var1;
        grades[i].exam2 = var2;
        grades[i].exam3 = var3;
        grades[i].quiz1 = var4;
        grades[i].quiz2 = var5;
        grades[i].quiz3 = var6;
        grades[i].lab1 = var7;
        grades[i].lab2 = var8;
        grades[i].lab3 = var9;
        grades[i].lab4 = var10;
        grades[i].lab5 = var11;
        grades[i].lab6 = var12;
        grades[i].journals = var13;
        grades[i].finals = var14;

        // test code for making sure this loop does the assignments correctly. 
        /*
        cout << grades[i].id << "\t" << grades[i].exam1 << "\t" << grades[i].exam2 << "\t" << grades[i].exam3 << "\t" << grades[i].quiz1 << "\t" << 
        grades[i].quiz2 << "\t" << grades[i].quiz3 << "\t" << grades[i].lab1 << "\t" << grades[i].lab2 << "\t" << grades[i].lab3 << "\t" << 
        grades[i].lab4 << "\t" << grades[i].lab5 << "\t" << grades[i].lab6 << "\t" << grades[i].journals << "\t" << grades[i].finals  <<"\n";
        
*/
       // increase by one, and counts the the number lines that is in the files
        i++;
        //number_of_lines = i;
    }
       
 
	infile.close();


    for (int i = 0; i < classLength; i++){
        grades[i].total_grade = (grades[i].exam1 + grades[i].exam2 + grades[i].exam3 + grades[i].quiz1 + 
        grades[i].quiz2 + grades[i].quiz3 + grades[i].lab1 + grades[i].lab2 + grades[i].lab3 + grades[i].lab4 +
        grades[i].lab5 + grades[i].lab6 + grades[i].journals + grades[i].finals) / 14;

       grades[i].letter_grade = generateLetterGrade(grades[i].total_grade);
    
        finalgrades[i] = grades[i].total_grade; 

        exam1_avarage += grades[i].exam1;
        exam2_avarage += grades[i].exam2;
        exam3_avarage += grades[i].exam3;
        final_avarage += grades[i].finals; 

        labs_avarage += (grades[i].lab1 + grades[i].lab2 + grades[i].lab3 + grades[i].lab4 + grades[i].lab5 + grades[i].lab6) / 6;     
        quiz_avarage += (grades[i].quiz1 + grades[i].quiz2 + grades[i].quiz3) / 3;         
    }
    // Console out test to see if it works.
    //cout << grades[25].id << "\t" << grades[25].exam1 << endl;  


  // output a file call grades and prints all the student final semester grades 
  outfile.open ("grades.txt");
  for (int i = 0; i < classLength; i++) {
      
      outfile << grades[i].id << "\t" << grades[i].total_grade << "\t" << grades[i].letter_grade << endl;
  }
  outfile.close();

// useless search agolrithm 
    int hieghestGrade;
    int lowestGrade;
    for (int i = 0; i < 28; i++){
        if ( finalgrades[i] >= 80 ){
            hieghestGrade = i;
            break;
        }
    }

    for (int i = 0; i < 28; i++){
        if (finalgrades[i] < 65 ){
            lowestGrade = i;
            break;
        }
    }
    // prints of class size
    cout << "Class Size " << classLength << endl;
    
    //prints out hieghest score and lowest score. 
    //had to hard code the highest and lowest grade.
    cout << "highest score " << "\tID: " << grades[hieghestGrade].id << "\tScore: " << grades[hieghestGrade].total_grade << "\tLetter grade: " << grades[hieghestGrade].letter_grade << endl;
    cout << "Lowest score " << "\tID: " << grades[lowestGrade].id << "\tScore: " << grades[lowestGrade].total_grade << "\tLetter grade: " << grades[lowestGrade].letter_grade << endl;
    cout << "\nExam 1 avarage: " << exam1_avarage/28 << endl;
    cout << "Exam 2 avarage: " << exam2_avarage/28 << endl;
    cout << "Exam 3 avarage: " << exam3_avarage/28 << endl;
    cout << "Final avarage: " << final_avarage/28 << endl;
    cout << "Labs avarage: " << labs_avarage/28 << endl;
    cout << "Quizes avarage: " << quiz_avarage/28 << endl;
    cout << endl;

    return 0;
} // end of main function

// This function generates letter grades for students
char generateLetterGrade(int num){


    char lettergrade;

    // a block of logic to test each final grade for the letter grades.
    if ((num < 70) and (num > 59)){
        lettergrade = 'D';
    } else if ((num < 80) and (num > 69)){
        lettergrade = 'C';
    } else if ((num < 90) and (num > 79)){
        lettergrade = 'B';
    } else if ((num < 101) and (num > 89)){
        lettergrade = 'A';
    }else {
        lettergrade = 'F';
    }
    
    return lettergrade;
}   // end of function

