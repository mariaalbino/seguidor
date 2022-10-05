
int motor1a = 5;  //motor da direita sentido horario
int motor1b = 4;  //motor da direita sentido anti-horario

int motor2a = 3;  //motor da esquerda sentido horario
int motor2b = 2;  //motor da esquerda sentido anti-horario

int pinInfrav1 = 10;  //infravermelho da direita
int pinInfrav2 = 8;  //infravermelho do meio
int pinInfrav3 = 6;  //infravermelho do esquerda

int cont = 0;

//transforma o input no infravermelho em um valor booleano

bool infraValor1;
bool infraValor2;
bool infraValor3;

void setup(){

    Serial.begin(9600);  //de acordo com o arduino

    //os motores recebem informacao

    pinMode(motor1a, OUTPUT);
    pinMode(motor1b, OUTPUT);

    pinMode(motor2a, OUTPUT);
    pinMode(motor2b, OUTPUT);

    //os infravermelhos dao informacao

    pinMode(pinInfrav1, INPUT);
    pinMode(pinInfrav2, INPUT);
    pinMode(pinInfrav3, INPUT);

}

void loop(){

    //ler o valor nos infravermelhos (0=branco e 1=preto)

    infraValor1 = analogRead(pinInfrav1);
    infraValor2 = analogRead(pinInfrav2);
    infraValor3 = analogRead(pinInfrav3);

    //marcacao nos dois lados = inicio/fim do percurso


    if (infraValor1<500 && infraValor2>500 && infraValor3<500){  //em frente
        emFrente();
    }

    else if (infraValor1>500 && infraValor2>500 && infraValor3>500){  //inicio/fim
        cont = cont + 1;

        if(cont==2){
            Parar();
        }
    }

    else if(infraValor1<500 && infraValor2>500 && infraValor3<500){  //a direita
        Direita();
    }

    else if(infraValor1<500 && infraValor2>500 && infraValor3<500){  //a esquerda
        Esquerda();
    }

}

void emFrente(){

        analogWrite(motor1a, 100);
        analogWrite(motor1b, 0);

        analogWrite(motor2a, 0);
        analogWrite(motor2b, 100);

    }
    
void Direita(){

        analogWrite(motor1a, 0);
        analogWrite(motor1b, 0);

        analogWrite(motor2a, 0);
        analogWrite(motor2b, 100);
    
    }

void Esquerda(){

        analogWrite(motor1a, 100);
        analogWrite(motor1b, 0);

        analogWrite(motor2a, 0);
        analogWrite(motor2b, 0);
        
    }

void Parar(){

        analogWrite(motor1a, 0);
        analogWrite(motor1b, 0);

        analogWrite(motor2a, 0);
        analogWrite(motor2b, 0);
        
    }
    

