#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>   
#include <fstream>

using namespace std;

int selectedOption = 0;
int choice = 0;
int i = 0;
int num_of_tickets = 0;
int num_of_stops[2] = {0};
int depart_mins[25] = {0};
int return_mins[25] = {0};
int total_mins[2] = {0};
string day_of_week;
string depart_stops_nm[25];
string return_stops_nm[25];

// My understanding is you wanted to print the SUMMARY but also be able to
// re-print it if the user chooses Menu Option 7. With this in mind see code 
// changes and comments I added. I also tried my best to not delete any of your
// original source code and I used comments instead.

// this code below is used to create a buffer for string streaming
// basically whatever you would usually send to cout in your TRIP SUMMARY
// we will send to this buffer instead
std::stringstream buffer;

// fn(buffer.str()) will print to the console output via cout
// but also save the string stream to a file.txt
// later on in your code when user chooses Menu Option 7, 
// we will open this file.txt and print its contents to the console
void fn(std::string output) {

    std::ofstream file("file.txt");

    std::cout << output;
    file << output;
    
    file.close();

}

int menu() 
{
    cout << "===========================================================" << endl;
    cout << "============== GREYHOUND BUS LINES SELECTION ==============" << endl;
    cout << "============= Program Created By: Joshua Ford =============" << endl;
    cout << "===========================================================" << endl;
    cout << "=====                  1. Exit                        =====" << endl;
    cout << "=====          2. See Complete Price List             =====" << endl;
    cout << "=====      3. New York to Detroit - ONE WAY           =====" << endl;
    cout << "=====      4. Detroit to New York - ONE WAY           =====" << endl;
    cout << "=====     5. New York to Detroit - ROUND TRIP         =====" << endl;
    cout << "=====     6. Detroit to New York - ROUND TRIP         =====" << endl;
    cout << "=====     7. Display Trip Summary Information         =====" << endl;
    cout << "===========================================================" << endl;
    cout << "=====      Enter Your Selection Below (1-7)           =====" << endl;
    cin >> choice;

    while (choice < 1 || choice > 7) 
    {
        cout << "===========================================================" << endl;
        cout << "                       You Entered " << choice << endl;
        cout << "=====          Which is an Invalid Selection.          =====" << endl;
        cout << "=====      Please enter a number between 1 and 7.     =====" << endl;
        cout << "===========================================================" << endl;
        cout << "=====        Enter Your Selection Below (1-7)         =====" << endl;
        cin >> choice;
    }

    return choice;
}

string depart_day() 
{
    int leave_day_num = 0;
    cout << "=====================================================================================" << endl;
    cout << "===== What Day of the Week are you Leaving?                                     =====" << endl;
    cout << "===== 0. Exit                                                                   =====" << endl;
    cout << "===== 1. Monday                                                                 =====" << endl;
    cout << "===== 2. Tuesday                                                                =====" << endl;
    cout << "===== 3. Wednesday                                                              =====" << endl;
    cout << "===== 4. Thursday                                                               =====" << endl;
    cout << "===== 5. Friday                                                                 =====" << endl;
    cout << "===== 6. Saturday                                                               =====" << endl;
    cout << "===== 7. Sunday                                                                 =====" << endl;
    cout << "=====================================================================================" << endl;
    cout << "===== Please Select your Departure Day (1-7) or (0)                            =====" << endl;
    cin >> leave_day_num;

    while (leave_day_num < 0 || leave_day_num > 7) 
    {
        cout << "===========================================================" << endl;
        cout << "                       You Entered " << leave_day_num << endl;
        cout << "=====          Which is an Invalid Selection.          =====" << endl;
        cout << "=====      Please enter a number between 0 and 7.     =====" << endl;
        cout << "===========================================================" << endl;
        cout << "=====           Enter Your Selection Below            =====" << endl;
        cin >> leave_day_num;
    }

    switch (leave_day_num) 
    {
        case 0: 
            return "";
        case 1: 
            return "Monday";
        case 2: 
            return "Tuesday";
        case 3: 
            return "Wednesday";
        case 4: 
            return "Thursday";
        case 5: 
            return "Friday";
        case 6: 
            return "Saturday";
        case 7: 
            return "Sunday";
    }

    return ""; 
}

