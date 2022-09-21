class Ldr{
  int ldrpin;
  int lum;
  public:
  Ldr(int pin){
    ldrpin = pin;
    }
  int read(){
    lum = analogRead(ldrpin);
    return lum;
    }
  String getluminosity(){
    float luminosity = this->read()/4095.0;
    String lumi = String(luminosity*100,0);
    lumi.trim();
    return TAG_RES + " " + TAG_LDR + " " +lumi+"\n";
    }
    
  };
Ldr ldr(ANALOG_PIN_0);
String getluminosity(){
  return ldr.getluminosity();
  };
