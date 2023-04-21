#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_MENU 45;
#define TOTAL_SUBMENU


void print_menuI(FILE* file, int* desired_line_num, int size) {
    static int counter = 0;
    char line[150];
    
    int line_num = 0;
    if (counter == 0) {
        FILE* output_file = fopen("output.txt", "w"); // open the output file for appending
    }
   
    FILE* output_file = fopen("output.txt", "a"); // open the output file for appending
    
    counter++;
    rewind(file); // move file pointer to the beginning of the file
    while (fgets(line, sizeof(line), file)) {
        line_num++;
        for (int i = 0; i < size; i++) {
            if (line_num == desired_line_num[i]) {
                // remove newline character from line
                line[strcspn(line, "\n")] = '\0';
                // write the line to the output file
                fprintf(output_file, "%s\n", line);
                // print the line to stdout
                printf("%s\n", line);
                break; // exit the loop after printing a desired line
            }
        }
    }
    fclose(output_file); // close the output file
}

void menuPrintUser(int menu, char title[]) {
    int subMenu = menu / 3;
    printf("\n"); //spacer
    printf("%s (%d Total Items)\n", title, menu);
    printf("- %d Vegan Items\n", subMenu);
    printf("- %d Vegetarian Items\n", subMenu);
    printf("- %d Non Vegan / Vegetarian Items\n", subMenu);
    printf("\n"); //spacer
}

void postMenuPrintUser(int menu, char title[], int vegan, int vegetarian, int meat) {
    printf("What Values The User Selected!\n");
    int subMenu = vegan + vegetarian + meat;
    printf("\n"); //spacer
    printf("%s (%d Total Items Used)\n", title, subMenu);
    printf("- %d Vegan Items\n", vegan);
    printf("- %d Vegetarian Items\n", vegetarian);
    printf("- %d Non Vegan / Vegetarian Items\n", meat);
    printf("\n"); //spacer
}

void printTextMenu(int line_num[], int menu[]) {
    int index = 1;
    line_num[0] = 1; //printing the title for BREAKFAST menu!!
    for (int i = 0; i < 3; i++) { // loop through each integer in B
        int start = i * 5 + 2; // calculate the starting index for the current section
        for (int j = 0; j < menu[i]; j++) { // loop through each iteration for the current section
            line_num[index] = start + j; // add the current line to desired_line
            index++; // increment index to keep track of the next available index in desired_line
        }
    }

    // Set the remaining elements to -1
    for (int i = index; i < 16; i++) {
        line_num[i] = -1;
    }

}
void printUserInputVEGAN(char menu[]) {
    printf("Welcome to %s Menu Selection!!\n", menu);
    printf("Enter a Value from 0-5 for the corresponding Values!!\n");
    printf("Each value input corresponds to how many items are added to each CATEGORY !VEGAN is always atleast 1!\n");
    printf("IMPORTANT! if value is out of range! AUTO GENERATOR will overwrite user input!\n\n");
    printf("VEGAN: ");
};
void printUserInputVEGETARIAN() {
    printf("VEGETARIAN: ");
}
void printUserInputNEITHER() {
    printf("NEITHER: ");
}

void space() {
    printf("\n\n");
}
void spacerPrint() {
    printf("---------------------------------------------------------\n");
}

//void printRandom(int)

