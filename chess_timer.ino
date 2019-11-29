#define D2  14
#define D1  15
#define D3  16
#define D0  17
#define SEG_MID   3 //Mid
#define SEG_BOTR  4 //BotR
#define SEG_BOT   5 //Bot
#define SEG_BOTL  6 //BotL
#define SEG_TOPR  7 //TopR
#define SEG_TOPL  8 //TopL
#define SEG_TOP   9 //Top

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(SEG_MID, OUTPUT);
  pinMode(SEG_BOTR, OUTPUT);
  pinMode(SEG_BOT, OUTPUT);
  pinMode(SEG_BOTL, OUTPUT);
  pinMode(SEG_TOPR, OUTPUT);
  pinMode(SEG_TOPL, OUTPUT);
  pinMode(SEG_TOP, OUTPUT);
  
  digitalWrite(D2, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D0, HIGH);
}

typedef void(*numfunc_t)(bool);

numfunc_t dispNum[] = {
  zero, one, two, three, four, five, six, seven, eight, nine, empty
};

void loop() {
  /*int count = (int)(millis() / 100);
  bool flip = ((count / 10) % 6) < 3;
  Serial.print(count);
  Serial.print(' ');
  Serial.println(flip);*/
  disp(-1, true);

  
  
  /*(for (i = 0; i <= 10; i++) {
    dispNum[i](false);
    delay(300);
  } */
}

void disp(int num, bool up) {
  int del = 5;

  int dig0 = num % 10;
  num /= 10;
  int dig1 = num % 10;
  num /= 10;
  int dig2 = num % 10;
  num /= 10;
  int dig3 = num % 10;

  dig0 = abs(dig0);
  dig1 = abs(dig1);
  dig2 = abs(dig2);
  dig3 = abs(dig3);
  
  digitalWrite(D0, LOW);
  dispNum[(up) ? dig0 : dig3](up);
  delay(del);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  dispNum[(up) ? dig1 : dig2](up);
  delay(del);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  dispNum[(up) ? dig2 : dig1](up);
  delay(del);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  dispNum[(up) ? dig3 : dig0](up);
  delay(del);
  digitalWrite(D3, HIGH);
}

void empty(bool up) {
  (void)up;
  digitalWrite(SEG_MID, LOW);
  digitalWrite(SEG_BOTR, LOW);
  digitalWrite(SEG_BOT, LOW);
  digitalWrite(SEG_BOTL, LOW);
  digitalWrite(SEG_TOPR, LOW);
  digitalWrite(SEG_TOPL, LOW);
  digitalWrite(SEG_TOP, LOW);
}

void zero(bool up) {
  (void)up;
  digitalWrite(SEG_MID, LOW);
  digitalWrite(SEG_BOTR, HIGH);
  digitalWrite(SEG_BOT, HIGH);
  digitalWrite(SEG_BOTL, HIGH);
  digitalWrite(SEG_TOPR, HIGH);
  digitalWrite(SEG_TOPL, HIGH);
  digitalWrite(SEG_TOP, HIGH);
}

void one(bool up) {
  if(up) {
    digitalWrite(SEG_MID, LOW);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, LOW);
    digitalWrite(SEG_TOP, LOW);
  }
  else {
    digitalWrite(SEG_MID, LOW);
    digitalWrite(SEG_BOTR, LOW);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, LOW);
  }
}

void two(bool up) {
  (void)up;
  digitalWrite(SEG_MID, HIGH);
  digitalWrite(SEG_BOTR, LOW);
  digitalWrite(SEG_BOT, HIGH);
  digitalWrite(SEG_BOTL, HIGH);
  digitalWrite(SEG_TOPR, HIGH);
  digitalWrite(SEG_TOPL, LOW);
  digitalWrite(SEG_TOP, HIGH);
}

void three(bool up) {
  if(up) {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, LOW);
    digitalWrite(SEG_TOP, HIGH);
  }
  else {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, LOW);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, HIGH);
  }
}

void four(bool up) {
  if(up) {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, LOW);
  }
  else {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, LOW);
  }
}

void five(bool up) {
  (void)up;
  digitalWrite(SEG_MID, HIGH);
  digitalWrite(SEG_BOTR, HIGH);
  digitalWrite(SEG_BOT, HIGH);
  digitalWrite(SEG_BOTL, LOW);
  digitalWrite(SEG_TOPR, LOW);
  digitalWrite(SEG_TOPL, HIGH);
  digitalWrite(SEG_TOP, HIGH);
}

void six(bool up) {
  if(up) {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, HIGH);
  }
  else {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, HIGH);
  }
}

void seven(bool up) {
  if(up) {
    digitalWrite(SEG_MID, LOW);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, LOW);
    digitalWrite(SEG_TOP, HIGH);
  }
  else {
    digitalWrite(SEG_MID, LOW);
    digitalWrite(SEG_BOTR, LOW);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, LOW);
  }
}

void eight(bool up) {
  (void)up;
  digitalWrite(SEG_MID, HIGH);
  digitalWrite(SEG_BOTR, HIGH);
  digitalWrite(SEG_BOT, HIGH);
  digitalWrite(SEG_BOTL, HIGH);
  digitalWrite(SEG_TOPR, HIGH);
  digitalWrite(SEG_TOPL, HIGH);
  digitalWrite(SEG_TOP, HIGH);
}

void nine(bool up) {
  if(up) {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, LOW);
    digitalWrite(SEG_BOTL, LOW);
    digitalWrite(SEG_TOPR, HIGH);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, HIGH);
  }
  else {
    digitalWrite(SEG_MID, HIGH);
    digitalWrite(SEG_BOTR, HIGH);
    digitalWrite(SEG_BOT, HIGH);
    digitalWrite(SEG_BOTL, HIGH);
    digitalWrite(SEG_TOPR, LOW);
    digitalWrite(SEG_TOPL, HIGH);
    digitalWrite(SEG_TOP, LOW);
  }
}
