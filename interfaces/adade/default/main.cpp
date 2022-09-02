#include "adade_service.h"

using namespace aidl::devtitans::adade;                // SmartlampService (smartlamp_service.cpp)
using namespace std;                                       // std::shared_ptr
using namespace ndk;                                       // ndk::SharedRefBase

int main() {
    LOG(INFO) << "Iniciando Adade AIDL Service ...";

    ABinderProcess_setThreadPoolMaxThreadCount(0);

    shared_ptr<AdadeService> adade_service = SharedRefBase::make<AdadeService>();

    const string instance = std::string() + IAdade::descriptor + "/default";   // devtitans.smartlamp.ISmartlamp/default
    binder_status_t status = AServiceManager_addService(adade_service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    LOG(INFO) << "Adade AIDL Service iniciado com nome: " << instance;
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;                                   // Não deve chegar nunca aqui
}
