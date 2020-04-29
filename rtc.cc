#include <swRTC.h>
swRTC rtc; //create a new istance of the lib

void setup() {
	rtc.stopRTC(); //stop the RTC
	rtc.setTime(12,23,0); //set the time here
	rtc.setDate(7,3,2019); //set the date here
	rtc.startRTC(); //start the RTC
	Serial.begin(19200); //choose the serial speed here
	delay(2000); //delay to let the user opens the serial monitor
}

void loop() {
    Serial.print(rtc.getHours(), DEC);
    Serial.print(":");
    Serial.print(rtc.getMinutes(), DEC);
    Serial.print(":");
    Serial.print(rtc.getSeconds(), DEC);
    Serial.print(" -- ");

    Serial.print("Timestamp: ");
    Serial.println(rtc.getTimestamp(), DEC);


	if(rtc.getHours() == 12 && rtc.getMinutes() ==23 )
	{

		if(Serial.available() > 0) 
		 {  
		   String c;
			c  = Serial.readString();// if data available from reader 
			Serial.print(c);    
			  
		  
			if(c == "$0001630441"){
			Serial.println("ID1");      

			}   
		}
	}
	if(rtc.getHours() == 12 && rtc.getMinutes() == 25)
	{
	   
		if(Serial.available() > 0) 
		 {  
		   String c;
			c  = Serial.readString();// if data available from reader 
			Serial.print(c);    
			  
		  
			if(c == "$0001630441"){
				Serial.println("ID1");      
				} 
		}
	}
	if(rtc.getHours() == 12 && rtc.getMinutes() == 27 )
	{
		if(Serial.available() > 0) 
		 {  
		   String c;
			c  = Serial.readString();// if data available from reader 
			Serial.print(c);    
			  
		  
			if(c == "$0001630441"){
			Serial.println("ID1");      
			}    
		}
	}
}