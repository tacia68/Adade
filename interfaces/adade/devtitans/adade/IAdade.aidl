package devtitans.adade;

@VintfStability
interface IAdade {
        int connect();

        //int getLed();
        //boolean setLed(in int ledValue);

        int getLuminosity();
        int getTemperature();
        int getHumidity();
}
