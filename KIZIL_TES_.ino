#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRrecv ali(2);

decode_results results;
#define  yesil 0xFF38C7
#define red 0xFF18E7

void setup() 
{
Serial.begin(9600); 

ali.enableIRIn();

pinMode(3,OUTPUT);

digitalWrite(3,LOW);




pinMode(4,OUTPUT); // başka led gelirse

digitalWrite(4,LOW);
}

void loop() 
{
if (ali.decode(&results))  
 {
  Serial.print(results.value , HEX);

  if(results.value==yesil)
 {

 digitalWrite( 3, !digitalRead(3));
 }
   if(results.value==red)
 {

 digitalWrite( 4, !digitalRead(4));

 }

 
  ali.resume();
 }


}
