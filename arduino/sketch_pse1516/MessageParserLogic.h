#ifndef _MESSAGE_PARSER_LOGIC_
#define _MESSAGE_PARSER_LOGIC_


#include "MessageParserStates.h"

/* This interface defines the behaviour of a MessageParserLogic for the MessageParserTask */
class MessageParserLogic {

public:
	/* handles the behaviour of the FSM piloted by the logic in its LISTENING state */
	virtual MessageParserState stateListening() = 0;
};

#endif
