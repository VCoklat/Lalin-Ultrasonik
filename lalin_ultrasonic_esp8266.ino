#define merah_1 16
#define kuning_1 5
#define hijau_1 4

#define merah_2 14
#define kuning_2 12
#define hijau_2 13

#define trigPin 13
#define echoPin 15

float duration, distance;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(merah_1, OUTPUT);
  pinMode(kuning_1, OUTPUT);
  pinMode(hijau_1, OUTPUT);

  pinMode(merah_2, OUTPUT);
  pinMode(kuning_2, OUTPUT);
  pinMode(hijau_2, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {

  float jarak = cek_sensor(trigPin, echoPin);
  int jeda = 0;

  if ((jarak>=5)&&(jarak <= 20)){
    jeda=10000;
  } else {
    jeda=3000;
  }
  // put your main code here, to run repeatedly:
  digitalWrite(merah_1, HIGH);
  digitalWrite(merah_2, LOW);
  digitalWrite(hijau_2, HIGH);
  digitalWrite(kuning_1, LOW);

  delay(jeda);
  
  digitalWrite(hijau_2, LOW);
  digitalWrite(kuning_2, HIGH);
  delay(1000);
  digitalWrite(merah_1, LOW);
  digitalWrite(kuning_2, LOW);
  digitalWrite(merah_2, HIGH);
  digitalWrite(hijau_1, HIGH);
  delay(3000);
  digitalWrite(hijau_1, LOW);
  digitalWrite(kuning_1, HIGH);
  delay(1000);
}

float cek_sensor(int out, int in){
  digitalWrite(out, LOW);
  delayMicroseconds(5);

  digitalWrite(out, HIGH);
  delayMicroseconds(10);
  digitalWrite(out, LOW);

  duration = pulseIn(in, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Jarak : ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}
