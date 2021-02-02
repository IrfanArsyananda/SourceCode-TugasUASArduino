#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

//deklarasi variabel
long duration; //variabel durasi
int distance; //variabel jarak

int biru = 13;//variabel LED
int merah = 12;
int hijau = 11;
int kuning = 10; 

void setup() {
  pinMode(trigPin, OUTPUT); //Set trigPin as OUTPUT
  pinMode(echoPin, INPUT); //Set echoPin as INPUT
  Serial.begin(9600); //Serial komunikasi media ke monitor
  //print text ke monitor
  Serial.println("Ultrasonic Sensor HC-SR04 + 4 LED");
  Serial.println("with Arduino UNO R3");
  //set LED OUTPUT
  pinMode(biru, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  
}

void loop() {
  //Meng enol kan kondisi trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Set trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //baca echoPin, kembalikan nilai sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //menghitung jarak
  distance = duration * 0.034 / 2; //Speed of sound wave divided by 2 (go and back)
  //memunculkan jarak ke Serial Monitor
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance > 0 && distance < 200){            
    digitalWrite(biru, LOW);
    digitalWrite(merah, LOW);
    digitalWrite(hijau, HIGH);
    digitalWrite(kuning, LOW);
  }else if (distance >= 200 && distance < 300){            
    digitalWrite(biru, LOW);
    digitalWrite(merah, HIGH);
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, LOW);
  }else if (distance >= 300){            
    digitalWrite(biru, HIGH);
    digitalWrite(merah, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, HIGH);
  }
  
}
//Sensor Ultrasonik + 3 LED by : Irfan Arsyananda-021