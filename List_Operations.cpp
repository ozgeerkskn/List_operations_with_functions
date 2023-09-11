#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
void display_menu();
void handle_print(vector<int> &vec);
void handle_add(vector<int> &vec);
void handle_mean(vector<int> &vec);
void handle_smallest(vector<int> &vec);
void handle_largest(vector<int> &vec);
void handle_find(vector<int> &vec);
bool find(vector<int> &vec, int target);
void quit();
void select(char &selection);


void display_menu(char &selection){
        cout << endl;
        cout << "P - Print numbers " << endl;
        cout << "A - Add a number " << endl;
        cout << "M - Display mean of the numbers " << endl;
        cout << "S - Display the smallest number " << endl;
        cout << "L - Display the largest number " << endl;
        cout << "F - Find a number " << endl;
        cout << "Q - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> selection;
}
void select(char &selection, vector<int> &vec){
    
    char letter;
    letter = toupper(selection);
    
    cout << endl;
    switch(letter){
        case 'P':
        handle_print(vec);
        break;
        case 'A':
        handle_add(vec);
        break;
        case 'M':
        handle_mean(vec);
        break;
        case 'S':
        handle_smallest(vec);
        break;
        case 'L':
        handle_largest(vec);
        break;
        case 'F':
        handle_find(vec);
        break;
        case 'Q':
        quit();
        break;
        default:
            cout << "Unknowwn selection, try again." << endl;
        
    }
    
}

void handle_print(vector<int> &vec){
    if(vec.size() == 0){
        cout << "[] - list is empty." << endl;
    }else{
        cout << "[";
        for(auto num: vec){
            cout << " " << num << " ";
            }
        cout << "]";
    }
    }
void handle_add(vector<int> &vec){
    int num;
    cout << "Enter an integer to add to the list: ";
            cin >> num;
            vec.push_back(num);
            cout << num << " added." << endl;
}
void handle_mean(vector<int> &vec){
    int sum{0};
    if(vec.size() == 0){
        cout << "Unable to calculate the mean - no data "<< endl;
    }else{
        for(auto k:vec){
        sum += k;
    }
    cout << "Average of the elements is " << static_cast<double>(sum) / vec.size() << endl;
    }
    
}
void handle_smallest(vector<int> &vec){
    int min = vec.at(0);
    if(vec.size() == 0){
        cout << "Unable to determine the smallest number - list is empty " << endl;
    }else{
        for(auto k: vec){
        if(k < min){
            min = k;
        }
        
    }
    cout << "The smallest number is " << min << endl;
    
    
}
}
void handle_largest(vector<int> &vec){
    int max = vec.at(0);
    if(vec.size() == 0){
        cout << "Unable to determine the smallest number - list is empty " << endl;
    }
    else {
        for(auto k : vec) {
            if(k > max){
                max = k;
                
            }
            
        }
         cout << "The largest number is " << max << endl;
    }
}
void handle_find(vector<int> &vec){
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;
    if(find(vec, target))
        cout << target << " was found." << endl; 
    else 
            cout << target << " was not found." << endl;
            
           
}
bool find(vector<int> &vec, int target){
     for(auto num:vec){
        if(num == target)
            return true;
     return false;        
    }
}   
void quit(){
    cout << "Goodbye..." << endl;
}

int main() {
char selection;
vector<int> vec{}; 
 
    do{
        display_menu(selection);
        select(selection, vec);
    }while(selection != 'Q' && selection != 'q');
    return 0;
    
}