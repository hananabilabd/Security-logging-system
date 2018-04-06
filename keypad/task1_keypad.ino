// Code Written by Arafa Microsystem
// Interfacing Between Arduino Keypad and LCD to Password Lock App
//www.youtube.com/arafamicrosystems


#include "Keypad.h" 
#include <LiquidCrystal.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns


LiquidCrystal lcd(2,3,4,5,6,7);
char k ;char key;int index;
int c=0; // flag1 used to check The Password
int i=0; //flag2 used to Limiting The Password Letters
int error=0; //flag3 Check if Invalid Password it Reached Specific Value
int n =0 ;
int x ;
char keys[ROWS][COLS] =
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};
  
char pass[]={'a','d','g'}; // The Password 
char newpass[3];  // New Array That's Carried The typed Password
byte rowPins[ROWS] = {A4,A3,9,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11,12,13}; //connect to the column pinouts of the keypad // el azr3 3and 13 l7ad 9 
int count=0;
int f=0; // to Enter Clear Display one time
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup()
{
  Serial.begin(9600);


  pinMode(8, INPUT);
  lcd.begin(16, 2);
  /*
  lcd.setCursor(0,0); // Set Cursor to Row 0 Column 0 16x2 LCD
  // Intro Message
  lcd.print("   Hint:If you  ");
  lcd.setCursor(0,1);
  lcd.println("Enter Wrong Pass");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  After 5 Times ");
  lcd.setCursor(0,1);
  lcd.println("Wt 5s to Retries");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter The Pass");
  lcd.setCursor(0,1);
  lcd.print("Please?");
  delay(3000);
  lcd.clear();
  */
  lcd.setCursor(0,0);
  lcd.print("Password:");
 
}

 void print1()
 {
   // it's Function Using to Display The Password Screen
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter The Pass");
    lcd.setCursor(0,1);
    lcd.print("Please?");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password:");
 
 }
 
void loop()
{
  
  alpha ();
  //if (y == '*'){h = 1;} // hide password
  //Serial.println(k);
  //Serial.println(newpass);
  
  
  
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////

void alpha(){
  delay (200);
char key = keypad.getKey(); //define which key is pressed with getKey
 char letters[29] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','&','|','!'};
if (key != NO_KEY){lcd.setCursor(n,1);
 lcd.print(key);
 k= key;
 int g = key-48; index = (g-1)*3;
 


 //for (int z=0; z <= 10; z++){
     int i=index;
   while(i<(index+3)){
        char newKey = keypad.getKey();
         if ( newKey == key){lcd.setCursor(n,1);lcd.print(letters[i]);k= letters[i];
             i++;
           }
             delay(100);
          
        }
      
       
     //}
      
     n++;check();
     lcdprint();
     }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void check(){
  if(  i<3)
  {
   newpass[i]=k;
   if(newpass[i]==pass[i])c++;
   i++;   
  }
  
  if(c==3)// If all charachters entered by User are Correct(Equal to Set Password)
  {
    
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Correct Password");
 
    delay(4000);
    char newpass[]={'0','0','0'}; // Clear The Value of password entered by user.
    print1();
    c=0;
    i=0;
    n=0;
  }
  else if(c<3&&i==3)//Invalid Password Function
  {
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Invalid Password");
    delay(1000);
    i=0;
    c=0;
    error++;
    if(error<5){print1();}
    n=0;
  }
  /*
  if(error==5)// Error Function
  {
    // if invalid states reached 5 times Entry The Function
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Ent Invalid ");
    lcd.setCursor(0,1);
    lcd.print(" Pass 5 Times");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait until 5 Sec");
    delay(5000);
    error=0;
    print1();
    f=0;
  } 
*/
}

 void lcdprint(){
  int s = i-1 ;
  //if () { h=1;lcdprint2();}
  
  //if (){h =0;lcdprint2();} //  show password
 
  if (digitalRead(8) == HIGH){while(s >= 0){char p=newpass[s];lcd.setCursor(s,1);lcd.print("*");s--;}}
  if(!(digitalRead(8) == HIGH)) {while(s >= 0){char p=newpass[s];lcd.setCursor(s,1);lcd.print(p);s--;}}
  }

