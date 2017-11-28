#ifndef _MESSAGE_
#define _MESSAGE_

typedef unsigned char Content; //defines the content type

/* This interface defines the behaviour of a Message */
class Message {

public:
	/* returns the content of the message */
	virtual Content getContent() const = 0;

};

#endif