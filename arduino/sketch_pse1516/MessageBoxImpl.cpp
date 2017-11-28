#include "MessageBoxImpl.h"
#include "MessageImpl.h"
#include "Arduino.h"

bool MessageBoxImpl::messageAvailable() {
	return Serial.available();
}

void MessageBoxImpl::send(Content content) {
	Serial.println(content);
}

Message* MessageBoxImpl::getMessage() const {
	Content content = Serial.read();
	return new MessageImpl(content);
}

