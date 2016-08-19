

// Function to initialize the RTC
void initRTC(void)
{
  
  startI2C();
  // Initialize the RTC
  rtc.begin();
  
  setTimeDate();
}


void setTimeDate(void)
{
  startI2C();
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  delay(10);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(10);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(10);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(10);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(10);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(10);
  delay(5000);
  stopI2C();
  
  // following line sets the RTC to the date & time this sketch was compiled
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //stopI2C();
}

