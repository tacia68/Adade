package devititans.adadeapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.RemoteException;
import android.view.View;
import android.widget.TextView;

import devtitans.adademanager.AdadeManager;                          // Biblioteca do Manager

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "DevTITANS.AdadeApp";
    private TextView textStatus
            , luminosidade
            , temperatura
            , umidade;
    private int valorTemperatura = 0
            ,valorUmidade = 0
            ,valorLuminosidade = 0,
            conexao = 0;
    private AdadeManager manager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textStatus   = findViewById(R.id.main_activity_conectado);
        luminosidade = findViewById(R.id.main_activity_valor_luminosidade);
        temperatura  = findViewById(R.id.main_activity_valor_temperatura);
        umidade      = findViewById(R.id.main_activity_valor_umidade);

        manager = AdadeManager.getInstance();


        AtualizarDados();
    }

    private void AtualizarDados() {
        View atualiza = findViewById(R.id.button);
        atualiza.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                int count = 0;
                int tentativas = 100;
                int espera = 50;

                try {
                    do{
                    Thread.sleep(espera );
                        count++;
                    valorTemperatura = manager.getTemperature();
                        if (count >= tentativas){
                            valorTemperatura = -2;
                        }
                    }while (valorTemperatura == -1);
                    do {
                        Thread.sleep(espera);
                        count++;
                        valorUmidade = manager.getHumidity();
                        if (count >= tentativas) {
                            valorUmidade = -2;
                        }
                    }while(valorUmidade ==-1);
                    count++;
                    do{
                        count++;
                    Thread.sleep(espera);
                    valorLuminosidade = manager.getLuminosity();
                        if (count >= tentativas) {
                            valorLuminosidade = -2;
                        }
                    Thread.sleep(espera);}while (valorLuminosidade == -1);
                    conexao = manager.connect();
                } catch (RemoteException | InterruptedException e) {
                    e.printStackTrace();
                }

                if (conexao == 0){

                    textStatus.setText("Desconectado");
                }else{
                    textStatus.setText("Conectado");
                }

                temperatura.setText(String.format("%.2f °C",valorTemperatura/100.0));
                luminosidade.setText(String.format("%.2f",valorLuminosidade/100.0));
                umidade.setText(String.format("%.2f %%",valorUmidade/100.0));
            }
        });
    }
}