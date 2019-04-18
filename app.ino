#include <RCSwitch.h>

const int lightPin = 7;
const int gatePin = 12;
bool light = true; // initial ligth on
const int receiverPin = 0; // Receiver on interrupt 0 => that is pin #2

RCSwitch mySwitch = RCSwitch();

void setup()
{
	mySwitch.enableReceive(receiverPin);
	pinMode(lightPin, OUTPUT);
	pinMode(gatePin, OUTPUT);
}

void loop()
{
	if(mySwitch.available()){

		if (mySwitch.getReceivedValue() == 175399013 || mySwitch.getReceivedValue() == 141695781){
			if (light){
				digitalWrite(lightPin, LOW);
				delay(2000);
				light = false;
				mySwitch.resetAvailable();
			}

			else{
				digitalWrite(lightPin, HIGH);
				delay(2000);
				light = true;
				mySwitch.resetAvailable();
			}
		}

		else if (mySwitch.getReceivedValue() == 175398997 || mySwitch.getReceivedValue() == 141695765){
			digitalWrite(gatePin, HIGH);
			delay(1000);
			digitalWrite(gatePin, LOW);
			delay(80);
			digitalWrite(gatePin, HIGH);
			delay(400);
			digitalWrite(gatePin, LOW);
			mySwitch.resetAvailable();
		}	
	}
}