#define MAX7219_DIN 11
#define MAX7219_CS  10
#define MAX7219_CLK 13

void initialise()
{
 
  pinMode(MAX7219_DIN, OUTPUT);
  digitalWrite(MAX7219_DIN, LOW);
  pinMode(MAX7219_CS, OUTPUT);
  digitalWrite(MAX7219_CS, HIGH);
  pinMode(MAX7219_CLK, OUTPUT);
  digitalWrite(MAX7219_CLK, LOW);
  
}

void output(byte address, byte data)
{
  digitalWrite(MAX7219_CS, LOW);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, address);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, data);
  digitalWrite(MAX7219_CS, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  initialise();
  //output(0x0f, 0x01); //display test mode is on
  //output(0x0f, 0x00); //display test mode is off
  output(0xc,0x1); //THE ENABLING REGISTER!!!
  output(0xb, 0x7); // Choose how many digits you want to drive 0-7
  output(0xa, 0xa); //set brightness 0xf will give max brightness
  output(1,5); //| Addres 1 is LSD and addres 8 MSD
  output(2,6); 
  //output(3,7);
  output(4,8);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
