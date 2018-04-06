# Security-logging-system
Security Logging system : SD Card , Interactive LCD screen ,Login keypad ,System switch ,RFID switch ,Mobile App switch

Develop a logging system that satisfies the following requirements:
- Acquires 3 signals from 3 different sensors (e.g. temperature, pressure, altitude), two readings 
for each sensor per second.

    **SD Card** :

    o Sensor readings are to be logged/saved on an SD card in a readable format.  Each reading should 
    be combined with the exact time at which it was acquired. For ex, a line in the SD card file would 
    look like:
    2017.09.18 05:44:53 Temperature: XXu Pressure: YYu Altitude: ZZu, where u is the proper 
    abbreviation for the unit in which each reading is acquired/recorded in.

    **Interactive LCD screen** :
    
    o Each sensor logging can be enabled or disabled using an interactive ATM-like 2- lines LCD. You 
    need 4 push buttons to turn the regular LCD into an ATM-like  one.

    o LCD should always display each sensor readings average over the last 5 seconds. It should also 
    have an option to switch to the enable/disable screen.

    o In the enable-disable screen, the user can switch each sensor acquisition on or off. This screen 
    should also have an option to return back to the main screen (the one that displays the readings 
    average). When a sensor is disabled for more  than 5 seconds, the average should basically be 0.

  **Login keypad** :
  
    o System should not start to operate until the user can provide a proper login password. This 
    password should be entered using a 9-button keypad. The 9- button keypad should allow all 
    alphabetic/numbers similar to your old mobile phones keypad.
    
    o  The system should allow the user to toggle between show and hide password.  As the user types 
    the password on the keypad, it should show up on the LCD either as the actual characters (i.e. the 
    Show mode), or as * characters (i.e. the Hide mode).

   **System switch** :
   
      o The whole system should have a software-style on/off  switch.
      
      ▪    By default, the system is OFF, and LCD is showing nothing.
      
      ▪ When the switch is turned ON, the system starts to operate and LCD  display its screens.
      
      ▪ When the switch is turned OFF, the LCD will  display  a  “shutdown”  warning message at which the 
      user can confirm or cancel.
      
      ▪   Upon user confirmation on the shutdown message, the system should    turn OFF.
      
   **RFID switch** :
    
      ▪ The software switch described above should be implemented using an  RFID key.
        
   **Mobile App  switch** :
   
      ▪ The software switch described above should also be implemented using a mobile app that connects 
        with the main controller via Bluetooth.



