const int starboard_outboard = 27;
const int starboard_inboard = 26;
const int port_outboard = 19;
const int port_inboard = 18;

void setup() {
  // put your setup code here, to run once:
    pinMode(starboard_outboard, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  go();
  delay(50);
  stop();
  delay(950);
}

void go() {
  analogWrite(starboard_outboard, 255);
  analogWrite(starboard_inboard, 255);
  analogWrite(port_outboard, 255);
  analogWrite(port_inboard, 255);
}

void stop() {
  analogWrite(starboard_outboard, 0);
  analogWrite(starboard_inboard, 0);
  analogWrite(port_outboard, 0);
  analogWrite(port_inboard, 0);
}