string return_day() 
{
    int return_day_num = 0;
    cout << "=====================================================================================" << endl;
    cout << "===== What Day of the Week are you Returning?                                   =====" << endl;
    cout << "===== 0. Exit                                                                   =====" << endl;
    cout << "===== 1. Monday                                                                 =====" << endl;
    cout << "===== 2. Tuesday                                                                =====" << endl;
    cout << "===== 3. Wednesday                                                              =====" << endl;
    cout << "===== 4. Thursday                                                               =====" << endl;
    cout << "===== 5. Friday                                                                 =====" << endl;
    cout << "===== 6. Saturday                                                               =====" << endl;
    cout << "===== 7. Sunday                                                                 =====" << endl;
    cout << "=====================================================================================" << endl;
    cout << "===== Please Select your Returning Day (1-7) or (0)                             =====" << endl;
    cin >> return_day_num;

    while (return_day_num < 0 || return_day_num > 7) 
    {
        cout << "===========================================================" << endl;
        cout << "                       You Entered " << return_day_num << endl;
        cout << "=====          Which is an Invalid Selection.          =====" << endl;
        cout << "=====      Please enter a number between 0 and 7.     =====" << endl;
        cout << "===========================================================" << endl;
        cout << "=====           Enter Your Selection Below            =====" << endl;
        cin >> return_day_num;
    }

    switch (return_day_num) 
    {
        case 0: 
            return "";
        case 1: 
            return "Monday";
        case 2: 
            return "Tuesday";
        case 3: 
            return "Wednesday";
        case 4: 
            return "Thursday";
        case 5: 
            return "Friday";
        case 6: 
            return "Saturday";
        case 7: 
            return "Sunday";
    }

    return ""; 
}
   
