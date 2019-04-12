#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Centipede.h> 


byte mac[] = { 0xDE, 0xAD, 0xBE, 0x01, 0x01, 0x01 };   //physical mac address
byte ip[] = { 192, 168, 1, 248 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 192, 168, 1, 1 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

Centipede CS; // create Centipede object
 

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // ---------- INIT Centipede --------

  Wire.begin(); // start I2C
 
  CS.initialize(); // set all registers to default
 
  CS.portMode(0, 0b0000000000000000); // set all pins on chip 0 to output
  CS.portMode(1, 0b0000000000000000); // set all pins on chip 1 to output
  CS.portMode(2, 0b0000000000000000); // set all pins on chip 2 to output
  CS.portMode(3, 0b0000000000000000); // set all pins on chip 3 to output
  CS.portWrite(0, 0b1111111111111111); // 0 = LOW, 1 = HIGH
  CS.portWrite(1, 0b1111111111111111); // 0 = LOW, 1 = HIGH
  CS.portWrite(2, 0b1111111111111111); // 0 = LOW, 1 = HIGH
  CS.portWrite(3, 0b1111111111111111); // 0 = LOW, 1 = HIGH
 
  //TWBR = 12; // uncomment for 400KHz I2C (on 16MHz Arduinos)


  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
         }

         //if HTTP request has ended
         if (c == '\n') {          
           Serial.println(readString); //print to serial monitor for debuging
     
           client.println("HTTP/1.1 200 OK"); //send new page
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<TITLE>Centipede Controller</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<p>Created by Jacob D Johnson 2/3/2016</p>");  
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //stopping client
           client.stop();
           //controls the Arduino if you press the buttons
           if (readString.indexOf("?0on") >0){
               CS.digitalWrite(0, LOW);
           }
           if (readString.indexOf("?0off") >0){
               CS.digitalWrite(0, HIGH);
           }
           if (readString.indexOf("?1on") >0){
               CS.digitalWrite(1, LOW);
           }
           if (readString.indexOf("?1off") >0){
               CS.digitalWrite(1, HIGH);
           }
           if (readString.indexOf("?2on") >0){
               CS.digitalWrite(2, LOW);
           }
           if (readString.indexOf("?2off") >0){
               CS.digitalWrite(2, HIGH);
           }
           if (readString.indexOf("?3on") >0){
               CS.digitalWrite(3, LOW);
           }
           if (readString.indexOf("?3off") >0){
               CS.digitalWrite(3, HIGH);
           }
           if (readString.indexOf("?4on") >0){
               CS.digitalWrite(4, LOW);
           }
           if (readString.indexOf("?4off") >0){
               CS.digitalWrite(4, HIGH);
           }
           if (readString.indexOf("?5on") >0){
               CS.digitalWrite(5, LOW);
           }
           if (readString.indexOf("?5off") >0){
               CS.digitalWrite(5, HIGH);
           }
           if (readString.indexOf("?6on") >0){
               CS.digitalWrite(6, LOW);
           }
           if (readString.indexOf("?6off") >0){
               CS.digitalWrite(6, HIGH);
           }
           if (readString.indexOf("?7on") >0){
               CS.digitalWrite(7, LOW);
           }
           if (readString.indexOf("?7off") >0){
               CS.digitalWrite(7, HIGH);
           }
           if (readString.indexOf("?8on") >0){
               CS.digitalWrite(8, LOW);
           }
           if (readString.indexOf("?8off") >0){
               CS.digitalWrite(8, HIGH);
           }
           if (readString.indexOf("?9on") >0){
               CS.digitalWrite(9, LOW);
           }
           if (readString.indexOf("?9off") >0){
               CS.digitalWrite(9, HIGH);
           }
           if (readString.indexOf("?10on") >0){
               CS.digitalWrite(10, LOW);
           }
           if (readString.indexOf("?10off") >0){
               CS.digitalWrite(10, HIGH);
           }
           if (readString.indexOf("?11on") >0){
               CS.digitalWrite(11, LOW);
           }
           if (readString.indexOf("?11off") >0){
               CS.digitalWrite(11, HIGH);
           }
           if (readString.indexOf("?12on") >0){
               CS.digitalWrite(12, LOW);
           }
           if (readString.indexOf("?12off") >0){
               CS.digitalWrite(12, HIGH);
           }
           if (readString.indexOf("?13on") >0){
               CS.digitalWrite(13, LOW);
           }
           if (readString.indexOf("?13off") >0){
               CS.digitalWrite(13, HIGH);
           }
           if (readString.indexOf("?14on") >0){
               CS.digitalWrite(14, LOW);
           }
           if (readString.indexOf("?14off") >0){
               CS.digitalWrite(14, HIGH);
           }
           if (readString.indexOf("?15on") >0){
               CS.digitalWrite(15, LOW);
           }
           if (readString.indexOf("?15off") >0){
               CS.digitalWrite(15, HIGH);
           }
           if (readString.indexOf("?16on") >0){
               CS.digitalWrite(16, LOW);
           }
           if (readString.indexOf("?16off") >0){
               CS.digitalWrite(16, HIGH);
           }
           if (readString.indexOf("?17on") >0){
               CS.digitalWrite(17, LOW);
           }
           if (readString.indexOf("?17off") >0){
               CS.digitalWrite(17, HIGH);
           }
           if (readString.indexOf("?18on") >0){
               CS.digitalWrite(18, LOW);
           }
           if (readString.indexOf("?18off") >0){
               CS.digitalWrite(18, HIGH);
           }
           if (readString.indexOf("?19on") >0){
               CS.digitalWrite(19, LOW);
           }
           if (readString.indexOf("?19off") >0){
               CS.digitalWrite(19, HIGH);
           }
           if (readString.indexOf("?20on") >0){
               CS.digitalWrite(20, LOW);
           }
           if (readString.indexOf("?20off") >0){
               CS.digitalWrite(20, HIGH);
           }
           if (readString.indexOf("?21on") >0){
               CS.digitalWrite(21, LOW);
           }
           if (readString.indexOf("?21off") >0){
               CS.digitalWrite(21, HIGH);
           }
           if (readString.indexOf("?22on") >0){
               CS.digitalWrite(22, LOW);
           }
           if (readString.indexOf("?22off") >0){
               CS.digitalWrite(22, HIGH);
           }
           if (readString.indexOf("?23on") >0){
               CS.digitalWrite(23, LOW);
           }
           if (readString.indexOf("?23off") >0){
               CS.digitalWrite(23, HIGH);
           }
           if (readString.indexOf("?24on") >0){
               CS.digitalWrite(24, LOW);
           }
           if (readString.indexOf("?24off") >0){
               CS.digitalWrite(24, HIGH);
           }
           if (readString.indexOf("?25on") >0){
               CS.digitalWrite(25, LOW);
           }
           if (readString.indexOf("?25off") >0){
               CS.digitalWrite(25, HIGH);
           }
           if (readString.indexOf("?26on") >0){
               CS.digitalWrite(26, LOW);
           }
           if (readString.indexOf("?26off") >0){
               CS.digitalWrite(26, HIGH);
           }
           if (readString.indexOf("?27on") >0){
               CS.digitalWrite(27, LOW);
           }
           if (readString.indexOf("?27off") >0){
               CS.digitalWrite(27, HIGH);
           }
           if (readString.indexOf("?28on") >0){
               CS.digitalWrite(28, LOW);
           }
           if (readString.indexOf("?28off") >0){
               CS.digitalWrite(28, HIGH);
           }
           if (readString.indexOf("?29on") >0){
               CS.digitalWrite(29, LOW);
           }
           if (readString.indexOf("?29off") >0){
               CS.digitalWrite(29, HIGH);
           }
           if (readString.indexOf("?30on") >0){
               CS.digitalWrite(30, LOW);
           }
           if (readString.indexOf("?30off") >0){
               CS.digitalWrite(30, HIGH);
           }
           if (readString.indexOf("?31on") >0){
               CS.digitalWrite(31, LOW);
           }
           if (readString.indexOf("?31off") >0){
               CS.digitalWrite(31, HIGH);
           }
           if (readString.indexOf("?32on") >0){
               CS.digitalWrite(32, LOW);
           }
           if (readString.indexOf("?32off") >0){
               CS.digitalWrite(32, HIGH);
           }
           if (readString.indexOf("?33on") >0){
               CS.digitalWrite(33, LOW);
           }
           if (readString.indexOf("?33off") >0){
               CS.digitalWrite(33, HIGH);
           }
           if (readString.indexOf("?34on") >0){
               CS.digitalWrite(34, LOW);
           }
           if (readString.indexOf("?34off") >0){
               CS.digitalWrite(34, HIGH);
           }
           if (readString.indexOf("?35on") >0){
               CS.digitalWrite(35, LOW);
           }
           if (readString.indexOf("?35off") >0){
               CS.digitalWrite(35, HIGH);
           }
           if (readString.indexOf("?36on") >0){
               CS.digitalWrite(36, LOW);
           }
           if (readString.indexOf("?36off") >0){
               CS.digitalWrite(36, HIGH);
           }
           if (readString.indexOf("?37on") >0){
               CS.digitalWrite(37, LOW);
           }
           if (readString.indexOf("?37off") >0){
               CS.digitalWrite(37, HIGH);
           }
           if (readString.indexOf("?38on") >0){
               CS.digitalWrite(38, LOW);
           }
           if (readString.indexOf("?38off") >0){
               CS.digitalWrite(38, HIGH);
           }
           if (readString.indexOf("?39on") >0){
               CS.digitalWrite(39, LOW);
           }
           if (readString.indexOf("?39off") >0){
               CS.digitalWrite(39, HIGH);
           }
           if (readString.indexOf("?40on") >0){
               CS.digitalWrite(40, LOW);
           }
           if (readString.indexOf("?40off") >0){
               CS.digitalWrite(40, HIGH);
           }
           if (readString.indexOf("?41on") >0){
               CS.digitalWrite(41, LOW);
           }
           if (readString.indexOf("?41off") >0){
               CS.digitalWrite(41, HIGH);
           }
           if (readString.indexOf("?42on") >0){
               CS.digitalWrite(42, LOW);
           }
           if (readString.indexOf("?42off") >0){
               CS.digitalWrite(42, HIGH);
           }
           if (readString.indexOf("?43on") >0){
               CS.digitalWrite(43, LOW);
           }
           if (readString.indexOf("?43off") >0){
               CS.digitalWrite(43, HIGH);
           }
           if (readString.indexOf("?44on") >0){
               CS.digitalWrite(44, LOW);
           }
           if (readString.indexOf("?44off") >0){
               CS.digitalWrite(44, HIGH);
           }
           if (readString.indexOf("?45on") >0){
               CS.digitalWrite(45, LOW);
           }
           if (readString.indexOf("?45off") >0){
               CS.digitalWrite(45, HIGH);
           }
           if (readString.indexOf("?46on") >0){
               CS.digitalWrite(46, LOW);
           }
           if (readString.indexOf("?46off") >0){
               CS.digitalWrite(46, HIGH);
           }
           if (readString.indexOf("?47on") >0){
               CS.digitalWrite(47, LOW);
           }
           if (readString.indexOf("?47off") >0){
               CS.digitalWrite(47, HIGH);
           }
           if (readString.indexOf("?48on") >0){
               CS.digitalWrite(48, LOW);
           }
           if (readString.indexOf("?48off") >0){
               CS.digitalWrite(48, HIGH);
           }
           if (readString.indexOf("?49on") >0){
               CS.digitalWrite(49, LOW);
           }
           if (readString.indexOf("?49off") >0){
               CS.digitalWrite(49, HIGH);
           }
           if (readString.indexOf("?50on") >0){
               CS.digitalWrite(50, LOW);
           }
           if (readString.indexOf("?50off") >0){
               CS.digitalWrite(50, HIGH);
           }
           if (readString.indexOf("?51on") >0){
               CS.digitalWrite(51, LOW);
           }
           if (readString.indexOf("?51off") >0){
               CS.digitalWrite(51, HIGH);
           }
           if (readString.indexOf("?52on") >0){
               CS.digitalWrite(52, LOW);
           }
           if (readString.indexOf("?52off") >0){
               CS.digitalWrite(52, HIGH);
           }
           if (readString.indexOf("?53on") >0){
               CS.digitalWrite(53, LOW);
           }
           if (readString.indexOf("?53off") >0){
               CS.digitalWrite(53, HIGH);
           }
           if (readString.indexOf("?54on") >0){
               CS.digitalWrite(54, LOW);
           }
           if (readString.indexOf("?54off") >0){
               CS.digitalWrite(54, HIGH);
           }
           if (readString.indexOf("?55on") >0){
               CS.digitalWrite(55, LOW);
           }
           if (readString.indexOf("?55off") >0){
               CS.digitalWrite(55, HIGH);
           }
           if (readString.indexOf("?56on") >0){
               CS.digitalWrite(56, LOW);
           }
           if (readString.indexOf("?56off") >0){
               CS.digitalWrite(56, HIGH);
           }
           if (readString.indexOf("?57on") >0){
               CS.digitalWrite(57, LOW);
           }
           if (readString.indexOf("?57off") >0){
               CS.digitalWrite(57, HIGH);
           }
           if (readString.indexOf("?58on") >0){
               CS.digitalWrite(58, LOW);
           }
           if (readString.indexOf("?58off") >0){
               CS.digitalWrite(58, HIGH);
           }
           if (readString.indexOf("?59on") >0){
               CS.digitalWrite(59, LOW);
           }
           if (readString.indexOf("?59off") >0){
               CS.digitalWrite(59, HIGH);
           }
           if (readString.indexOf("?60on") >0){
               CS.digitalWrite(60, LOW);
           }
           if (readString.indexOf("?60off") >0){
               CS.digitalWrite(60, HIGH);
           }
           if (readString.indexOf("?61on") >0){
               CS.digitalWrite(61, LOW);
           }
           if (readString.indexOf("?61off") >0){
               CS.digitalWrite(61, HIGH);
           }
           if (readString.indexOf("?62on") >0){
               CS.digitalWrite(62, LOW);
           }
           if (readString.indexOf("?62off") >0){
               CS.digitalWrite(62, HIGH);
           }
           if (readString.indexOf("?63on") >0){
               CS.digitalWrite(63, LOW);
           }
           if (readString.indexOf("?63off") >0){
               CS.digitalWrite(63, HIGH);
           }
           if (readString.indexOf("?ALLon") >0){
               for (int i = 0; i < 63; i++) {
                 CS.digitalWrite(i, LOW);
                 delay(10);
               }
           }
           if (readString.indexOf("?ALLoff") >0){
               for (int i = 0; i < 63; i++) {
                 CS.digitalWrite(i, HIGH);
                 delay(10);
               }
           }
            //clearing string for next read
            readString="";  
           
         }
       }
    }
}
}

