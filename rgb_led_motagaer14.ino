int B=10;
int G=9;
int R=11;
int x=0;
void setup (){
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
void loop () {
analogWrite(G,x);
analogWrite(B,x);
analogWrite(R,x);
delay(150); 
if (x<255) {x=x+5;}
else
{x=0; delay(300);}
}