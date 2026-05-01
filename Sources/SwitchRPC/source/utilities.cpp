#include <switch.h>
#include "utilities.hpp"
#include "logging.hpp"

// blocks until network is ready, if ever. 
void waitForNetworkReady() {
  writeToLog("[Network] Waiting for network to be ready...");

  while (true) {
    NifmInternetConnectionType connectionType;
    u32 wifiStrength;
    NifmInternetConnectionStatus connectionStatus;

    Result rc = nifmGetInternetConnectionStatus(&connectionType, &wifiStrength, &connectionStatus);
    
    if (R_SUCCEEDED(rc) && connectionStatus == NifmInternetConnectionStatus_Connected) {
      break;
    }

    svcSleepThread(1 * 1000 * 1000 * 1000ULL);
  }
}