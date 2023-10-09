/*
FUNDACION KINAL
CENTRO EDUCATIVO TECNICO LARELEORAL KINAL
PEROTO EN ELECTRONICA
QUINTO PERITO
SECCION: A
CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
ALUMNOS: PABLO DAVID HERNANDEZ AJIATAZ
CARNETS:2022472
PROYECTO FINAL
*/


#define Vout A0
float R1;

float SEN = 0.185;
int NUMBER = 100;


void setup() {
  pinMode(Vout, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}


void loop() {
  //RESISTENCIA
  float Lectura = analogRead(Vout);
  float Valor1 = map(Lectura, 0, 1023, 0, 5000);
  float Valor2 = Valor1 / 1000;
  float Valor3 = 50000 / Valor2;
  R1 = Valor3 - 10000;
  //CORRRIENTE
  float current = getCorriente(100);
  float currentRMS = 0.707 * current;
  float power = 230 * currentRMS;


  //VOLATJE

  float LecturaVolt = analogRead(A2);
  float Volt1 = map(LecturaVolt, 0, 1023, 0, 500);
  float Volt2 = Volt1;
  float Volt3 = Volt2 * 4800000;
  float Volt4 = Volt3 / 1000000;
  float Volt5 = Volt2 + Volt4;
  float Volt6 = Volt5 / 100;



  if (digitalRead(2) == HIGH) {
    Serial.println("EL VALOR DE LA RESISTENCIA ES:");
    Serial.println(R1);
    printM("Amperaje: ", current, " A ,");
    Serial.println("EL VALOR DE VOLTAJE ES:");
    Serial.print(Volt6);
    Serial.println(" V");
    delay(1000);
    Valor1 = 0;
    Valor2 = 0;
    Valor3 = 0;
    R1 = 0;
  }
}


void printM(String prefix, float value, String postfix)
{
  Serial.print(prefix);
  Serial.print(value, 3);
  Serial.println(postfix);
}
float getCorriente(int SNUMBER)
{
  float Voltage;
  float CorrienteSum = 0;
  for (int i = 0; i < SNUMBER ; i++)
  {
    Voltage = (analogRead(A1) * 5.0) / 1023.0;
    CorrienteSum += (Voltage - 2.5 ) / SEN;
  }
  float CorrienteSUM2 = CorrienteSum / SNUMBER;
  return (CorrienteSUM2);
}
