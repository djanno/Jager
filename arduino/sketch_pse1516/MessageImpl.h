#ifndef _MESSAGE_IMPL_
#define _MESSAGE_IMPL_

#include "Message.h"

/* This class defines a Message */
class MessageImpl : public Message {

	//the content of the message
	Content content;
	
public:
	MessageImpl(Content content);
	Content getContent() const;
	
};

#endif