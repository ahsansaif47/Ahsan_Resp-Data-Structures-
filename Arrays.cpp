#include<iostream>

using namespace std;

int array[10];
int si = 10;
int s = -1;
int e = -1;

int isEmpty(){
    if (s == -1 && e == -1){
        return 1;
    } return 0;
}

int isFull(){
    if(e == si-1 && s == 0){
        return 1;
    } else if(e == s-1){
        return 1;
    } return 0;
}

void insert(int data){
    if(isEmpty()){
        s++;
        array[++e] = data;
    } else if(isFull()){
        cout << "Array is full.." << endl;
        if(e < s){
            s = 0;
            e = si-1;
        }
    } else{
        if(s != 0 && e == si-1){
            e == 0;
            array[e++] = data;
        } else if(e < si-1){
            array[++e] = data;
        }
    }
}

void printArray(){
    for(int i=s; i<e; i++){
        cout << array[i] << "-->";
    }
    cout << endl;
}

void dFirst(){
    if(s < si)
        array[s++] = 0;
}

void dLast(){
    if(e > -1){
        array[e--] = 0;
    }
}

void del(int ind){
    if(ind == 0){
        dFirst();
    } else if(ind == si-1){
        dLast();
    } else{
        for(int i=ind; i<e; i++){
            array[i] = array[i+1];
        }
        array[e--] = 0;
    }
}

int main(){
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    printArray();
    return 0;
}