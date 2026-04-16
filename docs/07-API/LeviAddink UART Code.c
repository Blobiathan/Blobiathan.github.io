#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#include <SD.h>
#include <Arduino.h>

//UART STUFF BELOW

HardwareSerial MyUART(1);

int RX_PIN = 36;
int TX_PIN = 37;

char START_BYTE_1 = 'A';
char START_BYTE_2 = 'Z';
char END_BYTE_1 = 'Y';
char END_BYTE_2 = 'B';

uint8_t recieveBuffer[10]; //MAKE THIS HOWEVER BIG YOU WANT, NEEDS TO FIT WHATEVER DATA YOU EXPECT TO GET
int i = 0;
int recBytes = 0;
int endBytes = 0;
bool receiving = false;

struct Packet {
    uint8_t sender;
    uint8_t receiver;
    uint8_t type;
};


void sendPacket(uint8_t sender, uint8_t receiver, uint8_t type, uint8_t data) {
  MyUART.write(START_BYTE_1);
  MyUART.write(START_BYTE_2);
  MyUART.write(sender);
  MyUART.write(receiver);
  MyUART.write(type);
  MyUART.write(data);
  MyUART.write(END_BYTE_1);
  MyUART.write(END_BYTE_2);
}

void sendPacket2(uint8_t sender, uint8_t receiver, uint8_t type) {
  MyUART.write(START_BYTE_1);
  MyUART.write(START_BYTE_2);
  MyUART.write(sender);
  MyUART.write(receiver);
  MyUART.write(type);
  MyUART.write(END_BYTE_1);
  MyUART.write(END_BYTE_2);
}



//UART STUFF ABOVE


const int CS = 6;
const int SD_CS = 10;
const int buttonPin = 4;  // Pin for button

const int LED1 = 5;
const int LED2 = 7;
const int CD = 9;

bool SD_init = false;

bool is_header = false;
uint8_t start_capture = 0;
unsigned long captureStartTime = 0;  // To track when capture started
const unsigned long captureTimeout = 5000;  // Timeout in milliseconds (5 seconds)

#if defined (OV2640_MINI_2MP_PLUS)
ArduCAM myCAM( OV2640, CS );
#endif

uint8_t read_fifo_burst(ArduCAM myCAM);
void reset_camera();  // Function to reset the camera

void setup() {
  uint8_t temp;
  
  // Initialize I2C and Serial
#if defined(__SAM3X8E__)
  Wire1.begin(15,16);
  Serial.begin(9600);
  delay(1000);
#else
  Wire.begin(15, 16, 100000); // slower I2C
  Serial.begin(9600);
  delay(1000);
  MyUART.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
#endif

  Serial.println(F("ArduCAM Start"));

  // Set the CS as an output:
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  pinMode(SD_CS, OUTPUT);
  digitalWrite(CS, HIGH);
  
  // Initialize SPI:
  SPI.begin(13, 14, 12, CS);
  SPI.setFrequency(500000);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(CD, INPUT_PULLUP);


  
  // Reset the CPLD
  myCAM.write_reg(0x07, 0x80);
  delay(200);
  myCAM.write_reg(0x07, 0x00);
  delay(1000);


  if (!SD.begin(SD_CS)) {  // Initialize SD card with custom SPI
    Serial.println("SD card initialization failed! No SD card, or read error");
    digitalWrite(LED1,LOW);
  }
  else
  {
    SD_init = true;
    Serial.println("SD card initialized.");
    digitalWrite(LED1,HIGH);
  }
  delay(500);


  Serial.printf("Writing file \n");

  File file = SD.open("/test.txt", FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
  }
  if (file.print("test")) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();


  // Check if the ArduCAM SPI bus is OK
  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);
  if (temp != 0x55) {
    Serial.println(F("SPI interface Error"));
    delay(1000);
    return;
  }

  // Set camera to JPEG mode and initialize
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_1600x1200);  // Set JPEG size to 320x240
  //DIFFERENT SIZE YOU CAN CHOOSE FROM
  //    OV2640_160x120
  //    OV2640_176x144
  //    OV2640_320x240
  //    OV2640_352x288
  //    OV2640_640x480
  //    OV2640_800x600
  //    OV2640_1024x768
  //    OV2640_1280x1024
  //    OV2640_1600x1200
  // YIPEE CAMERA RESOLUTIONS
  delay(1000);
  myCAM.clear_fifo_flag();

  // Initialize button pin
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input with pullup
}

