CAYENNE_IN(1){
  int trr;
  int chaneel;
  chaneel=request.channel;
 trr = getValue.asInt(0);
if(trr==1&& chaneel==1 ){
   pinMode(Relay_3, OUTPUT);
   delay(3000);
   pinMode(Relay_3, INPUT);
    }
  else{
    pinMode(Relay_3, INPUT);
    }
}
