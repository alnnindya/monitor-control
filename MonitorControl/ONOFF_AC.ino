CAYENNE_IN(2)
{int TRX;
int flag=0;
int chanel;
chanel=request.channel;
TRX = getValue.asInt(0);
if (TRX==1 && chanel ==2 ){
  digitalWrite(Relay_1,LOW);
  digitalWrite(2,LOW);
  delay(3000);
  digitalWrite(Relay_1,HIGH);
  flag=1;
  }
  else{
     digitalWrite(2,HIGH);
     digitalWrite(Relay_1,LOW);
     delay(4000);
     digitalWrite(Relay_1,HIGH);
     flag=0;
    }

 CAYENNE_LOG("Channel %d, pin %d, value %d", request.channel, 2, TRX);
}
