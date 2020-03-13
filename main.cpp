/*
MIT License

Copyright (c) 2019 Jimmy Lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* This program allows the user to press a button to record the date and time. It supports deletion of the last created
 * time and keeps track of how many date/time entries you have. The user may print at any time. Instructions for how to
 * use the program are outputted at the start of the program.
 *
 * Compile with C++11 standard. Usage of emplace_back(), auto, and a range-based for loop require C++11.
 *
 * Created by: Jimmy Lee
 * On: Nov 13, 2019
 *
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <string>
#include <csignal> // For some reason the program works even without this include header??

using namespace std;

vector<string> times; // Each element stores the date and time in the form "Weekday Month Day Hr:Min:Sec Year"
time_t curr_time;

void signal_handler(int sig_num)
{
    if(sig_num == SIGINT) // CTRL-C pressed
    {
        curr_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        times.emplace_back(ctime(&curr_time));
        cout<<"\nEntry added. Current entries: "<<times.size()<<endl<<endl;
        cout<<"Input> ";
        fflush(stdout); // The last cout is buffered in the stream, forces it to print by flushing the stream.
    }
    else if(sig_num == SIGTSTP) // CTRL-Z pressed
    {
        times.pop_back();
        cout<<"\nLast entry deleted. Current entries: "<<times.size()<<endl<<endl;
        cout<<"Input> ";
        fflush(stdout); // The last cout is buffered in the stream, forces it to print by flushing the stream.
    }
}

int main()
{
    int i;
    signal(SIGINT, signal_handler); // Link CTRL-C to handler
    signal(SIGTSTP, signal_handler); // Link CTRL-Z to handler
    //vector<string> times; // Each element stores the date and time in the form "Weekday Month Day Hr:Min:Sec Year"
    //time_t curr_time;

    cout<<"Press \"CTRL-C\" to create and add a time entry.\nPress \"CTRL-Z\" to delete the last created entry.\nEnter "
          "\"print\" to output all current stored times as well as how many have been stored.\nEnter \"r\" to show "
          "these instructions again.\nEnter \"exit\" to exit."<<endl<<endl;

    string input = " ";
    while(input != "exit") // Accept user input commands until "exit".
    {
        cout<<"Input> ";
        cin>>input;

        // The below commented code was replaced with the key signals for more ease and instantaneous data recording.
        // It can be uncommented to be used if the key signals don't work for whatever reason.

        /*if(input == "e") // Add date time entry.
        {
            curr_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
            times.emplace_back(ctime(&curr_time));
            cout<<"Entry added. Current entries: "<<times.size()<<endl<<endl;
        }
        else if(input == "d") // Delete last added entry.
        {
            times.pop_back();
            cout<<"Last entry deleted. Current entries: "<<times.size()<<endl<<endl;
        }
        else */
        if(input == "print") // Print all current entries and how many entries are currently present.
        {
            i = 1;
            for(auto & print : times)
            {
                cout<<i++<<": "<<print;
            }
            cout<<"Total entries: "<<times.size()<<endl<<endl;
        }
        else if(input == "r") // Print list of commands.
        {
            cout<<"Press \"CTRL-C\" to create and add a time entry.\nPress \"CTRL-Z\" to delete the last created entry."
                  "\nEnter \"print\" to output all current stored times as well as how many have been stored.\nEnter "
                  "\"r\" to show these instructions again.\nEnter \"exit\" to exit."<<endl<<endl;
        }
    }

    return 0;
}
