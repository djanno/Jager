#include "Scheduler.h"
#include "MessageParserTask.h"
#include "OrientationTask.h"
#include "NavigationTask.h"
#include "LightControlTask.h"

Scheduler sched;

bool detected;
bool found;
bool ready;
int chosenDirection;

void setup() {
  //initializing the tasks
  MessageParserTask::getInstance()->init(MESSAGE_PARSER_PERIOD);
  OrientationTask::getInstance()->init(ORIENTATION_PERIOD);
  NavigationTask::getInstance()->init(NAVIGATION_PERIOD);
  LightControlTask::getInstance()->init(LIGHT_CONTROL_PERIOD);
  //initializing the scheduler and adding the tasks
  sched.init(MESSAGE_PARSER_PERIOD);
  sched.addTask(MessageParserTask::getInstance());
  sched.addTask(OrientationTask::getInstance());
  sched.addTask(NavigationTask::getInstance());
  sched.addTask(LightControlTask::getInstance());
  Serial.begin(9600);
}

void loop() {
  // begin
  sched.schedule();
}
