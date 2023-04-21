import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main {
    public static final int TOTAL_MENU = 45;
    public static void printMenuI(String fileName, int[] desiredLineNums, int size) {
        String line;
        int lineNum = -1;
        BufferedWriter output = null;
        try {
            File outputFile = new File("output.txt");
            if (outputFile.createNewFile()) {
                System.out.println("Output file created: " + outputFile.getName());
            } else {
                System.out.println("Output file already exists.");
            }
            output = new BufferedWriter(new FileWriter("output.txt", true));
            BufferedReader input = new BufferedReader(new FileReader(fileName));
            while ((line = input.readLine()) != null) {
                lineNum++;
                for (int i = 0; i < size; i++) {
                    if (lineNum == desiredLineNums[i]) {
                        // remove newline character from line
                        line = line.replace("\n", "");
                        // write the line to the output file
                        output.write(line + "\n");
                        // print the line to stdout
                        System.out.println(line);
                        break; // exit the loop after printing a desired line
                    }
                }
            }
            input.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (output != null) {
                    output.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void menuPrintUser(int menu, String title) {
        int subMenu = menu /3;
        System.out.println(); // spacer (NEW!!!)
        System.out.printf("%s (%d Total Items)\n",title,menu);
        System.out.printf("- %d Vegan Items\n",subMenu);
        System.out.printf("- %d Vegetarian Items\n",subMenu);
        System.out.printf("- %d Vegan Neither\n",subMenu);
        System.out.println();//spacer (NEW!!!)

    }

    public static void postMenuPrintUser(int menu, String title,int vegan, int vegetarian, int meat){
        System.out.print("What Values The User Selected!\n");
        int subMenu = vegan + vegetarian + meat;
        System.out.println(); // spacer
        System.out.printf("%s (%d Total Items)\n",title,subMenu);
        System.out.printf("- %d Vegan Items\n",vegan);
        System.out.printf("- %d Vegetarian Items\n",vegetarian);
        System.out.printf("- %d Vegan Neither\n",meat);
        System.out.println(); // spacer
    }
    public static void printTextMenu(int line_num[],int menu[]){
        int index = 1;
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

    public static void printUserInputVEGAN(String menu){
        System.out.printf("Welcome to %s Menu Selection!!\n",menu);
        System.out.printf("Enter a Value from 0-5 for the corresponding Values!!\n");
        System.out.printf("Each value input corresponds to how many items are added to each CATEGORY !VEGAN is always atleast 1!\n");
        System.out.printf("IMPORTANT! if value is out of range! AUTO GENERATOR will overwrite user input!\n\n");
        System.out.printf("VEGAN: ");
    }
    public static void printUserInputVEGETARIAN() {
        System.out.printf("VEGETARIAN: ");
    }
    public static void printUserInputNEITHER() {
        System.out.printf("NEITHER: ");
    }
    public static void space() {
        System.out.printf("\n\n");
    }
    public static void spacerPrint() {
        System.out.printf("---------------------------------------------------------\n");
    }
    public static void main(String[] args) {

        //----------------------------------------
        //Local Variables
        int[] breakfast = new int[3];
        int bVegan = 0, bVegetarian = 0, bMeat = 0;//Saved for user input

        int[] lunch = new int[3];
        int lVegan = 0, lVegetarian = 0, lMeat = 0;//Saved for user input

        int[] dinner = new int[3];
        int dVegan = 0, dVegetarian = 0, dMeat = 0; //Saved for user input
        int minBreak = 0;
        int minLunch = 0;
        int minDinner = 0;

        int rand_int;
        int[] random_num = new int[3]; // used for random number replacment
        int[] num = new int[5];
        int checker = 0; // used for user input ( DECIDE to print MENU or TERMINATE program)
        Random random = new Random(); // used to start random

        String filename1 = "BreakFastMenu.txt";
        String filename2 = "LunchMenu.txt";
        String filename3 = "DinnerMenu.txt";

        File file1 = new File("BreakFastMenu.txt");
        if (!file1.exists() || !file1.isFile()) {
            System.out.println("Failed to open file1");
            return;
        }

        File file2 = new File("LunchMenu.txt");
        if (!file2.exists() || !file2.isFile()) {
            System.out.println("Failed to open file2");
            return;
        }

        File file3 = new File("DinnerMenu.txt");
        if (!file3.exists() || !file3.isFile()) {
            System.out.println("Failed to open file3");
            return;
        }

        else{
            // Verifying that the program can access my files!!!
            System.out.printf("\nSuccessfully opened file named: %s,%s,%s\n\n", filename1, filename2, filename3);

            //Main Message!
            System.out.printf("!Welcome to menu Generator!\n\n");
            int totalMenu = TOTAL_MENU;
            int lastRow; //used for total number of Rows
            int lastCol; //used for total number of Col

            int maxMenu = totalMenu /3;
            int maxSubM = maxMenu /3;

            String b = "Breakfast";
            String l = "Lunch";
            String d = "Dinner";

            String v = "Vegan";
            String veg = "Vegetarian";
            String m = "Neither";

            spacerPrint();
            menuPrintUser(maxMenu, b);
            menuPrintUser(maxMenu, l);
            menuPrintUser(maxMenu, d);
            spacerPrint();
            //-------------------------user input BREAKFAST
            Scanner scanner = new Scanner(System.in); //NEW

            printUserInputVEGAN(b);
            bVegan = scanner.nextInt();
            breakfast[0] = bVegan;

            printUserInputVEGETARIAN();
            bVegetarian = scanner.nextInt();
            breakfast[1] = bVegetarian;

            printUserInputNEITHER();
            bMeat = scanner.nextInt();
            breakfast[2] = bMeat;

            spacerPrint();
            //-------------------------user input LUNCH
            printUserInputVEGAN(l);
            lVegan = scanner.nextInt();
            lunch[0] = lVegan;

            printUserInputVEGETARIAN();
            lVegetarian = scanner.nextInt();
            lunch[1] = lVegetarian;

            printUserInputNEITHER();
            lMeat = scanner.nextInt();
            lunch[2] = lMeat;

            spacerPrint();
            //-------------------------user input DINNER
            printUserInputVEGAN(d);
            dVegan = scanner.nextInt();
            dinner[0] = dVegan;

            printUserInputVEGETARIAN();
            dVegetarian = scanner.nextInt();
            dinner[1] = dVegetarian;

            printUserInputNEITHER();
            dMeat = scanner.nextInt();
            dinner[2] = dMeat;

            spacerPrint();
            //-------------------------End of user input
            for (int i = 0; i < 3; i++) {
                int rand_Int = random.nextInt(5) + 1;
                random_num[i] = rand_Int;
                // System.out.print(randomNum[i] + " "); // Print the generated number (used for Verification)
            }

            //safe way to change variables if INVALID INPUT, or Nothing was added
            int counter = 0;
            while ((bVegan < 1 || bVegan > 4 || bVegetarian < 0 || bVegetarian > 5 || bMeat < 0 || bMeat > 5) && counter < 3) {
                System.out.printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", b); // Breakfast Menu
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
            while ((lVegan == 0 || lVegan > 4 || lVegetarian < 0 || lVegetarian > 5 || lMeat < 0 || lMeat > 5) && counter < 3) {
                System.out.printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", l);// lunch Menu
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
            while ((dVegan == 0 || dVegan > 4 || dVegetarian < 0 || dVegetarian > 5 || dMeat < 0 || dMeat > 5) && counter < 3) {
                System.out.printf("AUTOGEN ACTIVATED!: %s No worries we got you!\n", d); // dinner Menu
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



            // TEST PRINTING...
            String line = "";
            int lineNum = 0;
            int[] desiredLineNum1 = new int[16];
            int[] desiredLineNum2 = new int[16];
            int[] desiredLineNum3 = new int[16];

            // calculates the lines from breakfast array to desired_line_num1 corresponding to breakfast menu
            printTextMenu(desiredLineNum1, breakfast);

            // calculates the lines from lunch array to desired_line_num1 corresponding to lunch menu
            printTextMenu(desiredLineNum2, lunch);

            // calculates the lines from dinner array to desired_line_num1 corresponding to dinner menu
            printTextMenu(desiredLineNum3, dinner);

            System.out.printf("\n\nEnd Of user input!! is this input okay??\nif yes-1 no-0\n");
            System.out.printf("if Yes: your menu will be printed to the screen and text file named Output.txt\n");
            System.out.printf("if No or INVALID INPUT!: program will exit!\nINPUT: ");


            checker = scanner.nextInt();
            if (checker != 1) {
                return;
            }
            else {
                long startTime = System.nanoTime();
1

                spacerPrint();

                //if user accepts it. itll print to the screen then append to a txt file called "output.txt"
                printMenuI(filename1, desiredLineNum1, 16); //Breakfast Menu
                space();
                printMenuI(filename2, desiredLineNum2, 16); //Lunch Menu
                space();
                printMenuI(filename3, desiredLineNum3, 16); //Dinner Menu

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
                // Total Time that Passed Calculated!

                long endTime = System.nanoTime();
                long elapsedTimeInNanoseconds = endTime - startTime;
                double elapsedTimeInSeconds = (double) elapsedTimeInNanoseconds / 1_000_000_000.0;
                System.out.printf("Elapsed time: %.6f seconds", elapsedTimeInSeconds);
            }
        }

    }
}