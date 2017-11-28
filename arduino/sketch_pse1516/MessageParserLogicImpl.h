#ifndef _MESSAGE_PARSER_LOGIC_IMPL_
#define _MESSAGE_PARSER_LOGIC_IMPL_

#include "MessageParserLogic.h"
#include "Robot.h"


/* This class defines a MessageParserLogic for the MessageParserTask */
class MessageParserLogicImpl : public MessageParserLogic {

protected:
	//the robot
	Robot* robot;

public:
	MessageParserLogicImpl();
	MessageParserState stateListening();

};

#endif