/*
**
** HadrianMicroSystem v1.2
** Adam Borucki (Sarverott) 2018
** https://github.com/Sarverott
** Program for Arduino, to connect with computer and read orders, expressed in commands
*/
int allowed_pins[8]={2,3,4,5,6,7,8,9};
void setup(){
  for(int i=0;i<sizeof(allowed_pins);i++){
    pinMode(allowed_pins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.print("#");
}
void loop(){
  String inputCommand[10]={"","","","","","","","","",""};
  int argIndex=0;
  while(true){
    if(Serial.available()){
      char inChar=Serial.read();
      if(inChar==':'){
        break;
      }else{
        if(inChar=='-'){
          argIndex++;
          continue;
        }else{
          inputCommand[argIndex]+=inChar;
        }
      }
    }else{
      delay(10);
    }
  }
  if(inputCommand[0]=="pin"){
    for(int i=0;i<sizeof(allowed_pins);i++){
      if(allowed_pins[i]==(inputCommand[1]).toInt()){
        if(inputCommand[2]=="high"){
          digitalWrite(inputCommand[1].toInt(), HIGH);
        }else if(inputCommand[2]=="low"){
          digitalWrite(inputCommand[1].toInt(), LOW);
        }
      }
    }
  }
}
