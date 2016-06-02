//
//  main.cpp
//  FinalProject
//
//  Created by Hoa Dang on 12/5/15.
//  Copyright © 2015 Hoa Dang. All rights reserved.
//  The program read a cvs file into 2 dimensional array, calculate the average
//	sort it

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <iomanip>
using namespace std;

void sort(int grade[27][7]);
/*void findAvg(int grade[27][7]);
void findClassAvg(int array[27]); */
int grade[27][7]={};
float finalArray[28][9];
string name[28] = {"0","Harris","Leon", "Pete","Sam","Tenzin","Shabab","Zakia","Chen","Xiang","Mario","Lawren","Kyle","Violet","Mary","Paolo","Joseph","Bill","Mario B.","Stephen","Lorraine","Harry","Nicholas","Ivy","James","Kenneth","Manuel","Novak"};
string quiznumber[10] = {"name","Quiz 1","Quiz 2","Quiz 3","Quiz 4", "Quiz 5", "Quiz 6", "Quiz 7", "Quiz Average", "Class Average"};


int main()
{
    //input file
    ifstream file("Project_MAC101.csv");
    
    // fill array
    for(int row = 0; row < 27; ++row)
    {
        string line;
        getline(file, line);
        if ( !file.good() )
            break;
        
        stringstream iss(line);
        
        for (int col = 0; col < 7; ++col)
        {
            string val;
            getline(iss, val, ',');
            if ( !iss ) break;
            stringstream convertor(val);
            convertor >> grade[row][col];
        }
        
    }
//duplicate array:
    int tempArray[27][7] = {};
    for (int row = 0; row<27; row++) {
        for (int col=0; col<7; col++) {
            tempArray[row][col] = grade[row][col];
        }
    }
    cout << endl;
sort(tempArray);
//show current file
   /* for (int row=0; row<27; row++)
    {
        for (int col=0; col<7; col++)
        {
            cout<<tempArray[row][col];
            if (row!=27)//add commas when not at end of row
                cout<<" ";
        }
        cout<<endl;
    }*/
    
    //findAvg(tempArray);
    //FIND AVG OF ARRAY
    float avgarray[27] = {};
    float classAvgarr[27] = {};
    double rowSum = 0.0;
    double finalRowAvg = 0.0;
    double rowAvgSum = 0.0;
    double classAvg = 0.0;

    //FIND ROW AVG
    for(int m=0; m<28; m++)
    {
        for(int n=0; n<5; n++)
        {
            rowSum += tempArray[m][n];
        }
        avgarray[m] = finalRowAvg = rowSum/5;
        rowSum = 0.0; // reset row average for next row
        finalRowAvg = 0.0; // reset final average for next row
    }
    
    //FIND CLASS AVG
    for(int k=0;k<27;k++) {
        rowAvgSum += avgarray[k];}
    classAvg = rowAvgSum/27;
    /*cout << rowAvgSum <<" " << classAvg <<endl;*/
    
    for (int h=0; h<27;h++) {
        classAvgarr[h] = classAvg;
    }
    
    
    //FILL FINAL ARRAY
    for (int row = 0; row<28; row++) {
        for (int col=0; col<7; col++) {
            finalArray[row+1][col] = grade[row][col];
        }
    }

    for (int row = 0;row<28; row++) {
        for (int col=7;col<8;col++) {
            finalArray[row+1][col] = avgarray[row];
        }
    }
    
    for (int row = 0;row<28; row++) {
        for (int col=8;col<9;col++) {
            finalArray[row+1][col] = classAvgarr[row];
        }
    }
    
    //PRINT FINAL ARRAY (CHECK)
    /*for (int row=0; row<28; row++)
    {
        for (int col=0; col<9; col++)
        {
            cout<<finalArray[row][col];
            if (row!=28)
                cout<<" ";
        }
        cout<<endl;
    }*/

   
    ofstream(outFile);
    outFile.open("finaldata.csv");
    
    for (int row = 0; row<28; row++) {
        outFile<<quiznumber[row] << ",";}
    
    for (int row=0;row<28;row++) {
        outFile<<name[row] << ",";
        for (int col = 0; col<9; col++) {
            outFile<<finalArray[row][col] << ",";
        }
        outFile << endl;
    }
    outFile.close();
    return 0;
}


//*****SORT ARRAY FUNCTION*****
void sort(int grade[27][7])
{
    for(int row = 0; row < 27; row++)
    {
        for(int i=0;i<7;i++)
        {
            for(int j=i;j<7;j++)
            {
                if(grade[row][i]<grade[row][j])
                {
                    int temp=grade[row][i];
                    grade[row][i]=grade[row][j];
                    grade[row][j]=temp;
                }
            }
        }
    }
}



