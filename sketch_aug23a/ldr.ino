class Ldr{
  int ldrpin;
  int lum;
  String lumi;
  public:
  Ldr(int pin){
    ldrpin = pin;
    }
  void conv_dig(){
    float luminosity = this->read()/4095.0;
    lumi = String(luminosity*100,0);
    lumi.trim();    
  }

  String getLumi(){
    this->conv_dig(); 
    return lumi;
  }
  int read(){
    lum = analogRead(ldrpin);
    return lum;
    }
  String getluminosity(){
    this->conv_dig();  
    return TAG_RES + " " + TAG_LDR + " " +lumi+"\n";
    }
    
  };
Ldr ldr(ANALOG_PIN_0);
String getluminosity(){
  return ldr.getluminosity();
  };

String getLogLuminosity(){ 
  return ldr.getLumi();
}
