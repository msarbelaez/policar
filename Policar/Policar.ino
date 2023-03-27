//int SI_Adelante = 7;
int SI_Atras = 8;
int SD_Adelante = 9;
int SD_Atras = 10;

int Motor1_InputA = 2;
int Motor1_InputB = 3;

int Motor2_InputA = 4;
int Motor2_InputB = 5;

int dist;
int dur;
const byte trig = 11; 
const byte echo = 12;

void setup() {
  Serial.begin(9600);
  //pinMode(SI_Adelante, INPUT);
  pinMode(SI_Atras, INPUT);
  pinMode(SD_Adelante, INPUT);
  pinMode(SD_Atras, INPUT);

  pinMode(Motor1_InputA, OUTPUT);
  pinMode(Motor1_InputB, OUTPUT);

  pinMode(Motor2_InputA, OUTPUT);
  pinMode(Motor2_InputB, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
   int Sensores;
   int Distancia;
    Sensores = lectorDeSensores();
    Distancia = get_dist();
    Serial.println("Obejeto esta a" + String(dist) + "cm de distancia");
  delay(100);
  
    switch (Sensores, Distancia) {
    case 0:
      carroAdelante();
      break;
    case 1:
      carroAtras();
      break;
    case 2:
      carroIzquierdaFuerte();
      break;
    case 3:
      carroIzquierdaDebil();
      break;
    case 4:
      carroDerechaFuerte();
      break;
    case 5:
      carroDerechaDebil();
      break;
    default:
      carroApagado();
      break;
  }

}

void carroAdelante() {
  digitalWrite(Motor1_InputA, HIGH);
  digitalWrite(Motor1_InputB, LOW);

  digitalWrite(Motor2_InputA, HIGH);
  digitalWrite(Motor2_InputB, LOW);
}

void carroApagado() {
digitalWrite(Motor1_InputA, LOW);
digitalWrite(Motor1_InputB, LOW);

digitalWrite(Motor2_InputA, LOW);
digitalWrite(Motor2_InputB, LOW);
}

void carroAtras() {
digitalWrite(Motor1_InputA, LOW);
digitalWrite(Motor1_InputB, HIGH);

digitalWrite(Motor2_InputA, LOW);
digitalWrite(Motor2_InputB, HIGH);
}

void carroIzquierdaFuerte() {
digitalWrite(Motor1_InputA, HIGH);
digitalWrite(Motor1_InputB, LOW);

digitalWrite(Motor2_InputA, LOW);
digitalWrite(Motor2_InputB, HIGH);
}

void carroIzquierdaDebil() {
digitalWrite(Motor1_InputA, HIGH);
digitalWrite(Motor1_InputB, LOW);

digitalWrite(Motor2_InputA, LOW);
digitalWrite(Motor2_InputB, LOW);
}

void carroDerechaFuerte() {
digitalWrite(Motor1_InputA, LOW);
digitalWrite(Motor1_InputB, HIGH);

digitalWrite(Motor2_InputA, HIGH);
digitalWrite(Motor2_InputB, LOW);
}

void carroDerechaDebil() {
digitalWrite(Motor1_InputA, LOW);
digitalWrite(Motor1_InputB, LOW);


digitalWrite(Motor2_InputA, HIGH);
digitalWrite(Motor2_InputB, LOW);
}

int lectorDeSensores() {
int sensores ;
sensores = ((digitalRead(SI_Atras) << 3) | (digitalRead(SD_Adelante) << 1) | (digitalRead(SD_Atras)<< 2));
//digitalRead(SI_Adelante) << 3
return sensores;
}

int get_dist(){
  int Distancia;
 digitalWrite(trig, LOW);
  delayMicroseconds(1);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  dist = dur*0.034/2;
  Distancia = dist;
  return Distancia;
}
