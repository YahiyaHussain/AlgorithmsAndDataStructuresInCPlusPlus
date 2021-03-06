#include <iostream>
#include <vector> 
#include<algorithm>

using namespace std;

enum SortDirection {Ascending, Descending};
vector<float> bubbleSort(vector<float>, SortDirection);
vector<float> swap(vector<float> numbers, int index1, int index2);
void printNumbers (vector<float> numbers);

int main() {
    cout << "Enter '[' and then numbers separated by spaces and then ']' and then press enter to see it sorted by Bubble Sort!\n";


    string rawInput;
    cin >> rawInput;

    vector<float> numbers;

    // we want inputs like this:  [ 1 2 3 ]
    if (rawInput == "[") {
        while (true) {
            cin >> rawInput;
            if (rawInput == "]") {
                cout << endl;
                break;
            }
            float value = stof(rawInput);
            
            numbers.push_back(value);
        }
    }
    else {
        cout << "Incorrect Input";
        return 0;
    }

    cout << "Ascending or Descending? Enter A/D" << endl;
    cin >> rawInput;

    if (rawInput == "A") {
        numbers = bubbleSort(numbers, Ascending);
    }
    else if (rawInput == "D") {
        numbers = bubbleSort(numbers, Descending);
    }
    else {
        cout << "Incorrect Input";
        return 0;
    }


    // passing by value to make things simple
    
    

    cout << "Result:" << endl;
    printNumbers(numbers);

    
    
    return 0;
}

vector<float> bubbleSort(vector<float> numbers, SortDirection direction) {
    
    //early breaking optimization
    bool didSwap;

    switch (direction) {
        case Ascending: 
            
            for (int i = 0; i < numbers.size() - 1; i++) {
                didSwap = false;
                cout << "Iteration: " << i << endl;
                for (int j = 0; j < numbers.size() - i - 1; j++) {
                    if (numbers[j] > numbers[j+1]) {
                        numbers = swap(numbers, j, j+1);
                        didSwap = true;
                    }
                    cout << "Step: " << j << endl;


                    printNumbers(numbers);
                }

                // a whole iteration without a swap means it is done
                if (!didSwap) {
                    break;
                }
                
            }
            break;
        case Descending:
            for (int i = 0; i < numbers.size() - 1; i++) {
                for (int j = 0; j < numbers.size() - i - 1; j++) {
                    if (numbers[j] < numbers[j+1]) {
                        numbers = swap(numbers, j, j+1);
                    }
                    printNumbers(numbers);
                }
                
            }
            break;
    }

    return numbers;
}

vector<float> swap(vector<float> numbers, int index1, int index2) {
    float f = numbers[index1];
    numbers[index1] = numbers[index2];
    numbers[index2] = f;
    return numbers;
}

void printNumbers (vector<float> numbers) {
    cout << "[ ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << "]" << endl;
}

