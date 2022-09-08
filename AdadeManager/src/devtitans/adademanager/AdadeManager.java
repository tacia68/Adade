package devtitans.adademanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.adade.IAdade;                      // Criado pelo AIDL

public class AdadeManager {
    private static final String TAG = "DevTITANS.AdadeManager";
    private IBinder binder;
    private IAdade service;

    private static AdadeManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada.
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro desse arquivo.
    private AdadeManager() {
        Log.d(TAG, "Nova (única) instância do AdadeManager ...");

        binder = ServiceManager.getService("devtitans.adade.IAdade/default");
        if (binder != null) {
            service = IAdade.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Adade acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Adade!");
        }
        else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um objeto.
    public static AdadeManager getInstance() {
        if (instance == null)
            instance = new AdadeManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getTemperature() throws RemoteException {
        Log.d(TAG, "Executando método getTemperature() ...");
        return service.getTemperature();
    }

    public int getHumidity() throws RemoteException {
        Log.d(TAG, "Executando método getHumidity() ...");
        return service.getHumidity();
    }

    public int getLuminosity() throws RemoteException {
        Log.d(TAG, "Executando método getLuminosity() ...");
        return service.getLuminosity();
    }
}
