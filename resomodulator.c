#include <stdio.h>
#include <math.h>

// Defining variables for configuration
int width = 950; // Set width of your terminal
int height = 80; // Set height of every line
int amplitude_0 = 2; // Amplitude of signal 0
int amplitude_1 = 8; // Amplitude of signal 1
char matrix[80][100000]; // Also put height here and put width very big
char filename[] = "sinusoid.txt"; // Filename where will be saved sinusoid

// Defining variables for using in functions
int data_length;
int binary_code[8];

// Function for converting char to binary and returning array of bits
int* char_to_binary(int ch) {
    int code = ch;
    int whole_part;
    int index = 7;
    int reminder;
    while (code >= 1) {
        reminder = code % 2;
        code = code / 2;
        binary_code[index] = reminder;
        index--;
    }
    return binary_code;
}

// Function for configuring matrix, i.e., making matrix with default chars
void configure_matrix(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < 100000; j++){
            matrix[i][j] = ' ';
        } 
    }
}

// Function for displaying matrix
void print_matrix(){
    for (int line = 0; line <= data_length*8*height; line+=width ){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                printf("%c", matrix[i][line+j]);
            } 
            printf("\n"); 
        }
        printf("\n"); 
    }
}

// Function for saving matrix
char matrix_str[1000000];
void save_matrix(){
    int char_index = 0;
    for (int i = 0; i < 79; i++){
        for (int j = 0; j < 3000; j++){
            matrix_str[char_index] =  matrix[i][j];
            char_index++;
        } 
        matrix_str[char_index] =  '\n';
        char_index++;
    }
    int size = sizeof(matrix_str);
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
    }
    fwrite(matrix_str, 1, size, fp);
    fclose(fp);
}

// Function for adding sinus to matrix
int sinus_index = 0;
void add_sinus(int value){
    float a = 0.1f;
    int amplitude;
    for (a = 0; a<= 6.28; a+=0.08){
        if (value == 1){
            amplitude = (height/2)+(height*amplitude_1/20)*sinf(a);
        }
        else{
            amplitude = (height/2)+(height*amplitude_0/20)*sinf(a);
        }
        matrix[amplitude][sinus_index] ='W';
        sinus_index ++;
    }
}

// Function that converts text to binary
int binary_text[10000000];

int* text_to_binary(char *text) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    int binary[length];
    int ascii_code;
    int* binary_codes;
    int index = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        ascii_code = text[i];
        binary_codes = char_to_binary(text[i]);
        for (int j = 0; j < 8; j++) {
            add_sinus(binary_codes[j]);
            binary_text[index] = binary_codes[j];
            index++;
        }
    }
    return binary_text;
}

// Main function for running
int main() {
    // Saving user input data as char list
    char* data;
    printf("Enter a string: ");
    scanf("%s%n", data, &data_length);
    
    // Configuring matrix
    configure_matrix();
    
    // Making text to binary
    text_to_binary(data);
    
    // Printing and saving matrix
    print_matrix();
    save_matrix();
    
    printf("\n\n Powered by RESONANCE")
    return 0;
}