int main()
{
    //Used to calcuated how long the program takes to run
    clock_t start, end;
    double cpu_time_used;
   
    //Local Variables
    int breakfast[3];
    int bVegan = 0, bVegetarian = 0, bMeat = 0; //Saved for user input

    int lunch[3];
    int lVegan = 0, lVegetarian = 0, lMeat = 0; //Saved for user input 

    int dinner[3];
    int dVegan = 0, dVegetarian = 0, dMeat = 0; //Saved for user input
    int minBreak = 0;
    int minLunch = 0;
    int minDinner = 0;

    int rand_int;
    int random_num[3]; // used for random number replacment
    int num[5] = { 0 };
    int checker = 0; // used for user input ( DECIDE to print MENU or TERMINATE program)
   srand(time(NULL)); // random number gen with current time


  // FILE* file;
   FILE* file1;
   FILE* file2;
   FILE* file3;
   //char filename[] = "MenuSheet_Gx54522.txt";
   char filename1[] = "BreakFastMenu.txt";
   char filename2[] = "LunchMenu.txt";
   char filename3[] = "DinnerMenu.txt";
   int value;

   //Checking if files open
   file1 = fopen("BreakFastMenu.txt", "r");
   if (file1 == NULL) {
       printf("Failed to open file1\n");
       return 1;
   }

   file2 = fopen("LunchMenu.txt", "r");
   if (file2 == NULL) {
       printf("Failed to open file2\n");
       return 1;
   }

   file3 = fopen("DinnerMenu.txt", "r");
   if (file3 == NULL) {
       printf("Failed to open file3\n");
       return 1;
   }
    else {
        //Letting user know
        printf("\nSuccessfully opened file Named: %s,%s,%s\n\n", filename1,filename2,filename3);

        
       
        // main message
        printf("!Welcome to menu Generator!\n\n");
        int totalMENU = TOTAL_MENU;
        int lastRow;  // used for total number of Rows
        int lastCol;// used for total number of Col

        int maxMenu = totalMENU / 3; // 15 total B,L,D items
        int maxSubM = maxMenu / 3; // 5 total sub menu Vegan, Veg. , Meat

        char b[] = "BreakFast";
        char l[] = "Lunch";
        char d[] = "Dinner";

        char v[] = "Vegan";
        char veg[] = "Vegetarian";
        char m[] = "Neither";


        spacerPrint();
        menuPrintUser(maxMenu, b);
        menuPrintUser(maxMenu, l);
        menuPrintUser(maxMenu, d);
        spacerPrint();
        //-------------------------user input BREAKFAST


        printUserInputVEGAN(b);
        fflush(stdout);
        scanf("%d", &bVegan);
        breakfast[0] = bVegan;


        printUserInputVEGETARIAN();
        fflush(stdout);
        scanf("%d", &bVegetarian);
        breakfast[1] = bVegetarian;
        printUserInputNEITHER();
        fflush(stdout);
        scanf("%d", &bMeat);
        breakfast[2] = bMeat;
       
        spacerPrint();
        //-------------------------user input LUNCH
        printUserInputVEGAN(l);
        fflush(stdout);
        scanf("%d", &lVegan);
        lunch[0] = lVegan;
        printUserInputVEGETARIAN();
        fflush(stdout);
        scanf("%d", &lVegetarian);
        lunch[1] = lVegetarian;
        printUserInputNEITHER();
        fflush(stdout);
        scanf("%d", &lMeat);
        lunch[2] = lMeat;
        spacerPrint();
        //-------------------------user input DINNER
        printUserInputVEGAN(l);
        fflush(stdout);
        scanf("%d", &dVegan);
        dinner[0] = dVegan;
        printUserInputVEGETARIAN();
        fflush(stdout);
        scanf("%d", &dVegetarian);
        dinner[1] = dVegetarian;
        printUserInputNEITHER();
        fflush(stdout);
        scanf("%d", &dMeat);
        lunch[2] = dMeat;
        spacerPrint();
        //-------------------------End of user input


        for (int i = 0; i < 3; i++) {
            rand_int = rand() % 5 + 1;
            random_num[i] = rand_int;
           // printf("%d ", random_num[i]); // Print the generated number (used for Verification)
        }
        //safe way to change variables if INVALID INPUT, Or Nothing was added
        int counter = 0;
        while ((bVegan < 1 || bVegan > 4|| bVegetarian < 0 || bVegetarian >5 || bMeat < 0 ||bMeat >5)&& counter <1) {
            printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", b); //Breakfast Menu
            bVegan = random_num[0];
            bVegetarian = random_num[0];
            bMeat = random_num[0];
            breakfast[0] = bVegan;
            breakfast[1] = bVegetarian;
            breakfast[2] = bMeat;
            counter++;
        }
        //safe way to change variables if INVALID INPUT, Or Nothing was added
        counter = 0;
        while ((lVegan == 0 || lVegan > 4 || lVegetarian < 0 || lVegetarian > 5 || lMeat < 0 || lMeat > 5) && counter < 1) {
            printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", l);// lunch Menu
            lVegan = random_num[1];
            lVegetarian = random_num[1];
            lMeat = random_num[1];
            lunch[0] = lVegan;
            lunch[1] = lVegetarian;
            lunch[2] = lMeat;
            counter++;
        }
        //safe way to change variables if INVALID INPUT, Or Nothing was added
        counter = 0;
        while ((dVegan == 0 || dVegan > 4 || dVegetarian < 0 || dVegetarian > 5 || dMeat < 0 || dMeat > 5) && counter < 1) {
            printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", d); // dinner Menu
            dVegan = random_num[2];
            dVegetarian = random_num[2];
            dMeat = random_num[2];
            dinner[0] = dVegan;
            dinner[1] = dVegetarian;
            dinner[2] = dMeat;
            counter++;
        }

        postMenuPrintUser(maxMenu, b, bVegan, bVegetarian, bMeat);
        postMenuPrintUser(maxMenu, l, lVegan, lVegetarian, lMeat);
        postMenuPrintUser(maxMenu, d, dVegan, dVegetarian, dMeat);
        spacerPrint();



        //TEST PRINTING...
        char line[150];
        int line_num = 0;
        int desired_line_num1[16];
        int desired_line_num2[16];
        int desired_line_num3[16];

        
        /*
        // Print the contents of desired_line_num1
        for (int i = 0; i < 16; i++) {
            printf("Element %d: %d\n", i, desired_line_num1[i]);
        }
        */
        // calculates the lines from breakfast array to dessired_line_num1 corresponding to breakfast menu
        printTextMenu(desired_line_num1, breakfast); 

        // calculates the lines from lunch array to dessired_line_num1 corresponding to lunch menu
        printTextMenu(desired_line_num2, lunch);

        // calculates the lines from dinner array to dessired_line_num1 corresponding to dinner menu
        printTextMenu(desired_line_num3, dinner);

        printf("\n\nEnd Of user input!! is this input okay??\nif yes-1 no-0\n");
        printf("if Yes: your menu will be printed to the screen and text file named Output.txt\n");
        printf("if No or INVALID INPUT!: program will exit!\nINPUT: ");
        fflush(stdout);
        scanf("%d", &checker);
        if (checker != 1) {
            return 0;
        }
        else {
            start = clock(); // start timer
            spacerPrint();

            //if user accepts it. itll print to the screen then append to a txt file called "output.txt"
            print_menuI(file1, desired_line_num1, sizeof(desired_line_num1) / sizeof(desired_line_num1[0])); //Breakfast Menu
            space();
            print_menuI(file2, desired_line_num2, sizeof(desired_line_num2) / sizeof(desired_line_num2[0])); //Lunch Menu
            space();
            print_menuI(file3, desired_line_num3, sizeof(desired_line_num3) / sizeof(desired_line_num3[0])); //Dinner Menu

            spacerPrint();
            /*ORIGNINAL CONCEPT /FILE 
            *
            *  Lines for Reference
            * ----------------------
            *    Breakfast: 1
            *     -  Vegan: 2-6
            *     - Vegetarian: 7-11
            *     - Neither: 12-16
            * ----------------------
            *    Lunch:  17
            *     -  Vegan:  18-22
            *     - Vegetarian:  23-27
            *     - Neither:  28-32
            * ---------------------
            *    Dinner: 33
            *     -  Vegan: 34-38
            *     - Vegetarian:39-43
            *     - Neither:44-48
            * ---------------------
            *   48-3 = 45 lines of items.
            */

            
        }
        
    }
    printf("End of Program!!");
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}


