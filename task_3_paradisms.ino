int motionSens = 7;
const int soilMoist = 3;
bool curr_State = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(motionSens, INPUT);
  pinMode(soilMoist, INPUT);

  attachInterrupt(digitalPinToInterrupt(motionSens), swap, CHANGE);
  attachInterrupt(digitalPinToInterrupt(soilMoist), soil_moist, RISING);
}

void loop()
{
  swap();
  soil_moist();
  delay(3000);
}

void swap()
{
  curr_State = !curr_State;
  digitalWrite(LED_BUILTIN, curr_State);
  Serial.println("Motion Interrupt");
}

void soil_moist()
{
  Serial.println("Soil Moisture Interrupt");
}
