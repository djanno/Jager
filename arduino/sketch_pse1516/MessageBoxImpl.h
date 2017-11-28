#ifndef _MESSAGE_BOX_IMPL_
#define _MESSAGE_BOX_IMPL_

#include "MessageBox.h"

/* This class defines a MessageBox. This component handles the message exchange functionalities of the robot. It has access to the serial port */
class MessageBoxImpl : public MessageBox {
	
public:
	bool messageAvailable();
	void send(Content content);
	Message* getMessage() const;
	
};

#endif