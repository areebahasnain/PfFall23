// Programmer: Areeba Hasnain
// Description: code to reverse words in a string while keeping the order of the words using Dynamic memory allocation
// Date:21/11/23

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Function to reverse a word using pointers
void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start=start+1;
        end=end-1;
    }
}

// Function to reverse each word in a sentence using DMA
void reverseSentenceWords(char *sentence) {
    
	//both start and end pointers are initialized to the first address of the sentence
	char *start = sentence;
    char *end = sentence;
    //calculating the length of the sentence
    int length = strlen(sentence);

    // Reverse the entire sentence
    reverseWord(start, start + length - 1);//start+length-1 will take to the last location in the sentence

    // Traverse the reversed sentence
    while (*end) { 
        // Loop will run until a space or end of sentence is encountered
        if (*end == ' ' || *end == '\0') {
            reverseWord(start, end - 1);
            start = end + 1;
        }
        end=end+1;
    }
    
        reverseWord(sentence, sentence + length - 1);


}

int main() {
    
    int maxLength = 1000;
    //malloc has allocated memory for the array sentence on the heap
    char *sentence = (char *)malloc(maxLength* sizeof(char));

    if (sentence == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }
    

    // Prompt the user to enter a sentence
    printf("Enter a sentence:");
    fgets(sentence, maxLength, stdin);

    // Remove the newline character from the input
    sentence[strcspn(sentence, "\n")] = '\0';

    // Reverse each word in the sentence
    reverseSentenceWords(sentence);

    // Print the modified sentence
    printf("Modified sentence:%s\n", sentence);

    // Free dynamically allocated memory
    free(sentence);

    return 0;
}