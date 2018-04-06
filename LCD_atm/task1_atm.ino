
float y1[10]={0,0,0,0,0,0,0,0,0,0};
float y2[10]={0,0,0,0,0,0,0,0,0,0};
float y3[10]={0,0,0,0,0,0,0,0,0,0};
int x =1;
int o1= 1 ;int o2=1;int o3 =1 ;
int ff,ff2,ff3=1;
float v1 ,v2,v3;

int t8,t9 ,t10,t11 =0;

float avg1,avg2,avg3;

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);//Rs ,E ,DB4 , DB5

int f=0; // to Enter Clear Display one time
int z =0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  lcd.begin(16, 2);

   //mainlcd();
}


 
void loop()
{
  //if (digitalRead(13)==HIGH){Serial.print("hiiii");}
  if((digitalRead(13)==HIGH) || z==1){
  delay(50);
  sensors();
  if(digitalRead(8)==HIGH){t8++;delay(500);}
  if(digitalRead(9)==HIGH){delay(500);t9++;}     
  if(digitalRead(10)==HIGH){t10++;delay(500);}
  if(digitalRead(11)==HIGH){t11++;delay(500);}
  if (t8==0 && t9==0 && t10==0 && t11==0){mainlcd();}
  if (t8==0 && t9==1 && t10==0 && t11==0){lcd.clear();lcd.setCursor(3,0);lcd.print("Select Sen");lcd.setCursor(0,0);lcd.print("<1");lcd.setCursor(14,0);lcd.print("2>");lcd.setCursor(0,1);lcd.print("<3");lcd.setCursor(11,1);lcd.print("Back>");}
  
  if (t8==1 && t9==1 && t10==0 && t11==0){if(o1==1){screen3_ds();}
                                         if(o1==0){screen3_en();}
                    }
  if (t8==0 && t9==2 && t10==0 && t11==0){if(o2==1){screen3_ds();}
                                         if(o2==0 ){screen3_en();}
                                      }
  if (t8==0 && t9==1 && t10==1 && t11==0){if(o3==1 ){screen3_ds();}
                                          if(o3==0 ){screen3_en();}
                                      } 
         
         
         if(t8==1 && t9==1 && t10==0 && t11 ==1 && o1==1){o1=0;t8=0;t9=0;t10=0;t11=0;delay(500);} //disable sensor 1 
         if(t8==1 && t9==1 && t10==0 && t11 ==1 && o1==0){o1=1;t8=0;t9=0;t10=0;t11=0;delay(500);} //Enable sensor 1
         if(t8==1 && t9==1 && t10==1 && t11 ==0){t8==1; t9==1; t10==0; t11==0;delay(500);} //Back 

         if(t8==0 && t9==2 && t10==0 && t11 ==1 && o2==1 ){o2=0;t8=0;t9=0;t10=0;t11=0;delay(500);} //disable sensor 2 
         if(t8==0 && t9==2 && t10==0 && t11 ==1 && o2==0 ){o2=1;t8=0;t9=0;t10=0;t11=0;delay(500);} //Enable sensor 2
         if(t8==0 && t9==2 && t10==1 && t11==0){t8==0;t9==2 ; t10==0 ; t11==0;delay(500);} //Back 

         if(t8==0 && t9==1 && t10==1 && t11 ==1 && o3==1 ){o3=0;t8=0;t9=0;t10=0;t11=0;delay(500);} //disable sensor 3 
         if(t8==0 && t9==1 && t10==1 && t11 ==1 && o3==0 ){o3=1;t8=0;t9=0;t10=0;t11=0;delay(500);} //Enable sensor 3
         if(t8==0 && t9==1 && t10==2 && t11==0){t8==0; t9==1; t10==1;t11==0;delay(500);} //Back 
    Serial.println(String (t8)+ String(t9) +String(t10)+String(t11));
    if  ((t8 ||t9||t10||t11) >4 ){t8=0 ;t9=0;t10=0;t11=0;}
  }
   if((!(digitalRead(13)==HIGH)) &( z==0)) {
    
      if(digitalRead(10)==HIGH){t10++;delay(500);}
      if(digitalRead(11)==HIGH){t11++;delay(500);}
        if(t10==0 && t11==0){lcd.clear();delay(500);lcd.setCursor(1,0);lcd.print("Sure TO Exit?");lcd.setCursor(0,1);lcd.print("<<YES");lcd.setCursor(12,1);lcd.print("NO>>");delay(1000);}
         if(t10==1 && t11==0){lcd.clear();} //Yes 
          if(t10==0 && t11==1){lcd.clear();z=1;t8=0 ;t9=0;t10=0;t11=0;delay(500);} //No
          Serial.println(String (t8)+ String(t9) +String(t10)+String(t11));
    } 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sensors(){
  
  //ff=1;ff2=1;ff3=1;
  float sum1,sum2,sum3=0;
  avg1,avg2,avg3 =0;
 if(o1==1){float r1 = analogRead(A0);v1 = r1 * (5 / 1023.0);}if(o1==0){ v1 = 0;}
  if(o2==1){float r2 = analogRead(A1);v2 = r2 * (5 / 1023.0);}if(o2==0){v2 = 0;}
  if(o3==1){float r3 = analogRead(A2);v3 = r3 * (5 / 1023.0);}if(o3==0){v3 = 0;}
 for (int i = 0 ; i<9;i++){y1[i]=y1[i+1];y2[i]=y2[i+1];y3[i]=y3[i+1];}
  y1[9] = v1;y2[9] = v2; y3[9] = v3;
  for (int i = 0 ; i < 10 ; i++){sum1 += y1[i] ;sum2 += y2[i] ;sum3 += y3[i] ;}
  avg1 = sum1/10 ;
  avg2 = sum2/10 ;
  avg3 = sum3/10 ;
  
  }
////////////////////////////////////////////////////////////////////////////////////////////////
 void mainlcd(){
  delay(400);
  lcd.clear();
  lcd.setCursor(11,0);lcd.print("En/D>");
  //lcd.setCursor(13,1);lcd.print("OFF");
  lcd.setCursor(2,0);lcd.print("V1="+String(avg1));
  lcd.setCursor(0,1);lcd.print("V2="+String(avg2));
  lcd.setCursor(9,1);lcd.print("V3="+String(avg3));
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void screen3_en(){delay(500);lcd.clear();lcd.setCursor(0,1);lcd.print("<Back");lcd.setCursor(9,1);lcd.print("Enable>");}
void screen3_ds(){lcd.clear();lcd.setCursor(0,1);lcd.print("<Back");lcd.setCursor(8,1);lcd.print("Disable>");}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