void loop() {

  if(digitalRead(CD) == LOW && SD_init == false)
  {
    if (!SD.begin(SD_CS)) {  // Initialize SD card with custom SPI
      Serial.println("SD card initialization failed!");
    }
    else
    {
      Serial.println("SD card inserted!");
      SD_init = true;
      digitalWrite(LED1,HIGH);
    }
    delay(200);
  }

  if(digitalRead(CD) == HIGH && SD_init == true)
  {
    Serial.println("SD card removed!");
    digitalWrite(LED1,LOW);
    SD_init = false;
    delay(200);
  }

  if(digitalRead(buttonPin) == LOW && SD_init == false)
  {
    Serial.println("Can't take photo, SD removed or invalid!");
  }

  // Check if button is pressed
  if (digitalRead(buttonPin) == LOW && SD_init == true) {  // Button is pressed (LOW because of pullup)
    if (start_capture == 0) {  // Capture only if not already capturing

      sendPacket2((uint8_t)'A',(uint8_t)'F',2);
      Serial.println("Sent message");
      //reset_camera(); //TURN THIS ON FOR ULTIMATE STABILITY
      //delay(100); //THIS TOO
      /*
      Serial.println(F("Button pressed: Capturing image..."));
      start_capture = 1;
      captureStartTime = millis();  // Start the timeout timer
      myCAM.flush_fifo();
      myCAM.clear_fifo_flag();
      myCAM.start_capture();
      delay(0);  // Debounce delay
      */
      delay(500);
    }
  }



    //HANDLE UART NONSENSE HERE
    while (MyUART.available()) {
        uint8_t byte = MyUART.read();

        if (receiving == false && recBytes == 0) { // FIRST "STARTBYTE" DETECTED
            if (byte == START_BYTE_1) {
              recBytes = 1;
              continue;
            }
        }

        if(receiving == false && recBytes == 1) 
        {
          if (byte == START_BYTE_2) // SECOND "STARTBYTE" DETECTED
          {
              receiving = true;
              i = 0;
              recBytes = 0;
              memset(recieveBuffer, 0, sizeof(recieveBuffer)); // Clear the recieve buffer since your gonna start filling it up
              continue;
          }
        }

        if (receiving == true) {
            
            
            if (byte == END_BYTE_1 && endBytes == 0) {
              endBytes = 1;
              continue;
            }
            
            if(byte == END_BYTE_2 && endBytes == 1) { //SECOND END BYTE IS DETECTED SO READ ALL THE DATA
                Packet pkt;
                pkt.sender   = recieveBuffer[0];
                pkt.receiver = recieveBuffer[1];
                pkt.type     = recieveBuffer[2];
                


                for(int e = 0; e < i; e++)
                {
                  Serial.println(recieveBuffer[e]);
                }

                if((char)pkt.sender != 'A' && (char)pkt.sender != 'B' && (char)pkt.sender != 'C' && (char)pkt.sender != 'D' && (char)pkt.sender != 'E' && (char)pkt.sender != 'F' && (char)pkt.sender != 'G' && (char)pkt.sender != 'H' && (char)pkt.sender != 'I' && (char)pkt.sender != 'J' )
                {
                  Serial.println("Stranger danger! I don't know who's sending this!");
                  receiving = false;
                  i = 0;
                  endBytes = 0;
                  continue;
                }

                if((char)pkt.receiver == 'F') //IF THE MESSAGE IS FOR ME
                {
                  Serial.println("This message is for me!");
                  //add whatever you need to do here
                  if(pkt.type == 2)
                  {
                    Serial.println(F("Button pressed: Capturing image..."));
                    start_capture = 1;
                    captureStartTime = millis();  // Start the timeout timer
                    myCAM.flush_fifo();
                    myCAM.clear_fifo_flag();
                    myCAM.start_capture();
                  }
                }
                if((char)pkt.receiver != 'F' && (char)pkt.sender != 'F') //IF ITS NOT FOR ME PASS IT ON
                {
                  MyUART.write(START_BYTE_1);
                  MyUART.write(START_BYTE_2);
                  for(int e = 0; e < i; e++)
                  {
                    MyUART.write(recieveBuffer[e]);
                  }
                  
                  MyUART.write(END_BYTE_1);
                  MyUART.write(END_BYTE_2);
                }

                if((char)pkt.sender == 'F')
                {
                  Serial.println("Message looped!");
                  receiving = false;
                  i = 0;
                  endBytes = 0;
                  continue;
                }

                receiving = false;
                i = 0;
                endBytes = 0;
                continue;
            }
            else{
              endBytes = 0; //Only saw the first endbyte not the second, so it must have been a fluke
            }

            if(i >= sizeof(recieveBuffer)) //MAKE SURE YOU DONT HAVE A GIANT MESSAGE (THIS CAN HAPPEN IF END BYTES ARE MISSED)
            {
              Serial.println("TOO MUCH DATA");
              receiving = false;
              i = 0;
              endBytes = 0;
              continue;
            }

            recieveBuffer[i++] = byte; //IF THERES NO START OR END BYTE STUFF GOING ON JUST ADD NEW DATA TO THE RECIEVE BUFFER
        }
    }

  // Check if we are in the capture stage and timeout
  if (start_capture == 1) {
    if (myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)) {
      Serial.println(F("Capture Done."));
      delay(50);
      read_fifo_burst(myCAM);  // Read the captured image from FIFO
      myCAM.clear_fifo_flag();
      start_capture = 0;  // Reset capture flag
    } 
    // Timeout condition (if capture takes too long)
    else if (millis() - captureStartTime > captureTimeout) {
      Serial.println(F("Capture Timeout AHHH! Resetting camera."));
      reset_camera();  // Reset camera on timeout
      start_capture = 0;  // Reset the state
    }
  }
}

