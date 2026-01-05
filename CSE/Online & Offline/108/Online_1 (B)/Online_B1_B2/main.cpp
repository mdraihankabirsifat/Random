#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
 * ONLINE 1: FileHandler Class Implementation
 * ================================================
 * 
 * TASK: Implement the FileHandler class to work with the given main() function.
 * Study the main() function carefully to understand what methods and constructors 
 * your class needs to provide.
 * 
 * IMPORTANT RULES:
 * ---------------
 * DO NOT modify ANY code in the main() function
 * DO NOT modify ANY code outside the FileHandler class definition
 * ONLY implement code inside the FileHandler class
 * You may include other standard headers if needed
 *
 *
 * EFFICIENCY REQUIREMENT:
 * ----------------------
 * Your FileHandler object should open and close the file ONLY ONCE during its lifetime.
 * 
 * FILE OPERATIONS REFERENCE:
 * --------------------------
 * To open a file in WRITE mode (overwrites existing content):
 *     Option 1 - Direct initialization:
 *         ofstream fileStream(filename);
 *     
 *     Option 2 - Declare then open (useful when ofstream is a member variable):
 *         ofstream fileStream;           // declare the stream
 *         fileStream.open(filename);     // open the file
 * 
 * To write to an opened file:
 *     fileStream << "some text" << endl;
 * 
 * To close a file:
 *     fileStream.close();
 * 
 * Study the expected console output format shown in the main() function comments.
 * Your program's output MUST EXACTLY MATCH the Expected Console Output.
 *
 *
 * Submission Instructions:
 * ------------------------
 * - Implement the FileHandler class below
 * - Ensure your code compiles and runs correctly with the provided main() function
 * - Do not change any other part of the code
 * - Submit only this file for evaluation
 * - The name of the file should be [YourID].cpp
 * - No need to zip the file, submit the .cpp file directly 
 * 
 */

class FileHandler {

};

int main() {

    // EXPECTED CONTENT OF output1.txt:
    // --------------------------------
    // Starting log
    // temperature = 25C
    // humidity = 70%
    // System stable
    // voltage = 220V
    // --------------------------------

    FileHandler fh1("output1.txt");

    fh1.writeLine("Starting log");
    fh1.writeLine("temperature", "25C");
    fh1.writeLine("humidity", "70%");
    fh1.writeLine("System stable");
    fh1.writeLine("voltage", "220V");


    // EXPECTED CONTENT OF output2.txt:
    // --------------------------------
    // Device A
    // mode = ACTIVE
    // retries = 3
    // Connection OK
    // speed = 1Gbps
    // --------------------------------

    FileHandler fh2("output2.txt");

    fh2.writeLine("Device A");
    fh2.writeLine("mode", "ACTIVE");
    fh2.writeLine("retries", "3");
    fh2.writeLine("Connection OK");
    fh2.writeLine("speed", "1Gbps");

    return 0;
}
