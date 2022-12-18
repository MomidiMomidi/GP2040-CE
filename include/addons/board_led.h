#ifndef _BoardLed_H
#define _BoardLed_H

#include "gpaddon.h"
#include "pico/stdlib.h"
#include "storagemanager.h"

// BoardLed Module Name
#define OnBoardLedName "OnBoardLed"

#define BOARD_LED_PIN 25
#define BLINK_INTERVAL_USB_UNMOUNTED 200
#define BLINK_INTERVAL_CONFIG_MODE 1000

class BoardLedAddon : public GPAddon {
public:
	virtual bool available();   // GPAddon available
	virtual void setup();       // BoardLed Setup
	virtual void process();     // BoardLed Process
	virtual std::string name() { return OnBoardLedName; }
private:
	OnBoardLedMode onBoardLedMode;
	bool isConfigMode;
	bool prevState;
	uint32_t timeSinceBlink;
};

#endif  // _BoardLed_H_