byte imageData[150000];  // Array to hold image data
int dataIndex = 0;

uint8_t read_fifo_burst(ArduCAM myCAM) {
  digitalWrite(LED2,HIGH);
  uint8_t temp = 0, temp_last = 0;
  uint32_t length = 0;
  length = myCAM.read_fifo_length();
  
  if (length >= MAX_FIFO_SIZE) {
    Serial.println(F("Image too large"));
    return 0;
  }
  
  if (length == 0) {
    Serial.println(F("Empty image"));
    return 0;
  }

  myCAM.CS_LOW();
  myCAM.set_fifo_burst();  // Set FIFO burst mode
  temp = SPI.transfer(0x00);
  length--;

  while (length--) {
    temp_last = temp;
    temp = SPI.transfer(0x00);

    if (is_header == true) {
      Serial.write(temp);
      imageData[dataIndex++] = temp;
    }
    else if ((temp == 0xD8) && (temp_last == 0xFF)) {
      is_header = true;
      Serial.println(F("Image start"));
      Serial.write(temp_last);
      Serial.write(temp);
      imageData[dataIndex++] = temp_last;  // Store first byte
      imageData[dataIndex++] = temp;  
    }
    if ((temp == 0xD9) && (temp_last == 0xFF)) {  // End of image
      break;
    }
    delayMicroseconds(15);
  }

  myCAM.CS_HIGH();
  is_header = false;

  Serial.println("Image data saved to byte array.");
  Serial.println(dataIndex);  // Print the number of bytes saved


  //int randomNumber = random(10000);
  int randomNumber = millis();
  char filename[20];
  snprintf(filename, sizeof(filename), "/image_%d.jpg", randomNumber);

  File imgFile = SD.open(filename, FILE_WRITE);
  if (imgFile) {
      imgFile.write(imageData, dataIndex);  // Write image data to file
      imgFile.close();
      Serial.println("Image saved to SD card");
  } else {
      Serial.println("Failed to open file for writing");
  }

  memset(imageData, 0, 100000);
  dataIndex = 0;

  digitalWrite(LED2,LOW);
  return 1;
}

void reset_camera() {
  // Reset the camera by re-initializing it
  myCAM.write_reg(0x07, 0x80);  // Reset the camera
  delay(100);
  myCAM.write_reg(0x07, 0x00);  // Clear reset
  delay(100);

  // Re-initialize the camera
  myCAM.InitCAM();
  myCAM.set_format(JPEG);
  myCAM.OV2640_set_JPEG_size(OV2640_1600x1200);  // Set JPEG size to 320x240
  myCAM.clear_fifo_flag();
  Serial.println(F("Camera reset and re-initialized."));

}