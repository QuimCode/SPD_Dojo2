#define LEDROJA_UNO 13
#define LEDROJA_DOS 12
#define LEDROJA_TRES 11
#define LEDROJA_CUATRO 10
#define PULSADOR 9
#define G 5
#define F 6
#define A 8
#define B 7
#define E 15
#define D 16
#define C 17
#define BUZZER 14

int estado_boton;

void setup()
{
    pinMode(9, INPUT_PULLUP);
    pinMode(LEDROJA_UNO, OUTPUT);
    pinMode(LEDROJA_DOS, OUTPUT);
    pinMode(LEDROJA_TRES, OUTPUT);
    pinMode(LEDROJA_CUATRO, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    estado_boton = digitalRead(9);
    Serial.println(estado_boton);

    digitalWrite(C, HIGH);

    if(estado_boton == 0)
    { 
    llegada_estacion(LEDROJA_UNO);
    delay(2000);
    salida_estacion(LEDROJA_UNO);
    delay(2000);

    llegada_estacion(LEDROJA_DOS);
    sonar(BUZZER,200,200);
    delay(2000);
    salida_estacion(LEDROJA_DOS);
    delay(2000);

    llegada_estacion(LEDROJA_TRES);
    sonar(BUZZER,250,200);
    delay(2000);
    salida_estacion(LEDROJA_TRES);
    delay(2000);

    llegada_estacion(LEDROJA_CUATRO);
    sonar(BUZZER,350,200);
    delay(2000);
    salida_estacion(LEDROJA_CUATRO);
    delay(2000);
}

    delay(50);
}

void llegada_estacion(int led)
{
    digitalWrite(led, HIGH);
}

void salida_estacion(int led)
{
    digitalWrite(led, LOW);
}

void sonar(int piezo,int frecuencia,int tiempo)
{
    Serial.println("Sonando buzzer");
    tone(piezo, frecuencia, tiempo);
    delay(500);
    tone(piezo, frecuencia, tiempo);
}