#ifndef _MESSAGE_BOX_
#define _MESSAGE_BOX_

#include "Message.h"

/* This interface defines the behaviour of a MessageBox component */
class MessageBox {

public:
	/* returns whether a message is available or not on the serial port */
	virtual bool messageAvailable() = 0;
	/* sends content towards the serial port */
	virtual void send(Content content) = 0;
	/* retrieves content from the serial port, wraps it in a message and then returns such message */
	virtual Message* getMessage() const = 0;
	
};

#endif