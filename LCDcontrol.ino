// Initialize pins for LCD operation
void initLCDpins(void)
{
  /* signal  pin  port
   *   D0    33   PC1
   *   D1    34   PC2
   *   D2    35   PC3
   *   D3    36   PC4
   *   D4    37   PC5
   *   D5    38   PC6
   *   D6    39   PC7
   *   D7    40   PC8
   *   CS    41   PC9
   *   A0    45   PC18
   *   A1    44   PC19
   */
   digitalWrite(33, LOW);   // D0
   digitalWrite(34, LOW);   // D1
   digitalWrite(35, LOW);   // D2
   digitalWrite(36, LOW);   // D3
   digitalWrite(37, LOW);   // D4
   digitalWrite(38, LOW);   // D5
   digitalWrite(39, LOW);   // D6
   digitalWrite(40, LOW);   // D7
   digitalWrite(41, HIGH);  // CS
   digitalWrite(45, LOW);   // A0
   digitalWrite(44, LOW);   // A1

   pinMode(33, OUTPUT);     // D0
   pinMode(34, OUTPUT);     // D1
   pinMode(35, OUTPUT);     // D2
   pinMode(36, OUTPUT);     // D3
   pinMode(37, OUTPUT);     // D4
   pinMode(38, OUTPUT);     // D5
   pinMode(39, OUTPUT);     // D6
   pinMode(40, OUTPUT);     // D7
   pinMode(41, OUTPUT);     // CS
   pinMode(45, OUTPUT);     // A0
   pinMode(44, OUTPUT);     // A1
}

void sendLCDcommand(uint32_t BYTE, uint32_t ADDRESS)
{
  /* This function sends over two bytes of data, the POSition and CHARacter
   * Both are 7-bit numbers. The 8th bit determines if POSition or CHARacter 
   * is being sent. The sequence is:
   * 1. set chip select bit HIGH
   * 2. clear bus: 8-bits of LCD data and the address
   * 3. send 8 bits of LCD data on parallel bus
   * 4. set the LCD address
   * 5. bring chip select bit ZERO to trigger interrupt
   */

  // 1. set chip select bit HIGH
  PIOC->PIO_SODR = LCDCS;

  // 2. clear bus: 8-bits of LCD data and the address
  PIOC->PIO_CODR = LCDclear;

  // 3. send 8 bits of LCD data on parallel bus
  PIOC->PIO_SODR = (BYTE << 1);

  // 4. set the LCD address
  PIOC->PIO_SODR = ADDRESS;

  // 5. bring chip select bit ZERO to trigger interrupt
  PIOC->PIO_CODR = LCDCS;
}

void setDef(void)
{
  /* This function sends over default text consisting 
   * of Brightness: and Contrast:
   */
  sendLCDcommand(66 | 0b10000000, LCDchar);  // character B
  delayMicroseconds(10);
  sendLCDcommand(20, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(114 | 0b10000000, LCDchar);  // character r
  delayMicroseconds(10);
  sendLCDcommand(21, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(105 | 0b10000000, LCDchar);  // character i
  delayMicroseconds(10);
  sendLCDcommand(22, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(103 | 0b10000000, LCDchar);  // character g
  delayMicroseconds(10);
  sendLCDcommand(23, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(104 | 0b10000000, LCDchar);  // character h
  delayMicroseconds(10);
  sendLCDcommand(24, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(116 | 0b10000000, LCDchar);  // character t
  delayMicroseconds(10);
  sendLCDcommand(25, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(110 | 0b10000000, LCDchar);  // character n
  delayMicroseconds(10);
  sendLCDcommand(26, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(101 | 0b10000000, LCDchar);  // character e
  delayMicroseconds(10);
  sendLCDcommand(27, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(115 | 0b10000000, LCDchar);  // character s
  delayMicroseconds(10);
  sendLCDcommand(28, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(115 | 0b10000000, LCDchar);  // character s
  delayMicroseconds(10);
  sendLCDcommand(29, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(58 | 0b10000000, LCDchar);  // character :
  delayMicroseconds(10);
  sendLCDcommand(30, LCDchar);               // position
  delayMicroseconds(10);


  sendLCDcommand(67 | 0b10000000, LCDchar);  // character C
  delayMicroseconds(10);
  sendLCDcommand(40, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(111 | 0b10000000, LCDchar);  // character o
  delayMicroseconds(10);
  sendLCDcommand(41, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(110 | 0b10000000, LCDchar);  // character n
  delayMicroseconds(10);
  sendLCDcommand(42, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(116 | 0b10000000, LCDchar);  // character t
  delayMicroseconds(10);
  sendLCDcommand(43, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(114 | 0b10000000, LCDchar);  // character r
  delayMicroseconds(10);
  sendLCDcommand(44, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(97 | 0b10000000, LCDchar);  // character a
  delayMicroseconds(10);
  sendLCDcommand(45, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(115 | 0b10000000, LCDchar);  // character s
  delayMicroseconds(10);
  sendLCDcommand(46, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(116 | 0b10000000, LCDchar);  // character t
  delayMicroseconds(10);
  sendLCDcommand(47, LCDchar);               // position
  delayMicroseconds(10);
  sendLCDcommand(58 | 0b10000000, LCDchar);  // character :
  delayMicroseconds(10);
  sendLCDcommand(48, LCDchar);               // position
  delay(10);
}
