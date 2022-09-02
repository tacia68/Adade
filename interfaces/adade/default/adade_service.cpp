#include "adade_service.h"

namespace aidl::devtitans::adade {
    ndk::ScopedAStatus AdadeService::connect(int32_t* _aidl_return) {
        *_aidl_return = this->adade.connect();
        LOG(INFO) << "connect(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus AdadeService::getLuminosity(int32_t* _aidl_return) {
        *_aidl_return = this->adade.getLuminosity();
        LOG(INFO) << "getLuminosity(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus AdadeService::getTemperature(int32_t* _aidl_return) {
        *_aidl_return = this->adade.getTemperature();
        LOG(INFO) << "getTemperature(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus AdadeService::getHumidity(int32_t* _aidl_return) {
        *_aidl_return = this->adade.getHumidity();
        LOG(INFO) << "getHumidity(): " << *_aidl_return;
        return ndk::ScopedAStatus::ok();
    }
}