int main() 
{
    double trip_at = 0;
    double total_trip_at = 0;
    int total_whours[2] = {0};
    int total_wmins[2] = {0};
    string trip_name[2];
    string trip_type;
    string dur_tm[2];
    string leave_dt[2];
    string depart_day_str;
    string return_day_str;
    string depart_city[2];
    string arrive_city[2];
    string arrive_dt[2];
    string arrive_day[2];
    char confirmation;
    
    // handle initial state for Menu Option 7
    // e.g. if user hasn't made any reservations but selects Option 7
    // basically just create file.txt and write a message 
    std::ofstream file("file.txt");
    file << "No Reservations Found" << endl; // message
    file.close();
    

    selectedOption = menu();
    

    while (selectedOption > 0) 
    {
        switch (selectedOption) 
        {
    case 1:
            if (choice == 1)
            {
                cout << "Thank you for considering Greyhound Bus Lines - Hope to see you soon" << endl;
                return 0;
            }
    case 2:
                // Code for option 2
            if (choice == 2)
            {
                cout << "New York to Detroit - ONE WAY      : $190.31 per Person" << endl;
                cout << "Detroit to New York - ONE WAY      : $186.98 per Person" << endl;
                cout << "New York to Detroit - ROUND TRIP   : $424.73 per Person" << endl;
                cout << "Detroit to New York - ROUND TRIP   : $347.17 per Person" << endl;
                selectedOption = menu();
            }
    case 3:
                // Code for option 3
            if (choice == 3)
            {
                
    depart_stops_nm[0] = "NY Gw Bridge";
    depart_stops_nm[1] = "Newark(NJ)";
    depart_mins[1] = 10;
    depart_stops_nm[2] = "Philadelphia Bus Station";
    depart_mins[2] = 10;
    depart_stops_nm[3] = "Baltimore Downtown";
    depart_mins[3] = 0;
    depart_stops_nm[4] = "Pittsburgh Intermodal Station";
    depart_mins[4] = 71;
    depart_stops_nm[5] = "Youngstown Mercer Bus Stop";
    depart_mins[5] = 10;
    depart_stops_nm[6] = "Akron Bus Station";
    depart_mins[6] = 5;
    depart_stops_nm[7] = "Cleveland Bus Station";
    depart_mins[7] = 0;
    depart_stops_nm[8] = "Toledo Bus Station";
    depart_mins[8] = 10;
    depart_stops_nm[9] = "Detroit Bus Station";
    for (i = 0; i < 9; ++i) 
        { 
            total_mins[0] += depart_mins[i];
        }

                
                
                cout << "=====           You have selected the New York to Detroit - ONE WAY             =====" << endl;
                cout << "=====                       The Cost is $190.31 per Person                      =====" << endl;
                cout << "=====                      The Bus Leaves from NY Gw Bridge                     =====" << endl;
                cout << "=====                     The Bus Arrives at Detroit Station                    =====" << endl;
                num_of_stops[0] = 9;
                trip_type = "ONE WAY";
                trip_at = 190.31;
                leave_dt[0] = "07/28/23";
                arrive_dt[0] = "07/29/23";
                dur_tm[0] = "19:00";
                depart_city[0] = "New York";
                arrive_city[0] = "Detroit";
                trip_name[0] = "New York to Detroit - ONE WAY";
                depart_day_str = depart_day();
                if (depart_day_str.empty()) 
                {
                    cout << "Thank you for considering Greyhound Bus Lines - Hope to see you soon" << endl;
                    return 0;
                }
                cout << "How many tickets do you need? ";
                cin >> num_of_tickets;
                cout << "You are purchasing " << num_of_tickets << " tickets and are leaving on " << depart_day_str << endl;
                cout << "Before printing your ticket, has all the information you given been correct?" << endl;
                cout << "=====                      (Y for Yes | N for No)                      =====" << endl;
                cout << "=====      (Keep in mind answering N will allow you to start over)     =====" << endl;
                
                cin >> confirmation;
                if (confirmation == 'N' || confirmation == 'n') 
                {
                    cout << "========================================" << endl;
                    cout << "Please Wait While I Restart Your Booking" << endl;
                    cout << "Restarting Trip Booking................." << endl;
                    cout << "========================================" << endl;
                    selectedOption = menu();
                }
                if (confirmation == 'Y' || confirmation == 'y')
                {
                    total_whours[0] = total_mins[0]/60;
                    total_wmins[0] = total_mins[0]-(total_whours[0]*60);
                    total_trip_at = trip_at * num_of_tickets;
                    
                    buffer.str(std::string()); // clear stream buffer THIS IS IMPORTANT (e.g. start with empty buffer)
                    // cout << "=================================================================================================="<<endl;
                    buffer << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    buffer << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    buffer << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                        //  << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                        //  << resetiosflags(ios::right)<< endl;
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                         << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    buffer << endl;
                    // cout << "=================================================================================================="<<endl;
                    buffer << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    buffer << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[0] << endl;
                    // cout << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[0] << endl;
                    buffer << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    
                    fn(buffer.str()); // cout the buffer but also save to file so it can be retrieved for Option 7
                    selectedOption = menu();
                }
            }
    case 4:     
            if (choice == 4)
            {
                
    depart_stops_nm[0] = "Detroit Bus Station";
    depart_stops_nm[1] = "Toledo Bus Station";
    depart_mins[1] = 10;
    depart_stops_nm[2] = "Cleveland Bus Station";
    depart_mins[2] = 60;
    depart_stops_nm[3] = "Pittsburgh Intermodal Station";
    depart_mins[3] = 0;
    depart_stops_nm[4] = "Harrisburg Bus Station";
    depart_mins[4] = 10;
    depart_stops_nm[5] = "Newark(NJ)";
    depart_mins[5] = 0;
    depart_stops_nm[6] = "NY Gw Bridge";
    for (i = 0; i < 6; ++i) 
        { 
            total_mins[0] += depart_mins[i];
        }

                
                
                cout << "=====           You have selected the Detroit to New York - ONE WAY             =====" << endl;
                cout << "=====                       The Cost is $196.76 per Person                      =====" << endl;
                cout << "=====                    The Bus Leaves from Detroit Station                    =====" << endl;
                cout << "=====                      The Bus Arrives at NY Gw Bridge                      =====" << endl;
                num_of_stops[0] = 6;
                trip_type = "ONE WAY";
                trip_at = 196.76;
                leave_dt[0] = "07/28/23";
                arrive_dt[0] = "07/29/23";
                dur_tm[0] = "15:35";
                depart_city[0] = "Detroit";
                arrive_city[0] = "New York";
                trip_name[0] = "Detroit to New York - ONE WAY";
                depart_day_str = depart_day();
                if (depart_day_str.empty()) 
                {
                    cout << "Thank you for considering Greyhound Bus Lines - Hope to see you soon" << endl;
                    return 0;
                }
                cout << "How many tickets do you need? ";
                cin >> num_of_tickets;
                cout << "You are purchasing " << num_of_tickets << " tickets and are leaving on " << depart_day_str << endl;
                cout << "Before printing your ticket, has all the information you given been correct?" << endl;
                cout << "=====                      (Y for Yes | N for No)                      =====" << endl;
                cout << "=====      (Keep in mind answering N will allow you to start over)     =====" << endl;
                
                cin >> confirmation;
                if (confirmation == 'N' || confirmation == 'n') 
                {
                    cout << "========================================" << endl;
                    cout << "Please Wait While I Restart Your Booking" << endl;
                    cout << "Restarting Trip Booking................." << endl;
                    cout << "========================================" << endl;
                    selectedOption = menu();
                }
                if (confirmation == 'Y' || confirmation == 'y')
                {
                    total_whours[0] = total_mins[0]/60;
                    total_wmins[0] = total_mins[0]-(total_whours[0]*60);
                    total_trip_at = trip_at * num_of_tickets;
                    
                    // cout << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                    //      << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                    //      << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[0] << endl;
                    // cout << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    
                    buffer.str(std::string()); // clear stream buffer THIS IS IMPORTANT (e.g. start with empty buffer)
                    buffer << "=================================================================================================="<<endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                         << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    buffer << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::left) << setprecision(2);
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[0] << endl;
                    buffer << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    fn(buffer.str()); // cout the buffer but also save to file so it can be retrieved for Option 7
                    selectedOption = menu();
                    // return 0;
                }
            }
    case 5:     
            if (choice == 5)
            {
                
    depart_stops_nm[0] = "NY Gw Bridge";
    depart_stops_nm[1] = "Newark(NJ)";
    depart_mins[1] = 10;
    depart_stops_nm[2] = "Philadelphia Bus Station";
    depart_mins[2] = 10;
    depart_stops_nm[3] = "Baltimore Downtown";
    depart_mins[3] = 0;
    depart_stops_nm[4] = "Pittsburgh Intermodal Station";
    depart_mins[4] = 71;
    depart_stops_nm[5] = "Youngstown Mercer Bus Stop";
    depart_mins[5] = 10;
    depart_stops_nm[6] = "Akron Bus Station";
    depart_mins[6] = 5;
    depart_stops_nm[7] = "Cleveland Bus Station";
    depart_mins[7] = 0;
    depart_stops_nm[8] = "Toledo Bus Station";
    depart_mins[8] = 10;
    depart_stops_nm[9] = "Detroit Bus Station";
    for (i = 0; i < 9; ++i) 
        { 
            total_mins[0] += depart_mins[i];
        }
        
    return_stops_nm[0] = "Detroit Bus Station";
    return_stops_nm[1] = "Toledo Bus Station";
    return_mins[1] = 10;
    return_stops_nm[2] = "Cleveland Bus Station";
    return_mins[2] = 60;
    return_stops_nm[3] = "Pittsburgh Intermodal Station";
    return_mins[3] = 0;
    return_stops_nm[4] = "Harrisburg Bus Station";
    return_mins[4] = 10;
    return_stops_nm[5] = "Newark(NJ)";
    return_mins[5] = 0;
    return_stops_nm[6] = "NY Gw Bridge";
    for (i = 0; i < 6; ++i) 
        { 
            total_mins[1] += return_mins[i];
        }
                
                
                
                cout << "=====           You have selected the New York to Detroit - ROUND TRIP          =====" << endl;
                cout << "=====                       The Cost is $323.87 per Person                      =====" << endl;
                cout << "=====                      The Bus Leaves from NY Gw Bridge                     =====" << endl;
                cout << "=====                     The Bus Arrives at Detroit Station                    =====" << endl;
                cout << "=====                        Then on Your Returning Trip                        =====" << endl;;
                cout << "=====                     The Bus Leaves from Detroit Station                   =====" << endl;
                cout << "=====                       The Bus Arrives at NY Gw Bridge                     =====" << endl;
                num_of_stops[0] = 10;
                num_of_stops[1] = 7;
                trip_type = "ROUND TRIP";
                trip_at = 323.87;
                leave_dt[0] = "07/28/23";
                arrive_dt[0] = "07/29/23";
                leave_dt[1] = "08/04/23";
                arrive_dt[1] = "08/05/23";
                dur_tm[0] = "19:00";
                dur_tm[1] = "15:35";
                depart_city[0] = "New York";
                arrive_city[0] = "Detroit";
                depart_city[1] = "Detroit";
                arrive_city[1] = "New York";
                trip_name[0] = "New York to Detroit - ROUND TRIP";
                depart_day_str = depart_day();
                return_day_str = return_day();
                if (depart_day_str.empty()) 
                {
                    cout << "Thank you for considering Greyhound Bus Lines - Hope to see you soon" << endl;
                    return 0;
                }
                cout << "How many tickets do you need? ";
                cin >> num_of_tickets;
                cout << "You are purchasing " << num_of_tickets << " tickets and are leaving on " << depart_day_str << endl;
                cout << "Before printing your ticket, has all the information you given been correct?" << endl;
                cout << "=====                      (Y for Yes | N for No)                      =====" << endl;
                cout << "=====      (Keep in mind answering N will allow you to start over)     =====" << endl;
                cin >> confirmation;
                if (confirmation == 'N' || confirmation == 'n') 
                {
                    cout << "========================================" << endl;
                    cout << "Please Wait While I Restart Your Booking" << endl;
                    cout << "Restarting Trip Booking................." << endl;
                    cout << "========================================" << endl;
                }
                if (confirmation == 'Y' || confirmation == 'y')
                {
                    total_whours[0] = total_mins[0]/60;
                    total_wmins[0] = total_mins[0]-(total_whours[0]*60);
                    total_whours[1] = total_mins[1]/60;
                    total_wmins[1] = total_mins[1]-(total_whours[1]*60);
                    total_trip_at = trip_at * num_of_tickets;
                    
                    // cout << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                    //      << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                    //      << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[0] << endl;
                    // cout << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "========================================" << endl;
                    // cout << "Please Wait While I Print Your Second ==" << endl;
                    // cout << "Trip Booking......................... ==" << endl;
                    // cout << "========================================" << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[1] << setw(16) << arrive_city[1] << setw(16) << return_day_str << setw(9)
                    //      << leave_dt[1] << setw(15) << setiosflags(ios::right) << arrive_dt[1] << setw(14) << total_trip_at << endl 
                    //      << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< return_stops_nm[0] <<  " and waits for "<< return_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[1] <<  " and waits for "<< return_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[2] <<  " and waits for "<< return_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[3] <<  " and waits for "<< return_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[4] <<  " and waits for "<< return_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[5] <<  " and waits for "<< return_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[6] <<  " and waits for "<< return_mins[6] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[1] << endl;
                    // cout << "Total Wait Time: " << total_whours[1] << " hours and " << total_wmins[1] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    
                    buffer.str(std::string()); // clear stream buffer THIS IS IMPORTANT (e.g. start with empty buffer)
                    buffer << "=================================================================================================="<<endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                         << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    buffer << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::left) << setprecision(2);
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[0] << endl;
                    buffer << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "========================================" << endl;
                    buffer << "Please Wait While I Print Your Second ==" << endl;
                    buffer << "Trip Booking......................... ==" << endl;
                    buffer << "========================================" << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[1] << setw(16) << arrive_city[1] << setw(16) << return_day_str << setw(9)
                         << leave_dt[1] << setw(15) << setiosflags(ios::right) << arrive_dt[1] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    buffer << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::left) << setprecision(2);
                    buffer << "Stops at " << setw(50)<< return_stops_nm[0] <<  " and waits for "<< return_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[1] <<  " and waits for "<< return_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[2] <<  " and waits for "<< return_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[3] <<  " and waits for "<< return_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[4] <<  " and waits for "<< return_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[5] <<  " and waits for "<< return_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[6] <<  " and waits for "<< return_mins[6] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[1] << endl;
                    buffer << "Total Wait Time: " << total_whours[1] << " hours and " << total_wmins[1] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    fn(buffer.str()); // cout the buffer but also save to file so it can be retrieved for Option 7
                    selectedOption = menu();
                    // return 0;
                }
            }
    case 6: 
            if (choice == 6)
            {
                
    depart_stops_nm[0] = "NY Gw Bridge";
    depart_stops_nm[1] = "Newark(NJ)";
    depart_mins[1] = 10;
    depart_stops_nm[2] = "Philadelphia Bus Station";
    depart_mins[2] = 10;
    depart_stops_nm[3] = "Baltimore Downtown";
    depart_mins[3] = 0;
    depart_stops_nm[4] = "Pittsburgh Intermodal Station";
    depart_mins[4] = 71;
    depart_stops_nm[5] = "Youngstown Mercer Bus Stop";
    depart_mins[5] = 10;
    depart_stops_nm[6] = "Akron Bus Station";
    depart_mins[6] = 5;
    depart_stops_nm[7] = "Cleveland Bus Station";
    depart_mins[7] = 0;
    depart_stops_nm[8] = "Toledo Bus Station";
    depart_mins[8] = 10;
    depart_stops_nm[9] = "Detroit Bus Station";
    for (i = 0; i < 9; ++i) 
        { 
            total_mins[0] += depart_mins[i];
        }
        
    return_stops_nm[0] = "Detroit Bus Station";
    return_stops_nm[1] = "Toledo Bus Station";
    return_mins[1] = 10;
    return_stops_nm[2] = "Cleveland Bus Station";
    return_mins[2] = 60;
    return_stops_nm[3] = "Pittsburgh Intermodal Station";
    return_mins[3] = 0;
    return_stops_nm[4] = "Harrisburg Bus Station";
    return_mins[4] = 10;
    return_stops_nm[5] = "Newark(NJ)";
    return_mins[5] = 0;
    return_stops_nm[6] = "NY Gw Bridge";
    for (i = 0; i < 6; ++i) 
        { 
            total_mins[1] += return_mins[i];
        }
                
                
                
                cout << "=====           You have selected the Detroit to New York - ROUND TRIP          =====" << endl;
                cout << "=====                       The Cost is $323.87 per Person                      =====" << endl;
                cout << "=====                    The Bus Leaves from Detroit Station                    =====" << endl;
                cout << "=====                       The Bus Arrives at NY Gw Bridge                     =====" << endl;
                cout << "=====                        Then on Your Returning Trip                        =====" << endl;;
                cout << "=====                      The Bus Leaves from NY Gw Bridge                     =====" << endl;
                cout << "=====                     The Bus Arrives at Detroit Station                    =====" << endl;
                num_of_stops[0] = 10;
                num_of_stops[1] = 7;
                trip_type = "ROUND TRIP";
                trip_at = 323.87;
                leave_dt[0] = "07/28/23";
                arrive_dt[0] = "07/29/23";
                leave_dt[1] = "08/04/23";
                arrive_dt[1] = "08/05/23";
                dur_tm[0] = "19:00";
                dur_tm[1] = "15:35";
                depart_city[0] = "Detroit";
                arrive_city[0] = "New York";
                depart_city[1] = "New York";
                arrive_city[1] = "Detroit";
                trip_name[0] = "Detroit to New York - ROUND TRIP";
                depart_day_str = depart_day();
                return_day_str = return_day();
                if (depart_day_str.empty()) 
                {
                    cout << "Thank you for considering Greyhound Bus Lines - Hope to see you soon" << endl;
                    return 0;
                }
                cout << "How many tickets do you need? ";
                cin >> num_of_tickets;
                cout << "You are purchasing " << num_of_tickets << " tickets and are leaving on " << depart_day_str << endl;
                cout << "Before printing your ticket, has all the information you given been correct?" << endl;
                cout << "=====                      (Y for Yes | N for No)                      =====" << endl;
                cout << "=====      (Keep in mind answering N will allow you to start over)     =====" << endl;
                cin >> confirmation;
                if (confirmation == 'N' || confirmation == 'n') 
                {
                    cout << "========================================" << endl;
                    cout << "Please Wait While I Restart Your Booking" << endl;
                    cout << "Restarting Trip Booking................." << endl;
                    cout << "========================================" << endl;
                }
                if (confirmation == 'Y' || confirmation == 'y')
                {
                    total_whours[0] = total_mins[0]/60;
                    total_wmins[0] = total_mins[0]-(total_whours[0]*60);
                    total_whours[1] = total_mins[1]/60;
                    total_wmins[1] = total_mins[1]-(total_whours[1]*60);
                    total_trip_at = trip_at * num_of_tickets;

    
                    // cout << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                    //      << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                    //      << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[0] << endl;
                    // cout << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "========================================" << endl;
                    // cout << "Please Wait While I Print Your Second ==" << endl;
                    // cout << "Trip Booking......................... ==" << endl;
                    // cout << "========================================" << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    // cout << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::fixed) << setprecision(2);
                    // cout << setw(16) << setiosflags(ios::left) << depart_city[1] << setw(16) << arrive_city[1] << setw(16) << return_day_str << setw(9)
                    //      << leave_dt[1] << setw(15) << setiosflags(ios::right) << arrive_dt[1] << setw(14) << total_trip_at << endl 
                    //      << resetiosflags(ios::right)<< endl;
                    // cout << endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << setiosflags(ios::left) << setprecision(2);
                    // cout << "Stops at " << setw(50)<< return_stops_nm[0] <<  " and waits for "<< return_mins[0] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[1] <<  " and waits for "<< return_mins[1] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[2] <<  " and waits for "<< return_mins[2] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[3] <<  " and waits for "<< return_mins[3] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[4] <<  " and waits for "<< return_mins[4] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[5] <<  " and waits for "<< return_mins[5] << " minutes."<< endl;
                    // cout << "Stops at " << setw(50)<< return_stops_nm[6] <<  " and waits for "<< return_mins[6] << " minutes."<< endl;
                    // cout << "=================================================================================================="<<endl;
                    // cout << "Total Trip Time: " << dur_tm[1] << endl;
                    // cout << "Total Wait Time: " << total_whours[1] << " hours and " << total_wmins[1] << " minutes" << endl;
                    // cout << "=================================================================================================="<<endl;
                    
                    buffer.str(std::string()); // clear stream buffer THIS IS IMPORTANT (e.g. start with empty buffer)
                    buffer << "=================================================================================================="<<endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[0] << setw(16) << arrive_city[0] << setw(16) << depart_day_str << setw(9)
                         << leave_dt[0] << setw(15) << setiosflags(ios::right) << arrive_dt[0] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    buffer << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::left) << setprecision(2);
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[0] <<  " and waits for "<< depart_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[1] <<  " and waits for "<< depart_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[2] <<  " and waits for "<< depart_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[3] <<  " and waits for "<< depart_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[4] <<  " and waits for "<< depart_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[5] <<  " and waits for "<< depart_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[6] <<  " and waits for "<< depart_mins[6] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[7] <<  " and waits for "<< depart_mins[7] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[8] <<  " and waits for "<< depart_mins[8] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< depart_stops_nm[9] <<  " and waits for "<< depart_mins[9] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[0] << endl;
                    buffer << "Total Wait Time: " << total_whours[0] << " hours and " << total_wmins[0] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "========================================" << endl;
                    buffer << "Please Wait While I Print Your Second ==" << endl;
                    buffer << "Trip Booking......................... ==" << endl;
                    buffer << "========================================" << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "============================ GREYHOUND BUS LINES TRIP SUMMARY ===================================="<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Departing\tReturning\t  Day of\t Date of\tDate of\t\tTotal"<<endl;
                    buffer << "  From \t\t  From\t\tDeparture\tDeparture\tArrival\t\tCost"<<endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::fixed) << setprecision(2);
                    buffer << setw(16) << setiosflags(ios::left) << depart_city[1] << setw(16) << arrive_city[1] << setw(16) << return_day_str << setw(9)
                         << leave_dt[1] << setw(15) << setiosflags(ios::right) << arrive_dt[1] << setw(14) << total_trip_at << endl 
                         << resetiosflags(ios::right)<< endl;
                    buffer << endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << setiosflags(ios::left) << setprecision(2);
                    buffer << "Stops at " << setw(50)<< return_stops_nm[0] <<  " and waits for "<< return_mins[0] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[1] <<  " and waits for "<< return_mins[1] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[2] <<  " and waits for "<< return_mins[2] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[3] <<  " and waits for "<< return_mins[3] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[4] <<  " and waits for "<< return_mins[4] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[5] <<  " and waits for "<< return_mins[5] << " minutes."<< endl;
                    buffer << "Stops at " << setw(50)<< return_stops_nm[6] <<  " and waits for "<< return_mins[6] << " minutes."<< endl;
                    buffer << "=================================================================================================="<<endl;
                    buffer << "Total Trip Time: " << dur_tm[1] << endl;
                    buffer << "Total Wait Time: " << total_whours[1] << " hours and " << total_wmins[1] << " minutes" << endl;
                    buffer << "=================================================================================================="<<endl;
                    fn(buffer.str()); // cout the buffer but also save to file so it can be retrieved for Option 7
                    selectedOption = menu();
                    // return 0;
    
                }
            }
    case 7:
        if (choice == 7)
        {
            
            // This code here opens file.txt and prints the contents to console
            std::ifstream f("file.txt");
            if (f.is_open())
                std::cout << f.rdbuf();
            f.close();
            /////////////////////////////////
            
            selectedOption = menu();
        }
            
        }
    }
        return 0;
}






