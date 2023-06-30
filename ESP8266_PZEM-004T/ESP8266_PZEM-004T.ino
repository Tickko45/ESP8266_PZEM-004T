#include <PZEM004Tv30.h>

// D2 -> TX
// D1 -> RX

PZEM004Tv30 pzem(D2, D1);

void setup() {
  Serial.begin(115200);
}

void loop() {
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();
                
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    }

    if(isnan(current)){
        Serial.println("Error reading current");
    }

    if(isnan(power)){
        Serial.println("Error reading power");
    }

    if(isnan(energy)){
        Serial.println("Error reading energy");
    }

    if(isnan(frequency)){
        Serial.println("Error reading frequency");
    }

    if(isnan(pf)){
        Serial.println("Error reading power factor");
    }

    Serial.println();
    
    Serial.print("Voltage: ");    Serial.print(voltage);        Serial.println("V");
    Serial.print("Current: ");    Serial.print(current);        Serial.println("A");
    Serial.print("Power: ");      Serial.print(power);          Serial.println("W");
    Serial.print("Energy: ");     Serial.print(energy,3);       Serial.println("kWh");
    Serial.print("Frequency: ");  Serial.print(frequency, 1);   Serial.println("Hz");
    Serial.print("PF: ");         Serial.println(pf);
        
    Serial.println();
    delay(1000);
}
