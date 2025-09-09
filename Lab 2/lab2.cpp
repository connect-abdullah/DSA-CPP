// Lab Activity 3

// #include <iostream>

// using namespace std;

// void swap(int arr[], int i, int j) {
//     int t = arr[i]; // for example if arr[1] (which is i) which is 2, it is stored in t
//     arr[i] = arr[j]; // now, if the j is [3] which is 5 in real array, it will swap [1] = [3] which means on the place of 2, 5 will come and on the place of 5, 2 will come.
//     arr[j] = t ;// new result will be 1,5,4,2,1 which was 1,2,4,5,1 before
// }

// void display(int arr[], int size) {
//     for(int i = 0; i < size; i++) {
//         cout << arr[i];
//         if (i != size - 1) {
//             cout << ", ";
//         }
//     }
//     cout << endl;
// }

// int main(){

//     int arr[5] = {1,2,4,5,1};
//     display(arr,5);
//     swap(arr,1,3);
//     display(arr,5);
//     return 0;
// }



// Lab Activity 4
// #include <iostream>

// using namespace std;

// int max_size = 5;
// int position = 0;

// void insert(int arr[], int value) {
//     if(position < max_size) {
//         arr[position++] = value; // at which position to add value, also incrementing it after adding to that index
//     } 
// }

// void display(int arr[], int size) {
//     for(int i = 0; i < size; i++) {
//         cout << arr[i];
//         if (i != size - 1) {
//             cout << ", ";
//         }
//     }
//     cout << endl;
// }

// int main(){

//     int arr[max_size]; // Initializing with the max_size given

//     for( int i = 0; i < max_size; i++){
//         int x;
//         cout << "Enter the number: ";
//         cin >> x;
//         insert(arr,x);
//     }
//     display(arr, max_size);
//     return 0;
// }



// Lab Activity 5
// #include <iostream>

// using namespace std;

// const int max_size = 5;
// int position = 0;

// void insert(int arr[], int value) {
//     if(position < max_size) {
//         arr[position++] = value; // at which position to add value, also incrementing it after adding to that index
//     } 
// }

// void remove(int arr[], int index) { // Index to delete
//     if(index < position) { // for example position is 5, so it check everytime that given index is less than 5, like 2 < 5. At [2] we have 3 number.
    
//         for(int j = index; j < position ; j++) { // so it will run until index == position. Like for [2] which is 3 in array, 4 will come bcz its j+1 so [2]=[3] --> 3 = 4.
//             // For [2], it will start from 3 in array {1,2,3,4,5}. 3 will become 4, 4 will become 5.
//             arr[j] = arr[j+1]; // at position [1] comes the numbers which is at [2]
//         }

//         position--; // it will decrement the position, so that the position 5 become equal to 2 because index given is 2.
//     } else if (index > position) {
//         cout << "Wrong Index";
//     }
// }

// void display(int arr[], int size) {
//     for(int i = 0; i < size; i++) {
//         cout << arr[i];
//         if (i != size - 1) {
//             cout << ", ";
//         }
//     }
//     cout << endl;
// }

// int main(){

//     int arr[max_size]; // Initializing with the max_size given

//     for( int i = 0; i < max_size; i++){
//         int x;
//         cout << "Enter the number: ";
//         cin >> x;
//         insert(arr,x);
//     }
//     display(arr, max_size);
//     cout << "Enter the index of number to remove: ";
//     int x;
//     cin >> x;
//     remove(arr,x);
//     display(arr, max_size-1);
//     return 0;
// }



// Lab Activity 6
#include <iostream>

using namespace std;

const int max_size = 5;

struct ArrayList {
    int array[max_size];
    int position = 0;
};

void insert(ArrayList * List, int value) {
    if(List -> position < max_size) {
        List -> array[List->position++] = value; // at which position to add value, also incrementing it after adding to that index
    } 
}

void remove(ArrayList * List, int index) { // Index to delete
    if(index < List -> position) { // for example position is 5, so it check everytime that given index is less than 5, like 2 < 5. At [2] we have 3 number.
    
        for(int j = index; j < List -> position ; j++) { // so it will run until index == position. Like for [2] which is 3 in array, 4 will come bcz its j+1 so [2]=[3] --> 3 = 4.
            // For [2], it will start from 3 in array {1,2,3,4,5}. 3 will become 4, 4 will become 5.
            List -> array[j] = List -> array[j+1]; // at position [1] comes the numbers which is at [2]
        }

        List -> position--; // it will decrement the position, so that the position 5 become equal to 2 because index given is 2.
    } else if (index < 0 || index >= List->position) {
        cout << "Wrong Index\n";
        return;
    }
}

void display(ArrayList * List) {
    for(int i = 0; i < List -> position; i++) {
        cout << List -> array[i];
        if (i != List -> position - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main(){

    ArrayList A, B; // Initializing two arrays with the same structure

    // Insert values into A
    for(int i = 0; i < max_size; i++){
        int x;
        cout << "Enter the number for A: ";
        cin >> x;
        insert(&A, x);
    }

    // Insert values into B as A
    for(int i = 0; i < max_size; i++){
        int x;
        cout << "Enter the number for B: ";
        cin >> x;
        insert(&B, x);
    }

    display(&A);
    display(&B);

    cout << "Enter the index of number to remove from A: ";
    int x;
    cin >> x;
    remove(&A, x);
    display(&A);

    return 0;
}


// Lab Task 1
// #include <iostream>
// using namespace std;

// const int STUDENTS = 10;

// float computeAverage(int marks[], int size) {
//     int sum = 0;
//     for (int i = 0; i < size; i++) {
//         sum += marks[i];
//     }
//     return (float)sum / size;
// }

// int main() {
//     int marks[STUDENTS] = {12, 10, 15, 9, 14, 8, 11, 13, 7, 15};

//     cout << "Average marks: " << computeAverage(marks, STUDENTS) << endl;
//     return 0;
// }



// Lab Task 2
// #include <iostream>
// using namespace std;

// const int MAX_SIZE = 7;

// struct ArrayList {
//     float array[MAX_SIZE];
//     int size = 0;
// };

// void insert(ArrayList& list, float value) {
//     if (list.size < MAX_SIZE) {
//         list.array[list.size++] = value;
//     }
// }

// float findMax(const ArrayList& list) {
//     float maxVal = list.array[0];
//     for (int i = 1; i < list.size; i++) {
//         if (list.array[i] > maxVal) {
//             maxVal = list.array[i];
//         }
//     }
//     return maxVal;
// }

// int main() {
//     ArrayList temps;
//     float weekTemps[7] = {30.5, 32.2, 29.8, 35.0, 33.5, 31.0, 34.1};

//     for (int i = 0; i < 7; i++) {
//         insert(temps, weekTemps[i]);
//     }

//     cout << "Maximum temperature of the week: " << findMax(temps) << endl;
//     return 0;
// }

