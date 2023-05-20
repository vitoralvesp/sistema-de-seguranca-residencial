
//Pinos do sensor da janela
int trig_j = 7;
int echo_j = 6;

//Pinos do sensor da porta
int trig_p=4;
int echo_p=3;

//Pino do LED da janela
int led_j = 8;

//Pino do LED da porta
int led_p=2;

//Pino do Buzzer
int buzzer=12;

//Medição do sensor da janela
float distancia_j;

//Medição do sensor da porta
float distancia_p;


void setup()  
{
  //Configura trig como saída e echo como entrada
  pinMode (trig_j, OUTPUT);
  pinMode (echo_j,INPUT);
  
  //Configura trig como saída e echo como entrada
  pinMode (trig_p, OUTPUT);
  pinMode (echo_p,INPUT);
  
  //Configura o LED da janela como saída
  pinMode(led_j, OUTPUT);
  
  //Configura o LED da porta como saída
  pinMode(led_p, OUTPUT);
  
  //Configura o Buzzer como saída
  pinMode(buzzer,OUTPUT);
  
  //Inicia a comunicação serial em 9600 bits/segundo
  Serial.begin (9600);
  
}

void loop()
{
  //Inicia o envio de pulsos sonoros no sensor da janela
  digitalWrite(trig_j, LOW);
  delay(0005);
  digitalWrite(trig_j, HIGH);
  delay(0010);
  digitalWrite(trig_j, LOW);
  
  //Armazena a medeição feita pelo sensor da janela
  distancia_j = pulseIn (echo_j, HIGH);
  distancia_j = distancia_j/58;
  
  //Inicia o envio de pulsos sonoros no sensor da porta
  digitalWrite(trig_p, LOW);
  delay(0005);
  digitalWrite(trig_p, HIGH);
  delay(0010);
  digitalWrite(trig_p, LOW);
  
  //Armazena a medeição feita pelo sensor da porta
  distancia_p = pulseIn (echo_p, HIGH);
  distancia_p = distancia_p/58;
    
  //Mostra no Monitor Serial as medições feitas
  Serial.print ("Janela:");
  Serial.println (distancia_j);
  Serial.print ("Porta:");
  Serial.println (distancia_p);

   //Caso apenas o sensor da janela detecte uma invasão(distância entre 0 e 10cm)
  if((distancia_j>0 && distancia_j<10) && (distancia_p>10 || distancia_p==0) ){
   //Aciona o Buzzer e o LED da janela
    
    digitalWrite(led_j,HIGH);
    tone(buzzer,500);
    delay(500);
    noTone(buzzer);
    digitalWrite(led_j,LOW);
    delay(500);
    }

   //Caso apenas o sensor da porta detecte uma invasão(distância entre 0 e 10cm)
 else if((distancia_p>0 && distancia_p<10)  && (distancia_j>10 || distancia_j==0) ){
//Aciona o Buzzer e o LED da porta
  
    digitalWrite(led_p,HIGH);
    tone(buzzer,500);
    delay(500);
    noTone(buzzer);
    digitalWrite(led_p,LOW);
    delay(500);
  }
  
  //Caso ambos os sensores detectem uma invasão(distância entre 0 e 10cm)
  else if((distancia_j>0 && distancia_j<10) && (distancia_p>0 && distancia_p<10) ){
  //Aciona o Buzzer e os LEDs da porta e da janela
  
    digitalWrite(led_j,HIGH);
    tone(buzzer,500);
    delay(500);
    noTone(buzzer);
    digitalWrite(led_j,LOW);
    delay(500);
    
    digitalWrite(led_p,HIGH);
    tone(buzzer,500);
    delay(500);
    noTone(buzzer);
    digitalWrite(led_p,LOW);
    delay(500);
    
  }
  }

  
