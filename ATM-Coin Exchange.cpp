#include<iostream>

using namespace std;

//function that finds the minimum number of notes to give exchange
int minimum_notes(int* notes, int numberOfNotes, int value){

    //counter for number of notes in change
    int numberOfExchangeNotes=0;

    //if the exchange value is 0
    //return 0 number of notes
    if(value==0){
        return 0;
    }

    for(int i=0; i<numberOfNotes; i++){

        //if the current note is less than or equal to exchange value
        if(notes[i]<=value){

            //finds the exchange by recurring the minimum note function
            //And deducing current note value from exchange value
            int findExchange=minimum_notes(notes, numberOfNotes, value-notes[i]);

            //when there is some exchange value and not equal to 0
            //if the current number of exchange note+1 is less then total number of exchange notes
            if(findExchange!=0 && findExchange+1<numberOfExchangeNotes){

                //update total number of exchange note
                numberOfExchangeNotes=findExchange+1;
            }
        }
    }
    //returns number of exchange note
    return numberOfExchangeNotes;

    }

int main(){

    int *notes;
    int value;
    int numberOfNotes;

    cout<<"Enter number of Notes in your country: ";
    cin>>numberOfNotes;

    cout<<"Enter all note values in your country: ";

    notes=new int[numberOfNotes];
    //populate all notes available in country
    for(int i=0; i<=numberOfNotes-1; i++){
        cin>>notes[i];
    }

    cout<<"Enter your Exchange value: ";
    cin>>value;

    cout<<"Minimum number of Notes required: "<<minimum_notes(notes,numberOfNotes,value);

    //n=number of Notes available in country
    //Time Complexity = (n-1)+n
    //                = 2n-1




    return 0;
}
