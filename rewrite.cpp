#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#ifdef _WIN32
    // Windows-specific code
    void setConsoleWindowSize(int width, int height) {
        std::string command = "mode con: cols=" + std::to_string(width) + " lines=" + std::to_string(height);
        system(command.c_str());
    }
#elif __unix__
    // Linux/MacOS-specific code
    void setConsoleWindowSize(int width, int height) {
        std::string command = "resize -s " + std::to_string(height) + " " + std::to_string(width);
        system(command.c_str());
    }
#endif

void calculateToStacks(int& stackSize)
{
    int totalItems, stacks, leftover;

    cout<<"Enter the total number of items: ";
    cin>>totalItems;

    if(totalItems<stackSize){
        cout<<"Please enter a given that is greater than "<<stackSize<<"!\n";
    }

    stacks= floor(totalItems/stackSize);
    leftover= totalItems%stackSize;

    cout<<stacks<<" stack/s";
    if(leftover != 0){
        cout<<" and "<<leftover<<" item/s";
    }
    cout<<"\n";
}
void calculateToDecimal()
{
    int choice;
    int totalItems, stacks, leftover;

    cout<<"Enter how many stacks: ";
    cin>>stacks;
    cout<<"Enter leftover items: ";
    cin>>leftover;
    cout<<"What maximum stack size? (16 or 64)\n";
    cin>>choice;

    if(choice == 16 || choice == 64){
        cout<<"* The value you entered is invalid!\n\n";
        return;
    }

    totalItems= stacks*choice+leftover;
    cout<<"* Total of "<<totalItems<<" items.\n\n";
}
int main()
{
    setConsoleWindowSize(50, 30);
    int choice;

    do{
        cout<<"Pick a base number system: \n"
            <<"1. Base-16\n"
            <<"2. Base-64\n"
            <<"3. Decimal\n"
            <<"4. Exit\n";
        cin>>choice;

        switch(choice){
            int stackSize;
            case 1:  // 16
                stackSize = 16;
                calculateToStacks(stackSize);
                break;
            case 2:  // 64
                stackSize = 64;
                calculateToStacks(stackSize);
                break;
            case 3:  // decimal
                calculateToDecimal;
                break;
            case 4:  // exit
                system("pause");
                break;
            default:
                cout<<"The value you entered is invalid!\n";
                break;
        }
        cout<<"\n";
    }while(choice != 4);
    
    return 0;
}